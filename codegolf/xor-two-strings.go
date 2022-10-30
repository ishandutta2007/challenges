/*

Given two strings as input, return the result of XORing the code-points of one string against the code points of the other.

For each character in the first input string, take the code-point (e.g. for A, this is 65) and XOR the value against the corresponding index in the second string and output the character at the code-point of the result.
If one string is longer than the other, you must return the portion of the string beyond the length of the shorter, as-is. (Alternatively, you may pad the shorter string with NUL bytes, which is equivalent.)

See the following JavaScript code for an example:

const xorStrings = (a, b) => {
  let s = '';

  // use the longer of the two words to calculate the length of the result
  for (let i = 0; i < Math.max(a.length, b.length); i++) {
    // append the result of the char from the code-point that results from
    // XORing the char codes (or 0 if one string is too short)
    s += String.fromCharCode(
      (a.charCodeAt(i) || 0) ^ (b.charCodeAt(i) || 0)
    );
  }

  return s;
};

Try it online!
Test cases

Input                         Output

['Hello,', 'World!']          '\x1f\x0a\x1e\x00\x0b\x0d'
['Hello', 'wORLD']            '?*> +'
['abcde', '01234']            'QSQWQ'
['lowercase', "9?'      "]    'UPPERCASE'
['test', '']                  'test'
['12345', '98765']            '\x08\x0a\x04\x02\x00' _not_ 111092
['test', 'test']              '\x00\x00\x00\x00'
['123', 'ABCDE']              'pppDE'
['01', 'qsCDE']               'ABCDE'
['`c345', 'QQ']               '12345'

Rules

    The two input strings will only ever be code-points 0-255.
    This is code-golf so the shortest solution, in each language, wins.

*/

package main

import (
	"bytes"
)

func main() {
	assert(xorstr("Hello,", "World!") == "\x1f\x0a\x1e\x00\x0b\x0d")
	assert(xorstr("Hello", "wORLD") == "?*> +")
	assert(xorstr("abcde", "01234") == "QSQWQ")
	assert(xorstr("lowercase", "9?'      ") == "UPPERCASE")
	assert(xorstr("test", "") == "test")
	assert(xorstr("12345", "98765") == "\x08\x0a\x04\x02\x00")
	assert(xorstr("test", "test") == "\x00\x00\x00\x00")
	assert(xorstr("123", "ABCDE") == "pppDE")
	assert(xorstr("01", "qsCDE") == "ABCDE")
	assert(xorstr("`c345", "QQ") == "12345")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func xorstr(a, b string) string {
	w := new(bytes.Buffer)
	n := len(a)
	m := len(b)
	l := max(n, m)
	for i := 0; i < l; i++ {
		x, y := byte(0), byte(0)
		if i < n {
			x = a[i]
		}
		if i < m {
			y = b[i]
		}
		w.WriteByte(x ^ y)
	}
	return w.String()
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
