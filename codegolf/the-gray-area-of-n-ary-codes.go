/*

Write a program or function that takes a base n and a number x, and returns or outputs the n-ary Gray code of x.
Rules

    n is an integer in the range 2 <= n <= 16.
    x is an integer in the range 0 <= n < 2**32.
    The inputted numbers can either be two integer arguments if you write a function, or two arguments to ARGV or a space separated pair to STDIN if you write a program.
    The output should be a string, either returned or printed to STDOUT.
    If n is 10 or more, use hex digits to represent digits with a value greater than 9. The case of the digits does not matter.
    If the n-ary Gray code of x is zero, '0' must be printed or returned.
    Code length is in bytes, and standard loopholes are not permitted.
    You do not need to use the same algorithm as below, but if you use a different one, make sure it produces valid Gray codes.

Example

Example code adapted from Wikipedia:

>>> import string
>>>
>>> def nary_gray_code(base, num):
...     base_num = []
...     # Convert to num to base base
...     while num:
...         base_num.append(num % base)
...         num = num // base
...     # Convert base base number to base-ary Gray code
...     shift = 0
...     gray = []
...     for b in reversed(base_num):
...         gray.insert(0, (b + shift) % base)
...         shift += base - gray[0]
...     return "".join(string.hexdigits[i] for i in reversed(gray)) or "0"
...
>>> nary_gray_code(2, 100)
'1010110'
>>> nary_gray_code(2, 1)
'1'
>>> nary_gray_code(2, 0)
'0'
>>> nary_gray_code(10, 23)
'21'
>>> nary_gray_code(10, 100)
'190'
>>> nary_gray_code(3, 26)
'200'
>>> nary_gray_code(3, 27)
'1200'
>>> for i in range(2, 17):
...     print(i, nary_gray_code(i, 2**32 - 1))
...
2 10000000000000000000000000000000
3 122102120011102000122
4 3000000000000000
5 34020102231331
6 1401154214013
7 260241350125
8 34000000000
9 11762782617
10 4875571576
11 1824007509
12 92b627446
13 5b25a2c00
14 2ac96ab2b
15 197dde1a7
16 f0000000
>>>

*/

package main

import "fmt"

func main() {
	assert(grayn(2, 100) == "1010110")
	assert(grayn(2, 1) == "1")
	assert(grayn(2, 0) == "0")
	assert(grayn(10, 23) == "21")
	assert(grayn(10, 100) == "190")
	assert(grayn(3, 26) == "200")
	assert(grayn(3, 27) == "1200")
	for i := uint(2); i <= 16; i++ {
		fmt.Println(i, grayn(i, 1<<32-1))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func grayn(b, n uint) string {
	if b == 0 || n == 0 {
		return "0"
	}

	var v []uint
	for ; n != 0; n /= b {
		v = append(v, n%b)
	}

	l := len(v)
	g := make([]uint, l)
	s := uint(0)
	for i := 0; i < l; i++ {
		g[i] = (v[l-i-1] + s) % b
		s += b - g[i]
	}

	r := ""
	for i := range g {
		r += fmt.Sprintf("%x", g[i])
	}
	return r
}
