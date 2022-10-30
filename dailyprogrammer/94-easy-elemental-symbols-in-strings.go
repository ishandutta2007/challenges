/*

If you've ever seen Breaking Bad, you might have noticed how some names in the opening credit sequence get highlights according to symbols of elements in the periodic table.
Given a string as input, output every possible such modification with the element symbol enclosed in brackets and capitalized.
The elements can appear anywhere in the string, but you must only highlight one element per line, like this:

$ ./highlight dailyprogrammer
dailypr[O]grammer
daily[P]rogrammer
dail[Y]programmer
da[I]lyprogrammer
dailyprog[Ra]mmer
daily[Pr]ogrammer
dailyprogramm[Er]
dailyprogr[Am]mer

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	elements("dailyprogrammer")
}

func elements(s string) {
	tab := []string{
		"Ac", "Ag", "Al", "Am", "Ar", "As", "At", "Au", "B", "Ba", "Be", "Bh", "Bi",
		"Bk", "Br", "C", "Ca", "Cd", "Ce", "Cf", "Cl", "Cm", "Cn", "Co", "Cr", "Cs",
		"Cu", "Db", "Ds", "Dy", "Er", "Es", "Eu", "F", "Fe", "Fl", "Fm", "Fr", "Ga",
		"Gd", "Ge", "H", "He", "Hf", "Hg", "Ho", "Hs", "I", "In", "Ir", "K", "Kr", "La",
		"Li", "Lr", "Lu", "Lv", "Md", "Mg", "Mn", "Mo", "Mt", "N", "Na", "Nb", "Nd", "Ne",
		"Ni", "No", "Np", "O", "Os", "P", "Pa", "Pb", "Pd", "Pm", "Po", "Pr", "Pt", "Pu",
		"Ra", "Rb", "Re", "Rf", "Rg", "Rh", "Rn", "Ru", "S", "Sb", "Sc", "Se", "Sg", "Si", "Sm",
		"Sn", "Sr", "Ta", "Tb", "Tc", "Te", "Th", "Ti", "Tl", "Tm", "U", "Uuo", "Uup", "Uus", "Uut",
		"V", "W", "Xe", "Y", "Yb", "Zn", "Zr",
	}

	u := strings.ToUpper(s)
	for _, t := range tab {
		i := strings.Index(u, strings.ToUpper(t))
		if i >= 0 {
			fmt.Printf("%s[%s]%s\n", s[:i], t, s[i+len(t):])
		}
	}
}
