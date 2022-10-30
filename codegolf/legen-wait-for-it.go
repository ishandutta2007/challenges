/*

In events entirely unrelated to what will hopefully happen to me in the next couple of days, I task you to write code that does the following:

Print

Legen... wait for it...

immediately, with a trailing newline.

Wait until the next full hour (when the cron job for awarding the badge runs).

Print

dary!

with an optional trailing newline.

Additional rules

You may write a program or a function, but the output has to be printed to STDOUT (or its closest alternative of your language).

You have to wait until the next full hour, not just for 60 minutes. If the code is run at 6:58, it should print the second line at 7:00.

The last line must be printed no later than one second after the next full hour.

In the event that the program is started in the first second of a full hour, it should it wait for the next full hour.

You may query local or UTC time.

Standard code-golf rules apply.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("Legen... wait for it...")
	time.Sleep(1 * time.Hour)
	fmt.Println("dary!")
}
