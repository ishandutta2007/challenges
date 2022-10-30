/*

Write a short program for 196-algorithm. The algorithm starts from an integer, then adds its reverse to it until a palindrome is reached.

e.g.

input = 5280
5280 + 0825 = 6105
6105 + 5016 = 11121
11121 + 12111 = 23232
output = 23232

Input

an integer, which is not a lychrel number (that is, it does eventually yield a palindrome under this algorithm, rather than continuing infinitely)

Output

the palindrome reached.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	for i := int64(0); i <= 100; i++ {
		fmt.Println(i, x196(big.NewInt(i)))
	}
}

// https://oeis.org/A033865
func x196(n *big.Int) *big.Int {
	x := new(big.Int)
	x.Set(n)
	for !palindrome(x) {
		y := reverse(x)
		x.Add(x, y)
	}
	return x
}

func xint(s string) *big.Int {
	x := new(big.Int)
	x.SetString(s, 10)
	return x
}

func reverse(n *big.Int) *big.Int {
	s := n.String()
	b := []byte(s)
	l := len(b)
	for i := 0; i < l/2; i++ {
		b[i], b[l-1-i] = b[l-1-i], b[i]
	}
	return xint(string(b))
}

func palindrome(n *big.Int) bool {
	s := n.String()
	l := len(s)
	for i := 0; i < l/2; i++ {
		if s[i] != s[l-1-i] {
			return false
		}
	}
	return true
}
