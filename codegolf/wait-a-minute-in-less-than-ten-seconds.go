/*

Task

Using any type of parallelisation, wait multiple periods, for a total sleep time of at least a minute (but less than a minute and a half).

The program/function must terminate within 10 seconds and return (by any means and in any format) two values: the total elapsed time, and the total executed sleep time. Both time values have to have a precision of at least 0.1 seconds.

This is similar to the concept of man-hours: a job that takes 60 hours can be completed in only 6 hours if 10 workers are splitting the job. Here we can have 60 seconds of sleep time e.g. in 10 parallel threads, thus requiring only 6 seconds for the whole job to be completed.
Example

The program MyProgram creates 14 threads, each thread sleeps for 5 seconds:

MyProgram → [5.016,70.105]

The execution time is greater than 5 seconds, and the total sleep time is greater than 70 seconds because of overhead.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(mansleep(14, 70*time.Second))
	fmt.Println(mansleep(15, 10*time.Second))
}

func mansleep(n int, d time.Duration) [2]time.Duration {
	t0 := time.Now()

	ch := make(chan time.Duration, n)
	dt := time.Duration(0)
	dn := d / time.Duration(n)
	for i := 0; i < n; i++ {
		go worker(t0, ch, dn)
	}
	for i := 0; i < n; i++ {
		dt += <-ch
	}

	return [2]time.Duration{
		time.Since(t0),
		dt,
	}
}

func worker(t0 time.Time, ch chan time.Duration, d time.Duration) {
	time.Sleep(d)
	ch <- time.Since(t0)
}
