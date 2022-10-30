/*

Create a function that takes a string (morse code) as an argument and returns an unencrypted string.
Examples

decodeMorse(".... . .-.. .--.   -- .   -.-.--") ➞ "HELP ME !"

decodeMorse("-.-. .... .- .-.. .-.. . -. --. .") ➞ "CHALLENGE"

decodeMorse(". -.. .- -... -... .. -   -.-. .... .- .-.. .-.. . -. --. .") ➞ "EDABBIT CHALLENGE"

The following object can be used for coding:

morseToDots = {
  ".-":"A", "-...":"B", "-.-.":"C", "-..":"D", ".":"E", "..-.":"F",
  "--.":"G", "....":"H", "..":"I", ".---":"J", "-.-":"K", ".-..":"L",
  "--":"M", "-.":"N", "---":"O", ".--.":"P", "--.-":"Q", ".-.":"R",
  "...":"S", "-":"T", "..-":"U", "...-":"V", ".--":"W", "-..-":"X",
  "-.--":"Y", "--..":"Z", "-----":"0", ".----":"1", "..---":"2",
  "...--":"3", "....-":"4", ".....":"5", "-....":"6", "--...":"7",
  "---..":"8", "----.":"9", "-.-.--":"!", "   ":" ", "..--..":"?",
  ".-.-.-":".", ".----.":""", "---...":":", "--..--":", ", " ":""
}

Notes

    Return values are all uppercase.
    Input string can have digits.
    Input string can have some special chararacters (e.g. comma, colon, apostrophe, period, question mark, exclamation mark).

*/

package main

import (
	"bytes"
	"strings"
)

func main() {
	assert(morse(". -.. .- -... -... .. -   -.-. .... .- .-.. .-.. . -. --. .") == "EDABBIT CHALLENGE")
	assert(morse(".... . .-.. .--.   -- .   -.-.--") == "HELP ME !")
	assert(morse("-.-. .... .- .-.. .-.. . -. --. .") == "CHALLENGE")
	assert(morse(".----   .- .--. .--. .-.. .   .- -. -..   .....   -.-. .... . .-. .-. -.-- --..--   --...   ... .- -. -.. .-- .. -.-. .... . ... --..--   ..---   - .- -... .-.. . ... --..--   ----.   .. -. ...- .. - . -..   --. ..- -.-- ...   -.-.--   - .... .- - .----. ...   ... ---   -.-. --- --- .-.. .-.-.- .-.-.- .-.-.-") == "1 APPLE AND 5 CHERRY, 7 SANDWICHES, 2 TABLES, 9 INVITED GUYS ! THAT'S SO COOL...")
	assert(morse("-.. .. -..   -.-- --- ..-   --. --- -   -- -.--   -- .- .. .-..   ..--..") == "DID YOU GOT MY MAIL ?")
	assert(morse("- .-- ---   - .... .. -. --. ...   - ---   -.- -. --- .--   ---...   ..   ..-. --- .-. --. . -   - .... . --   ---... -.-.") == "TWO THINGS TO KNOW : I FORGET THEM :C")
}

func morse(s string) string {
	var tab = map[string]string{
		".-": "A", "-...": "B", "-.-.": "C", "-..": "D", ".": "E", "..-.": "F",
		"--.": "G", "....": "H", "..": "I", ".---": "J", "-.-": "K", ".-..": "L",
		"--": "M", "-.": "N", "---": "O", ".--.": "P", "--.-": "Q", ".-.": "R",
		"...": "S", "-": "T", "..-": "U", "...-": "V", ".--": "W", "-..-": "X",
		"-.--": "Y", "--..": "Z", "-----": "0", ".----": "1", "..---": "2",
		"...--": "3", "....-": "4", ".....": "5", "-....": "6", "--...": "7",
		"---..": "8", "----.": "9", "-.-.--": "!", "   ": " ", "..--..": "?",
		".-.-.-": ".", ".----.": "'", "---...": ":", "--..--": ",", " ": "",
	}

	p := new(bytes.Buffer)
	for i, j := 0, 0; i < len(s); {
		u := ".-"
		if s[i] == ' ' {
			u = " "
		}
		for i < len(s) && strings.IndexRune(u, rune(s[i])) >= 0 {
			i++
		}

		p.WriteString(tab[s[j:i]])
		j = i
	}
	return p.String()
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
