/*

Premise:

For those in networking, you've most likely sent a ping to or from some device to make sure everything's properly connected. Cisco, a popular company in networking[citation needed], has a command for it in their IOS that looks like this:

Capture

(Image source)

Your challenge is to graphically recreate a portion of this. The portions we are skipping are the first line (Type escape sequence to abort.) entirely, along with the IP address and round-trip times.

You will start by outputting the following:

Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:
You will then simulate the echo requests going out. Each request will start by waiting 2 seconds and then generating the response.
A successful echo response is represented by a !, a failed one by .. We won't actually be sending packets but to represent packet loss, your program must randomly choose between the two options with a non-zero chance for each.
This line will start empty and each tick will add another character.

After the fifth echo, the percentage line will be outputted and the program should then terminate. The percentage line will be in the format of

Success rate is $p percent ($s/5)
where $p is in regex 0|20|40|60|80|100 and $s is the number of successful echos. The screen must be updated after each wait period by either redrawing the new state or appending to the existing echo line. This includes the Sending line.

Example run: (The tick count should not be displayed and is there to clarify what the output should look like at each time step)

#Tick 0
Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:

#Tick 1
Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:
.

#Tick 2
Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:
.!

#Tick 3
Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:
.!.

#Tick 4
Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:
.!.!

#Tick 5
Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:
.!.!.
Success rate is 40 percent (2/5)
Input:
No usable input provided.

Output:
Any reasonable format. An example final output looks like this:

Sending 5, 100-byte ICMP Echos, timeout is 2 seconds:
...!!
Success rate is 40 percent (2/5)

Rules:

You must either append to the echo line or redraw the screen after each tick.
! and . do not have to be equally likely, just both possible.
Successive runs must be able to generate different results
Gifs or webms of your output would be cool. No bonus or anything for it though.

Standard Loopholes forbidden

This is code-golf

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	simulate(5, 0.7, 2)
}

func simulate(trials int, prob float64, secs time.Duration) {
	success := 0
	fmt.Printf("Sending %d, 100-byte ICMP Echos, timeout is %d seconds:\n", trials, secs)
	for i := 0; i < trials; i++ {
		time.Sleep(secs * time.Second)
		if rand.Float64() < prob {
			fmt.Printf("!")
			success++
		} else {
			fmt.Printf(".")
		}
	}
	fmt.Println()
	fmt.Printf("Success rate is %.2f percent (%d/%d)\n", float64(success)/float64(trials), success, trials)
}
