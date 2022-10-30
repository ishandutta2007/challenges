/*

Create a function that calculates the missing value of 3 inputs using Ohm's law. The inputs are v, r or i (aka: voltage, resistance and current).

Ohm's law:

V = R * I

Return the missing value rounded to two decimal places.
Examples

ohms_law(12, 220, None) ➞ 0.05

ohms_law(230, None, 2) ➞ 115

ohms_law(None, 220, 0.02) ➞ 4.4

ohms_law(None, None, 10) ➞ "Invalid"

ohms_law(500, 50, 10) ➞ "Invalid"

Notes

    Missing values will be None
    If there is more than one missing value, or no missing value, return "Invalid"
    Only numbers will be given.

*/

package main

import (
	"math"
	"reflect"
)

func main() {
	test(12, 220, nil, 0.05)
	test(230, nil, 2, 115)
	test(nil, 220, 0.02, 4.4)
	test(nil, nil, 10, "Invalid")
	test(500, 50, 10, "Invalid")
}

func ohms(v, r, i interface{}) interface{} {
	V, hv := get(v)
	R, hr := get(r)
	I, hi := get(i)
	switch {
	case hv && hr && hi:
		return "Invalid"
	case hv && hr:
		return V / R
	case hv && hi:
		return V / I
	case hr && hi:
		return R * I
	default:
		return "Invalid"
	}
}

func get(v interface{}) (f float64, ok bool) {
	if v == nil {
		return
	}

	defer func() {
		if err := recover(); err != nil {
			ok = false
		}
	}()
	rv := reflect.ValueOf(v)
	rf := rv.Convert(reflect.TypeOf(f))
	return rf.Float(), true
}

func test(v, r, i, p interface{}) {
	x := ohms(v, r, i)
	y, ok := get(p)
	if !ok {
		assert(x == p)
	} else {
		z := x.(float64)
		assert(math.Abs(z-y) < 1e-2)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
