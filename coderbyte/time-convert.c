/*

Have the function TimeConvert(num) take the num parameter being passed and return the number of hours and minutes the parameter converts to (ie. if num = 63 then the output should be 1:3).
Separate the number of hours and minutes with a colon. 

*/

#include <stdio.h>

void
timeconvert(unsigned n)
{
	printf("%u:%u\n", n / 60, n % 60);
}

int
main(void)
{
	timeconvert(63);
	timeconvert(126);
	timeconvert(45);
	return 0;
}
