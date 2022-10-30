/*

Problem: Slot Machine Hacker from Facebook Hacker Cup 2011 Round 1B

Goal: Shortest code in your favourite language using stdin/stdout. You cannot assume getRandomNumber is defined, i.e. your solution has to include a potentially golfed version as a function or in some other way.

Reference solution: on SO [I chose mine, because it uses stdin/stdout and I'm unsure about dave's solution.]

Problem text follows:

You recently befriended a guy who writes software for slot machines. After hanging out with him a bit, you notice that he has a penchant for showing off his knowledge of how the slot machines work.
Eventually you get him to describe for you in precise detail the algorithm used on a particular brand of machine. The algorithm is as follows:

int getRandomNumber() {
  secret = (secret * 5402147 + 54321) % 10000001;
  return secret % 1000;
}

This function returns an integer number in [0, 999]; each digit represents one of ten symbols that appear on a wheel during a particular machine state. secret is initially set to some nonnegative value unknown to you.

By observing the operation of a machine long enough, you can determine value of secret and thus predict future outcomes. Knowing future outcomes you would be able to bet in a smart way and win lots of money.
Input

The first line of the input contains positive number T, the number of test cases. This is followed by T test cases. Each test case consists of a positive integer N, the number of observations you make.
Next N tokens are integers from 0 to 999 describing your observations.

Output

For each test case, output the next 10 values that would be displayed by the machine separated by whitespace.
If the sequence you observed cannot be produced by the machine your friend described to you, print "Wrong machine" instead.
If you cannot uniquely determine the next 10 values, print "Not enough observations" instead.
Constraints

    T = 20
    1 ≤ N ≤ 100
    Tokens in the input are no more than 3 characters long and contain only digits 0-9.

Example input

5
1 968
3 767 308 284
5 78 880 53 698 235
7 23 786 292 615 259 635 540
9 862 452 303 558 767 105 911 846 462

Example output

Not enough observations
577 428 402 291 252 544 735 545 771 34
762 18 98 703 456 676 621 291 488 332
38 802 434 531 725 594 86 921 607 35
Wrong machine

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]uint{968}, ErrShortObservations)
	test([]uint{767, 308, 284}, []uint{577, 428, 402, 291, 252, 544, 735, 545, 771, 34})
	test([]uint{78, 880, 53, 698, 235}, []uint{762, 18, 98, 703, 456, 676, 621, 291, 488, 332})
	test([]uint{23, 786, 292, 615, 259, 635, 540}, []uint{38, 802, 434, 531, 725, 594, 86, 921, 607, 35})
	test([]uint{862, 452, 303, 558, 767, 105, 911, 846, 462}, ErrWrongMachine)
}

func test(a []uint, r interface{}) {
	p, err := predict(a)
	fmt.Println(p, err)
	switch r := r.(type) {
	case []uint:
		assert(reflect.DeepEqual(p, r))
	case error:
		assert(err == r)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func predict(a []uint) ([]uint, error) {
	l := len(a)
	if l == 0 {
		return nil, ErrShortObservations
	}

	var (
		sd uint
		n  int
	)
	for i := uint(0); i <= 10000; i++ {
		s := i*1000 + a[0]
		if match(a, s) {
			sd = s
			if n++; n > 1 {
				break
			}
		}
	}
	if n == 0 {
		return nil, ErrWrongMachine
	}
	if n > 1 {
		return nil, ErrShortObservations
	}

	v := gen(sd, l+10)
	return v[l:], nil
}

func gen(s uint, n int) []uint {
	var (
		r RNG
		v []uint
	)
	r.Seed(s)
	for i := 0; i < n; i++ {
		v = append(v, r.Value())
		r.Next()
	}
	return v
}

func match(a []uint, s uint) bool {
	var r RNG
	r.Seed(s)
	for _, v := range a {
		if r.Value() != v {
			return false
		}
		r.Next()
	}
	return true
}

var (
	ErrShortObservations = fmt.Errorf("Not enough observations")
	ErrWrongMachine      = fmt.Errorf("Wrong machine")
)

type RNG struct {
	secret uint
}

func (r *RNG) Seed(seed uint) {
	r.secret = seed
}

func (r *RNG) Next() {
	r.secret = (r.secret*5402147 + 54321) % 10000001
}

func (r *RNG) Value() uint {
	return r.secret % 1000
}
