/*

Given a number, return the difference between the maximum and minimum numbers that can be formed when the digits are rearranged.

Examples

rearrangedDifference(972882) ➞ 760833
// 988722 - 227889 = 760833

rearrangedDifference(3320707) ➞ 7709823
// 7733200 - 23377 = 7709823

rearrangedDifference(90010) ➞ 90981
// 91000 - 19 = 90981

Notes

N/A

*/

package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	assert(reardiff(9092564) == 9719721)
	assert(reardiff(1308821) == 8719722)
	assert(reardiff(8386568) == 5319765)
	assert(reardiff(7794084) == 9429651)
	assert(reardiff(6366093) == 9329661)
	assert(reardiff(7863060) == 8729622)
	assert(reardiff(3368327) == 6429654)
	assert(reardiff(7218787) == 7599933)
	assert(reardiff(7723188) == 7639533)
	assert(reardiff(8816317) == 7739523)
	assert(reardiff(8824349) == 7539543)
	assert(reardiff(3320707) == 7709823)
	assert(reardiff(1695488) == 8429652)
	assert(reardiff(2120034) == 4309866)
	assert(reardiff(5300586) == 8619732)
	assert(reardiff(3538814) == 7519743)
	assert(reardiff(1336939) == 8629632)
	assert(reardiff(6290200) == 9619731)
	assert(reardiff(5268866) == 6299964)
	assert(reardiff(5155458) == 7099983)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reardiff(n uint) uint {
	s := []byte(fmt.Sprintf("%d", n))
	t := []byte(fmt.Sprintf("%d", n))

	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	sort.Slice(t, func(i, j int) bool { return t[i] > t[j] })

	x, _ := strconv.ParseUint(string(s), 10, 64)
	y, _ := strconv.ParseUint(string(t), 10, 64)

	return uint(y - x)
}
