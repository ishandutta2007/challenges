/*

Write a program, which takes an integer N and if the number is less than 10 then display "What an obedient servant you are!" otherwise print "-1". 

*/

#include <stdio.h>

void
servitude(int n)
{
	if (n < 10)
		printf("What an obedient servant you are!\n");
	else
		printf("-1\n");
}

int
main(void)
{
	servitude(3);
	servitude(1);
	servitude(12);
	servitude(-5);
	return 0;
}
