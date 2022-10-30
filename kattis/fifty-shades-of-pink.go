/*

Thore is a fashionable man. Every time he meets up with his programming team, he wears his hot pink team hoodie over a salmon colored shirt with shirt buttons in a dashing rose or pink shade.
Of course, he can’t show up to two training sessions with the same buttons on his shirt, that would cause unbearable ridicule.
If he can’t find buttons for this perfect color combination, he will come up with some poor excuse for not showing up.
He has a box full of different colored buttons in labeled packages. Unfortunately, Thore is color blind, so his helpful daughter has labeled each package with the color of the buttons.
Her writing is terrible though, she mixes uppercase and lowercase arbitrarily and has no spacing between words, so Thore needs your help to decipher the names on the labels and select buttons with either “pink” or “rose” somewhere in the name, ignoring case.

Input

Input starts with an integer 1≤N≤1000, the number of button packages in the box. The following N lines each has a color name, one for each package. The names consist of up to 30 characters of letters A - Z, a - z.

Output

Print one integer, the number of training sessions Thore can attend. If he can’t attend any session because there are no pink buttons, output his standard excuse “I must watch Star Wars with my daughter”.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(shades([]string{
		"pink",
		"tequilaSunrose",
		"mExicanPInK",
		"Coquelicot",
		"turqrose",
		"roSee",
		"JETblack",
		"pink",
		"babypink",
		"pInKpinkPinK",
		"PInkrose",
		"lazerlemon",
	}) == "9")

	assert(shades([]string{
		"roose",
		"rosse",
		"pinnk",
		"screw",
		"cerise",
		"magenta",
	}) == "I must watch Star Wars with my daughter")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shades(s []string) string {
	c := 0
	for _, p := range s {
		p = strings.ToLower(p)
		if strings.Index(p, "pink") >= 0 || strings.Index(p, "rose") >= 0 {
			c++
		}
	}
	if c > 0 {
		return fmt.Sprint(c)
	}
	return "I must watch Star Wars with my daughter"
}
