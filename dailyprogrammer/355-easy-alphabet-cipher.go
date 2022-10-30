/*

Description
"The Alphabet Cipher", published by Lewis Carroll in 1868, describes a Vigenère cipher (thanks /u/Yadkee for the clarification) for passing secret messages. The cipher involves alphabet substitution using a shared keyword. Using the alphabet cipher to tranmit messages follows this procedure:

You must make a substitution chart like this, where each row of the alphabet is rotated by one as each letter goes down the chart. All test cases will utilize this same substitution chart.
  ABCDEFGHIJKLMNOPQRSTUVWXYZ
A abcdefghijklmnopqrstuvwxyz
B bcdefghijklmnopqrstuvwxyza
C cdefghijklmnopqrstuvwxyzab
D defghijklmnopqrstuvwxyzabc
E efghijklmnopqrstuvwxyzabcd
F fghijklmnopqrstuvwxyzabcde
G ghijklmnopqrstuvwxyzabcdef
H hijklmnopqrstuvwxyzabcdefg
I ijklmnopqrstuvwxyzabcdefgh
J jklmnopqrstuvwxyzabcdefghi
K klmnopqrstuvwxyzabcdefghij
L lmnopqrstuvwxyzabcdefghijk
M mnopqrstuvwxyzabcdefghijkl
N nopqrstuvwxyzabcdefghijklm
O opqrstuvwxyzabcdefghijklmn
P pqrstuvwxyzabcdefghijklmno
Q qrstuvwxyzabcdefghijklmnop
R rstuvwxyzabcdefghijklmnopq
S stuvwxyzabcdefghijklmnopqr
T tuvwxyzabcdefghijklmnopqrs
U uvwxyzabcdefghijklmnopqrst
V vwxyzabcdefghijklmnopqrstu
W wxyzabcdefghijklmnopqrstuv
X xyzabcdefghijklmnopqrstuvw
Y yzabcdefghijklmnopqrstuvwx
Z zabcdefghijklmnopqrstuvwxy
Both people exchanging messages must agree on the secret keyword. To be effective, this keyword should not be written down anywhere, but memorized.

To encode the message, first write it down.

thepackagehasbeendelivered
Then, write the keyword, (for example, snitch), repeated as many times as necessary.

snitchsnitchsnitchsnitchsn
thepackagehasbeendelivered
Now you can look up the column S in the table and follow it down until it meets the T row. The value at the intersection is the letter L. All the letters would be thus encoded.

snitchsnitchsnitchsnitchsn
thepackagehasbeendelivered
lumicjcnoxjhkomxpkwyqogywq
The encoded message is now lumicjcnoxjhkomxpkwyqogywq

To decode, the other person would use the secret keyword and the table to look up the letters in reverse.

Input Description
Each input will consist of two strings, separate by a space. The first word will be the secret word, and the second will be the message to encrypt.

snitch thepackagehasbeendelivered
Output Description
Your program should print out the encrypted message.

lumicjcnoxjhkomxpkwyqogywq

Challenge Inputs
bond theredfoxtrotsquietlyatmidnight
train murderontheorientexpress
garden themolessnuckintothegardenlastnight

Challenge Outputs
uvrufrsryherugdxjsgozogpjralhvg
flrlrkfnbuxfrqrgkefckvsa
zhvpsyksjqypqiewsgnexdvqkncdwgtixkx

*/

package main

import (
	"fmt"
	"strings"
	"unicode"
)

var tab [26][26]rune

func init() {
	for i := 0; i < 26; i++ {
		for j := 0; j < 26; j++ {
			tab[i][j] = rune('a' + (j+i)%26)
		}
	}
}

func encode(key, plain string) string {
	var w strings.Builder
	for i, ch := range plain {
		ch = unicode.ToLower(ch)
		if !('a' <= ch && ch <= 'z') {
			w.WriteRune(ch)
		} else {
			c := key[i%len(key)] - 'a'
			r := ch - 'a'
			w.WriteRune(tab[r][c])
		}
	}
	return w.String()
}

func decode(key, cipher string) string {
	var w strings.Builder
	for i, ch := range cipher {
		ch = unicode.ToLower(ch)
		if !('a' <= ch && ch <= 'z') {
			w.WriteRune(ch)
		} else {
			c := key[i%len(key)] - 'a'
			for i := range tab {
				if tab[i][c] == ch {
					w.WriteRune(rune('a' + i))
					break
				}
			}
		}
	}
	return w.String()
}

func main() {
	enc := encode("snitch", "thepackagehasbeendelivered")
	dec := decode("snitch", enc)
	fmt.Printf("%s\n%s\n\n", enc, dec)

	enc = encode("bond", "theredfoxtrotsquietlyatmidnight")
	dec = decode("bond", enc)
	fmt.Printf("%s\n%s\n\n", enc, dec)

	enc = encode("train", "murderontheorientexpress")
	dec = decode("train", enc)
	fmt.Printf("%s\n%s\n\n", enc, dec)

	enc = encode("garden", "themolessnuckintothegardenlastnight")
	dec = decode("garden", enc)
	fmt.Printf("%s\n%s\n\n", enc, dec)
}
