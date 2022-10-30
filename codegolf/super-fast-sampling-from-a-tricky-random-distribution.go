/*

This is a micro-optimization challenge. The task is to sample from the maximally skewed stable distribution F(x;1,-1,Pi/2,0).
See Table 1 of http://arxiv.org/pdf/0908.3961v2.pdf .
It is easiest to describe how to do this using the following C code which uses the Mersenne Twister RNG C code from here .

#include <stdio.h>
#include <stdlib.h>
#include "mtwist.h"
#include <math.h>


int main(void) {
   int i;
   volatile double x;
   mt_seed();
   double u1;
   double u2;
   double w1;
   double w2;
   for(i = 0; i < 100000000; ++i) {
     u1 = mt_drand();
     u2 = mt_drand();
     w1 = M_PI*(u1-1/2.0);
     w2 = -log(u2);
     x = tan(w1)*(M_PI_2-w1)+log(w2*cos(w1)/(M_PI_2-w1));
   }
   return EXIT_SUCCESS;
}
I compile with

gcc -Wall -O3 random.c mtwist-1.5/mtwist.c -o random -lm
The running time is 20 seconds taking 5,000,000 iterations per second.

There are two obvious ways of making this fast. The first is to choose a very fast uniform random number generator.
If you choose to use anything but the Mersenne twister then you must run it through the Diehard tests and check the P-values provided.
Use the code here http://www.stat.fsu.edu/pub/diehard/ to do this. Your uniform random number generator must pass at least 15 of these tests.

The second way is to find fast micro-optimizations for the transcendental functions, perhaps using some CPU specific features. For example in my case these features of the AMD FX-8350 CPU.

Rules The code must maintain at least 32 bits of accuracy throughout. The code should be compilable on ubuntu using easy to install free software only.
Please provide full compile and run instructions.
You should also provide a diehard log for any non Mersenne twister RNGs as was done for Build a random number generator that passes the Diehard tests . Note the very simple RNG that passes 15 tests in that link.

Scores You can report your score as the time taken by the code above divided by the time taken by your code on your own machine.
For running your code you can use any compiler and compilation options you like. To test the code above you should use gcc 4.8 or later with -O3.
If any submission take less than one second I will increase N by factors of 10 until the fastest submission takes longer than 1 second.

Test machine My test machine was a standard 8GB RAM ubuntu install on an AMD FX-8350 Processor. Your machine can be anything that supports gcc 4.8 or later.

The Intel optimization manual says

If there is no critical need to evaluate the transcendental functions using the extended precision of 80 bits, applications should consider an alternate, software-based approach, such as a look-up-table-based algorithm using interpolation techniques.
It is possible to improve transcendental performance with these techniques by choosing the desired numeric precision and the size of the look-up table, and by taking advantage of the parallelism of the SSE and the SSE2 instructions.

According to this very helpful table,fcos has latency 154 and fptan has latency 166-231 on my AMD FX 8350.

*/

package main

import (
	"math"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 100000000; i++ {
		skew()
	}
}

func skew() float64 {
	u1 := rand.Float64()
	u2 := rand.Float64()
	w1 := math.Pi * (u1 - 0.5)
	w2 := -math.Log(u2)
	return math.Tan(w1)*(math.Pi*0.5-w1) + math.Log(w2*math.Cos(w1)/(math.Pi*0.5-w1))
}
