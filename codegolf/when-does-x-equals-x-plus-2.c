/*

The challenge: Define x in such a way that the expression (x == x+2) would evaluate to true.

I tagged the question with C, but answers in other languages are welcome, as long as they're creative or highlight an interesting aspect of the language.

I intend to accept a C solution, but other languages can get my vote.

    Correct - works on standard-compliant implementations. Exception - assuming an implementation of the basic types, if it's a common implementation (e.g. assuming int is 32bit 2's complement) is OK.
    Simple - should be small, use basic language features.
    Interesting - it's subjective, I admit. I have some examples for what I consider interesting, but I don't want to give hints. Update: Avoiding the preprocessor is interesting.
    Quick - The first good answer will be accepted.

After getting 60 answers (I never expected such prticipation), It may be good to summarize them.

The 60 answers divide into 7 groups, 3 of which can be implemented in C, the rest in other languages:

    The C preprocessor. #define x 2|0 was suggested, but there are many other possibilities.
    Floating point. Large numbers, infinity or NaN all work.

    Pointer arithmetic. A pointer to a huge struct causes adding 2 to wrap around.

    The rest don't work with C:
    Operator overloading - A + that doesn't add or a == that always returns true.
    Making x a function call (some languages allow it without the x() syntax). Then it can return something else each time.
    A one-bit data type. Then x == x+2 (mod 2).
    Changing 2 - some language let you assign 0 to it.

*/

#include <assert.h>
#include <math.h>

int
main(void)
{
	double x;

	x = INFINITY;
	assert(x == x + 2);
	return 0;
}
