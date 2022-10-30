/*

Introduction
The middle-square method is used for the generation of pseudorandom numbers. However, this is not a good method in practice, since its period is usually very short and has some severe weaknesses. How does this work? Let's take an example:

For the seed, we pick 123456:

Seed     123456
The seed squared (seed × seed), is equal to:

Seed²  15241383936
We started with a 6-digit number. That means that the seed squared should deliver a 12-digit number. If this is not the case, leading zeroes are added to compensate:

Seed²  015241383936
We then take the middle part of the number, with the same size as the seed:

Seed²  015241383936
          ^^^^^^
This is then our new seed: 241383. We repeat the same process as shown above. We get the following:

0:     123456
    015241383936
       |    |
1:     241383
    058265752689
       |    |
2:     265752
    070624125504
       |    |
3:     624125
    389532015625
       |    |
4:     532015
    283039960225
       |    |
5:     039960
    001596801600
       |    |
6:     596801
And this keeps on in a while... Now we know what the middle-square method is, let's get to the challenge:

The Task
Every seed has a period. The period of a n-digit seed cannot be longer than 8n. For example, the seed 82. This would give the following sequence:

82 > 72 > 18 > 32 > 02 > 00 > 00 > 00 > 00 > 00
|____|____|____|____|____|____|____|____|____|___...
0    1    2    3    4    5    6    7    8    9
You can see that the period is equal to 5, before containing the same digit again. Your task is, when given a seed greater than 0 containing no leading zeroes, output the period of the seed. So, in this case, you need to output 5.

Another example is: 24, which gives the following:

24 > 57 > 24
|____|____|___...
0    1    2
As you can see, not all sequences end in 0. This cycle has a period of 1.

Test cases
Input   >   Output
24      >   1
82      >   5
123456  >   146
8989    >   68
789987  >   226
The pastebins with the sequences for 123456, 8989, 789987

This is code-golf, so the submission with the least amount of bytes wins!

You can assume that the input will never have an uneven number of digits.

*/

#include <cassert>
#include <map>

using namespace std;

typedef unsigned long long uvlong;

class MSQ
{
	uvlong d, v;
	uvlong l, m;

public:
	MSQ(uvlong s);

	void seed(uvlong s);
	uvlong next();
};

uvlong digits(uvlong n)
{
	uvlong c;

	c = 0;
	do
	{
		c++;
	} while (n /= 10);

	return c;
}

uvlong ipow(uvlong x, uvlong y)
{
	uvlong i, r;

	r = 1;
	for (i = 0; i < y; i++)
		r *= x;
	return r;
}

MSQ::MSQ(uvlong s)
{
	seed(s);
}

void MSQ::seed(uvlong s)
{
	d = digits(s);
	v = s;
	l = ipow(10, d / 2);
	m = ipow(10, d);
}

uvlong MSQ::next()
{
	v = ((v * v) / l) % m;
	return v;
}

uvlong cycles(uvlong v)
{
	map<uvlong, bool> m = { { v, true } };
	auto r = MSQ(v);
	auto c = 0ULL;
	for (;;)
	{
		v = r.next();
		if (m.find(v) != m.end())
			break;
		m[v] = true;
		c++;
	}
	return c;
}

int main()
{
	assert(cycles(24ULL) == 1);
	assert(cycles(82ULL) == 5);
	assert(cycles(123456ULL) == 146);
	assert(cycles(8989ULL) == 68);
	assert(cycles(789987ULL) == 226);

	return 0;
}
