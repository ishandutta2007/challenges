/*

In The Netherlands we have PostNL, the postal company. They use KixCodes, it's a fast way to deliver letters and packages that can be scanned during the process.

Kix Code

https://www.postnl.nl/Images/KIX-code-van-PostNL_tcm10-8633.gif

The code is a combination of: Postal code, House/box/call number and House appendage / suffix


If there is a character between the house number and the suffix, we need to replace that with an X. Eventually, the code will be printed in the KixCode font.
Examples

kixCode(`PostNL, Postbus 30250, 2500 GG ’s Gravenhage`) ➞ `2500GG30250`

kixCode(`Liesanne B Wilkens, Kogge 11-1, 1657 KA Abbekerk`) ➞ `1657KA11X1`

kixCode(`Dijk, Antwoordnummer 80430, 2130 VA Hoofddorp`) ➞ `2130VA80430`

Notes

    Your function will get an address line (string) separated by comma's.
    The input format will always be the same.
    Watch out for the different suffixes!

*/

package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	assert(kixcode("PostNL, Postbus 30250, 2500 GG 's Gravenhage") == "2500GG30250")
	assert(kixcode("De Jong, Havendijk 13 hs, 1231 FZ POSTDAM") == "1231FZ13XHS")
	assert(kixcode("B. Bartelds, Boerheem 46, 9421 MC Bovensmilde") == "9421MC46")
	assert(kixcode("Huisman, Koninginneweg 182 B, 3331 CH Zwijndrecht") == "3331CH182XB")
	assert(kixcode("Liesanne B Wilkens, Kogge 11-1, 1657 KA Abbekerk") == "1657KA11X1")
	assert(kixcode("Dijk, Antwoordnummer 80430, 2130 VA Hoofddorp") == "2130VA80430")
	assert(kixcode("Van Eert, Dirk van Heinsbergstraat 200-A, 5575 BM Luyksgestel") == "5575BM200XA")
	assert(kixcode("B.C. Dieker, Korhoenlaan 130b, 3847 LN Harderwijk") == "3847LN130B")
	assert(kixcode("Mahir F Schipperen, IJsselmeerlaan 31, 8304 DE Emmeloord") == "8304DE31")
	assert(kixcode("Jet de Wit, Wielingenstraat 129/7, 3522 PG Utrecht") == "3522PG129X7")
}

func kixcode(s string) string {
	t := strings.Split(s, ",")
	if len(t) != 3 {
		return ""
	}

	var (
		i int
		p string
	)
	n, err := fmt.Sscanf(t[2], "%v %v", &i, &p)
	if n != 2 || err != nil {
		return ""
	}

	for j, r := range t[1] {
		if unicode.IsDigit(r) {
			t[1] = t[1][j:]
			break
		}
	}
	t[1] = strings.Replace(t[1], "-", "X", -1)
	t[1] = strings.Replace(t[1], "/", "X", -1)
	t[1] = strings.Replace(t[1], " ", "X", -1)
	t[1] = strings.ToUpper(t[1])

	return fmt.Sprintf("%v%v%v", i, p, t[1])
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
