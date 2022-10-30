/*

Alienese refers to two "languages" in the show Futurama. In actuality, they are two ciphers of English text with a pictographic alphabet.
The first is a simple substitution cipher, but the second is slightly more complex. The second is a type of autokey cipher that follows these steps:

Take a word to be encrypted, e.g. FUTURAMA
Replace each letter with its 0-index in the alphabet: [5, 20, 19, 20, 17, 0, 12, 0]
Note that, due to the next step, zero indexing is important and 1 indexing cannot be used
Take the cumulative sums of the array: [5, 25, 44, 64, 81, 81, 93, 93]
Modulo each term by 26 to bring it within bounds: [5, 25, 18, 12, 3, 3, 15, 15]
Index into the alphabet: FZSMDDPP
We can iterate this process until we reach our original word again. For example, for FUTURAMA, the full list, space separated, is

FUTURAMA FZSMDDPP FEWILODS FJFNYMPH FOTGEQFM FTMSWMRD FYKCYKBE FDNPNXYC FIVKXUSU FNISPJBV FSASHQRM FXXPWMDP FCZOKWZO FHGUEAZN FMSMQQPC FRJVLBQS FWFALMCU FBGGRDFZ FGMSJMRQ FLXPYKBR FQNCAKLC FVIKKUFH FAISCWBI FFNFHDEM FKXCJMQC FPMOXJZB FUGURAZA FZFZQQPP FEJIYODS FJSAYMPH FOGGEQFM FTZFJZEQ FYXCLKOE FDACNXLP FIIKXUFU FNVFCWBV FSNSUQRM FXKCWMDP FCMOKWZO FHTHRNMA FMFMDQCC FRWILBDF FWSALMPU FBTTEQFZ FGZSWMRQ FLKCYKBR FQACAKLC FVVXXHSU FAVSPWOI FFASHDRZ FKKCJMDC FPZBKWZB FUTUEAZA FZSMQQPP FEWIYODS FJFNLZCU FOTGRQSM FTMSJZRD FYKCLKBE FDNPAKLP FIVKKUFU FNISCWBV FSASUQRM FXXPJZQC FCZOXWMO FHGURNZN FMSMDQPC FRJVYODF FWFAYMPU FBGGEQFZ FGMSWMRQ FLXPLXOE FQNCNKYC FVIKXHFH FAISPWBI FFNFUQRZ FKXCWMDC FPMOKWZB FUGUEAZA FZFZDDCC FEJILOQS FJSALZPH FOGGRQFM FTZFWMRD FYXCYKBE FDACAKLP FIIKKUFU FNVFPJOI FSNSHQEM FXKCJZDP FCMOXWZO FHTHEAZN FMFMQQPC FRWIYODF FWSAYMPU FBTTRDSM FGZSJMEQ FLKCLXBR FQACNKLC FVVXKUFH FAVSCWBI FFASUQRZ FKKCWMDC FPZBXJMO
and takes 104 steps to return to FUTURAMA. I conjecture that, for any non-empty string of letters, this process always returns to the original string in a finite number of steps.

You are to "prove" this conjecture. That is, write a program that takes a non-empty string of letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ, or abcdefghijklmnopqrstuvwxyz, you may choose), and outputs the number of steps to return to the original input, by iterating this autokey cipher. Note that, by listing the terms, the list should either start or end with the input, which counts as either the first or last step.

You may take input in any convenient format, including taking the input as an array of characters. You may only take the input as an array of code points if you are unable to input as characters or as a string (e.g. brainfuck).

This is code-golf, so the shortest code in bytes wins.

Test cases
J -> 1
NK -> 2
TQR -> 52
NAK -> 4
AAAQ -> 1
CGCC -> 13
CAIRD -> 26
NNNNX -> 8
FUTURAMA -> 104
ALIENESE -> 104
NANNANNAN -> 16
ZBDMBCWJQJPWF -> 208
MUJJEKIBPULKWRHW -> 2704
HWGYIBRBRBLADVYTXL -> 5408

Interestingly, it appears as almost all words result in a number of steps either equal to 1 (a fixed point) or divisible by 13.
We say a word is "interestingly-aliense" if this isn't the case, i.e. it is neither a fixed point, nor has a cycle length divisible by 13.
We can see, by brute forcing all combinations of words with 2 or 3 letters, that the full list of these words is

NA NB NC ND NE NF NG NH NI NJ NK NL NM NN NO NP NQ NR NS NT NU NV NW NX NY NZ ANA ANB ANC AND ANE ANF ANG ANH ANI ANJ ANK ANL ANM ANN ANO ANP ANQ ANR ANS ANT ANU ANV ANW ANX ANY ANZ NAA NAB NAC NAD NAE NAF NAG NAH NAI NAJ NAK NAL NAM NAN NAO NAP NAQ NAR NAS NAT NAU NAV NAW NAX NAY NAZ NNA NNB NNC NND NNE NNF NNG NNH NNI NNJ NNK NNL NNM NNN NNO NNP NNQ NNR NNS NNT NNU NNV NNW NNX NNY NNZ
All of which either result in 2 or 4. We can also see that all of these contain the letter N. Indeed, we can try out some guesses for longer "interestingly-alienese" words based on this. For example, NNNNX has a cycle of 8 (NNNNX, NANAX, NNAAX, NAAAX, NNNNK, NANAK, NNAAK, NAAAK), and NANNANNAN has a cycle of 16, as shown above. Can you find any more, potentially with longer cycles?

*/

package main

import (
	"bytes"
	"math"
)

func main() {
	assert(cycles("J") == 1)
	assert(cycles("NK") == 2)
	assert(cycles("TQR") == 52)
	assert(cycles("NAK") == 4)
	assert(cycles("AAAQ") == 1)
	assert(cycles("CGCC") == 13)
	assert(cycles("CAIRD") == 26)
	assert(cycles("NNNNX") == 8)
	assert(cycles("FUTURAMA") == 104)
	assert(cycles("ALIENESE") == 104)
	assert(cycles("NANNANNAN") == 16)
	assert(cycles("ZBDMBCWJQJPWF") == 208)
	assert(cycles("MUJJEKIBPULKWRHW") == 2704)
	assert(cycles("HWGYIBRBRBLADVYTXL") == 5408)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cycles(s string) int {
	t := alienese(s)
	for c := 1; c < math.MaxInt; c++ {
		if s == t {
			return c
		}
		t = alienese(t)
	}
	return -1
}

func alienese(s string) string {
	n := len(s)
	v := make([]int, n)
	for i := 0; i < n; i++ {
		switch v[i] = int(s[i]); {
		case 'a' <= s[i] && s[i] <= 'z':
			v[i] -= 'a'
		case 'A' <= s[i] && s[i] <= 'Z':
			v[i] -= 'A'
		}
	}

	for i := 1; i < n; i++ {
		v[i] += v[i-1]
	}

	for i := 0; i < n; i++ {
		v[i] %= 26
	}

	w := new(bytes.Buffer)
	for i := 0; i < n; i++ {
		w.WriteByte(byte(v[i]) + 'A')
	}

	return w.String()
}
