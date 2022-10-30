/*

Background
IEEE 754 Double-precision floating-point format is a way to represent real numbers with 64 bits. It looks like the following:

A real number n is converted to a double in the following manner:

The sign bit s is 0 if the number is positive, 1 otherwise.
The absolute value of n is represented in the form 2**y * 1.xxx, i.e. a power-of-2 times a base.
The exponent e is y (the power of 2) plus 1023.
The fraction f is the xxx part (fractional part of the base), taking the most significant 52 bits.
Conversely, a bit pattern (defined by sign s, exponent e and fraction f, each an integer) represents the number:

(s ? -1 : 1) * 2 ** (e - 1023) * (1 + f / (2 ** 52))
Challenge
Given a real number n, output its 52-bit fraction part of the double representation of n as an integer.

Test Cases
0.0        =>                0
16.0       =>                0
0.0625     =>                0
1.2        =>  900719925474099 (hex 3333333333333)
3.1        => 2476979795053773 (hex 8cccccccccccd)
3.5        => 3377699720527872 (hex c000000000000)
10.0       => 1125899906842624 (hex 4000000000000)
1234567.0  =>  798825262350336 (hex 2d68700000000)
1e-256     => 2258570371166019 (hex 8062864ac6f43)
1e+256     => 1495187628212028 (hex 54fdd7f73bf3c)

-0.0       =>                0
-16.0      =>                0
-0.0625    =>                0
-1.2       =>  900719925474099 (hex 3333333333333)
-3.1       => 2476979795053773 (hex 8cccccccccccd)
-3.5       => 3377699720527872 (hex c000000000000)
-10.0      => 1125899906842624 (hex 4000000000000)
-1234567.0 =>  798825262350336 (hex 2d68700000000)
-1e-256    => 2258570371166019 (hex 8062864ac6f43)
-1e+256    => 1495187628212028 (hex 54fdd7f73bf3c)

You can check other numbers using this C reference which uses bit fields and a union.
#include <stdint.h>
#include <stdio.h>

typedef union {
  double d;
  struct {
    uint64_t f:52;
    uint64_t e:11;
    uint64_t s:1;
  };
} X;

double a[] = {0.0, 1.2, 3.1, 3.5, 10.0, 1234567.0, 1e-256, 1e256};

main() {
  for (int i = 0; i < 8; ++i) {
    X x = {.d=a[i]};
    printf("%lf %lld %013llx\n", x.d, x.f, x.f);
    X y = {.d=-a[i]};
    printf("%lf %lld %013llx\n", y.d, y.f, y.f);
  }
}

Note that the expected answer is the same for +n and -n for any number n.

Input and Output
Standard rules apply.

Accepted input format:

A floating-point number, at least having double precision internally
A string representation of the number in decimal (you don't need to support scientific notation, since you can use 1000...00 or 0.0000...01 as input)
For output, a rounding error at the least significant bit is tolerable.

Winning Condition
This is code-golf, so the lowest bytes in each language wins.

*/

package main

import (
	"math"
)

func main() {
	assert(dblfi(0.0) == 0)
	assert(dblfi(16.0) == 0)
	assert(dblfi(0.0625) == 0)
	assert(dblfi(1.2) == 900719925474099)
	assert(dblfi(3.1) == 2476979795053773)
	assert(dblfi(3.5) == 3377699720527872)
	assert(dblfi(10.0) == 1125899906842624)
	assert(dblfi(1234567.0) == 798825262350336)
	assert(dblfi(1e-256) == 2258570371166019)
	assert(dblfi(1e+256) == 1495187628212028)

	assert(dblfi(-0.0) == 0)
	assert(dblfi(-16.0) == 0)
	assert(dblfi(-0.0625) == 0)
	assert(dblfi(-1.2) == 900719925474099)
	assert(dblfi(-3.1) == 2476979795053773)
	assert(dblfi(-3.5) == 3377699720527872)
	assert(dblfi(-10.0) == 1125899906842624)
	assert(dblfi(-1234567.0) == 798825262350336)
	assert(dblfi(-1e-256) == 2258570371166019)
	assert(dblfi(-1e+256) == 1495187628212028)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dblfi(x float64) uint64 {
	return math.Float64bits(x) & ((1 << 52) - 1)
}
