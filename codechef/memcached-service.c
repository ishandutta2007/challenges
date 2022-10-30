/*

Chef is a programmer. In his computer, he is running a caching service, Memcached. He can give the commands "start", "restart" or "stop" to the service, the functionalities of which are specified below.

"start": Start the service.
"restart": If the service is started, do nothing. Otherwise, start the service.
"stop": If the service is not running, give an error. Otherwise, stop the service.
The service is initially not running. You are given n commands that he then gives to the program in sequence. Your task is to identify whether some error/s were encountered while running these commands.

Input

The first line of each test case contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer n, denoting the number of commands.
The next line contains n space separated strings, each of which is either "start", "restart" or "stop".

Output

For each test case, output "404" if some error occurred, otherwise output "200" (without quotes).

Constraints
1≤T≤100
1≤n≤10

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmd(const char **s, size_t n)
{
	size_t i;
	int t;

	t = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(s[i], "start") || !strcmp(s[i], "restart"))
			t = 1;
		else if (!strcmp(s[i], "stop")) {
			t = (t == 1) ? 0 : -1;
			if (t < 0)
				break;
		}
	}
	return (t >= 0) ? 200 : 404;
}

int
main(void)
{
	const char *s1[] = {
	    "start",
	    "stop",
	};
	const char *s2[] = {
	    "restart",
	    "stop",
	};
	const char *s3[] = {
	    "start",
	    "restart",
	    "stop",
	};
	const char *s4[] = {
	    "start",
	    "stop",
	    "stop",
	};
	const char *s5[] = {
	    "stop",
	};

	assert(cmd(s1, nelem(s1)) == 200);
	assert(cmd(s2, nelem(s2)) == 200);
	assert(cmd(s3, nelem(s3)) == 200);
	assert(cmd(s4, nelem(s4)) == 404);
	assert(cmd(s5, nelem(s5)) == 404);

	return 0;
}
