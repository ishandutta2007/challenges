/*

Given a text file file.txt that contains list of phone numbers (one per line), write a one liner bash script to print all valid phone numbers.

You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

You may also assume each line in the text file must not contain leading or trailing white spaces.

Example:

Assume that file.txt has the following content:

987-123-4567
123 456 7890
(123) 456-7890

Your script should output the following valid phone numbers:

987-123-4567
(123) 456-7890

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <regex.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
validpn(const char *s)
{
	static const char *pat[] = {
	    "^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$",
	    "^([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$",
	};
	regex_t re;
	size_t i;
	int rv;

	rv = 0;
	for (i = 0; i < nelem(pat); i++) {
		regcomp(&re, pat[i], 0);
		rv |= regexec(&re, s, 0, NULL, 0) == 0;
		regfree(&re);
	}
	return rv;
}

int
parse(const char *name)
{
	FILE *fp;
	char b[1024], *p;

	fp = fopen(name, "rt");
	if (!fp)
		return -errno;

	while (fgets(b, sizeof(b), fp)) {
		if ((p = strstr(b, "\n")))
			*p = '\0';
		if (validpn(b))
			printf("%s\n", b);
	}

	fclose(fp);
	return 0;
}

int
main(void)
{
	const char *name;
	int rv;

	name = "valid-phone-numbers.txt";
	if ((rv = parse(name)) < 0) {
		fprintf(stderr, "%s: %s\n", name, strerror(-rv));
		return 1;
	}

	return 0;
}
