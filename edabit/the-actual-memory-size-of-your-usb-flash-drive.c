/*

Create a function that takes the memory size (ms is a string type) as an argument and returns the actual memory size.
Examples

actualMemorySize("32GB") ➞ "29.76GB"

actualMemorySize("2GB") ➞ "1.86GB"

actualMemorySize("512MB") ➞ "476MB"

Notes

    The actual storage loss on a USB device is 7% of the overall memory size!
    If the actual memory size was greater than 1 GB, round your result to two decimal places.
    For the purposes of this challenge, there are 1000 MB in a Gigabyte.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
memsize(const char *s, char *b, size_t n)
{
	unsigned long long sz;
	double rsz;
	char *ep;

	sz = strtoull(s, &ep, 10);
	rsz = sz - (sz * 0.07);
	if (!strcmp(ep, "GB")) {
		if (rsz > 1)
			snprintf(b, n, "%.2f%s", rsz, ep);
		else
			snprintf(b, n, "%.0fMB", rsz * 1000);
	} else
		snprintf(b, n, "%.0f%s", rsz, ep);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	memsize(s, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("32GB", "29.76GB");
	test("2GB", "1.86GB");
	test("512MB", "476MB");
	test("256MB", "238MB");
	test("8GB", "7.44GB");
	test("16GB", "14.88GB");
	test("32GB", "29.76GB");
	test("1GB", "930MB");

	return 0;
}
