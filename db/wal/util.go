package wal

import (
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"github.com/iost-official/go-iost/v3/ilog"
)

var errBadWALName = errors.New("bad wal name")

func filterDirWithExt(d, ext string) ([]string, error) {
	dir, err := os.Open(d)
	if err != nil {
		return nil, err
	}
	defer dir.Close()

	names, err := dir.Readdirnames(-1)
	if err != nil {
		return nil, err
	}
	sort.Strings(names)

	if ext != "" {
		tss := make([]string, 0)
		for _, v := range names {
			if strings.HasSuffix(v, ext) {
				tss = append(tss, v)
			}
		}
		names = tss
	}
	return names, nil
}

// exists returns whether the given file or directory exists
func exists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}
	if os.IsNotExist(err) {
		return false, nil
	}
	return true, err
}

// Exist returns true if there are any files in a given directory.
func Exist(dir string) bool {
	names, err := filterDirWithExt(dir, ".wal")
	names2, err2 := filterDirWithExt(dir, ".wal.tmp")
	if err != nil || err2 != nil {
		return false
	}
	return len(names) != 0 || len(names2) != 0
}

func readWALNames(dirpath string) ([]string, error) {
	names, err := filterDirWithExt(dirpath, "")
	if err != nil {
		return nil, err
	}
	wnames := checkWalNames(dirpath, names)
	if len(wnames) == 0 {
		return nil, ErrFileNotFound
	}
	return wnames, nil
}

func checkWalNames(dirpath string, names []string) []string {
	wnames := make([]string, 0)
	var tmpWal string
	for _, name := range names {
		if _, _, err := parseWALName(name); err != nil {
			// don't complain about left over tmp files
			if !strings.HasSuffix(name, ".wal.tmp") {
				continue
			}
			if strings.HasSuffix(name, ".wal.tmp") && len(tmpWal) == 0 {
				tmpWal = name
			} else {
				ilog.Warn("ignore file in WAL directory, path: ", name, " error: ", err)
				err := os.Remove(dirpath + "/" + name)
				if err != nil {
					ilog.Error("Remove file: ", err)
				}
			}
			continue
		}
		wnames = append(wnames, name)
	}
	wnames = append(wnames, tmpWal)
	return wnames
}

func parseWALName(str string) (seq, index uint64, err error) {
	if !strings.HasSuffix(str, ".wal") {
		return 0, 0, errBadWALName
	}
	nameBase := filepath.Base(str)
	_, err = fmt.Sscanf(nameBase, "%016x-%016x.wal", &seq, &index)
	return seq, index, err
}

func walName(seq, index uint64) string {
	return fmt.Sprintf("%016x-%016x.wal", seq, index)
}

// OpenDir open a dir
func OpenDir(path string) (*os.File, error) { return os.Open(path) }

// ZeroToEnd write zero to file from current to end
func ZeroToEnd(f *os.File) error {
	off, err := f.Seek(0, io.SeekCurrent)
	if err != nil {
		return err
	}
	lenf, lerr := f.Seek(0, io.SeekEnd)
	if lerr != nil {
		return lerr
	}
	if err = f.Truncate(off); err != nil {
		return err
	}
	// make sure blocks remain allocated
	if err = f.Truncate(lenf); err != nil {
		return err
	}
	_, err = f.Seek(off, io.SeekStart)
	return err
}

// Uint64ToBytes convert uint64 to byte array
func Uint64ToBytes(i uint64) []byte {
	var buf = make([]byte, 8)
	binary.BigEndian.PutUint64(buf, i)
	return buf
}

// BytesToUint64 convert byte array to uint64
func BytesToUint64(p []byte) uint64 {
	res := binary.BigEndian.Uint64(p)
	return res
}
