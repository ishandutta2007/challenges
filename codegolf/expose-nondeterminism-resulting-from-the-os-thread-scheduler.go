/*

As we all know, modern operating systems have thread schedulers that can pick different orders to schedule your threads based on internal logic which your code is not privy to.
Normally you architect your multithreaded code to ensure that this nondeterminism imposed on you does not meaningfully affect your output.

The goal here is the opposite. Produce a program which prints the integers in the interval [0,99] but in an order which will vary from run to run due to the OS thread scheduler.

You must achieve "enough nondeterminism", defined as:

In 10 sequential sets of 10 trials your program must produce at least 9 unique permutations within each trial. You may have a reasonable number of failed sets of trials on either side of the consecutive 10 which succeed.

Or, to put it another way, you need 100 runs of your program where each block of 10 runs has at most two runs which output the same thing.

So, occasionally swapping 98 and 99 won't cut it.

This is a code-golf, so the answer which uses the fewest bytes wins.

Minutiae
Write your output to stdout, one entry per line
If you mangle the format by having two threads interleave character writes to stdout (even occasionally) resulting in things like three digit numbers or empty lines, your result is invalid
The only exception to the above rule is that you may emit a single empty line after printing the last required number (you're welcome)
If you ever miss or duplicate any required values your result is invalid
Your program does not need to be nondeterministic on a single core processor (though kudos if it is)
Your program may use green threads/fibers which are not actually managed by the OS kernel iff it still meets the other requirements of the challenge and the threading system is part of your language or the standard library for your language
Runtime for your program must be reliably under 5 seconds on a modern processor
You do not get to specify changes to the environment which happen outside of your program such as waits or settings changes;
your program should pass whether run 100ish times back to back or with an hour between each run or 100ish times in parallel (that would probably help actually...)
You may use a coprocessor such as a GPU or Xeon Phi and its own internal scheduling mechanism for tasks. The rules apply to this the same way they apply to green threads.
Feel free to provoke the scheduler with all manner of sleeps, yields, and other tricks as long as you obey the rules specified in this post
Banned Operations
The only source of nondeterminism you are allowed to draw on is when the scheduler schedules your threads to run.
The following list is not exhaustive, intended only to provides examples of things you are not allowed to do as they admit other sources of nondeterminism.

Directly or indirectly accessing any sort of PRNG or hardware RNG capability (unless it is as an inherent part of the scheduler).
Reading in any kind of input (system time, filesystem, network, etc.)
Reading thread IDs or Process IDs
Customizing the OS scheduler; you must use a standard OS scheduler from a mainstream OS
Customizing your green thread/fiber scheduler is also prohibited. This means that if you write a language for this challenge you must use OS threads.
Answer Validation
Preferably an answer would work across all common OSes and modern processors, with kudos awarded proportional to the breadth of support.
However, this is not a requirement of the challenge.
At a minimum an answer must support one modern SMP processor and modern OS. I'll test leading answers to the extent of my hardware availability.

If your entry will not produce the required output on an i7 5960x running Windows 10 v1607 x64, specify the environment required
If it's something I can easily reproduce with VMWare Workstation, provide the exact OS and VM specs
If it can't be produced in under either of those conditions, record a simultaneous screen capture of the test as described in the header section and a handheld video
recording of your screen with your mouse and keyboard interaction (or whatever control scheme your nonstandard computation device uses) clearly visible and post both videos along with your answer and include an explanation of why it works
Alternately, get a reputable long-standing user (who is not you) with matching hardware to reproduce the result and vouch for you
If your entry is in an exotic programming language that a typical developer won't be set up to compile/jit/interpret, provide setup instructions
If you entry depends on a specific version of the JVM/Python interpreter/other, specify which
If it takes more than 10 minutes of back-to-back runs to get your 10 successful sequential sets of trials in my testing you fail (so don't let the success condition be a freak occurrence, especially if you're near the upper runtime bound)

*/

package main

import (
	"fmt"
	"reflect"
	"runtime"
	"sync"
)

func main() {
	ncpu := runtime.NumCPU()

	var r [][]int
	for i := 0; i < 100; i++ {
		r = append(r, sim(ncpu, ncpu*100))
	}

	n := len(r)
	d := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if reflect.DeepEqual(r[i], r[j]) {
				d++
			}
		}
	}
	fmt.Printf("%d duplicates\n", d)
}

func sim(n, m int) []int {
	var (
		r  []int
		mu sync.Mutex
		wg sync.WaitGroup
	)
	wg.Add(n)
	for i := 0; i < n; i++ {
		go runner(&r, m, i, &mu, &wg)
	}
	wg.Wait()

	return r
}

func runner(r *[]int, n, i int, mu *sync.Mutex, wg *sync.WaitGroup) {
	defer wg.Done()

	ncpu := runtime.NumCPU()
	quit := false
	for !quit {
		mu.Lock()
		if len(*r) >= n {
			quit = true
		} else {
			*r = append(*r, i)
		}
		mu.Unlock()

		for i := 0; i < ncpu*2; i++ {
			runtime.Gosched()
		}
	}
}
