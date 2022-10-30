/*

Background

Person of Interest is a crime drama on CBS, and my favorite TV show, as of late.

The show is about a man named Harold Finch, a billionaire programmer, and his partner John Reese, a special forces veteran and ex-CIA operative. This programmer created a sentient AI called "The Machine" that predicts violent crimes before they happen. It tracks every person on Earth at all times by monitoring and analyzing all surveillance cameras and electronic communications across the globe.

Harold built The Machine for the United States government to detect terrorist activity before-the-fact. It divides the crimes that it predicts into lists based on whether or not they are relevant to national security. The relevant cases are handled by the government, while the "irrelevant" list is programmed to be deleted daily.

Harold made a small backdoor for himself in hopes to deal with the "irrelevant" list, himself. This backdoor causes The Machine to call the payphone nearest Harold (once every day or so) and read a Social Security number to him. This SSN belongs to someone whose life is in danger as part of a premeditated crime, or of someone who is planning such a crime.
The Challenge

Write a program that takes no input, and outputs 30 random phone numbers & SSNs (see below).
Output

There are two lines of text that will be printed every "day".

    Crime predicted: 555-55-5555
    Calling: 1-555-555-5555 followed by a newline

This process should repeat for one "month" (30 "days").
Phone Numbers

Every phone number must have the following elements:

    Must have the United States country code (the first digit).

    Must have a random area code (first set of three digits).

    The first three digits of the phone number itself should be 555, followed then by 4 random digits.

Here is an annotated example:

1-814-555-3857
|  |   |   |
|  |   |   |
|  |   |   +---------->   random four digits
|  |   |
|  |   +-------------->   the set 555
|  |
|  +------------------>   area code
|
+--------------------->   country code

Social Security Numbers

Every SSN must be 9 random digits in the following format.

342-98-1613

Example

Crime predicted: 234-72-8311
Calling: 1-633-555-0188

Crime predicted: 135-77-0910
Calling: 1-202-555-4719

Crime predicted: 722-90-6653
Calling: 1-466-555-1069

...

Continuing for 27 more cycles.
Scoreboard

For your score to appear on the board, it should be in this format:

# Language, Bytes

Strikethroughs shouldn't cause a problem.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	gen(30)
}

func gen(n int) {
	r := RNG(10)
	for i := 0; i < n; i++ {
		fmt.Printf("Crime predicted: %v%v%v-%v%v-%v%v%v%v\n", r, r, r, r, r, r, r, r, r)
		fmt.Printf("Calling: 1-%v%v%v-555-%v%v%v%v\n", r, r, r, r, r, r, r)
		fmt.Printf("\n")
	}
}

type RNG int

func (r RNG) String() string {
	return fmt.Sprintf("%d", rand.Intn(int(r)))
}
