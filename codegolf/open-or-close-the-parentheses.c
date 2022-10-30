/*

Every phone needs a calculator app. Because of the limited screen real estate, the developer of mine has decided to save some buttons.
Instead of having two dedicated bracket buttons - one for open ( and one for close ) - there is just a single bracket button (). It looks something like this:

My phone's calculator app

When the button is pressed, it places a bracket. Based on the input given so far, it predicts whether the bracket should be open ( or close ).

By trial and error, I have found the button to follow these rules:

If there are no unmatched brackets, the next bracket will always be open (.
Else, if the last character is a numeral 0123456789 or close ) bracket, the next bracket will be close ).
Else, if the last character is an operator + - * / or open ( bracket, the next bracket will be open (.
The challenge
Based on the given input and the rules mentioned above, predict whether the button places an open ( or close ) bracket.

Input
Either a string, an array of characters, or anything equivalent. The input will only contain the following characters*: 0 1 2 3 4 5 6 7 8 9 + - * / ( )

Output
An open ( or close ) bracket or any two consistent values representing them.

Test cases
""                  -> "("
"(1+"               -> "("
"(1+(2/3"           -> ")"
"(1+(2/3)"          -> ")"
"(1+(2/3))-8"       -> "("
"(1+(2/3))-8*("     -> "("
"(1+(2/3))-8*((5"   -> ")"
"(1+(2/3))-8*((5)"  -> ")"
"(1+(2/3))-8*((5))" -> "("
Scoring
This is code-golf, so the shortest answer in each language wins.

Note
* The actual calculator also includes the symbols .%, but you don't need to care about those.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char
predict(const char *s)
{
	size_t i, p;
	char c;

	c = 0;
	p = 0;
	for (i = 0; s[i]; i++) {
		p += (s[i] == '(');
		p -= (s[i] == ')');
		c = s[i];
	}

	if (p == 0)
		return '(';
	if (strchr("0123456789_", c))
		return ')';
	if (strchr("+-*/(", c))
		return '(';
	return ')';
}

int
main(void)
{
	assert(predict("") == '(');
	assert(predict("(1+") == '(');
	assert(predict("(1+(2/3") == ')');
	assert(predict("(1+(2/3)") == ')');
	assert(predict("(1+(2/3))-8") == '(');
	assert(predict("(1+(2/3))-8*(") == '(');
	assert(predict("(1+(2/3))-8*((5") == ')');
	assert(predict("(1+(2/3))-8*((5)") == ')');
	assert(predict("(1+(2/3))-8*((5))") == '(');

	return 0;
}
