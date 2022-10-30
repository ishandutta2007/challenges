/*

Once I wrote a JavaScript program that would take as input a string and a character and would remove all characters except for the first one and the character given as input, one by one.

For example, computing this with inputs codegolf.stackexchange.com and e for the character yields:

codegolf.stackexchange.com
cdegolf.stackexchange.com
cegolf.stackexchange.com
ceolf.stackexchange.com
celf.stackexchange.com
cef.stackexchange.com
ce.stackexchange.com
cestackexchange.com
cetackexchange.com
ceackexchange.com
ceckexchange.com
cekexchange.com
ceexchange.com
ceechange.com
ceehange.com
ceeange.com
ceenge.com
ceege.com
ceee.com
ceeecom
ceeeom
ceeem
ceee
It keeps the first character and all es. All other characters are removed one by one.

Your task is to write a program (or function) that takes two inputs and outputs (or returns) a string that accomplishes this effect.

Specifications
You can assume that the string will not contain any newlines.
The second input will always be one character.
If the answer is in the form of a function, you may return an array of strings containing each line in the output.
The output can contain a trailing newline.
Test Cases

Test Cases, s:

Test Cases
Tst Cases
Ts Cases
TsCases
Tsases
Tsses
Tsss

Make a "Ceeeeeeee" program, e:

Make a "Ceeeeeeee" program
Mke a "Ceeeeeeee" program
Me a "Ceeeeeeee" program
Mea "Ceeeeeeee" program
Me "Ceeeeeeee" program
Me"Ceeeeeeee" program
MeCeeeeeeee" program
Meeeeeeeee" program
Meeeeeeeee program
Meeeeeeeeeprogram
Meeeeeeeeerogram
Meeeeeeeeeogram
Meeeeeeeeegram
Meeeeeeeeeram
Meeeeeeeeeam
Meeeeeeeeem
Meeeeeeeee

Hello World!, !:

Hello World!
Hllo World!
Hlo World!
Ho World!
H World!
HWorld!
Horld!
Hrld!
Hld!
Hd!
H!

Hello World!, z:

Hello World!
Hllo World!
Hlo World!
Ho World!
H World!
HWorld!
Horld!
Hrld!
Hld!
Hd!
H!
H

alphabet, a:

alphabet
aphabet
ahabet
aabet
aaet
aat
aa

upperCASE, e:

upperCASE
uperCASE
uerCASE
ueCASE
ueASE
ueSE
ueE
ue

This is code-golf, so the shortest code (in bytes) wins.

*/

#include <stdio.h>

int
del1(char *b, char c)
{
	size_t i, j;
	int f;

	f = 0;
	for (i = j = 0; b[i]; i++) {
		if (i == 0 || b[i] == c || f)
			b[j++] = b[i];
		else if (!f)
			f = 1;
	}
	b[j] = '\0';

	return i == j;
}

void
ce(char *b, char c)
{
	int n;

	for (n = 0; n != 1; n += del1(b, c))
		printf("%s\n", b);
	printf("\n");
}

int
main(void)
{
	char b1[] = "codegolf.stackexchange.com";
	char b2[] = "Test Cases";
	char b3[] = "Make a \"Ceeeeeeee\" program";
	char b4[] = "Hello World!";
	char b5[] = "Hello World!";
	char b6[] = "alphabet";
	char b7[] = "upperCASE";

	ce(b1, 'e');
	ce(b2, 's');
	ce(b3, 'e');
	ce(b4, '!');
	ce(b5, 'z');
	ce(b6, 'a');
	ce(b7, 'e');

	return 0;
}
