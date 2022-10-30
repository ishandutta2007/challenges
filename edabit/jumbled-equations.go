/*

In this challenge, you are given an array of one or more arithmetic operators and a array of numbers.
Take each of the operators and mate it with any three separate numbers in the array to create a valid equation.
Your answer should contain all possible equations.

Examples

jumbled([["+"], [2, 1, 3]]) ➞ ["1+2=3"]

jumbled(["+", "*"], [36, 28, 71, 4, 12, 7, 11]]) ➞ ["4*7=28", "4+7=11"]

jumbled([["+", "-", "*", "**"], [1, 2, 3, 0]]) ➞ ["1+2=3", "2**0=1", "3**0=1", "3-1=2", "3-2=1"]
// Each equation must contain 3 discrete numbers from the array.
// "1+0=1" or "3-3=0" are not allowed.

Notes

    For operators with commutative properties, return only the equation with the smallest term first. "4*6=24" not "6*4=24".
    Return your answer as an array sorted lexicographically.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]string{"+"}, []int{2, 1, 3}, []string{"1+2=3"})
	test([]string{"+", "-", "*", "**"}, []int{1, 2, 3, 0}, []string{"1+2=3", "2**0=1", "3**0=1", "3-1=2", "3-2=1"})
	test([]string{"+", "*"}, []int{36, 28, 71, 4, 12, 7, 11}, []string{"4*7=28", "4+7=11"})
	test([]string{"+", "-", "*", "/"}, []int{3, 11, 23, 47, 59, 89, 41, 2}, []string{})
	test([]string{"%"}, []int{34, 67, 18, 14, 69, 1, 5, 19}, []string{"19%14=5", "19%18=1", "69%34=1"})
	test([]string{"+", "-", "*", "/"}, []int{312, 145, 13, 65, 11, 24}, []string{"11+13=24", "13*24=312", "24-11=13", "24-13=11", "312/13=24", "312/24=13"})
	test([]string{"&", "<<"}, []int{3, 168, 5, 21, 79}, []string{"21&79=5", "21<<3=168"})
	test([]string{"|", "^", "&"}, []int{2, 67, 18, 15, 99, 33}, []string{"15&18=2", "18&67=2", "18&99=2", "33|67=99"})
	test([]string{"<<", ">>"}, []int{2, 128, 6, 16, 64}, []string{"128>>6=2", "16<<2=64", "2<<6=128", "64>>2=16"})
	test([]string{"**", "|"}, []int{1, 2, 3, 4, 16}, []string{"1|2=3", "2**4=16", "4**2=16"})
}

func test(op []string, v []int, r []string) {
	p := jumbled(op, v)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func jumbled(op []string, v []int) []string {
	var r [][4]int
	m := make(map[[4]int]bool)
	for i := range op {
		for j := range v {
			for k := range v {
				if j == k {
					continue
				}

				b := iop(op[i])
				x := v[j]
				y := v[k]
				if !valid(b, x, y) {
					continue
				}

				z := binop(b, x, y)
				if find(v, z, j, k) < 0 {
					continue
				}

				p := [4]int{x, y, z, b}
				if commutative(b) {
					p[0], p[1] = min(p[0], p[1]), max(p[0], p[1])
				}
				if !m[p] {
					r, m[p] = append(r, p), true
				}
			}
		}
	}

	s := make([]string, len(r))
	for i, u := range r {
		s[i] = fmt.Sprintf("%v%s%v=%v", u[0], sop(u[3]), u[1], u[2])
	}
	sort.Strings(s)

	return s
}

func find(v []int, z, j, k int) int {
	for i := range v {
		if v[i] == z && i != j && i != k {
			return i
		}
	}
	return -1
}

func iop(op string) int {
	switch op {
	case "+", "-", "*", "/", "%", "&", "|", "^":
		return int(op[0])
	case "<<":
		return 'l'
	case ">>":
		return 'r'
	case "**":
		return 'p'
	}
	return 0
}

func sop(op int) string {
	switch op {
	case '+', '-', '*', '/', '%', '&', '|', '^':
		return fmt.Sprintf("%c", op)
	case 'l':
		return "<<"
	case 'r':
		return ">>"
	case 'p':
		return "**"
	}
	return "λ"
}

func commutative(op int) bool {
	switch op {
	case '+', '*', '&', '|', '^':
		return true
	}
	return false
}

func valid(op, x, y int) bool {
	switch op {
	case '/':
		if y == 0 || x%y != 0 {
			return false
		}
	case '%':
		if y == 0 {
			return false
		}
	case 'p':
		if y < 0 {
			return false
		}
	}
	return true
}

func binop(op int, x, y int) int {
	switch op {
	case '+':
		return x + y
	case '-':
		return x - y
	case '*':
		return x * y
	case '/':
		if y == 0 {
			return 0
		}
		return x / y
	case '%':
		if y == 0 {
			return 0
		}
		return x % y
	case '&':
		return x & y
	case '|':
		return x | y
	case '^':
		return x ^ y
	case 'l':
		return x << y
	case 'r':
		return x >> y
	case 'p':
		return ipow(x, y)
	}
	return 0
}

func ipow(x, y int) int {
	if y < 0 {
		return 0
	}

	p := 1
	for i := 0; i < y; i++ {
		p *= x
	}
	return p
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
