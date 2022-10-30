/*

The van der Corput sequence is one of the simplest example of low-discrepancy sequence. Its n-th term is just 0.(n written in base 10 and mirrored), so its first terms are :

0.1, 0.2,0.3,0.4, 0.5,0.6,0.7, 0.8,0.9, 0.01, 0.11,0.21,0.31, 0.41,0.51,0.61, 0.71,0.81,0.91, 0.02, 0.12,0.22,0.32, 0.42,0.52,0.62, 0.72,0.82,0.92, ...
The challenge

Write a program or a function in any programming language that takes as input a positive integer n less than 10^6 and returns or print the first n terms of the van der Corput sequence.
The output format can be a list of floating point numbers, a list of strings of the form 0.digits, or a unique string where the terms are separated by commas and/or whitespaces, newlines.

Standard loopholes are forbidden. The shortest source code wins.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	for i := uint(1); i <= 100; i++ {
		fmt.Println(corput(i))
	}
}

func corput(n uint) string {
	s := fmt.Sprint(n)
	return fmt.Sprintf("0.%s", rev(s))
}

func rev(s string) string {
	w := new(bytes.Buffer)
	for i := len(s) - 1; i >= 0; i-- {
		w.WriteByte(s[i])
	}
	return w.String()
}
