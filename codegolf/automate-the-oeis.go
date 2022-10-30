/*

We see a lot of challenges here asking for a function to create a sequence from the OEIS. While these challenges are fun, as a programmer I see an opportunity for automation.

Your challenge is to make a program that takes the index of a sequence (e.g. A172141) and some integer n (e.g. 7), and pulls the appropriate value from the appropriate webpage.
I/O

As mentioned, your program should take a sequence index and some value n as input and output the nth term in that sequence. You accept any index in the sequence's B-files.
If the index is greater than the largest index listed in the B-files you may throw an exception or output whatever you choose (these are not in the test cases). Standard methods of input and output are permitted.
Restrictions on web use

You should not access any websites other than https://oeis.org and http://oeis.org. This includes url shorteners, your own personal website, and this question itself.
If you would like to access some other website and you believe that it is not unfair to allow you to do so, you can leave a comment and I will arbitrate.

Scoring

This is a code golf challenge so the program with the least bytes used in its source code wins. Standard loopholes are disallowed.
Test Cases

Assuming that your machine has proper internet connection and the OEIS servers are up and running the following inputs and outputs should correspond.

A172141, 7   -> 980
A173429, 4   -> 276
A190394, 6   -> 16
A002911, 11  -> 960
A052170, 3   -> 24
A060296, 8   -> 3
A178732, 5   -> 27
A000001, 1   -> 1
A000796, 314 -> 3
A001622, 162 -> 8
A002206, -1  -> 1

Tip

    When accessing the B-files http://oeis.org/b<A-number>.txt will redirect to the proper B-file.

*/

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"math/big"
	"net/http"
	"strings"
)

func main() {
	fmt.Println(oeis("A172141", 7))
	fmt.Println(oeis("A173429", 4))
	fmt.Println(oeis("A190394", 6))
	fmt.Println(oeis("A002911", 11))
	fmt.Println(oeis("A052170", 3))
	fmt.Println(oeis("A060296", 8))
	fmt.Println(oeis("A178732", 5))
	fmt.Println(oeis("A000001", 1))
	fmt.Println(oeis("A000796", 314))
	fmt.Println(oeis("A001622", 162))
	fmt.Println(oeis("A002206", -1))
}

func oeis(seq string, term int64) (res string, err error) {
	url := fmt.Sprintf("http://oeis.org/b%s.txt", strings.TrimPrefix(seq, "A"))
	resp, err := http.Get(url)
	if err != nil {
		return
	}

	buf, err := io.ReadAll(resp.Body)
	if err != nil {
		return
	}

	x := new(big.Int)
	y := new(big.Int)

	r := bytes.NewReader(buf)
	sc := bufio.NewScanner(r)
	for sc.Scan() {
		line := sc.Text()
		fmt.Sscanf(line, "%v %v", x, y)
		if x.Int64() == term {
			res = y.String()
			break
		}
	}

	if res == "" {
		err = fmt.Errorf("sequence not found")
	}
	return
}
