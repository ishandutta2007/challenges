/*

Challenge:
Write a a program to take an array of 24 4-letter strings, and output a compressed (lossless) representation of the array. You should also provide a program to decompress your representations.

Input:
The input will be comprised of 4 letter words using each of [G,T,A,C] exactly once (e.g. GTAC, ATGC, CATG, etc). There are always exactly 24 words, so the full input is something like:

GTAC CATG TACG GACT GTAC CATG TACG GACT GTAC CATG TACG GACT GTAC CATG TACG GACT GTAC CATG TACG GACT GTAC CATG TACG GACT
So there are 4!=24 possibilities for each word, and 24 words in total.

Output:
The output should be a printable ASCII string that can be decompressed back into the input string. Since this is lossless compression, each output should match to exactly one input.

Example:
>>> compress(["GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT"])
"3Ax/8TC+drkuB"
Winning Criterion
Your code should minimize the output length. The program with the shortest output wins. If it's not consistent, the longest possible output will be the score.

Edit: Based on helpful feedback comments, I would like to amend the criterion to add:

If two entries have the same results, the shortest code measured in characters wins. If an entry is length dependent, a length of 1 million words is the standard.

However, I fear the community angrily telling me I didn't say it right and downvoting me to the abyss, so I leave to community editors to see if it makes sense with code golf traditions

*/

package main

import (
	"bytes"
	"compress/zlib"
	"io"
	"reflect"
	"strings"
)

func main() {
	test([]string{"GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT", "GTAC", "CATG", "TACG", "GACT"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s []string) {
	c := compress(s)
	p := uncompress(c)
	assert(reflect.DeepEqual(s, p))
}

func compress(s []string) string {
	w := new(bytes.Buffer)
	z, _ := zlib.NewWriterLevel(w, zlib.BestCompression)
	for _, p := range s {
		z.Write([]byte(p))
	}
	z.Close()
	return w.String()
}

func uncompress(s string) []string {
	r := strings.NewReader(s)
	z, _ := zlib.NewReader(r)
	p, _ := io.ReadAll(z)

	l := []string{}
	for i := 0; i+4 <= len(p); i += 4 {
		l = append(l, string(p[i:i+4]))
	}
	return l
}
