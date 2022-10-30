/*

Create a function that takes a string containing money in dollars and pounds sterling (seperated by comma+space) and returns the sum of dollar bills only, as an integer.

For the input string:

    Each amount is prefixed by the currency symbol: $ for dollars and £ for pounds.
    Thousands are represented by the suffix k.

i.e. $4k = $4,000 and £40k = £40,000
Examples

AddBill("$20, £40, £60, $50") ➞ 70
// 20 + 50 = 70

AddBill("£30, $20, £60, $150, £360") ➞ 170
// 20  + 150 = 170

AddBill("£30, $2k, £60, $200, £360") ➞ 2200
// 2 * 1000 + 200 = 2200

Notes

There is at least one dollar bill in string.

*/

package main

import (
	"strconv"
	"strings"
)

func main() {
	assert(bill("$20, £40, £60, $50") == 70)
	assert(bill("£30, $20, £60, $150, £360") == 170)
	assert(bill("£30, $2k, £60, $200, £360") == 2200)
	assert(bill("$200, £40, £60, $1k") == 1200)
	assert(bill("$10, $40, £60, $200") == 250)
	assert(bill("$10k") == 10000)
	assert(bill("£400, $200, £40, £60") == 200)
	assert(bill("$20k, $100, £40") == 20100)
	assert(bill("$100") == 100)
	assert(bill("$100k") == 100000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bill(s string) int {
	v := 0
	t := strings.Split(s, ",")
	for _, p := range t {
		p = strings.TrimSpace(p)
		if !strings.HasPrefix(p, "$") {
			continue
		}
		p = p[1:]

		m := 1
		if strings.HasSuffix(p, "k") {
			m = 1000
			p = p[:len(p)-1]
		}

		n, _ := strconv.Atoi(p[:])
		v += n * m
	}
	return v
}
