/*

Challenge
The challenge is to implement the bottom encoding (only encoding, not decoding). There is a wide variety of existing implementations in the bottom-software-foundation org.

Bottom is a text encoding where each character is separated into multiple emoji.

Unicode escape(s)	Character	Value
U+1FAC2	🫂	200
U+1F496	💖	50
U+2728	✨	10
U+1F97A	🥺	5
U+002C	,	1
U+2764, U+FE0F	❤️	0
Unicode escape(s)	Character	Purpose
U+1F449, U+1F448	👉👈	Byte separator
Notes on encoding
The output stream will be a sequence of groups of value characters (see table above) with each group separated by the byte separator character, i.e.
💖✨✨✨👉👈💖💖🥺,,,👉👈💖💖,👉👈💖✨✨✨✨🥺,,👉👈💖💖✨🥺👉👈💖💖,👉👈💖✨,,,👉👈
The total numerical value of each group must equal the decimal value of the corresponding input byte.
For example, the numerical value of 💖💖,,,,, as according to the character table above, is 50 + 50 + 1 + 1 + 1 + 1, or 104. This sequence would thus represent U+0068 or h, which has a decimal value of 104.
Note the ordering of characters within groups. Groups of value characters must be in descending order.
While character order (within groups) technically does not affect the output in any way, arbitrary ordering can encroach significantly on decoding speed and is considered both illegal and bad form.
Byte separators that do not follow a group of value characters are illegal, i.e 💖💖,,,,👉👈👉👈 or 👉👈💖💖,,,,👉👈. As such, 👉👈 alone is illegal.
Groups of value characters must be followed by a byte separator. 💖💖,,,, alone is illegal, but 💖💖,,,,👉👈 is valid.
The null value must not be followed by a byte separator. 💖💖,,,,👉👈❤️💖💖,,,,👉👈 and 💖💖,,,,👉👈❤️ alone are valid, but 💖💖,,,,👉👈❤️👉👈 is illegal.
Some pseudocode to illustrate how each character is converted:

for b in input_stream:
    # Get `b`'s UTF-8 value
    let v = b as number
    let o = new string

    if v == 0:
        o.append("❤️")
    else:
        while true:
            if v >= 200:
                o.append("🫂")
                v = v - 200
            else if v >= 50:
                o.append("💖")
                v = v - 50
            else if v >= 10:
                o.append("✨")
                v = v - 10
            else if v >= 5:
                o.append("🥺")
                v = v - 5
            else if v >= 1:
                o.append(",")
                v = v - 1
            else:
                break

        o.append("👉👈")

return o
Rules
The standard I/O rules apply.
The input must be a string, not a list of bytes.
An empty string should return an empty string.
It should return the same result as bottom-web for any input with no null bytes (UTF-8 validation is not required).
Some test cases:

test -> 💖💖✨🥺,👉👈💖💖,👉👈💖💖✨🥺👉👈💖💖✨🥺,👉👈
Hello World! -> 💖✨✨,,👉👈💖💖,👉👈💖💖🥺,,,👉👈💖💖🥺,,,👉👈💖💖✨,👉👈✨✨✨,,👉👈💖✨✨✨🥺,,👉👈💖💖✨,👉👈💖💖✨,,,,👉👈💖💖🥺,,,👉👈💖💖👉👈✨✨✨,,,👉👈
🥺 -> 🫂✨✨✨✨👉👈💖💖💖🥺,,,,👉👈💖💖💖✨🥺👉👈💖💖💖✨✨✨🥺,👉👈
   (2 spaces) -> ✨✨✨,,👉👈✨✨✨,,👉👈
𐀊 -> 🫂✨✨✨✨👉👈💖💖✨✨✨✨,,,,👉👈💖💖✨✨🥺,,,👉👈💖💖✨✨✨🥺,,,👉👈
⍉⃠ -> 🫂✨✨🥺,👉👈💖💖✨✨✨✨,👉👈💖💖✨✨✨🥺,,👉👈🫂✨✨🥺,👉👈💖💖✨✨✨,👉👈💖💖💖✨👉👈
X⃩ -> 💖✨✨✨🥺,,,👉👈🫂✨✨🥺,👉👈💖💖✨✨✨,👉👈💖💖💖✨🥺,,,,👉👈
❤️ -> 🫂✨✨🥺,👉👈💖💖💖🥺,,👉👈💖💖💖✨,,,,👉👈🫂✨✨✨🥺,,,,👉👈💖💖💖✨✨✨,,,,👉👈💖💖✨✨✨✨,,,👉👈
.\0. (null byte surrounded by full stops) -> ✨✨✨✨🥺,👉👈❤️✨✨✨✨🥺,👉👈
This is code-golf, so fewest bytes win!

*/

package main

import "bytes"

func main() {
	assert(botenc("test") == "💖💖✨🥺,👉👈💖💖,👉👈💖💖✨🥺👉👈💖💖✨🥺,👉👈")
	assert(botenc("Hello World!") == "💖✨✨,,👉👈💖💖,👉👈💖💖🥺,,,👉👈💖💖🥺,,,👉👈💖💖✨,👉👈✨✨✨,,👉👈💖✨✨✨🥺,,👉👈💖💖✨,👉👈💖💖✨,,,,👉👈💖💖🥺,,,👉👈💖💖👉👈✨✨✨,,,👉👈")
	assert(botenc("🥺") == "🫂✨✨✨✨👉👈💖💖💖🥺,,,,👉👈💖💖💖✨🥺👉👈💖💖💖✨✨✨🥺,👉👈")
	assert(botenc("  ") == "✨✨✨,,👉👈✨✨✨,,👉👈")
	assert(botenc("𐀊") == "🫂✨✨✨✨👉👈💖💖✨✨✨✨,,,,👉👈💖💖✨✨🥺,,,👉👈💖💖✨✨✨🥺,,,👉👈")
	assert(botenc("⍉⃠") == "🫂✨✨🥺,👉👈💖💖✨✨✨✨,👉👈💖💖✨✨✨🥺,,👉👈🫂✨✨🥺,👉👈💖💖✨✨✨,👉👈💖💖💖✨👉👈")
	assert(botenc("X⃩") == "💖✨✨✨🥺,,,👉👈🫂✨✨🥺,👉👈💖💖✨✨✨,👉👈💖💖💖✨🥺,,,,👉👈")
	assert(botenc("❤️") == "🫂✨✨🥺,👉👈💖💖💖🥺,,👉👈💖💖💖✨,,,,👉👈🫂✨✨✨🥺,,,,👉👈💖💖💖✨✨✨,,,,👉👈💖💖✨✨✨✨,,,👉👈")
	assert(botenc(".\x00.") == "✨✨✨✨🥺,👉👈❤️✨✨✨✨🥺,👉👈")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func botenc(s string) string {
	w := new(bytes.Buffer)
	for i := 0; i < len(s); i++ {
		r := s[i]
		if r == 0 {
			w.WriteString("❤️")
			continue
		}
		for r > 0 {
			switch {
			case r >= 200:
				w.WriteString("🫂")
				r -= 200
			case r >= 50:
				w.WriteString("💖")
				r -= 50
			case r >= 10:
				w.WriteString("✨")
				r -= 10
			case r >= 5:
				w.WriteString("🥺")
				r -= 5
			case r >= 1:
				w.WriteString(",")
				r -= 1
			}
		}
		w.WriteString("👉👈")
	}
	return w.String()
}
