/*

What better problem for PCG.SE than to implement PCG, A Better Random Number Generator? This new paper claims to present a fast, hard-to-predict, small, statistically optimal random number generator.

Its minimal C implementation is just about nine lines:

// *Really* minimal PCG32 code / (c) 2014 M.E. O'Neill / pcg-random.org
// Licensed under Apache License 2.0 (NO WARRANTY, etc. see website)

typedef struct { uint64_t state;  uint64_t inc; } pcg32_random_t;

uint32_t pcg32_random_r(pcg32_random_t* rng)
{
    uint64_t oldstate = rng->state;
    // Advance internal state
    rng->state = oldstate * 6364136223846793005ULL + (rng->inc|1);
    // Calculate output function (XSH RR), uses old state for max ILP
    uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

(from: http://www.pcg-random.org/download.html)

The question is: can you do better?
Rules

Write a program or define a function that implements PCG on 32-bit unsigned integers. This is fairly broad: you could print out an infinite sequence, define a pcg32_random_r function and corresponding struct, etc.

You must be able to seed your random number generator equivalently to the following C function:

// pcg32_srandom(initstate, initseq)
// pcg32_srandom_r(rng, initstate, initseq):
//     Seed the rng.  Specified in two parts, state initializer and a
//     sequence selection constant (a.k.a. stream id)

void pcg32_srandom_r(pcg32_random_t* rng, uint64_t initstate, uint64_t initseq)
{
    rng->state = 0U;
    rng->inc = (initseq << 1u) | 1u;
    pcg32_random_r(rng);
    rng->state += initstate;
    pcg32_random_r(rng);
}

(from: pcg_basic.c:37)

Calling the random number generator without seeding it first is undefined behaviour.

To easily check your submission, verify that, when seeded with initstate = 42 and initseq = 52, the output is 2380307335:

$ tail -n 8 pcg.c
int main()
{
    pcg32_random_t pcg;
    pcg32_srandom_r(&pcg, 42u, 52u);

    printf("%u\n", pcg32_random_r(&pcg));
    return 0;
}
$ gcc pcg.c
$ ./a.out
2380307335

Scoring

Standard scoring. Measured in bytes. Lowest is best. In case of tie, earlier submission wins. Standard loopholes apply.
Sample solution

Compiles under gcc -W -Wall cleanly (version 4.8.2).

Compare your submission to this to make sure you get the same sequence.

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct { uint64_t state;  uint64_t inc; } pcg32_random_t;

uint32_t pcg32_random_r(pcg32_random_t* rng)
{
    uint64_t oldstate = rng->state;
    // Advance internal state
    rng->state = oldstate * 6364136223846793005ULL + (rng->inc|1);
    // Calculate output function (XSH RR), uses old state for max ILP
    uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

void pcg32_srandom_r(pcg32_random_t* rng, uint64_t initstate, uint64_t initseq)
{
    rng->state = 0U;
    rng->inc = (initseq << 1u) | 1u;
    pcg32_random_r(rng);
    rng->state += initstate;
    pcg32_random_r(rng);
}

int main()
{
    size_t i;
    pcg32_random_t pcg;
    pcg32_srandom_r(&pcg, 42u, 52u);

    for (i = 0; i < 16; i++)
    {
        printf("%u\n", pcg32_random_r(&pcg));
    }
    return 0;
}

Sequence:

2380307335
948027835
187788573
3952545547
2315139320
3279422313
2401519167
2248674523
3148099331
3383824018
2720691756
2668542805
2457340157
3945009091
1614694131
4292140870

*/

package main

import "fmt"

func main() {
	var pcg PCG32
	pcg.Seed(42, 52)
	for i := 0; i < 16; i++ {
		fmt.Println(pcg.Next())
	}
}

type PCG32 struct {
	state uint64
	inc   uint64
}

func (r *PCG32) Seed(state, inc uint64) {
	r.state = 0
	r.inc = (inc << 1) | 1
	r.Next()
	r.state += state
	r.Next()
}

func (r *PCG32) Next() uint32 {
	oldstate := r.state
	r.state = oldstate*6364136223846793005 + (r.inc | 1)
	xorshifted := ((oldstate >> 18) ^ oldstate) >> 27
	rot := oldstate >> 59
	return uint32((xorshifted >> rot) | (xorshifted << ((-rot) & 31)))
}
