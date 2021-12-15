package verifier

import (
	"os"
	"testing"
	"time"

	"github.com/iost-official/go-iost/v3/core/block"
	"github.com/iost-official/go-iost/v3/core/tx"
	"github.com/iost-official/go-iost/v3/core/txpool"
	"github.com/iost-official/go-iost/v3/db"
)

type mockTxIter struct {
}

func (m *mockTxIter) Next() (*tx.Tx, bool) {
	return nil, false
}

func TestVerifier_Gen(t *testing.T) {
	mvccdb, err := db.NewMVCCDB("mvcc")
	if err != nil {
		t.Fatal(err)
	}
	defer os.RemoveAll("mvcc")

	mti := txpool.NewSortedTxMap()

	blk := block.Block{
		Head: &block.BlockHead{
			Version:    0,
			ParentHash: []byte{},
			Number:     0,
			Witness:    "abc",
			Time:       time.Now().UnixNano(),
		},
		Txs:      []*tx.Tx{},
		Receipts: []*tx.TxReceipt{},
	}
	var e Executor
	var v Verifier
	a, b, c := e.Gen(&blk, nil, nil, mvccdb, mti, &Config{
		Mode:        0,
		Timeout:     time.Second,
		TxTimeLimit: time.Millisecond * 100,
	})

	t.Log(a, b, c)
	t.Log(blk)

	err = v.Verify(&blk, nil, nil, mvccdb, &Config{
		Mode:        0,
		Timeout:     time.Second,
		TxTimeLimit: time.Millisecond * 100,
	})

	if err != nil {
		t.Fatal(err)
	}
}
