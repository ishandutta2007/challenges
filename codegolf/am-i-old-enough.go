/*

It is currently December 31, 2015, 11:59:00pm, and you must be at least 1324900 seconds old to be able to go to the New Year Celebration. Given the year, month, day, hour, minute, and second of your birth, determine if you are old enough to go.

Notes:

    Assume that you are in the same timezone.
    Leap years are every 4 years, but if the year is a multiple of 100, it is not a leap year, unless it is a multiple of 400.

Remember, this is code-golf, so the code with the smallest number of bytes wins.
Leaderboards

Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

# Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the leaderboard snippet:

# [><>](http://esolangs.org/wiki/Fish), 121 bytes


*/

package main

import (
	"time"
)

func main() {
	assert(old(time.Time{}) == true)
	assert(old(time.Date(2014, time.January, 31, 2, 59, 0, 0, time.UTC)) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func old(t time.Time) bool {
	p := time.Date(2015, time.December, 31, 23, 59, 0, 0, time.UTC)
	if p.Before(t) {
		return false
	}
	d := p.Sub(t)
	return d.Seconds() >= 1324900
}
