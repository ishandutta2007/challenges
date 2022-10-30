/*

Computers are everywhere nowadays - in cars, trains, skateboards, even nuclear reactors.
The possibility that your software will run in a time travelling device is just a matter of time.
Can you deal with it? Can you at least detect it?

Your task:

Write a program that loops and keeps querying the system time, in order to detect time travel.
If time moves forward a day or more between two consecutive queries, it's forward time travel. In this case, your program should print:
TS TS: YYYY? You mean we're in the future?
If time moves back, by any amount, between two consecutive queries, it's backward time travel. In this case, your program should print:
TS TS: Back in good old YYYY.
TS TS are the timestamps before and after the time travel. YYYY is the destination year.
Timestamps may be in any format, that includes at least the 4-digit year, month, day, hour, minute and second, separated by non-digits.
Limitations:

You must support dates in the 19th, 20th and 21st centuries, at least.
You must use a language that existed before this challenge was posted.
You must post your answers only after this challenge was posted.
You must use a language that existed before your answer was posted.
You may edit your answer only after you've posted it.
Your program must not print any output other than the required output. An occasional "Great Scott!" is allowed.
This is code-golf. The shortest answer wins.
Relevant movie references will probably make your answer too long, but might get you upvotes.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	detect()
}

func detect() {
	t0 := time.Now()
	for {
		time.Sleep(1 * time.Second)

		t1 := time.Now()
		d0 := t0.Day()
		d1 := t1.Day()
		y1 := t1.Year()

		s0 := t0.Format("2006/01/02")
		s1 := t1.Format("2006/01/02")

		if rand.Intn(10000) == 9999 {
			fmt.Println("%v %v: Great Scott!\n", s0, s1)
		}

		if t1.Before(t0) {
			fmt.Printf("%v %v: Back in good old %v.\n", s0, s1, y1)
		} else if d0 != d1 {
			fmt.Printf("%v %v: %v? You mean we're in the future?\n", s0, s1, y1)
		}

		t0 = t1
	}
}
