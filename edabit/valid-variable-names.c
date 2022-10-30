/*

When creating variables, the variable name must always start with a letter, though numbers and underscores are allowed to be contained in it also.

Create a function which returns true if a given variable name is valid, otherwise return false.
Examples

variableValid("result") ➞ true

variableValid("odd_nums") ➞ true

variableValid("2TimesN") ➞ false

Notes

    Inputs are given as strings.
    Variable names with spaces are not allowed.
    Although this question may seem like otherwise, you can't actually assign words with quotes around them as variables.
    The rules exposed in this challenge are an oversimplification on how variable and identifier names are considered valid in JavaScript.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
varvalid(const char *s)
{
	size_t i;

	if (!isalpha(s[0]))
		return 0;

	for (i = 1; s[i]; i++) {
		if (!(isalpha(s[i]) || s[i] == '_' || isdigit(s[i])))
			return 0;
	}
	return 1;
}

int
main(void)
{
	assert(varvalid("result") == 1);
	assert(varvalid("odd_nums") == 1);
	assert(varvalid("2TimesN") == 0);
	assert(varvalid("rather_long_variable_name") == 1);
	assert(varvalid("count spaces") == 0);
	assert(varvalid("nTimes2") == 1);

	return 0;
}
