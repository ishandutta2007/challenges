/*

I like patterns in time. My favorite is when the time lines up. For example, all of these line up:

3:45
12:34
23:45
3:21
6:54

This is because each digit in the hour/minute is increasing/decreasing by one each time.

Your task is to take the current time and check if it "lines up" in this pattern in a program. (You will output a truthy or falsey value according to this check.) Along with the times above, your program should match these:

1:23
4:32
2:10

And not match these:

1:00
12:13
1:21
1:34

You may take the time as an argument to a function/through STDIN, but this incurs a +125% byte penalty on your program. You may take the time from UTC or system time; 12-hour or 24-hour. This is a code golf, so the shortest program in bytes wins.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
lineartime(const char *s)
{
	unsigned h, m;
	int i, n, f;
	char b[8];

	if (sscanf(s, "%u:%u", &h, &m) != 2)
		return false;

	if (!(h <= 23 && m <= 59))
		return false;

	f = 0;
	n = snprintf(b, sizeof(b), "%u%02u", h, m);
	for (i = 0; i < n - 1; i++) {
		if (b[i] + 1 == b[i + 1])
			f |= 1;
		else if (b[i] - 1 == b[i + 1])
			f |= 2;
		else
			return false;
	}
	return f == 1 || f == 2;
}

int
main(void)
{
	assert(lineartime("3:45") == true);
	assert(lineartime("12:34") == true);
	assert(lineartime("23:45") == true);
	assert(lineartime("3:21") == true);
	assert(lineartime("6:54") == true);
	assert(lineartime("1:23") == true);
	assert(lineartime("4:32") == true);
	assert(lineartime("2:10") == true);

	assert(lineartime("1:00") == false);
	assert(lineartime("12:13") == false);
	assert(lineartime("1:21") == false);
	assert(lineartime("1:34") == false);

	return 0;
}
