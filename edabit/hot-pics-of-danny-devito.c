/*

I'm trying to watch some lectures to study for my next exam but I keep getting distracted by meme compilations, vine compilations, anime, and more on my favorite video platform.

Your job is to help me create a function that takes a string and checks to see if it contains the following words or phrases:

    "anime"
    "meme"
    "vines"
    "roasts"
    "Danny DeVito"

If it does, return "NO!". Otherwise, return "Safe watching!".
Examples

preventDistractions("vines that butter my eggroll") ➞ "NO!"

preventDistractions("Hot pictures of Danny DeVito") ➞ "NO!"

preventDistractions("How to ace BC Calculus in 5 Easy Steps") ➞ "Safe watching!"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
preventdistractions(const char *s)
{
	static const char *tab[] = {
		"anime",
		"meme",
		"vines",
		"roasts",
		"Danny DeVito",
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (strstr(s, tab[i]))
			return "NO!";
	}
	return "Safe watching!";
}

int
main(void)
{
	assert(strcmp(preventdistractions("vines that butter my eggroll"), "NO!") == 0);
	assert(strcmp(preventdistractions("Hot pictures of Danny DeVito"), "NO!") == 0);
	assert(strcmp(preventdistractions("top 10 insert random yt celebrity roasts"), "NO!") == 0);
	assert(strcmp(preventdistractions("best anime food ever!"), "NO!") == 0);
	assert(strcmp(preventdistractions("How to Be a Productive Member of Society"), "Safe watching!") == 0);
	assert(strcmp(preventdistractions("How to ace BC Calculus in 5 Easy Steps"), "Safe watching!") == 0);

	return 0;
}
