/*

Write a function that returns the number of users in a chatroom based on the following rules:

    If there is no one, return "no one online".
    If there 1 person, return "[user1] online".
    If there are 2 people, return [user 1] and [user 2] online".
    If there are n>2 people, return the first two names and add "and n-2 more online".

For example, if there are 5 users, return:

"[user1], [user2] and 3 more online"

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
chatstat(const char **s, size_t m, char *b, size_t n)
{
	switch (m) {
	case 0:
		snprintf(b, n, "no one online");
		break;
	case 1:
		snprintf(b, n, "%s online", s[0]);
		break;
	case 2:
		snprintf(b, n, "%s and %s online", s[0], s[1]);
		break;
	default:
		snprintf(b, n, "%s, %s and %zu more online", s[0], s[1], m - 2);
		break;
	}
	return b;
}

int
main(void)
{
	char b[80];
	const char *s1[] = { "becky325" };
	const char *s2[] = { "becky325", "malcolm888" };
	const char *s3[] = { "becky325", "malcolm888", "fah32fa" };
	const char *s4[] = { "paRIE_to" };
	const char *s5[] = { "s234f", "mailbox2" };
	const char *s6[] = { "pap_ier44", "townieBOY", "panda321", "motor_bike5", "sandwichmaker833", "violinist91" };

	printf("%s\n", chatstat(s1, 0, b, sizeof(b)));
	printf("%s\n", chatstat(s1, nelem(s1), b, sizeof(b)));
	printf("%s\n", chatstat(s2, nelem(s2), b, sizeof(b)));
	printf("%s\n", chatstat(s3, nelem(s3), b, sizeof(b)));
	printf("%s\n", chatstat(s4, nelem(s4), b, sizeof(b)));
	printf("%s\n", chatstat(s5, nelem(s5), b, sizeof(b)));
	printf("%s\n", chatstat(s6, nelem(s6), b, sizeof(b)));

	return 0;
}
