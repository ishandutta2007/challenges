/*

3var is a variant of deadfish which uses three variables called A, B and R. A and B are accumulators, while R is used as a result variable.

In this code-golf challenge, you need to make an interpreter for a stripped-down version of this language.

Required Commands:
i   Increments A
d   Decrements A
s   Squares A
p   Prints A
P   Prints the ASCII character of A
>   Sets A to R
a   Increments B
k   Decrements B
m   Squares B
o   Prints B
O   Prints the ASCII character of B
<   Sets B to R
+   Adds A and B, stores in R
-   Subtracts B from A, stores in R
*   Multiplies A and B, stores in R
/   Divides A by B, stores in R
w   Prints R
@   Resets A to 0
#   Resets B to 0
e   Resets R to 0
Everything else (including whitespaces) is ignored.

Clarifications
o and p should output without anything after it.
Division is integer division.
Numbers above 255 and numbers below 0 are supported.
'w' should output a space or a newline after R
Division by 0 halts without errors. (No output to STDERR)
A, B and R are initially 0
Rules
This is code-golf so the shortest answer wins.
In the event of a tie, the oldest answer wins.
The file will be provided through command line arguments or STDIN.
Any language is allowed.
Eval is allowed.
Test Cases
Hello world! (taken from Esolangs)

iisssaa/>e
maa->e#
aamam->e#
dddddddddddddddddddddddddPiiiiiiiiiiiiiiiiiiiiiiiii
iiiiPiiiiiiiPPiiiP
@#e
iis
aamaaaa
*>P
@#e
iisssaa/>e
maa->e#
aamam->e#
iiiiiiiiiiiiiiiiiiiiiiP
ddddddddP
iiiP
ddddddP
ddddddddP
@#e
iiss
aa*>
iP
Outputs 20spooky22me:

iipois+iis<-<aaaO<OkOOkkkkOP@#iippisa+<m+>PaO
Outputs 9P-1420 100 3Q-1 162 0:

iiispsdPkokmo/w<+w#aaaommO-w@ii*wew

*/

#include <stdio.h>

void
interpret(const char *s)
{
	int a, b, r;
	size_t i;

	a = b = r = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case 'i':
			a++;
			break;

		case 'd':
			a--;
			break;

		case 's':
			a *= a;
			break;

		case 'p':
			printf("%d", a);
			break;

		case 'P':
			printf("%c", a);
			break;

		case '>':
			a = r;
			break;

		case 'a':
			b++;
			break;

		case 'k':
			b--;
			break;

		case 'm':
			b *= b;
			break;

		case 'o':
			printf("%d", b);
			break;

		case 'O':
			printf("%c", b);
			break;

		case '<':
			b = r;
			break;

		case '+':
			r = a + b;
			break;

		case '-':
			r = a - b;
			break;

		case '*':
			r = a * b;
			break;

		case '/':
			if (b == 0)
				return;
			r = a / b;
			break;

		case 'w':
			printf("%d ", r);
			break;

		case '@':
			a = 0;
			break;

		case '#':
			b = 0;
			break;

		case 'e':
			r = 0;
			break;
		}
	}
	printf("\n");
}

int
main(void)
{
	static const char *hw =
	    "iisssaa/>e"
	    "maa->e#"
	    "aamam->e#"
	    "dddddddddddddddddddddddddPiiiiiiiiiiiiiiiiiiiiiiiii"
	    "iiiiPiiiiiiiPPiiiP"
	    "@#e"
	    "iis"
	    "aamaaaa"
	    "*>P"
	    "@#e"
	    "iisssaa/>e"
	    "maa->e#"
	    "aamam->e#"
	    "iiiiiiiiiiiiiiiiiiiiiiP"
	    "ddddddddP"
	    "iiiP"
	    "ddddddP"
	    "ddddddddP"
	    "@#e"
	    "iiss"
	    "aa*>"
	    "iP";

	interpret(hw);
	interpret("iipois+iis<-<aaaO<OkOOkkkkOP@#iippisa+<m+>PaO");
	interpret("iiispsdPkokmo/w<+w#aaaommO-w@ii*wew");

	return 0;
}
