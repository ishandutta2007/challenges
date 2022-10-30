/*

Almost all operating systems allow you to run multiple programs at the same time.
If your system does not have enough processors to run all the programs you want to run, it starts to give each program just a tiny slice of time on the processor it runs on.
This is normally not noticeable but can lead to strange artefacts that you might not expect.

Your task is to write a program that tries to find out how many cores your computer has without asking the operating system. This is a popularity contest, the most upvoted solution wins. Here are the constraints:

While you cannot expect that your submission is the only thing that runs, you may expect that all other programs on the system are idling and wake up only sporadically.
You may not ask the operating system how many cores your computer has. Neither may you look up this number from any configuration file or similar. You may also not invoke a utility that provides you with that information.
For the sake of this challenge, the number of cores your computer has is the number of processes your computer can run at the same time. For instance, if you have an Intel processor with 2 cores and hyper threading, that would count as 4 cores.
Your solution needs not to be precise. It should not be terribly wrong all the time though.

*/

package main

import (
	"fmt"
	"math"
	"sync"
	"time"
)

func main() {
	var (
		x  uint64
		y  []uint64
		wg sync.WaitGroup
	)
	count(&x, nil)
	for i := 2; ; i++ {
		y = make([]uint64, i)
		wg.Add(i)
		for j := 0; j < i; j++ {
			go count(&y[j], &wg)
		}
		wg.Wait()

		r := float64(sum(y)) / float64(x)
		c := int(math.Round(r))
		if c != i {
			fmt.Printf("estimated number of cores: %v\n", c)
			break
		}
	}
}

func count(r *uint64, wg *sync.WaitGroup) {
	c := uint64(0)
	t0 := time.Now()
	for {
		c += 1
		dt := time.Since(t0)
		if dt >= 1*time.Second {
			break
		}
	}

	*r = c
	if wg != nil {
		wg.Done()
	}
}

func sum(a []uint64) uint64 {
	r := uint64(0)
	for i := range a {
		r += a[i]
	}
	return r
}
