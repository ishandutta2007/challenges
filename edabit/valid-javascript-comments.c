// In JavaScript, there are two types of comments:
// Single-line comments start with //
// Multi-line or inline comments start with /* and end with */
// The input will be a sequence of //, /* and */. Every /* must have a */ that immediately follows it. To add, there can be no single-line comments in between multi-line comments in between the /* and */.
//
// Create a function that returns true if comments are properly formatted, and false otherwise.
// Examples
//
// commentsCorrect("//////") ➞ true
// 3 single-line comments: ["//", "//", "//"]
//
// commentsCorrect("/**//**////**/") ➞ true
// 3 multi-line comments + 1 single-line comment:
// ["/*", "*/", "/*", "*/", "//", "/*", "*/"]
//
// commentsCorrect("///*/**/") ➞ false
// The first /* is missing a */
//
// commentsCorrect("/////") ➞ false
// The 5th / is single, not a double //
//
// Notes
// N/A

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
jscom(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] != '/')
			return false;

		switch (s[++i]) {
		case '/':
			break;

		case '*':
			i++;
			while (s[i] != '*')
				i++;
			if (s[++i] != '/')
				return false;
			break;

		default:
			return false;
		}
	}

	return true;
}

int
main(void)
{
	assert(jscom("//////") == true);
	assert(jscom("/**//**////**/") == true);
	assert(jscom("/**//**//**//**/") == true);
	assert(jscom("///**///") == true);
	assert(jscom("/**//////**//**////**/////") == true);
	assert(jscom("//") == true);
	assert(jscom("/**/") == true);
	assert(jscom("///*/**/") == false);
	assert(jscom("//*/**/") == false);
	assert(jscom("/////") == false);
	assert(jscom("///") == false);
	assert(jscom("/**///**/") == false);
	assert(jscom("/**/////**/") == false);
	assert(jscom("/**//") == false);
	assert(jscom("/**///") == true);

	return 0;
}
