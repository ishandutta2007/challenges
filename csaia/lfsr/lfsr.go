// https://www.cs.princeton.edu/courses/archive/fall10/cos126/assignments/lfsr.html
package main

import (
	"fmt"
	"image"
	"image/color"
	"image/png"
	"log"
	"math/big"
	"os"
	"strings"
)

func main() {
	testlfsr()
	testcrypt()
}

func testlfsr() {
	lfsr, _ := NewLFSR("01101000010", 8)
	for i := 0; i < 10; i++ {
		bit := lfsr.Step()
		fmt.Printf("%v %v\n", lfsr, bit)
	}
	fmt.Println()

	lfsr.Reset()
	for i := 0; i < 10; i++ {
		val := lfsr.Gen(5)
		fmt.Printf("%v %v\n", lfsr, val)
	}
}

func testcrypt() {
	lfsr, _ := NewLFSR("01101000010100010000", 16)
	cryptfile(lfsr, "pipe.png", "xpipe.png")
	cryptfile(lfsr, "xpipe.png", "xxpipe.png")
}

func cryptfile(l *LFSR, in, out string) {
	l.Reset()

	f, err := os.Open(in)
	ck(err)
	defer f.Close()

	m, _, err := image.Decode(f)
	ck(err)

	w, err := os.Create(out)
	ck(err)

	b := m.Bounds()
	p := image.NewRGBA(b)
	for y := b.Min.Y; y < b.Max.Y; y++ {
		for x := b.Min.X; x < b.Max.X; x++ {
			co := m.At(x, y)
			cp := color.RGBAModel.Convert(co).(color.RGBA)
			cp.R ^= uint8(l.Gen(8))
			cp.G ^= uint8(l.Gen(8))
			cp.B ^= uint8(l.Gen(8))
			p.Set(x, y, cp)
		}
	}
	ck(png.Encode(w, p))
	ck(w.Close())
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

type LFSR struct {
	seed   string
	state  *big.Int
	length int
	tap    uint
}

func NewLFSR(seed string, tap uint) (*LFSR, error) {
	l := &LFSR{
		seed:   seed,
		state:  new(big.Int),
		length: len(seed),
		tap:    tap,
	}
	_, ok := l.state.SetString(seed, 2)
	if !ok {
		return nil, fmt.Errorf("invalid seed")
	}
	return l, nil
}

func (l *LFSR) Reset() {
	l.state.SetString(l.seed, 2)
}

func (l *LFSR) Step() int {
	x := l.state.Bit(int(l.tap))
	y := l.state.Bit(l.length - 1)
	b := x ^ y

	m := big.NewInt(1)
	m.Lsh(m, uint(l.length))
	m.Sub(m, big.NewInt(1))

	l.state.Lsh(l.state, 1)
	l.state.SetBit(l.state, 0, b)
	l.state.And(l.state, m)

	return int(b)
}

func (l *LFSR) Gen(k int) int {
	v := 0
	for i := 0; i < k; i++ {
		v = (v << 1) | l.Step()
	}
	return v
}

func (l *LFSR) String() string {
	s := l.state.Text(2)
	return strings.Repeat("0", l.length-len(s)) + s
}
