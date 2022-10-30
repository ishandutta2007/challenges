/*

π(n) is the number of primes less than or equal to n.

Input: a natural number, n.

Output: π(n).

Scoring: This is a fastest-code challenge. Score will be the sum of times for the score cases. I will time each entry on my computer.

Rules and Details

    Your code should work for n up to 2 billion ( 2,000,000,000 ).

    Built-ins that trivialize this are not allowed. This includes built in π functions or lists of values for π(n).

    Built-ins that test primality or generate primes are not allowed.
	This includes lists of primes, which may not be looked up externally or hardcoded locally, except with regards to the next bullet point.

    You may hardcode primes up to and including 19 and no higher.

    your implementation of π should be deterministic. This means that given a specific n, your code should run in (approximately) the same amount of time.

    Languages used must be freely available on Linux (Centos 7). Instructions should be included on how to run your code. Include compiler/interpreter details if necessary.

    Official times will be from my computer.

    When posting, please include a self-measured time on some/all of the test/score cases, just to give me an estimate of how fast your code is running.

    Submissions must fit in an answer post to this question.

    I am running 64bit centos7. I only have 8GB of RAM and 1GB swap. The cpu model is: AMD FX(tm)-6300 Six-Core Processor.

Test cases(source):

Input        Output
90           24
3000         430
9000         1117
4000000      283146           <--- input = 4*10^6
800000000    41146179         <--- input = 9*10^8
1100000000   55662470         <--- input = 1.1*10^9

Score Cases (same source)

As usual, these cases are subject to change. Optimizing for the scoring cases is not permitted. I may also change the number of cases in an effort to balance reasonable run times and accurate results.

Input        Output
1907000000   93875448         <--- input = 1.907*10^9
1337000000   66990613         <--- input = 1.337*10^9
1240000000   62366021         <--- input = 1.24*10^9
660000000    34286170         <--- input = 6.6*10^8
99820000     5751639          <--- input = 9.982*10^7
40550000     2465109          <--- input = 4.055*10^7
24850000     1557132          <--- input = 2.485*10^7
41500        4339

Duration

Since this is a fastest-code challenge and entries are to be run on my computer, I reserve the right to stop timing entries after 2 weeks.
After this point, entries are still accepted, but there is no guarantee that they are officially timed.

Having said this, I don't expect too many answers to this challenge and I will likely continue to time new answers indefinitely.

Scoring Particulars

I timed the faster entries with the following script:

#!/bin/bash

a=(1907000000 1337000000 1240000000 660000000 99820000 40550000 24850000 41500)

echo DennisC
exec 2>> times/dennisc.txt
time for j in ${a[@]}; do ./dennisc $j; done >> /dev/null;

echo DennisPy
exec 2>> times/dennispy.txt
time for j in ${a[@]}; do pypy dennispy.py <<< $j; done >> /dev/null;

echo arjandelumens
exec 2>> times/arjandelumens.txt
time for j in ${a[@]}; do ./arjandelumens $j; done >> /dev/null;

echo orlp
exec 2>> times/orlp.txt
time for j in ${a[@]}; do ./orlp $j; done >> /dev/null;

# echo mwr247
# time node-v4.3.1-linux-x64/bin/node mwr247.js

# mwr247 using js seems a bit longer, so I am going to run the fastest
# and then come back to his.

# mwr247 provided a function, so I appended
# console.log( F( <argument> ) )
# to his code, for each argument.

time writes to stderr, so I sent stderr to a log file using exec 2 >> <filename>.
You may notice that stdout is sent to /dev/null.
This isn't a problem, because I already verified that the programs were producing the correct output.

I ran the above timeall.sh script 10 times using for i in {1..10}; do ./timeall.sh; done;

I then averaged the real time score for each entry.

Note that no other programs were running on my computer while timing.

Also, the official times have been appended to each entry. Please double check your own average.

*/

package main

import (
	"math/big"
	"runtime"
	"sync"
	"sync/atomic"
)

func main() {
	tab := [][2]int64{
		{90, 24},
		{3000, 430},
		{9000, 1117},
		{4000000, 283146},
		{800000000, 41146179},
		{1100000000, 55662470},

		{41500, 4339},
		{24850000, 1557132},
		{40550000, 2465109},
		{99820000, 5751639},
		{660000000, 34286170},
		{1240000000, 62366021},
		{1337000000, 66990613},
		{1907000000, 93875448},
	}
	for _, v := range tab {
		assert(numprimes(v[0]) == v[1])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func numprimes(n int64) int64 {
	if n < 2 {
		return 0
	}
	if n == 2 {
		return 1
	}

	var (
		wg sync.WaitGroup
		c  = make([]int64, runtime.NumCPU())
		p  = int64(1)
	)
	wg.Add(len(c))
	for i := range c {
		go count(&c[i], &p, n, &wg)
	}
	wg.Wait()

	r := int64(1)
	for i := range c {
		r += c[i]
	}
	return r
}

func count(c, p *int64, n int64, wg *sync.WaitGroup) {
	r := int64(0)
	x := new(big.Int)
	for {
		v := atomic.AddInt64(p, 2)
		if v > n {
			break
		}
		x.SetInt64(v)

		if x.ProbablyPrime(1) {
			r++
		}
	}

	*c = r
	wg.Done()
}
