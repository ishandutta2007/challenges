/*

Taking each four digit number of an array in turn, return the number that you are on when all of the digits 0-9 have been discovered.
If not all of the digits can be found, return "Missing digits!".

Examples

findAllDigits([5175, 4538, 2926, 5057, 6401, 4376, 2280, 6137, 8798, 9083]) ➞ 5057
// digits found:  517-  4-38  29-6  -0

findAllDigits([5719, 7218, 3989, 8161, 2676, 3847, 6896, 3370, 2363, 1381]) ➞ 3370
// digits found:  5719  -2-8  3---  --6-  ----  --4-  ----  ---0

findAllDigits([4883, 3876, 7769, 9846, 9546, 9634, 9696, 2832, 6822, 6868]) ➞ "Missing digits!"
// digits found:  48-3  --76  ---9  ----  -5--  ----  ----  2---
// 0 and 1 are missing

Notes

The digits can be discovered in any order.

*/

package main

func main() {
	test(digits([]int{5175, 4538, 2926, 5057, 6401, 4376, 2280, 6137, 8798, 9083}), 5057)
	test(digits([]int{5719, 7218, 3989, 8161, 2676, 3847, 6896, 3370, 2363, 1381}), 3370)
	test(digits([]int{4883, 3876, 7769, 9846, 9546, 9634, 9696, 2832, 6822, 6868}), "Missing digits!")
	test(digits([]int{3129, 7689, 7449, 4389, 5855, 9670, 9245, 1291, 7367, 1810}), 9670)
	test(digits([]int{2758, 3737, 3349, 5118, 7004, 6106, 8868, 6687, 2510, 8911}), 6106)
	test(digits([]int{5343, 6743, 2922, 2423, 7050, 5116, 3992, 2707, 2435, 5251}), "Missing digits!")
	test(digits([]int{4169, 4511, 1498, 6945, 7959, 2666, 7872, 3217, 5408, 8662}), 5408)
	test(digits([]int{7985, 7130, 4625, 7392, 4933, 7163, 7130, 2145, 1596, 6188}), 4625)
	test(digits([]int{4823, 1049, 9555, 9466, 2191, 9316, 1105, 4489, 8318, 7081}), 7081)
	test(digits([]int{9827, 4405, 6317, 6086, 8091, 7800, 8365, 2544, 3402, 7248}), 6317)
	test(digits([]int{2227, 7262, 9322, 8967, 4807, 8708, 3317, 6543, 9522, 7106}), 6543)
	test(digits([]int{8452, 7326, 6786, 1893, 6546, 8714, 6699, 1361, 4891, 9797}), "Missing digits!")
	test(digits([]int{2627, 1146, 3964, 6280, 9759, 6188, 8917, 9375, 4012, 4217}), 9759)
	test(digits([]int{1291, 6903, 5887, 8914, 3906, 1465, 8452, 4909, 4143, 6921}), 8914)
	test(digits([]int{7433, 8245, 9603, 1446, 8158, 8756, 5066, 4996, 5233, 2856}), 1446)
	test(digits([]int{4661, 1207, 8411, 2010, 2092, 2441, 7885, 3810, 7433, 2034}), 3810)
	test(digits([]int{9429, 6519, 3795, 7924, 3042, 3425, 1371, 7194, 7680, 9007}), 7680)
	test(digits([]int{6621, 9480, 8239, 4542, 9772, 5108, 6872, 5057, 9477, 3602}), 9772)
	test(digits([]int{9701, 3828, 7183, 2727, 5212, 6721, 5413, 2351, 4237, 8207}), 5413)
	test(digits([]int{3914, 9923, 8187, 1657, 4271, 9538, 3759, 4543, 3438, 1943}), "Missing digits!")
	test(digits([]int{6572, 3752, 9661, 7017, 8139, 2596, 3054, 2730, 1350, 2483}), 3054)
	test(digits([]int{2102, 4519, 4229, 8347, 2019, 7342, 7181, 8977, 1339, 9988}), "Missing digits!")
	test(digits([]int{4467, 2849, 5706, 7330, 9488, 2529, 8837, 2256, 3975, 7311}), 7311)
}

func test(x, y interface{}) {
	assert(x == y)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func digits(a []int) interface{} {
	var h [10]int
	c := 0
	for i, n := range a {
		if n < 0 {
			n = -n
		}
		for {
			j := n % 10
			if h[j]++; h[j] == 1 {
				if c++; c >= len(h) {
					return a[i]
				}
			}

			if n /= 10; n == 0 {
				break
			}
		}
	}
	return "Missing digits!"
}
