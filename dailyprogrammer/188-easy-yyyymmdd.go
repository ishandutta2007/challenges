/*

Description:

iso 8601 standard for dates tells us the proper way to do an extended day is yyyy-mm-dd

    yyyy = year

    mm = month

    dd = day

A company's database has become polluted with mixed date formats. They could be one of 6 different formats

    yyyy-mm-dd

    mm/dd/yy

    mm#yy#dd

    dd*mm*yyyy

    (month word) dd, yy

    (month word) dd, yyyy

(month word) can be: Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec

Note if is yyyy it is a full 4 digit year. If it is yy then it is only the last 2 digits of the year. Years only go between 1950-2049.
Input:

You will be given 1000 dates to correct.
Output:

You must output the dates to the proper iso 8601 standard of yyyy-mm-dd
Challenge Input:

https://gist.github.com/coderd00d/a88d4d2da014203898af
Posting Solutions:

Please do not post your 1000 dates converted. If you must use a gist or link to another site. Or just show a sampling
Challenge Idea:

Thanks to all the people pointing out the iso standard for dates in last week's intermediate challenge. Not only did it inspire today's easy challenge but help give us a weekly topic. You all are awesome :)

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"time"
)

func main() {
	err := convert("188-easy-yyyymmdd.txt")
	if err != nil {
		log.Fatal(err)
	}
}

func convert(name string) error {
	f, err := os.Open(name)
	if err != nil {
		return err
	}
	defer f.Close()

	s := bufio.NewScanner(f)
	for s.Scan() {
		fmt.Println(fixdate(s.Text()))
	}

	return nil
}

func fixdate(s string) string {
	layouts := []string{
		"2006-01-02",
		"01/02/06",
		"01#06#02",
		"02*01*2006",
		"Jan 02, 06",
		"Jan 02, 2006",
	}

	for _, l := range layouts {
		t, err := time.Parse(l, s)
		if err == nil {
			if y := t.Year(); y >= 2050 {
				t = t.AddDate(-100, 0, 0)
			}
			return t.Format("2006-01-02")
		}
	}
	return s
}
