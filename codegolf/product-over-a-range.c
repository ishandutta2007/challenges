/*

Your task is simple: given two integers a and b, output Π[a,b]; that is, the product of the range between a and b.
You may take a and b in any reasonable format, whether that be arguments to a function, a list input, STDIN, et cetera.
You may output in any reasonable format, such as a return value (for functions) or STDOUT. a will always be less than b.

Note that the end may be exclusive or inclusive of b

. I'm not picky. ^_^
Test cases

[a,b) => result
[2,5) => 24
[5,10) => 15120
[-4,3) => 0
[0,3) => 0
[-4,0) => 24

[a,b] => result
[2,5] => 120
[5,10] => 151200
[-4,3] => 0
[0,3] => 0
[-4,-1] => 24

This is a code-golf, so the shortest program in bytes wins.
Leaderboard

The Stack Snippet at the bottom of this post generates the catalog from the answers a) as a list of shortest solution per language and b) as an overall leaderboard.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

## Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

## Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

## Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the snippet:

## [><>](http://esolangs.org/wiki/Fish), 121 bytes

*/

#include <assert.h>

typedef long long vlong;

vlong
productrange(vlong a, vlong b, int inclusive)
{
	vlong i, r;

	r = a;
	for (i = a + 1; i < b; i++)
		r *= i;
	if (inclusive)
		r *= b;
	return r;
}

int
main(void)
{
	assert(productrange(2, 5, 0) == 24);
	assert(productrange(5, 10, 0) == 15120);
	assert(productrange(-4, 3, 0) == 0);
	assert(productrange(0, 3, 0) == 0);
	assert(productrange(-4, 0, 0) == 24);

	assert(productrange(2, 5, 1) == 120);
	assert(productrange(5, 10, 1) == 151200ll);
	assert(productrange(-4, 3, 1) == 0);
	assert(productrange(0, 3, 1) == 0);
	assert(productrange(-4, -1, 1) == 24);

	return 0;
}
