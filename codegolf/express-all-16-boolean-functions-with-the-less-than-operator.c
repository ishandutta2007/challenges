/*

There are 16 distinct boolean functions for two binary variables, A and B:

A B | F0 | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15
-----------------------------------------------------------------------------------------
0 0 | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  | 1  | 1   | 1   | 1   | 1   | 1   | 1
0 1 | 0  | 0  | 0  | 0  | 1  | 1  | 1  | 1  | 0  | 0  | 0   | 0   | 1   | 1   | 1   | 1
1 0 | 0  | 0  | 1  | 1  | 0  | 0  | 1  | 1  | 0  | 0  | 1   | 1   | 0   | 0   | 1   | 1
1 1 | 0  | 1  | 0  | 1  | 0  | 1  | 0  | 1  | 0  | 1  | 0   | 1   | 0   | 1   | 0   | 1
The less than operator <, which normally isn't thought of as a logic operator like NOT, AND, or OR, is in fact one of these functions (F4) when applied to boolean values:

A B | A < B
-----------
0 0 | 0
0 1 | 1
1 0 | 0
1 1 | 0
Interestingly, we can simulate any of the 15 other functions using expressions that only contain the symbols ()<AB10.
These expressions are read and evaluated just as they would be in many standard programming languages, e.g. parentheses must match and < must have arguments on either side of it.

Specifically, these expressions must comply with the following grammar (given in Backus-Naur form):

element ::= A | B | 1 | 0
expression ::= element<element | (expression)<element | element<(expression) | (expression)<(expression)
This means that useless paretheses and expressions of the form A<B<1 are not allowed.

So the expression A<B matches the function F4, and A<B<1 must be changed to (A<B)<1 or A<(B<1).

To prove that all of the 15 other functions can be turned into expressions, it suffices to form a set of expressions that is functionally complete, because then, by definition, they can be composed into expressions for any function.

One such set of expressions is x<1 (where x is A or B), which is ¬x, and (((B<A)<1)<A)<1, which is A → B. Negation (¬) and implication (→) are known to be functionally complete.

Challenge
Using the characters ()<AB10, write 16 expressions in the form described above that are equivalent to each of the 16 distinct boolean functions.

The goal is to make each of the expressions as short as possible. Your score is the sum of the number of characters in each of your 16 expressions.
The lowest score wins. Tiebreaker goes to the earliest answer (provided they didn't edit their answer later with shorter expressions taken from someone else).

You do not technically need to write any real code for this contest but if you did write any programs to help you generate the expressions, you are highly encouraged to post them.

You can use this Stack Snippet to check if your expressions do what's expected:

function check() {
  var input = document.getElementById('input').value.split('\n'), output = ''
  if (input.length == 1 && input[0].length == 0)
    input = []

  for (var i = 0; i < 16; i++) {
    var expected = [(i & 8) >> 3, (i & 4) >> 2, (i & 2) >> 1, i & 1]

    output += 'F' + i.toString() + '\nA B | expected | actual\n-----------------------\n'
    for (var j = 0; j < 4; j++) {
      var A = (j & 2) >> 1, B = j & 1, actual = '?'
      if (i < input.length) {
        try {
          actual = eval(input[i]) ? 1 : 0
        } catch (e) {}
      }

      output += A.toString() + ' ' + B.toString() +
        ' | ' + expected[j] + '        | ' + actual.toString() + '     '
      if (expected[j] != actual)
        output += ' <- MISMATCH'
      if (j != 3)
        output += '\n'
    }
    if (i != 15)
      output += '\n\n'
  }
  document.getElementById('output').value = output
}

*/

#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@Peter Taylor:

A NOR gate can be constructed out of < with the expression A<(B<1)

*/

int
f(int a, int b, unsigned n)
{
	const int tab[] = {
	    0,
	    (b < a) < a,
	    b < a,
	    a,
	    a < b,
	    b,
	    ((a < b) < ((b < a) < 1)) < 1,
	    (a < (b < 1)) < 1,
	    a < (b < 1),
	    (a < b) < ((b < a) < 1),
	    b < 1,
	    (a < b) < 1,
	    a < 1,
	    (b < a) < 1,
	    ((b < a) < a) < 1,
	    1,
	};

	if (n >= nelem(tab))
		return -1;
	return tab[n];
}

int
main(void)
{
	int a, b;
	int i, j;
	int v;

	for (i = 0; i < 16; i++) {
		v = 0;
		for (j = 0; j < 4; j++) {
			a = (j >> 1) & 1;
			b = (j & 1);
			v = (v << 1) | f(a, b, i);
		}

		assert(v == i);
	}

	return 0;
}
