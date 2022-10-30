/*

A half-exponential function is one which when composed with itself gives an exponential function. For instance, if f(f(x)) = 2^x, then f would be a half-exponential function. In this challenge, you will compute a specific half-exponential function.

Specifically, you will compute the function from the non-negative integers to the non-negative integers with the following properties:

Monotonically increasing: if x < y, then f(x) < f(y)

At least half-exponential: For all x, f(f(x)) >= 2^x

Lexicographically smallest: Among all functions with the above properties, output the one which minimizes f(0), which given that choice minimizes f(1), then f(2), and so on.

The initial values of this function, for inputs 0, 1, 2, ... are:

[1, 2, 3, 4, 8, 9, 10, 11, 16, 32, 64, 128, 129, 130, 131, 132, 256, 257, ...]

You may output this function via any of the following methods, either as a function or as a full program:

Take x as input, output f(x).

Take x as input, output the first x values of f.

Infinitely output all of f.

If you want to take x and output f(x), x must be zero indexed.

Reference implementation

fn half_exp(n: usize) -> Vec<usize> {
    let mut f: Vec<usize> = vec![0; n];
    if n == 0 { return f }
    f[0] = 1;
    if n == 1 { return f }
    f[1] = 2;
    if n == 2 { return f }
    f[2] = 3;
    for i in 3..n {
        if f[i] == 0 {
            f[i] = f[i-1] + 1;
        }
        let f_i = f[i];
        if f_i < n {
            f[f_i] = (2 as u64).pow(i as u32) as usize
        }
    }
    f
}

fn main() {
    let max = std::env::args().nth(1).unwrap().parse().unwrap();
    let f = half_exp(max);
    println!("{:?}", f);
}

This is code golf - shortest code in bytes wins. Standard loopholes are banned, as always.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

void
halfexp(uvlong n, uvlong *f)
{
	uvlong i;

	memset(f, 0, sizeof(*f) * n);
	f[0] = 1;
	if (n >= 1)
		f[1] = 2;
	if (n >= 2)
		f[2] = 3;

	for (i = 0; i < n; i++) {
		if (f[i] == 0)
			f[i] = f[i - 1] + 1;

		if (f[i] < n)
			f[f[i]] = 1ULL << i;
	}
}

int
main(void)
{
	static const uvlong tab[] = {1, 2, 3, 4, 8, 9, 10, 11, 16, 32, 64, 128, 129, 130, 131, 132, 256, 257};
	uvlong f[128];

	halfexp(nelem(tab), f);
	assert(!memcmp(f, tab, sizeof(tab)));

	return 0;
}
