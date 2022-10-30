/*

Given a string of digits, return the longest substring with alternating odd/even or even/odd digits.
If two or more substrings have the same length, return the substring that occurs first.

Examples

LongestSubstring("225424272163254474441338664823") ➞ "272163254"
// substrings = 254, 272163254, 474, 41, 38, 23

LongestSubstring("594127169973391692147228678476") ➞ "16921472"
// substrings = 94127, 169, 16921472, 678, 476

LongestSubstring("721449827599186159274227324466") ➞ "7214"
// substrings = 7214, 498, 27, 18, 61, 9274, 27, 32
// 7214 and 9274 have same length, but 7214 occurs first.

Notes

The minimum alternating substring size is 2.

*/

package main

func main() {
	assert(lst("225424272163254474441338664823") == "272163254")
	assert(lst("594127169973391692147228678476") == "16921472")
	assert(lst("721449827599186159274227324466") == "7214")
	assert(lst("844929328912985315632725682153") == "56327256")
	assert(lst("769697538272129475593767931733") == "27212947")
	assert(lst("937948289456111258444958189244") == "894561")
	assert(lst("736237766362158694825822899262") == "636")
	assert(lst("369715978955362655737322836233") == "369")
	assert(lst("345724969853525333273796592356") == "496985")
	assert(lst("548915548581127334254139969136") == "8581")
	assert(lst("417922164857852157775176959188") == "78521")
	assert(lst("251346385699223913113161144327") == "638569")
	assert(lst("483563951878576456268539849244") == "18785")
	assert(lst("853667717122615664748443484823") == "474")
	assert(lst("398785511683322662883368457392") == "98785")
	assert(lst("368293545763611759335443678239") == "76361")
	assert(lst("775195358448494712934755311372") == "4947")
	assert(lst("646113733929969155976523363762") == "76523")
	assert(lst("575337321726324966478369152265") == "478369")
	assert(lst("754388489999793138912431545258") == "545258")
	assert(lst("198644286258141856918653955964") == "2581418569")
	assert(lst("643349187319779695864213682274") == "349")
	assert(lst("919331281193713636178478295857") == "36361")
	assert(lst("") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lst(s string) string {
	r := ""
	for i := 0; i < len(s); {
		for i < len(s) && !isdigit(s[i]) {
			i++
		}

		j, k := i, i
		for p := -1; i < len(s) && isdigit(s[i]); i++ {
			if q := parity(s[i]); p < 0 || p != q {
				p, k = q, i+1
			} else {
				break
			}
		}

		if k-j > len(r) {
			r = s[j:k]
		}
	}
	return r
}

func isdigit(c byte) bool {
	return '0' <= c && c <= '9'
}

func parity(c byte) int {
	return int((c - '0') & 1)
}
