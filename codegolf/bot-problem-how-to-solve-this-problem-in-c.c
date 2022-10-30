/*

Programming problem: In BotLand, Robots can understand all words of any combination of letters and letters with leading or trailing (not both) numeric value.
Given a word W (string of alphanumeric). Write a function to check if W is Bot word. Don't use library functions/ regex.

Example:

Input: BotLand
Output: Bot word

Input: BotLand77
Output: Bot word

Input: 1Bot2Land3
Output: Non Bot word

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *
botword(const char *s)
{
	size_t n;

	n = strlen(s);
	if (isdigit(s[0]) && isdigit(s[n - 1]))
		return "Non Bot word";
	return "Bot word";
}

int
main(void)
{
	assert(!strcmp(botword("BotLand"), "Bot word"));
	assert(!strcmp(botword("BotLand77"), "Bot word"));
	assert(!strcmp(botword("1Bot2Land3"), "Non Bot word"));

	return 0;
}
