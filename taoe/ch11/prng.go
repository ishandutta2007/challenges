package main

import "fmt"

func main() {
	var r RNG

	r.Init()
	for {
		fmt.Println(r.Gen())
	}
}

type RNG struct {
	a, b, c, d uint8
}

func (r *RNG) Init() {
	r.a, r.b, r.c, r.d = 0xff, 0xff, 0xff, 0xff
}

func (r *RNG) Gen() uint8 {
	v := (r.d<<1 | r.c>>7) ^ r.c
	r.d, r.c, r.b, r.a = r.c, r.b, r.a, v
	return v
}
