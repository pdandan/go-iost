package cverifier

import (
	"testing"
	"time"

	"github.com/iost-official/go-iost/v3/core/block"
	"github.com/iost-official/go-iost/v3/core/tx"
	"github.com/smartystreets/goconvey/convey"
)

func TestVerifyBlockHead(t *testing.T) {
	stamp := time.Now().UnixNano()
	convey.Convey("Test of verify block head", t, func() {
		parentBlk := &block.Block{
			Head: &block.BlockHead{
				Number: 3,
				Time:   stamp - 1,
			},
		}
		hash := parentBlk.HeadHash()
		blk := &block.Block{
			Head: &block.BlockHead{
				ParentHash:          hash,
				Number:              4,
				Time:                stamp,
				TxMerkleHash:        []byte{},
				TxReceiptMerkleHash: []byte{},
			},
		}
		convey.Convey("Pass", func() {
			err := VerifyBlockHead(blk, parentBlk)
			convey.So(err, convey.ShouldBeNil)
		})

		convey.Convey("Wrong time", func() {
			blk.Head.Time = stamp - 5
			err := VerifyBlockHead(blk, parentBlk)
			convey.So(err, convey.ShouldEqual, errOldBlk)
			blk.Head.Time = stamp + 10*1e9
			err = VerifyBlockHead(blk, parentBlk)
			convey.So(err, convey.ShouldEqual, errFutureBlk)
		})

		convey.Convey("Wrong parent", func() {
			blk.Head.ParentHash = []byte("fake hash")
			err := VerifyBlockHead(blk, parentBlk)
			convey.So(err, convey.ShouldEqual, errParentHash)
		})

		convey.Convey("Wrong number", func() {
			blk.Head.Number = 5
			err := VerifyBlockHead(blk, parentBlk)
			convey.So(err, convey.ShouldEqual, errNumber)
		})

		convey.Convey("Wrong tx hash", func() {
			tx0 := tx.NewTx(nil, nil, 1000, 1, 300, 0, 0)
			blk.Txs = append(blk.Txs, tx0)
			blk.Head.TxMerkleHash = blk.CalculateTxMerkleHash()
			err := VerifyBlockHead(blk, parentBlk)
			convey.So(err, convey.ShouldBeNil)
			blk.Head.TxMerkleHash = []byte("fake hash")
			err = VerifyBlockHead(blk, parentBlk)
			convey.So(err, convey.ShouldEqual, errTxHash)
		})
	})
}
