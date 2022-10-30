/*

A number n becomes a super-d number when, for any digit d from 2 up to 9,
the result of d * nᵈ contains d consecutive digits equal to d.

Given a positive integer n, implement a function that returns:

    "Super-d Number" if n is a super-d number, replacing the letterd with the digit (any from 2 up to 9) that makes it super;
    "Normal Number" if n is not a super-d number.

Examples

isSuperD(19) ➞ "Super-2 Number"
// when d = 2
// 2 * 19² = 722
// There are two (d) consecutives digits equal to 2 (d)

isSuperD(753) ➞ "Super-3 Number"
// when d = 3
// 3 * 753³ = 1280873331
// There are three (d) consecutives digits equal to 3 (d)

isSuperD(1168) ➞ "Super-4 Number"
// when d = 4
// 4 * 1168⁴ = 7444428488704
// There are four (d) consecutives digits equal to 4 (d)

isSuperD(24) ➞ "Normal Number"
// No cases where d * 24ᵈ (with d being any digit from 2 up to 9)...
// ...leads to a result containing d consecutive digits equal to d

Notes

    Any given n will be a positive integer greater or equal to 0.

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	assert(superd(19) == "Super-2 Number")
	assert(superd(753) == "Super-3 Number")
	assert(superd(1168) == "Super-4 Number")
	assert(superd(24) == "Normal Number")
	assert(superd(20379) == "Super-5 Number")
	assert(superd(185423) == "Super-8 Number")
	assert(superd(1170) == "Normal Number")
	assert(superd(118) == "Normal Number")
	assert(superd(93568867) == "Super-9 Number")
	assert(superd(333) == "Super-2 Number")
	assert(superd(107) == "Super-2 Number")
	assert(superd(1184321) == "Super-7 Number")
	assert(superd(10098023246) == "Normal Number")
	assert(superd(1045361) == "Super-6 Number")
	assert(superd(0) == "Normal Number")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func superd(n uint64) string {
	x := new(big.Int)
	x.SetUint64(n)
	for i := 2; i <= 9; i++ {
		p := big.NewInt(int64(i))
		q := new(big.Int)
		q.Exp(x, p, nil)
		p.Mul(p, q)

		t := strings.Repeat(fmt.Sprint(i), i)
		if strings.Index(p.String(), t) >= 0 {
			return fmt.Sprintf("Super-%d Number", i)
		}
	}
	return "Normal Number"
}
