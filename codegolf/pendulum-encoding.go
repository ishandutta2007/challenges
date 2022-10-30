/*

Given a string as an input (which can be any acceptable/convenient format in your language), implement pendulum encoding.
The test cases are split into individual items (which aren't quoted) for a visually appealing explanation.

How do I do that?

The current iteration index starts at 0.

    If the iteration index is even, append the current item onto the output string.
    If the iteration index is odd, prepend the current item onto the output string.

An example

The input is [a b c d e f g].
Note that the letters a-g are individual one-character strings, to prevent confusion from the iteration index.
N: the iteration index

N:0 Out:      [a]
N:1 Out:    [b a]
N:2 Out:    [b a c]
N:3 Out:  [d b a c]
N:4 Out:  [d b a c e]
N:5 Out:[f d b a c e]
N:6 Out:[f d b a c e g]

The output should be [f d b a c e g].
Another example

The input is [u d l n u e m p].

N:0 Out:        [u]
N:1 Out:      [d u]
N:2 Out:      [d u l]
N:3 Out:    [n d u l]
N:4 Out:    [n d u l u]
N:5 Out:  [e n d u l u]
N:6 Out:  [e n d u l u m]
N:7 Out:[p e n d u l u m]

Test cases

Here's a sample program doing this encoding.

Take note that the characters in the string aren't always unique.

Your output *has* to be flattened.

[a,b,c,d,e,f,g]   -> [f,d,b,a,c,e,g]
[]                -> []
[a]               -> [a]
[a,b,c,d]         -> [d,b,a,c]
[a,b]             -> [b,a]
[a,b,d]           -> [b,a,d]
[a,b,a,c,b,c]     -> [c,c,b,a,a,b]
[a,a,b,b,c,c]     -> [c,b,a,a,b,c]
[u,d,l,n,u,e,m,p] -> [p,e,n,d,u,l,u,m]

*/

package main

func main() {
	assert(pendulum("abcdefg") == "fdbaceg")
	assert(pendulum("") == "")
	assert(pendulum("abcd") == "dbac")
	assert(pendulum("ab") == "ba")
	assert(pendulum("abd") == "bad")
	assert(pendulum("abacbc") == "ccbaab")
	assert(pendulum("aabbcc") == "cbaabc")
	assert(pendulum("udlnuemp") == "pendulum")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pendulum(s string) string {
	var (
		p string
		i int
	)
	for _, r := range s {
		if i&1 == 0 {
			p = p + string(r)
		} else {
			p = string(r) + p
		}
		i++
	}
	return p
}
