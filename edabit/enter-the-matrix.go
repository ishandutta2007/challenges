/*

In this challenge, you have to obtain a sentence from the elements of a given matrix.
In the matrix, each word of the sentence follows a columnar order from the top to the bottom, instead of the usual left-to-right order: it's time for transposition!

Given a matrix mtx, implement a function that returns the complete sentence as a string, with the words separated by a space between them.

Examples

transposeMatrix([
  ["Enter"],
  ["the"],
  ["Matrix!"]
]) ➞ "Enter the Matrix!"

transposeMatrix([
  ["The", "are"],
  ["columns", "rows."]
]) ➞ "The columns are rows."

transposeMatrix([
  ["You", "the"],
  ["must", "table"],
  ["transpose", "order."]
]) ➞ "You must transpose the table order."

Notes

    All given matrices are regular, as to say that each column has the same length.
    Punctuation is already given, you just have to add the spaces in the returned string.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(matrix([][]string{
		{"The", "are"},
		{"columns", "rows."},
	}) == "The columns are rows.")
	assert(matrix([][]string{
		{"You", "the"},
		{"must", "table"},
		{"transpose", "order."},
	}) == "You must transpose the table order.")
	assert(matrix([][]string{{"Enter"}, {"the"}, {"Matrix."}}) == "Enter the Matrix.")
	assert(matrix([][]string{
		{"Unfortunately,", "be", "is.", "see"},
		{"no", "told", "You'll", "it"},
		{"one", "what", "have", "for"},
		{"can", "Matrix", "to", "yourself."},
	}) == "Unfortunately, no one can be told what Matrix is. You'll have to see it for yourself.")
	assert(matrix([][]string{
		{"Matrix", "that"},
		{"is", "system"},
		{"a", "is"},
		{"system", "our"},
		{"Neo,", "enemy."},
	}) == "Matrix is a system Neo, that system is our enemy.")
	assert(matrix([][]string{
		{"If", "killed", "you"},
		{"you", "in", "die"},
		{"are", "Matrix", "here?"},
	}) == "If you are killed in Matrix you die here?")
	assert(matrix([][]string{
		{"As", "human"},
		{"long", "race"},
		{"as", "will"},
		{"Matrix", "never"},
		{"exists,", "be"},
		{"the", "free."},
	}) == "As long as Matrix exists, the human race will never be free.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func matrix(m [][]string) string {
	if len(m) == 0 || len(m[0]) == 0 {
		return ""
	}

	w := new(bytes.Buffer)
	for i := range m[0] {
		for j := range m {
			fmt.Fprintf(w, "%s ", m[j][i])
		}
	}
	p := w.String()
	p = p[:len(p)-1]
	return p
}
