/*

Names scores

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

*/

package main

import (
	"encoding/csv"
	"fmt"
	"log"
	"os"
	"sort"
)

func main() {
	sum, err := process("p022_names.txt")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(sum)
}

func process(name string) (sum uint64, err error) {
	f, err := os.Open(name)
	if err != nil {
		return
	}
	defer f.Close()

	r := csv.NewReader(f)
	recs, err := r.ReadAll()
	if err != nil {
		return
	}

	var names []string
	for i := range recs {
		for j := range recs[i] {
			names = append(names, recs[i][j])
		}
	}
	sort.Strings(names)

	for i := range names {
		sum += uint64(i+1) * nsc(names[i])
	}

	return
}

func nsc(s string) uint64 {
	r := uint64(0)
	for i := range s {
		switch {
		case 'A' <= s[i] && s[i] <= 'Z':
			r += uint64(s[i]) - 'A' + 1
		case 'a' <= s[i] && s[i] <= 'z':
			r += uint64(s[i]) - 'a' + 1
		}
	}
	return r
}
