/*

Write a program or function that takes in a positive integer. You can assume the input is valid and may take it as a string. If the number is any of

123
234
345
456
567
678
789
then output a truthy value. Otherwise, output a falsy value. For example, the inputs

1
2
3
12
122
124
132
321
457
777
890
900
1011
1230
1234
must all result in falsy output. (The input will not have leading zeroes so you needn't worry about things like 012.)

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
valid(unsigned n)
{
	static const char tab[] = {
	    [123] = 1,
	    [234] = 1,
	    [345] = 1,
	    [456] = 1,
	    [567] = 1,
	    [678] = 1,
	    [789] = 1,
	};

	if (n >= nelem(tab))
		return false;
	return tab[n];
}

int
main(void)
{
	static const unsigned truthy[] = {
	    123,
	    234,
	    345,
	    456,
	    567,
	    678,
	    789,
	};

	static const unsigned falsy[] = {
	    1,
	    2,
	    3,
	    12,
	    122,
	    124,
	    132,
	    321,
	    457,
	    777,
	    890,
	    900,
	    1011,
	    1230,
	    1234,
	};

	size_t i;

	for (i = 0; i < nelem(truthy); i++)
		assert(valid(truthy[i]) == true);
	for (i = 0; i < nelem(falsy); i++)
		assert(valid(falsy[i]) == false);

	return 0;
}
