/*

Description
Welcome to DailyProgrammer University. Today you will be earning a degree in converting degrees. This includes Fahrenheit, Celsius, Kelvin, Degrees (angle), and Radians.

Input Description
You will be given two lines of text as input. On the first line, you will receive a number followed by two letters, the first representing the unit that the number is currently in, the second representing the unit it needs to be converted to.

Examples of valid units are:

d for degrees of a circle

r for radians

Output Description
You must output the given input value, in the unit specified. It must be followed by the unit letter. You may round to a whole number, or to a few decimal places.

Challenge Input
3.1416rd
90dr
Challenge Output
180d
1.57r
Bonus
Also support these units:

c for Celsius

f for Fahrenheit

k for Kelvin

If the two units given are incompatible, give an error message as output.

Bonus Input
212fc
70cf
100cr
315.15kc
Bonus Output
100c
158f
No candidate for conversion
42c
Notes
See here for a wikipedia page with temperature conversion formulas.

See here for a random web link about converting between degrees and radians.

Finally
Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(conv("3.1416rd"))
	fmt.Println(conv("90dr"))
	fmt.Println(conv("212fc"))
	fmt.Println(conv("70cf"))
	fmt.Println(conv("100cr"))
	fmt.Println(conv("315.15kc"))
	fmt.Println(conv("42ck"))
	fmt.Println(conv("345kf"))
	fmt.Println(conv("161.33fk"))
}

func conv(s string) string {
	const unsupported = "No candidate for conversion"

	var (
		a, b rune
		v    float64
	)
	n, err := fmt.Sscanf(s, "%f%c%c", &v, &a, &b)
	if n != 3 || err != nil {
		return unsupported
	}

	r := 0.0
	t := fmt.Sprintf("%c%c", a, b)
	switch t {
	case "rd":
		r = rad2deg(v)
	case "dr":
		r = deg2rad(v)
	case "fc":
		r = fahr2cel(v)
	case "cf":
		r = cel2fahr(v)
	case "fk":
		r = fahr2kel(v)
	case "kf":
		r = kel2fahr(v)
	case "ck":
		r = cel2kel(v)
	case "kc":
		r = kel2cel(v)
	default:
		return unsupported
	}

	return fmt.Sprintf("%f%c", r, b)
}

func rad2deg(x float64) float64  { return x * 180 / math.Pi }
func deg2rad(x float64) float64  { return x * math.Pi / 180 }
func fahr2cel(x float64) float64 { return (x - 32) * 5 / 9 }
func cel2fahr(x float64) float64 { return x*9/5 + 32 }
func fahr2kel(x float64) float64 { return cel2kel(fahr2cel(x)) }
func kel2fahr(x float64) float64 { return cel2fahr(kel2cel(x)) }
func cel2kel(x float64) float64  { return x + 273.15 }
func kel2cel(x float64) float64  { return x - 273.15 }
