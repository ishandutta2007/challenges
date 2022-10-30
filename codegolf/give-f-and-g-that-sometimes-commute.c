/*

Let Z be either the integers, the positive integers, or the non-zero integers; pick whatever's convenient. Give two functions f and g, each Z→Z, such that:

f(g(a))=g(f(a)), for infinitely many integers a, and
f(g(b))≠g(f(b)), for infinitely many integers b.

Rules
Many of the rules from f(g(x)) decreases while g(f(x)) increases are stolen here:

Please provide an argument for why your functions fulfill the requirements.
Interpret "function" in the mathematical sense. That is, they must be total (defined over all of Z) and pure (given the same input, it must produce the same output).
You may submit the functions as a single program or two separate ones.
A single program must either have two named functions f and g, or, when run, have output that can be interpreted as a pair of two functions f and g.
Two separate programs must have one give f, and the other give g. The two programs may not refer to each other. In this case, functions may be unnamed.
Standard submission rules and input/output methods apply, but we require that f and g must have identical input and output representations; that is, they can be directly composed without manually converting in between.
Conceptually, they must be functions over integers, so you can't cheat by using two different string representations of the same number or anything like that.
The usual integer overflow rules apply: your solution must be able to work for arbitrarily large integers in a hypothetical (or perhaps real) version of your language in which all integers are unbounded by default,
but if your program fails in practice due to the implementation not supporting integers that large, that doesn't invalidate the solution.
This is code-golf. If you submit a single program, your score is the number of bytes of that program. If you submit two programs, your score is the sum of the number of bytes of both programs.

*/

#include <stdio.h>

int
f(int x)
{
	return x & 1;
}

int
g(int x)
{
	return x << 1;
}

int
main(void)
{
	int i;

	for (i = -50; i <= 50; i++)
		printf("%+03d | %d %d\n", i, f(g(i)), g(f(i)));

	return 0;
}
