/*

Your task, should you choose to accept it, is to take two input values a and b, where a and b are in the set {T,U,F}, and compute and output their logical conjunction in a three-valued logic system.

A three valued logical conjunction is this transformation:

a	b	output
U	U	U
U	F	F
F	U	F
U	T	U
T	U	U
F	F	F
F	T	F
T	F	F
T	T	T

I/O Rules
You have to take as an input two characters a and b, where a and b are T, U, or F.

You have to output one of F, T, or U, with an optional trailing newline.

These very restrictive I/O rules help prevent trivial solutions.

Example Program (in Nim)
proc f(s: string): char =
  if s[0]=='F' or s[1]=='F':return 'F'
  if s[0]=='U' or s[1]=='U':return 'U'
  if s[0]=='T' and s[1]=='T':return 'T'

*/

#include <assert.h>

int
conjunction(int a, int b)
{
	if (a == 'F' || b == 'F')
		return 'F';
	if (a == 'U' || b == 'U')
		return 'U';
	if (a == 'T' && b == 'T')
		return 'T';
	return 0;
}

int
main(void)
{
	assert(conjunction('U', 'U') == 'U');
	assert(conjunction('U', 'F') == 'F');
	assert(conjunction('F', 'U') == 'F');
	assert(conjunction('U', 'T') == 'U');
	assert(conjunction('T', 'U') == 'U');
	assert(conjunction('F', 'F') == 'F');
	assert(conjunction('F', 'T') == 'F');
	assert(conjunction('T', 'F') == 'F');
	assert(conjunction('T', 'T') == 'T');

	return 0;
}
