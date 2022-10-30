/*

Your job is to find out whether the lamp is on or off.

Check the tests tab to find out what you have to do to make this work.

*/

#include <stdio.h>
#include <stdbool.h>

typedef bool lamp_t;

bool
lampstatus(lamp_t l)
{
	return l;
}

lamp_t
setlamp(bool state)
{
	return state;
}

int
main(void)
{
	lamp_t l;

	l = setlamp(false);
	printf("%d\n", lampstatus(l));
	printf("%d\n", lampstatus(l));
	l = setlamp(true);
	printf("%d\n", lampstatus(l));
	l = setlamp(false);
	printf("%d\n", lampstatus(l));
	l = setlamp(true);
	printf("%d\n", lampstatus(l));
	printf("%d\n", lampstatus(l));
	l = setlamp(false);
	printf("%d\n", lampstatus(l));
	l = setlamp(true);
	printf("%d\n", lampstatus(l));
	printf("%d\n", lampstatus(l));
	l = setlamp(false);
	printf("%d\n", lampstatus(l));
	l = setlamp(true);
	printf("%d\n", lampstatus(l));
	return 0;
}
