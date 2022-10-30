/*

Given an unsigned integer that represents a timestamp since 1970/01/01 00:00:00 (which is Unix epoch time), output one of these:

    An array that stores year, month, date, hour, minute, second.
    A string in format YYYYMMDDHHmmss.
    Or whatever similar, as long as it complies with standard i/o rules.

Rules

    Implement the function or the full program from vanilla.
        So no built-ins nor libraries that has the fuctionality.
    Implement leap year, too; but don't leap second (although leap second is not supported).
    You just need to support up to 2038/01/19 (so input range shall be 0 to 2147483647 (inclusive)).
    Standard loopholes apply.
    Standard I/O rules apply.
    Input and output format should be consistent and not ambiguous.
        So, for example, if output is a string like 1970121000, it's unqualified, as it can be recognized as 1970/01/21 00:00:00, 1970/12/01 00:00:00, or 1970/01/02 10:00:00.
    Shortest code wins.

Test cases

0
-> 1970/01/01 00:00:00
999999999
-> 2001/09/09 01:46:39
1145141919
-> 2006/04/15 22:58:39
1330500000
-> 2012/02/29 07:20:00
1633773293
-> 2021/10/09 09:54:53
2147483647
-> 2038/01/19 03:14:07

Hint

Here are implementations:

    minix-server/gmtime.c
    シェルスクリプトで時間計算を一人前にこなす: AWK implementation.
        Try it online! I translated comments.

Related problems

    Unix timestamp to datetime string
    Shortest script that gives the time passed since a Unix timestamp

*/

package main

import (
	"time"
)

func main() {
	assert(unixtime(0) == "1970/01/01 00:00:00")
	assert(unixtime(999999999) == "2001/09/09 01:46:39")
	assert(unixtime(1145141919) == "2006/04/15 22:58:39")
	assert(unixtime(1330500000) == "2012/02/29 07:20:00")
	assert(unixtime(1633773293) == "2021/10/09 09:54:53")
	assert(unixtime(2147483647) == "2038/01/19 03:14:07")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unixtime(s int64) string {
	t := time.Unix(s, 0)
	u := t.UTC()
	return u.Format("2006/01/02 15:04:05")
}
