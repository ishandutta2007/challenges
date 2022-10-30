/*

Create a function that takes an array of strings representing times ('hours:minutes:seconds')
and returns their sum as an array of integers ([hours, minutes, seconds]).

Note
	For empty arrays, return [0, 0, 0]

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
timesum(const char **a, size_t n, unsigned t[3])
{
	unsigned h, m, s;
	size_t i;

	memset(t, 0, 3 * sizeof(*t));
	if (n == 0)
		return 0;

	for (i = 0; i < n; i++) {
		if (sscanf(a[i], "%u:%u:%u", &h, &m, &s) != 3)
			return -1;

		t[0] += h;
		t[1] += m;
		t[2] += s;

		t[1] += t[2] / 60;
		t[0] += t[1] / 60;

		t[1] %= 60;
		t[2] %= 60;
	}

	return 0;
}

void
test(const char **a, size_t n)
{
	unsigned t[3];

	timesum(a, n, t);
	printf("[%u, %u, %u]\n", t[0], t[1], t[2]);
}

int
main(void)
{
	const char *a1[] = {"1:23:45"};
	const char *a2[] = {"1:03:45", "1:23:05"};
	const char *a3[] = {"1:23:45", "0:00:00"};
	const char *a4[] = {
	    "18:54:02",
	    "0:26:28",
	    "11:48:22",
	    "22:26:16",
	    "7:17:05",
	    "8:01:44",
	    "0:35:24",
	    "16:25:11",
	    "9:11:24",
	    "18:30:46",
	    "3:31:51",
	    "16:55:32",
	    "17:59:00",
	    "11:29:30",
	    "3:19:58",
	    "9:12:27",
	    "22:03:34",
	    "1:06:12",
	    "0:44:07",
	    "4:47:46",
	    "10:38:00",
	    "14:26:51",
	    "10:09:07",
	    "5:08:29",
	    "5:29:57",
	    "22:15:03",
	    "20:52:28",
	    "8:42:20",
	    "17:36:32",
	    "9:36:17",
	};
	const char *a5[] = {"5:39:42", "10:02:08", "8:26:33"};
	const char *a6[] = {"10:11:02", "8:57:30", "10:58:56", "4:04:17", "3:01:13"};
	const char *a7[] = {"10:39:35", "11:33:23", "2:34:52", "9:17:09", "4:41:57", "3:34:19", "1:31:26", "4:06:01"};

	test(NULL, 0);
	test(a1, nelem(a1));
	test(a2, nelem(a2));
	test(a3, nelem(a3));
	test(a4, nelem(a4));
	test(a5, nelem(a5));
	test(a6, nelem(a6));
	test(a7, nelem(a7));
	return 0;
}
