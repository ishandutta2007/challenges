/*

The program must print the following block of text of LED numbers exactly.

+-----------------------------------------------------------------+
|                                                                 |
| 000   1 222 333 4 4 555 666 777 888 999 AAA B   CCC   D EEE FFF |
| 0 0   1   2   3 4 4 5   6     7 8 8 9 9 A A B   C     D E   F   |
| 0 0   1 222 333 444 555 666   7 888 999 AAA BBB C   DDD EEE FFF |
| 0 0   1 2     3   4   5 6 6   7 8 8   9 A A B B C   D D E   F   |
| 000   1 222 333   4 555 666   7 888 999 A A BBB CCC DDD EEE F   |
|                                                                 |
+-----------------------------------------------------------------+

Notice the 1-char padding inside the borders. The trailing newlines, and the types of the newlines are not significant. However, the whitespaces are the spaces you get when you press spacebars (ASCII 32).

Shortest code wins. Using data encoding (base64, gzip), or compressing with other Unicode characters is discouraged. You cannot use programs like cat or gzip since they are not programming languages.

The character count must be less than 600 to qualify.

*/

package main

import "fmt"

func main() {
	fmt.Println(text)
}

const text = `
+-----------------------------------------------------------------+
|                                                                 |
| 000   1 222 333 4 4 555 666 777 888 999 AAA B   CCC   D EEE FFF |
| 0 0   1   2   3 4 4 5   6     7 8 8 9 9 A A B   C     D E   F   |
| 0 0   1 222 333 444 555 666   7 888 999 AAA BBB C   DDD EEE FFF |
| 0 0   1 2     3   4   5 6 6   7 8 8   9 A A B B C   D D E   F   |
| 000   1 222 333   4 555 666   7 888 999 A A BBB CCC DDD EEE F   |
|                                                                 |
+-----------------------------------------------------------------+
`
