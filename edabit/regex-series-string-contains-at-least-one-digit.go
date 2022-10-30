/*

Write a regular expression that matches a string if it contains at least one digit.

Examples

hasDigit("c8") ➞ true

hasDigit("23cc4") ➞ true

hasDigit("abwekz") ➞ false

hasDigit("sdfkxi") ➞ false

Notes

This challenge is designed to use RegEx only.

*/

package main

import "regexp"

func main() {
	assert(hasdigit("c8") == true)
	assert(hasdigit("23cc4") == true)
	assert(hasdigit("abwekz") == false)
	assert(hasdigit("sdfkxi") == false)
	assert(hasdigit("rxizw") == false)
	assert(hasdigit("jren3biy") == true)
	assert(hasdigit("mxkbj3bg") == true)
	assert(hasdigit("qageha") == false)
	assert(hasdigit("qian5rtjzwgkjk") == true)
	assert(hasdigit("kyehbjosrx") == false)
	assert(hasdigit("cvlcg2ggggzowzas") == true)
	assert(hasdigit("jjbbvb7kjmypz") == true)
	assert(hasdigit("rfjgzn50djg") == true)
	assert(hasdigit("mvepzvqgumaihtoudh") == false)
	assert(hasdigit("kauhkwmd") == false)
	assert(hasdigit("s8fonjkblhu") == true)
	assert(hasdigit("krkccxwmmx3lcjbe") == true)
	assert(hasdigit("dirg") == false)
	assert(hasdigit("ntqdkskd6srln") == true)
	assert(hasdigit("tkabcvzfabqz") == false)
	assert(hasdigit("umqihuaikhzcaprtmrkf") == false)
	assert(hasdigit("nvvwhxt") == false)
	assert(hasdigit("r2clrks") == true)
	assert(hasdigit("mlzuwfusierivfrbq") == false)
	assert(hasdigit("mvggduqcr") == false)
	assert(hasdigit("sbxfntq4ekwf") == true)
	assert(hasdigit("ulylvolxuf5vofllvdjg") == true)
	assert(hasdigit("usa3ouizefs") == true)
	assert(hasdigit("hqmszb7somqcdnox") == true)
	assert(hasdigit("ftnnqspmdifi") == false)
	assert(hasdigit("fbgryiyzjirysz") == false)
	assert(hasdigit("rhwikmwfzis") == false)
	assert(hasdigit("ru4rlpyv") == true)
	assert(hasdigit("kokzjam32zl7bnucb") == true)
	assert(hasdigit("zpy6kasuouaq") == true)
	assert(hasdigit("nctja8xktcipevfo") == true)
	assert(hasdigit("anevx6cgqa") == true)
	assert(hasdigit("fzxbb") == false)
	assert(hasdigit("hryvztjuvjspcfjtezh") == false)
	assert(hasdigit("qvwbeepylwsqnipb") == false)
	assert(hasdigit("dsrgbgeqopjvqgjto") == false)
	assert(hasdigit("o6fwynnypu") == true)
	assert(hasdigit("oordrxk3j1lbo") == true)
	assert(hasdigit("kgbfxnmjbh") == false)
	assert(hasdigit("fklgfkiafmvxifqz") == false)
	assert(hasdigit("xct") == false)
	assert(hasdigit("kqf6tneg") == true)
	assert(hasdigit("xu0w") == true)
	assert(hasdigit("erqcrooj9tu") == true)
	assert(hasdigit("niouwjzphmyllvmwf") == false)
	assert(hasdigit("lmnuovrhlg") == false)
	assert(hasdigit("xlnjr33gtj4gcmuw") == true)
	assert(hasdigit("meijxmi0mfvsvajsqn") == true)
	assert(hasdigit("gnd7rksfnx0vxz") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hasdigit(s string) bool {
	m, _ := regexp.MatchString("[0-9]+", s)
	return m
}
