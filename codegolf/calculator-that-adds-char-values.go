/*

Task
Build a calculator, that takes any string, from a file, stdin or whatever, and adds up all the values of the chars.

Example

Input
Hello World!

Output
1085
Rules
The calculator needs to accept just ASCII encoding.

The shortest code wins.

Notes
Regarding to the comment of m.buettner, I need to say, I didn't thought of the multibyte part.
So I leave it as a bonus thing aswell.
The calculator should be run as written, so no need to modify before compiling or interpreting.

Bonus
Thanks to Synthetica, here is one more bonus,

The program that has the lowest output when you use its code as its input wins gets a star.

I don't want to modify it completly.

If you write it additional to output the (right) value in UTF-8 you get a star.

The code that executes fastest on my Laptop (Lenovo Yoga 13 Intel Core i5 3317U 1.7Ghz, 8GB RAM, 128GB SSD, Intel HD 4000, Windows 8) gets a star.

Web codes will run first under IE11 with chakra and then in FireFox 29.0.1 with SpiderMonkey

Linux code will run on a Raspberry Pi with Raspbian.

The teststring is this:

q/%8hnp>T%y?'wNb\},9krW &D9']K$n;l.3O+tE*$*._B^s!@k\&Cl:EO1zo8sVxEvBxCock_I+2o6 yeX*0Xq:tS^f)!!7=!tk9K<6#/E`ks(D'$z$\6Ac+MT&[s[]_Y(`<g%"w%cW'`c&q)D$0#C$QGf>?A$iawvc,}`9!('`c&q)D$0#C$QGf>?A$iawvc,}`9!(
Have fun coding :)

Bonusscoring
I plan to do the scoring at this Saturday so the 07.06.14, all answers after that date won't get bonus points ;)

You can download the code I gonna use for testing here feel free to fork and improve it :)

Little update because of the bonus, my laptop is partially broken so I will do it probably next weekend, I am really sorry for that :(

*/

package main

import (
	"fmt"
	"io"
	"os"
)

func main() {
	var sum Sum
	io.Copy(&sum, os.Stdin)
	fmt.Println(sum)
}

type Sum int

func (s *Sum) Write(p []byte) (n int, err error) {
	for _, v := range p {
		*s += Sum(v)
	}
	return len(p), nil
}
