/*

Create a function that takes a string as an argument and return a non-encoded, encrypted string.
Examples

encode_morse("EDABBIT CHALLENGE") ➞ ". -.. .- -... -... .. -   -.-. .... .- .-.. .-.. . -. --. ."

encode_morse("HELP ME !") ➞ ".... . .-.. .--.   -- .   -.-.--"

This dictionary can be used for coding:

char_to_dots = {
  'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.',
  'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..',
  'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
  'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
  'Y': '-.--', 'Z': '--..', ' ': ' ', '0': '-----',
  '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....',
  '6': '-....', '7': '--...', '8': '---..', '9': '----.',
  '&': '.-...', "'": '.----.', '@': '.--.-.', ')': '-.--.-', '(': '-.--.',
  ':': '---...', ',': '--..--', '=': '-...-', '!': '-.-.--', '.': '.-.-.-',
  '-': '-....-', '+': '.-.-.', '"': '.-..-.', '?': '..--..', '/': '-..-.'
}

Notes

    Input value can be lower or upper case.
    Input string can have digits.
    Input string can have some special characters (e.g. comma, colon, apostrophe, period, question mark, exclamation mark).

*/
package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(morsify("EDABBIT CHALLENGE") == ". -.. .- -... -... .. -   -.-. .... .- .-.. .-.. . -. --. .")
	assert(morsify("HELP ME !") == ".... . .-.. .--.   -- .   -.-.--")
	assert(morsify("CHALLENGE") == "-.-. .... .- .-.. .-.. . -. --. .")
	assert(morsify("1 APPLE AND 5 CHERRY, 7 SANDWICHES, 2 TABLES, 9 INVITED GUYS ! THAT'S SO COOL...") == ".----   .- .--. .--. .-.. .   .- -. -..   .....   -.-. .... . .-. .-. -.-- --..--   --...   ... .- -. -.. .-- .. -.-. .... . ... --..--   ..---   - .- -... .-.. . ... --..--   ----.   .. -. ...- .. - . -..   --. ..- -.-- ...   -.-.--   - .... .- - .----. ...   ... ---   -.-. --- --- .-.. .-.-.- .-.-.- .-.-.-")
	assert(morsify("did you got my mail ?") == "-.. .. -..   -.-- --- ..-   --. --- -   -- -.--   -- .- .. .-..   ..--..")
	assert(morsify("TWO THInGS TO KNOW : i FORGeT THeM :C") == "- .-- ---   - .... .. -. --. ...   - ---   -.- -. --- .--   ---...   ..   ..-. --- .-. --. . -   - .... . --   ---... -.-.")
}

func morsify(s string) string {
	tab := map[rune]string{
		'A': ".-", 'B': "-...", 'C': "-.-.", 'D': "-..", 'E': ".", 'F': "..-.",
		'G': "--.", 'H': "....", 'I': "..", 'J': ".---", 'K': "-.-", 'L': ".-..",
		'M': "--", 'N': "-.", 'O': "---", 'P': ".--.", 'Q': "--.-", 'R': ".-.",
		'S': "...", 'T': "-", 'U': "..-", 'V': "...-", 'W': ".--", 'X': "-..-",
		'Y': "-.--", 'Z': "--..", ' ': " ", '0': "-----",
		'1': ".----", '2': "..---", '3': "...--", '4': "....-", '5': ".....",
		'6': "-....", '7': "--...", '8': "---..", '9': "----.",
		'&': ".-...", '\'': ".----.", '@': ".--.-.", ')': "-.--.-", '(': "-.--.",
		':': "---...", ',': "--..--", '=': "-...-", '!': "-.-.--", '.': ".-.-.-",
		'-': "-....-", '+': ".-.-.", '"': ".-..-.", '?': "..--..", '/': "-..-.",
	}

	p := new(bytes.Buffer)
	for _, r := range s {
		p.WriteString(tab[unicode.ToUpper(r)])
		p.WriteString(" ")
	}

	t := p.String()
	if t != "" {
		t = t[:len(t)-1]
	}
	return t
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
