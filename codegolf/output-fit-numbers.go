/*

"Fit Numbers"
Sam has a "brilliant" idea for compression! Can you help?

Here is a rundown of Sam's compression scheme. First take in a base 10 representation of any natural number strictly smaller than 2^16, and write it as a binary string without any leading zeros.
1 -> 1
9 -> 1001
15 ->1111
13 ->1101
16 -> 10000
17 -> 10001
65535 -> 111111111111111
Now replace any group of one or more zeros with a single zero. This is because the number has gotten leaner. Your binary string now will look like this.

1 -> 1 -> 1
9 -> 1001 -> 101
15 ->1111 -> 1111
13 ->1101 -> 1101
16 -> 10000 -> 10
17 -> 10001 -> 101
65535 -> 111111111111111 -> 111111111111111

Now you convert the binary string back to a base 10 representation, and output it in any acceptable format. Here are your test cases.
The first integer represents an input, and the last integer represents an output. Note that some numbers do not change, and thus can be called "fit"

1 -> 1 -> 1 -> 1
9 -> 1001 -> 101 -> 5
15 ->1111 -> 1111 -> 15
13 ->1101 -> 1101 -> 13
16 -> 10000 -> 10 -> 2
17 -> 10001 -> 101 -> 5
65535 -> 1111111111111111 -> 1111111111111111 -> 65535
65000 -> 1111110111101000 -> 11111101111010 -> 16250

You may use any language, but please note that Sam hates standard loopholes. This is code golf so the code can be as short as possible to make room for the "compressed" numbers".
Note:This is NOT an acceptable compression scheme. Using this will promptly get you fired.
Citation-Needed: I do not take credit for this concept. This comes from @Conor O' Brien's blog here see this OEIS of fit numbers. https://oeis.org/A090078

*/

package main

func main() {
	assert(fit(0) == 0)
	assert(fit(1) == 1)
	assert(fit(9) == 5)
	assert(fit(15) == 15)
	assert(fit(13) == 13)
	assert(fit(16) == 2)
	assert(fit(17) == 5)
	assert(fit(65535) == 65535)
	assert(fit(65000) == 16250)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fit(x uint16) uint16 {
	v := uint16(0)
	for s := 0; x != 0; s++ {
		if x&1 != 0 {
			v |= 1 << s
			x >>= 1
		} else {
			for x != 0 && x&1 == 0 {
				x >>= 1
			}
		}
	}
	return v
}
