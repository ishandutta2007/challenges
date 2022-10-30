/*

I'm a code golf novice, but I'm eager to give it a go.

My challenge is: Write the shortest program in C which takes in a date D as input and outputs the date D + 1 day

Rules:

    program must compile only with gcc progname.c -o progname So no compiler/makefile tricks (if there are any) - compiler warnings don't matter
    The input and output format must be day/month/year zero padding of single digit values does not matter: 1/3/1998 is equal to 01/03/1998
    It doesn't matter how you give the the program it's input date, it can be a program argument, scanf whatever. Output must be to stdout however
    February has 29 days when the year is divisible by 4
    No date validation necessary, i.e. assume the input is always a valid date.
    any integer year should be supported, i.e. INT_MIN -> INT_MAX

Shortest code length wins, and there are extra points for extra bastardised C.
My solution uses 126 123* 121 characters

Good luck

*s="%i/%i/%i",m,d;main(y){scanf(s,&d,&m,&y);printf(s,d,m,(d=d%((m>7^m&1)+27+(m-2?3:y%4?1:2))+1)-1?y:(m=m%12+1)-1?y:y+1);}

*because of an idea Gareth's code gave me

*/

#define _XOPEN_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char *
tomorrow(const char *s, char *b, size_t n)
{
	struct tm tm;

	memset(&tm, 0, sizeof(tm));
	strptime(s, "%d/%m/%Y", &tm);
	tm.tm_mday++;
	mktime(&tm);
	strftime(b, n, "%d/%m/%Y", &tm);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	tomorrow(s, b, sizeof(b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1/3/1998", "02/03/1998");
	test("31/7/1990", "01/08/1990");
	test("31/12/1999", "01/01/2000");

	return 0;
}
