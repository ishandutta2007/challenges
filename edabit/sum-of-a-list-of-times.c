/*

Create a function that takes an array of strings representing times ('hours:minutes:seconds') and returns their sum as an array of integers ([hours, minutes, seconds]).

Examples

time_sum(["1:23:45"]) ➞ [1, 23, 45]

time_sum(["1:03:45", "1:23:05"]) ➞ [2, 26, 50]

time_sum(["5:39:42", "10:02:08", "8:26:33"]) ➞ [24, 8, 23]

Notes

If the input is an empty array, return [0, 0, 0].

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
timesum(const char **s, size_t n, unsigned r[3])
{
	unsigned x, y, z;
	size_t i;

	r[0] = r[1] = r[2] = 0;
	for (i = 0; i < n; i++) {
		if (sscanf(s[i], "%u:%u:%u", &x, &y, &z) != 3)
			return -1;
		r[0] += x;
		r[1] += y;
		r[2] += z;
	}

	r[1] += r[2] / 60;
	r[0] += r[1] / 60;
	r[2] %= 60;
	r[1] %= 60;

	return 0;
}

void
test(const char **s, size_t n, unsigned r[3])
{
	unsigned p[3];

	assert(timesum(s, n, p) >= 0);
	printf("%u %u %u\n", p[0], p[1], p[2]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	const char *s1[] = {
	    "1:23:45",
	};
	const char *s2[] = {
	    "1:03:45",
	    "1:23:05",
	};
	const char *s3[] = {
	    "1:23:45",
	    "0:00:00",
	};
	const char *s4[] = {
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
	const char *s5[] = {
	    "5:39:42",
	    "10:02:08",
	    "8:26:33",
	};
	const char *s6[] = {
	    "10:11:02",
	    "8:57:30",
	    "10:58:56",
	    "4:04:17",
	    "3:01:13",
	};
	const char *s7[] = {
	    "10:39:35",
	    "11:33:23",
	    "2:34:52",
	    "9:17:09",
	    "4:41:57",
	    "3:34:19",
	    "1:31:26",
	    "4:06:01",
	};

	test(NULL, 0, (unsigned[3]){0, 0, 0});
	test(s1, nelem(s1), (unsigned[3]){1, 23, 45});
	test(s2, nelem(s2), (unsigned[3]){2, 26, 50});
	test(s3, nelem(s3), (unsigned[3]){1, 23, 45});
	test(s4, nelem(s4), (unsigned[3]){329, 41, 43});
	test(s5, nelem(s5), (unsigned[3]){24, 8, 23});
	test(s6, nelem(s6), (unsigned[3]){37, 12, 58});
	test(s7, nelem(s7), (unsigned[3]){47, 58, 42});

	return 0;
}
