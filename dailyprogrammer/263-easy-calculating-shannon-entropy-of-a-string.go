/*

Description

Shannon entropy was introduced by Claude E. Shannon in his 1948 paper "A Mathematical Theory of Communication". Somewhat related to the physical and chemical concept entropy, the Shannon entropy measures the uncertainty associated with a random variable, i.e. the expected value of the information in the message (in classical informatics it is measured in bits). This is a key concept in information theory and has consequences for things like compression, cryptography and privacy, and more.

The Shannon entropy H of input sequence X is calculated as -1 times the sum of the frequency of the symbol i times the log base 2 of the frequency:

            n
            _   count(i)          count(i)
H(X) = -1 * >   --------- * log  (--------)
            -       N          2      N
            i=1

(That funny thing is the summation for i=1 to n. I didn't see a good way to do this in Reddit's markup so I did some crude ASCII art.)

For more, see Wikipedia for Entropy in information theory).
Input Description

You'll be given a string, one per line, for which you should calculate the Shannon entropy. Examples:

1223334444
Hello, world!

Output Description

Your program should emit the calculated entropy values for the strings to at least five decimal places. Examples:

1.84644
3.18083

Challenge Input

122333444455555666666777777788888888
563881467447538846567288767728553786
https://www.reddit.com/r/dailyprogrammer
int main(int argc, char *argv[])

Challenge Output

2.794208683
2.794208683
4.056198332
3.866729296

*/
package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"math"
	"os"
	"unicode/utf8"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("entropy-count: ")

	flag.Parse()
	if flag.NArg() < 1 {
		fmt.Println(entropy("1223334444"))
		fmt.Println(entropy("Hello, world!"))
		fmt.Println(entropy("122333444455555666666777777788888888"))
		fmt.Println(entropy("563881467447538846567288767728553786"))
		fmt.Println(entropy("https://www.reddit.com/r/dailyprogrammer"))
		fmt.Println(entropy("int main(int argc, char *argv[])"))
	} else {
		f, err := os.Open(flag.Arg(0))
		if err != nil {
			log.Fatal(err)
		}
		defer f.Close()

		s := bufio.NewScanner(f)
		for s.Scan() {
			fmt.Println(entropy(s.Text()))
		}
	}
}

func entropy(str string) float64 {
	S := 0.0
	N := float64(utf8.RuneCountInString(str))
	F := count(str)
	for _, f := range F {
		S += (f / N) * math.Log2(f/N)
	}
	return -1 * S
}

func count(str string) map[rune]float64 {
	F := make(map[rune]float64)
	for _, ch := range str {
		F[ch]++
	}
	return F
}
