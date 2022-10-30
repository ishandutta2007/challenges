/*

Create a function that takes a number as an argument and returns the appropriate error message. You should do this without the use of the switch or if statements.

The input error will be 1 to 5:

1 >> "Check the fan"
2 >> "Emergency stop"
3 >> "Pump Error"
4 >> "Press Sensor Error"
5 >> "Temperature Sensor Error"

The above five return "101" (you can use an if statment here).
Examples

error(1) ➞ "Check the fan : e1"

error(2) ➞ "Emergency stop : e2"

error(3) ➞ "Pump Error : e3"

Notes

You should do this WITHOUT the USE of the SWITCH or IF statements.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
error(unsigned e)
{
	static const char *tab[] = {
		"101",
		"Check the fan : e1",
		"Emergency stop : e2",
		"Pump Error : e3",
		"Press Sensor Error : e4",
		"Temperature Sensor Error : e5",
	};
	return (e < nelem(tab)) ? tab[e] : tab[0];
}

int
main(void)
{
	assert(strcmp(error(1), "Check the fan : e1") == 0);
	assert(strcmp(error(2), "Emergency stop : e2") == 0);
	assert(strcmp(error(3), "Pump Error : e3") == 0);
	assert(strcmp(error(7), "101") == 0);
	return 0;
}
