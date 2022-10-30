/*

This is a copy cat question of Simplify ijk string applied to the other nonabelian group of order 8. See also Dihedral group composition with custom labels.
Challenge

Given a string made of r and s interpret it as the product of elements of the dihedral group D8
and simplify it into one of the eight possible values "", "r", "rr", "rrr", "s", "rs", "rrs", and "rrrs". The empty string denotes the identity element 1.

The evaluation rules are as follows:
rrrr=1ss=1sr=rrrs

The multiplication on the dihedral group is associative but not commutative. This means that you may do the simplification in any order, but you cannot reorder the items.

For the I/O format, function parameter and return from a function should be done as a string or list. You may output any amount of leading and trailing whitespace (spaces, tabs, newlines).
You may use any other pair of distinct characters for r and s except for a tab, space, or newline. (If you really want to you can pick r or s to be whitespace, you can as long as you don't have leading or trailing whitespace.)
It's also fine to use numbers for r and s, for example if you take 0 for r and 1 for s, it would be okay to do I/O like [1, 0] ==> [0, 0, 0, 1].

Test cases

"" -> ""
"r" -> "r"
"rrr" -> "rrr"
"s" -> "s"
"rs" -> "rs"
"rrs" -> "rrs"
"rrrr" -> ""
"rrrrrr" -> "rr"
"sr" -> "rrrs"
"rsr" -> "s"
"srsr" -> ""
"srr" -> "rrs"
"srs" -> "rrr"
"rsrsr" -> "r"
"rrsss" -> "rrs"
"sssrrr" -> "rs"

Reference implementation

Here is a Javascript reference implementation.

function f(x) {
  let lastx;
  while(lastx !== x){
    lastx = x;
    x = x.replace("rrrr", "");
    x = x.replace("sr", "rrrs");
    x = x.replace("ss", "");
  }
  return x;
}

*/

package main

import "strings"

func main() {
	assert(simplify("") == "")
	assert(simplify("r") == "r")
	assert(simplify("rrr") == "rrr")
	assert(simplify("s") == "s")
	assert(simplify("rs") == "rs")
	assert(simplify("rrs") == "rrs")
	assert(simplify("rrrr") == "")
	assert(simplify("rrrrrr") == "rr")
	assert(simplify("sr") == "rrrs")
	assert(simplify("rsr") == "s")
	assert(simplify("srsr") == "")
	assert(simplify("srr") == "rrs")
	assert(simplify("srs") == "rrr")
	assert(simplify("rsrsr") == "r")
	assert(simplify("rrsss") == "rrs")
	assert(simplify("sssrrr") == "rs")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func simplify(s string) string {
	var t string
	for t != s {
		t = s
		s = strings.Replace(s, "rrrr", "", -1)
		s = strings.Replace(s, "sr", "rrrs", -1)
		s = strings.Replace(s, "ss", "", -1)
	}
	return s
}
