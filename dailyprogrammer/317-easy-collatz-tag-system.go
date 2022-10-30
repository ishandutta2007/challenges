/*

Description

Implement the Collatz Conjecture tag system described here
Input Description

A string of n a's
Output Description

Print the string at each step. The last line should be "a" (assuming the Collatz conjecture)
Challenge Input

aaa
aaaaa

Challenge Output

aaa

abc
cbc
caaa
aaaaa
aaabc
abcbc
cbcbc
cbcaaa
caaaaaa
aaaaaaaa
aaaaaabc
aaaabcbc
aabcbcbc
bcbcbcbc
bcbcbca
bcbcaa
bcaaa
aaaa
aabc
bcbc
bca
aa
bc
a

aaaaaaa

aaaaabc
aaabcbc
abcbcbc
cbcbcbc
cbcbcaaa
cbcaaaaaa
caaaaaaaaa
aaaaaaaaaaa
aaaaaaaaabc
aaaaaaabcbc
aaaaabcbcbc
aaabcbcbcbc
abcbcbcbcbc
cbcbcbcbcbc
cbcbcbcbcaaa
cbcbcbcaaaaaa
cbcbcaaaaaaaaa
cbcaaaaaaaaaaaa
caaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaabc
aaaaaaaaaaaaabcbc
aaaaaaaaaaabcbcbc
aaaaaaaaabcbcbcbc
aaaaaaabcbcbcbcbc
aaaaabcbcbcbcbcbc
aaabcbcbcbcbcbcbc
abcbcbcbcbcbcbcbc
cbcbcbcbcbcbcbcbc
cbcbcbcbcbcbcbcaaa
cbcbcbcbcbcbcaaaaaa
cbcbcbcbcbcaaaaaaaaa
cbcbcbcbcaaaaaaaaaaaa
cbcbcbcaaaaaaaaaaaaaaa
cbcbcaaaaaaaaaaaaaaaaaa
cbcaaaaaaaaaaaaaaaaaaaaa
caaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaabc
aaaaaaaaaaaaaaaaaaaaaabcbc
aaaaaaaaaaaaaaaaaaaabcbcbc
aaaaaaaaaaaaaaaaaabcbcbcbc
aaaaaaaaaaaaaaaabcbcbcbcbc
aaaaaaaaaaaaaabcbcbcbcbcbc
aaaaaaaaaaaabcbcbcbcbcbcbc
aaaaaaaaaabcbcbcbcbcbcbcbc
aaaaaaaabcbcbcbcbcbcbcbcbc
aaaaaabcbcbcbcbcbcbcbcbcbc
aaaabcbcbcbcbcbcbcbcbcbcbc
aabcbcbcbcbcbcbcbcbcbcbcbc
bcbcbcbcbcbcbcbcbcbcbcbcbc
bcbcbcbcbcbcbcbcbcbcbcbca
bcbcbcbcbcbcbcbcbcbcbcaa
bcbcbcbcbcbcbcbcbcbcaaa
bcbcbcbcbcbcbcbcbcaaaa
bcbcbcbcbcbcbcbcaaaaa
bcbcbcbcbcbcbcaaaaaa
bcbcbcbcbcbcaaaaaaa
bcbcbcbcbcaaaaaaaa
bcbcbcbcaaaaaaaaa
bcbcbcaaaaaaaaaa
bcbcaaaaaaaaaaa
bcaaaaaaaaaaaa
aaaaaaaaaaaaa
aaaaaaaaaaabc
aaaaaaaaabcbc
aaaaaaabcbcbc
aaaaabcbcbcbc
aaabcbcbcbcbc
abcbcbcbcbcbc
cbcbcbcbcbcbc
cbcbcbcbcbcaaa
cbcbcbcbcaaaaaa
cbcbcbcaaaaaaaaa
cbcbcaaaaaaaaaaaa
cbcaaaaaaaaaaaaaaa
caaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaabc
aaaaaaaaaaaaaaaabcbc
aaaaaaaaaaaaaabcbcbc
aaaaaaaaaaaabcbcbcbc
aaaaaaaaaabcbcbcbcbc
aaaaaaaabcbcbcbcbcbc
aaaaaabcbcbcbcbcbcbc
aaaabcbcbcbcbcbcbcbc
aabcbcbcbcbcbcbcbcbc
bcbcbcbcbcbcbcbcbcbc
bcbcbcbcbcbcbcbcbca
bcbcbcbcbcbcbcbcaa
bcbcbcbcbcbcbcaaa
bcbcbcbcbcbcaaaa
bcbcbcbcbcaaaaa
bcbcbcbcaaaaaa
bcbcbcaaaaaaa
bcbcaaaaaaaa
bcaaaaaaaaa
aaaaaaaaaa
aaaaaaaabc
aaaaaabcbc
aaaabcbcbc
aabcbcbcbc
bcbcbcbcbc
bcbcbcbca
bcbcbcaa
bcbcaaa
bcaaaa
aaaaa
aaabc
abcbc
cbcbc
cbcaaa
caaaaaa
aaaaaaaa
aaaaaabc
aaaabcbc
aabcbcbc
bcbcbcbc
bcbcbca
bcbcaa
bcaaa
aaaa
aabc
bcbc
bca
aa
bc
a

Notes/Hints

The Collatz Conjecture

If you're not familiar with tag systems, you can read the Wikipedia article on them here
Bonus

Implement the same tag system as a cyclic tag system using the schema described here
Bonus Input

100100100

Bonus Output

00100100010001
0100100010001
100100010001
00100010001
0100010001
100010001
00010001010001
0010001010001
010001010001
10001010001
0001010001
001010001
01010001
1010001
010001100100100
10001100100100
0001100100100
001100100100
01100100100
1100100100
100100100100100100
00100100100100100
0100100100100100
100100100100100
00100100100100010001
0100100100100010001
100100100100010001
00100100100010001
0100100100010001
100100100010001
00100100010001010001
0100100010001010001
100100010001010001
00100010001010001
0100010001010001
100010001010001
00010001010001010001
0010001010001010001
010001010001010001
10001010001010001
0001010001010001
001010001010001
01010001010001
1010001010001
010001010001100100100
10001010001100100100
0001010001100100100
001010001100100100
01010001100100100
1010001100100100
010001100100100100100100
10001100100100100100100
0001100100100100100100
001100100100100100100
01100100100100100100
1100100100100100100
100100100100100100100100100
00100100100100100100100100
0100100100100100100100100
100100100100100100100100
00100100100100100100100010001
0100100100100100100100010001
100100100100100100100010001
00100100100100100100010001
0100100100100100100010001
100100100100100100010001
00100100100100100010001010001
0100100100100100010001010001
100100100100100010001010001
00100100100100010001010001
0100100100100010001010001
100100100100010001010001
00100100100010001010001010001
0100100100010001010001010001
100100100010001010001010001
00100100010001010001010001
0100100010001010001010001
100100010001010001010001
00100010001010001010001010001
0100010001010001010001010001
100010001010001010001010001
00010001010001010001010001
0010001010001010001010001
010001010001010001010001
10001010001010001010001
0001010001010001010001100
001010001010001010001100
01010001010001010001100
1010001010001010001100
010001010001010001100
10001010001010001100
0001010001010001100100
001010001010001100100
01010001010001100100
1010001010001100100
010001010001100100
10001010001100100
0001010001100100100
001010001100100100
01010001100100100
1010001100100100
010001100100100
10001100100100
0001100100100100
001100100100100
01100100100100
1100100100100
100100100100
00100100100010001
0100100100010001
100100100010001
00100100010001
0100100010001
100100010001
00100010001010001
0100010001010001
100010001010001
00010001010001
0010001010001
010001010001
10001010001
0001010001100
001010001100
01010001100
1010001100
010001100
10001100
0001100100
001100100
01100100
1100100
100100
00100010001
0100010001
100010001
00010001
0010001
010001
10001
0001100
001100
01100
1100
100

Credit

This challenge was proposed by /u/thebutterflydefect, many thanks. If you have a challenge idea, please share it in r/dailyprogrammer_ideas and there's a good chance we'll use it.

*/

package main

import "fmt"

func main() {
	collatz := map[byte]string{
		'a': "bc",
		'b': "a",
		'c': "aaa",
	}

	tag("aaa", 2, collatz)
	tag("aaaaaaa", 2, collatz)
}

func tag(str string, step int, rules map[byte]string) {
	for {
		fmt.Println(str)
		if len(str) < step {
			break
		}
		str = str[step:] + rules[str[0]]
	}
	fmt.Println()
}
