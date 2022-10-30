/*

Description

Output the rhyme scheme for a very long Terza Rima.
Input

None.
Output

ABA
BCB
CDC
DED
EFE
FGF
GHG
HIH
IJI
JKJ
KLK
LML
MNM
NON
OPO
PQP
QRQ
RSR
STS
TUT
UVU
VWV
WXW
XYX
YZY

Rules

You can pick between separating stanzas with whitespace or newlines, so either:

ABA BCB...

OR

ABA
BCB
...

A single trailing whitespace allowed per line and one trailing newline allowed.

Output can be either uppercase or lowercase.

This is code-golf, so the shortest code in bytes for each language wins.

*/

#include <stdio.h>

void
terzarima(void)
{
	int i;

	for (i = 'A'; i <= 'Y'; i++)
		printf("%c%c%c\n", i, i + 1, i);
}

int
main(void)
{
	terzarima();
	return 0;
}
