/*

TASK
print integers n, where 12 <= n <= 123456789, and all pairs of consecutive digits in n have the same positive difference between them (e.g. 2468 but not 2469).

NO INPUT.
Output:
12
13
14
15
16
17
18
19
23
24
25
26
27
28
29
34
35
36
37
38
39
45
46
47
48
49
56
57
58
59
67
68
69
78
79
89
123
135
147
159
234
246
258
345
357
369
456
468
567
579
678
789
1234
1357
2345
2468
3456
3579
4567
5678
6789
12345
13579
23456
34567
45678
56789
123456
234567
345678
456789
1234567
2345678
3456789
12345678
23456789
123456789

Rules
Standard loopholes apply.
no input
shortest code wins.

Credits anarchy golf

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

int
diff(uvlong n)
{
	int x, y;

	x = (n % 10);
	y = (n / 10) % 10;
	return x - y;
}

int
hoppy(uvlong n)
{
	int d;

	d = diff(n);
	for (n /= 10; n >= 10; n /= 10) {
		if (d != diff(n))
			return 0;
	}
	return d > 0;
}

size_t
gen(uvlong n, uvlong m, uvlong *r)
{
	uvlong i;
	size_t l;

	l = 0;
	for (i = n; i <= m; i++) {
		if (hoppy(i))
			r[l++] = i;
	}
	return l;
}

int
main(void)
{
	static const uvlong tab[] = {
	    12ULL,
	    13ULL,
	    14ULL,
	    15ULL,
	    16ULL,
	    17ULL,
	    18ULL,
	    19ULL,
	    23ULL,
	    24ULL,
	    25ULL,
	    26ULL,
	    27ULL,
	    28ULL,
	    29ULL,
	    34ULL,
	    35ULL,
	    36ULL,
	    37ULL,
	    38ULL,
	    39ULL,
	    45ULL,
	    46ULL,
	    47ULL,
	    48ULL,
	    49ULL,
	    56ULL,
	    57ULL,
	    58ULL,
	    59ULL,
	    67ULL,
	    68ULL,
	    69ULL,
	    78ULL,
	    79ULL,
	    89ULL,
	    123ULL,
	    135ULL,
	    147ULL,
	    159ULL,
	    234ULL,
	    246ULL,
	    258ULL,
	    345ULL,
	    357ULL,
	    369ULL,
	    456ULL,
	    468ULL,
	    567ULL,
	    579ULL,
	    678ULL,
	    789ULL,
	    1234ULL,
	    1357ULL,
	    2345ULL,
	    2468ULL,
	    3456ULL,
	    3579ULL,
	    4567ULL,
	    5678ULL,
	    6789ULL,
	    12345ULL,
	    13579ULL,
	    23456ULL,
	    34567ULL,
	    45678ULL,
	    56789ULL,
	    123456ULL,
	    234567ULL,
	    345678ULL,
	    456789ULL,
	    1234567ULL,
	    2345678ULL,
	    3456789ULL,
	    12345678ULL,
	    23456789ULL,
	    123456789ULL,
	};

	uvlong r[128];
	uvlong n;

	n = gen(12ULL, 123456789ULL, r);
	assert(n == nelem(tab));
	assert(!memcmp(r, tab, sizeof(tab)));

	return 0;
}
