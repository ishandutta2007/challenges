/*

I use "suffix" loosely here to mean "any sub-string that follows the prefix".

"Prefix" here means the START of a word, where a word's start is defined as either after a space or from the first character of the input text (for the first word). A "prefix" in the middle of a word is ignored.

E.g. if your input prefix is "arm" and the input text is "Dumbledore's army was fully armed for the impending armageddon" then the output list contains (y, ed, ageddon).

Test Cases
Assume case-sensitive, strings end after spaces. Input will not start with a space.

Removing duplicates is optional.

Input prefix: "1"

Input text:

"He1in aosl 1ll j21j 1lj2j 1lj2 1ll l1j2i"

Output: (ll, lj2j, lj2) - in any permutation
Input prefix: "frac"

Input text:

"fracking fractals fracted fractional currency fractionally fractioned into fractious fractostratic fractures causing quite a fracas"

Output: (king, tals, ted, tional, tionally, tioned, tious, tostratic, tures, as)
Input prefix: "href="https://www.astrotheme.com/astrology/"

Input text:

"(div style="padding: 0; background: url('https://www.astrotheme.com/images/site/arrondi_450_hd.png') no-repeat; text-align: left; font-weight: bold; width: 450px; height: 36px")
  (div class="titreFiche" style="padding: 5px 0 0 6px")(a href="https://www.astrotheme.com/astrology/Nolwenn_Leroy" title="Nolwenn Leroy: Astrology, birth chart, horoscope and astrological portrait")Nolwenn Leroy(br /)
(/div)
  (div style="text-align: right; border-left: 1px solid #b2c1e2; border-right: 1px solid #b2c1e2; width: 446px; padding: 1px 1px 0; background: #eff8ff")
    (table style="width: 100%")(tr)(td style="width: 220px")
(div style="padding: 0; background: url('https://www.astrotheme.com/images/site/arrondi_450_hd.png') no-repeat; text-align: left; font-weight: bold; width: 450px; height: 36px")
  (div class="titreFiche" style="padding: 5px 0 0 6px")(a href="https://www.astrotheme.com/astrology/Kim_Kardashian" title="Kim Kardashian: Astrology, birth chart, horoscope and astrological portrait")Kim Kardashian(br /)(span style="font-weight: normal; font-size: 11px")Display her detailed horoscope and birth chart(/span)(/a)(/div)
(/div)
(div style="padding: 0; background: url('https://www.astrotheme.com/images/site/arrondi_450_hd.png') no-repeat; text-align: left; font-weight: bold; width: 450px; height: 36px")
  (div class="titreFiche" style="padding: 5px 0 0 6px")(a href="https://www.astrotheme.com/astrology/Julia_Roberts" title="Julia Roberts: Astrology, birth chart, horoscope and astrological portrait")Julia Roberts(br /)(span style="font-weight: normal; font-size: 11px")Display her detailed horoscope and birth chart(/span)(/a)(/div)
    (td id="cfcXkw9aycuj35h" style="text-align: right")
  (/div)"

Output: (Nolwenn_Leroy", Kim_Kardashian", Julia_Roberts")
The Winner
This is code-golf, so the fewest bytes wins. :)

Can accept the inputs in any way that works, as long as your code can solve arbitrary problems like the test cases.

*/

package main

import (
	"fmt"
	"reflect"
	"regexp"
)

func main() {
	test("1", "He1in aosl 1ll j21j 1lj2j 1lj2 1ll l1j2i", []string{"ll", "lj2j", "lj2"})
	test("frac", "fracking fractals fracted fractional currency fractionally fractioned into fractious fractostratic fractures causing quite a fracas", []string{"king", "tals", "ted", "tional", "tionally", "tioned", "tious", "tostratic", "tures", "as"})
	test(`href="https://www.astrotheme.com/astrology/`, `(div style="padding: 0; background: url('https://www.astrotheme.com/images/site/arrondi_450_hd.png') no-repeat; text-align: left; font-weight: bold; width: 450px; height: 36px")
  (div class="titreFiche" style="padding: 5px 0 0 6px")(a href="https://www.astrotheme.com/astrology/Nolwenn_Leroy" title="Nolwenn Leroy: Astrology, birth chart, horoscope and astrological portrait")Nolwenn Leroy(br /)
(/div)
  (div style="text-align: right; border-left: 1px solid #b2c1e2; border-right: 1px solid #b2c1e2; width: 446px; padding: 1px 1px 0; background: #eff8ff")
    (table style="width: 100%")(tr)(td style="width: 220px")
(div style="padding: 0; background: url('https://www.astrotheme.com/images/site/arrondi_450_hd.png') no-repeat; text-align: left; font-weight: bold; width: 450px; height: 36px")
  (div class="titreFiche" style="padding: 5px 0 0 6px")(a href="https://www.astrotheme.com/astrology/Kim_Kardashian" title="Kim Kardashian: Astrology, birth chart, horoscope and astrological portrait")Kim Kardashian(br /)(span style="font-weight: normal; font-size: 11px")Display her detailed horoscope and birth chart(/span)(/a)(/div)
(/div)
(div style="padding: 0; background: url('https://www.astrotheme.com/images/site/arrondi_450_hd.png') no-repeat; text-align: left; font-weight: bold; width: 450px; height: 36px")
  (div class="titreFiche" style="padding: 5px 0 0 6px")(a href="https://www.astrotheme.com/astrology/Julia_Roberts" title="Julia Roberts: Astrology, birth chart, horoscope and astrological portrait")Julia Roberts(br /)(span style="font-weight: normal; font-size: 11px")Display her detailed horoscope and birth chart(/span)(/a)(/div)
    (td id="cfcXkw9aycuj35h" style="text-align: right")
  (/div)`, []string{`Nolwenn_Leroy"`, `Kim_Kardashian"`, `Julia_Roberts"`})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(prefix, text string, result []string) {
	list := find(prefix, text)
	fmt.Println(list)
	assert(reflect.DeepEqual(list, result))
}

func find(prefix, text string) []string {
	ex := fmt.Sprintf("\\b%s\\S+", prefix)
	re := regexp.MustCompile(ex)

	r := []string{}
	m := make(map[string]bool)
	p := re.FindAllString(text, -1)
	for _, s := range p {
		s = s[len(prefix):]
		if !m[s] {
			r = append(r, s)
			m[s] = true
		}
	}
	return r
}
