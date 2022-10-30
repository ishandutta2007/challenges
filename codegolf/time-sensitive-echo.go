/*

Background

The echo program is so neat. You can say anything to it, and it repeats your words perfectly, every time!
How cool is that! Disappointingly, it repeats the input all at once, regardless of your typing speed, which is not very realistic.
We'll have to fix that.

The Task

Your program shall take its input from STDIN or closest equivalent. It shall read lines from the user one by one, possibly displaying some prompt, until they enter an empty line.
After that, it shall print the lines to STDOUT or closest equivalent, in the same order as they were given.
The last (empty) line is not printed, and the last printed line doesn't need to have a trailing newline.

Additionally, the program shall preserve the time intervals between each line: if it took the user x seconds to enter a line, it shall take x seconds for the program to print it.
This applies to the first and last lines too; the empty line is not printed, but the program waits anyway before terminating.

Example
Here's an example session with the program. All actions that don't produce text are described in brackets, and the (optional) prompt is displayed as >.

[begin program]
> fhtagn[enter; 1.48s passed since starting program]
> yum yum[enter; 3.33s passed since previous enter]
> so cool![enter; 2.24s passed since previous enter]
> [enter; 0.23s passed since previous enter]
[wait 1.48s]fhtagn
[wait 3.33s]yum yum
[wait 2.24s]so cool!
[wait 0.23s, then end program]
Without the actions, the session looks like this:

> fhtagn
> yum yum
> so cool!
>
fhtagn
yum yum
so cool!

Rules and Scoring
The waiting times should be accurate to within 0.01 seconds (in practice, if the average human can't tell the difference, you're fine).
The lowest byte count wins, and standard loopholes are disallowed.
If your language has a built-in function for precisely this task, you may not use it.

*/

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"time"
)

func main() {
	echo(os.Stdin)
}

func echo(r io.Reader) {
	p := []record{}
	s := bufio.NewScanner(r)
	t0 := time.Now()
	for s.Scan() {
		l := s.Text()
		if l == "" {
			break
		}

		t1 := time.Now()
		dt := t1.Sub(t0)
		t0 = t1

		p = append(p, record{l, dt})
	}

	for _, p := range p {
		time.Sleep(p.delay)
		fmt.Println(p.line)
	}
}

type record struct {
	line  string
	delay time.Duration
}
