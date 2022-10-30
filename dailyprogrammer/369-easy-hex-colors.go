/*

Background

One common way for software specifications such as HTML to specify colors is with a hexadecimal string. For instance the color aquamarine is represented by the string "#7FFFD4". Here's how the string breaks down:

    The first character is always "#".

    The second and third character are the red channel value, represented as a hexadecimal value between 00 and FF. In this example, the red channel value is 127, which in hexadecimal is 7F.

    The fourth and fifth character are the green channel value, represented the same way. In this example, the green channel value is 255, which in hexadecimal is FF.

    The sixth and seventh character are the blue channel value, represented the same way. In this example, the blue channel value is 212, which in hexadecimal is D4.

All three channel values must be an integer between 0 (minimum brightness) and 255 (maximum brightness). In all cases the hex values are two digits each, including a leading 0 if necessary. See the Wikipedia page for more examples, and a link for how to convert a number to hexadecimal.
Challenge

Given three integers between 0 and 255, corresponding to the red, green, and blue channel values of a color, find the hex string for that color. You may use anything built into your programming language, such as for base conversion, but you can also do it manually.
Examples

hexcolor(255, 99, 71) => "#FF6347"  (Tomato)
hexcolor(184, 134, 11) => "#B8860B"  (DarkGoldenrod)
hexcolor(189, 183, 107) => "#BDB76B"  (DarkKhaki)
hexcolor(0, 0, 205) => "#0000CD"  (MediumBlue)

Optional bonus: color blending

Given a list of hex color strings, produce the hex color string you get from averaging their RGB values together. You'll need to round channel values to integers.

blend({"#000000", "#778899"}) => "#3C444C"
blend({"#E6E6FA", "#FF69B4", "#B0C4DE"}) => "#DCB1D9"

(This is not actually the best way to blend two hex colors: to do it properly you need gamma correction. But we'll leave that for another time!)

*/

package main

import (
	"fmt"
)

func main() {
	fmt.Println(hexcolor(255, 99, 71))
	fmt.Println(hexcolor(184, 134, 11))
	fmt.Println(hexcolor(189, 183, 107))
	fmt.Println(hexcolor(0, 0, 205))

	fmt.Println(blend([]string{"#000000", "#778899"}))
	fmt.Println(blend([]string{"#E6E6FA", "#FF69B4", "#B0C4DE"}))
}

func hexcolor(r, g, b uint8) string {
	return fmt.Sprintf("#%02X%02X%02X", r, g, b)
}

func blend(c []string) string {
	var r, g, b float64
	var x, y, z int

	for i := range c {
		fmt.Sscanf(c[i], "#%02X%02X%02X", &x, &y, &z)
		r += float64(x)
		g += float64(y)
		b += float64(z)
	}
	r /= float64(len(c))
	g /= float64(len(c))
	b /= float64(len(c))

	return fmt.Sprintf("#%02X%02X%02X", int(r), int(g), int(b))
}
