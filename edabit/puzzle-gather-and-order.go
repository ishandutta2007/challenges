/*

Create a gather function that accepts a string argument and returns another function. The function calls should support continued chaining until order is called.

order should accept a number as an argument and return another function. The function calls should support continued chaining until get is called.

get should return all of the arguments provided to the gather functions as a string in the order specified in the order functions.

Examples

gather("a")("b")("c").order(0)(1)(2).get() ➞ "abc"

gather("a")("b")("c").order(2)(1)(0).get() ➞ "cba"

gather("e")("l")("o")("l")("!")("h").order(5)(0)(1)(3)(2)(4).get()  ➞ "hello!"

Notes

Expect gather and order to chain any number of times, but always with the same number of invocations for each (i.e both fuctions will always be chained the same nubmer of times).

*/

package main

func main() {
	assert(gather("a")("b")("c").order(0)(1)(2).get() == "abc")
	assert(gather("a")("b")("c").order(2)(1)(0).get() == "cba")
	assert(gather("a")("b")("c")("d")("e")("f").order(1)(0)(2)(3)(4)(5).get() == "bacdef")
	assert(gather("h")("i")("j")("k")("l")("m").order(0)(4)(3)(5)(1)(2).get() == "hlkmij")
	assert(gather("e")("l")("o")("l")("!")("h").order(5)(0)(1)(3)(2)(4).get() == "hello!")
	assert(gather("e")("a")("d")("b")("i")("!")("t")("!").order(0)(2)(1)(3)(4)(6)(5)(7).get() == "edabit!!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type chain func(interface{}) chain

func (c chain) order(v interface{}) chain {
	return c(v)
}

func (c chain) get() string {
	var s string
	c(&s)
	return s
}

type sentence struct {
	word []string
	seq  []int
}

func (s *sentence) process(v interface{}) chain {
	switch v := v.(type) {
	case string:
		s.word = append(s.word, v)
	case int:
		s.seq = append(s.seq, v)
	case *string:
		var p string
		for _, i := range s.seq {
			p += s.word[i]
		}
		*v = p
	}
	return s.process
}

func gather(v interface{}) chain {
	s := &sentence{}
	return s.process(v)
}
