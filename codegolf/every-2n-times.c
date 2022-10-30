/*

Let n be the number of times your program has been executed. If n is a power of 2, then print 2^x where n = 2^x; otherwise, simply output the number. Example run:

[1st time] 2^0
[2nd time] 2^1
[3rd time] 3
[4th time] 2^2
[5th time] 5

and so on. This is a popularity contest, so the answer with the most upvotes wins..

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>

unsigned
get(const char *name)
{
	FILE *fp;
	unsigned x;

	x = 1;
	fp = fopen(name, "rb");
	if (!fp)
		return x;
	fscanf(fp, "%u", &x);
	fclose(fp);
	return x;
}

void
put(const char *name, unsigned x)
{
	FILE *fp;

	fp = fopen(name, "wb");
	if (!fp)
		return;
	fprintf(fp, "%u\n", x);
	fclose(fp);
}

void
run(const char *name)
{
	unsigned x;

	x = get(name);
	if (!(x & (x - 1)))
		printf("2^%.0f\n", log2(x));
	else
		printf("%u\n", x);
	put(name, x + 1);
}

int
main(void)
{
	int i;

	for (i = 0; i < 1024; i++)
		run("counter.txt");
	return 0;
}
