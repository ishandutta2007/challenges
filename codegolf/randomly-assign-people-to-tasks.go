/*

The challenge is to assign people to tasks randomly~.
From stdin you get 2 lines.
Line one is a comma-separated list of names.
Line 2 is a comma-separated list of jobs.
The output required is one line per task person combo.
The line should be formatted as Name:task.
If there are not enough people for jobs or vice verse then they will not be output.

~ Randomly is defined as each run with the same input has a reasonably different output.

Example Input:

Bob,John,Susan,Josie,Kim,Tom
Bins,Floor,Windows
Example Output:

Bob:Windows
Susan:Bins
Kim:Floor

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	assign(
		[]string{"Bob", "John", "Susan", "Josie", "Kim", "Tom"},
		[]string{"Bins", "Floor", "Windows"},
	)
}

func assign(names, jobs []string) {
	for {
		n := len(names)
		m := len(jobs)
		if n == 0 || m == 0 {
			break
		}

		i := rand.Intn(n)
		j := rand.Intn(m)
		fmt.Printf("%s: %s\n", names[i], jobs[j])

		names[i], names = names[n-1], names[:n-1]
		jobs[j], jobs = jobs[m-1], jobs[:m-1]
	}
}
