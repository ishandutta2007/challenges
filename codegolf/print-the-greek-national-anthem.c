/*

In March 25, 1821, Greece fought its great war of independence. In order to honor this, your task is to print the Greek national anthem:

Σε γνωρίζω από την κόψη
του σπαθιού την τρομερή.
Σε γνωρίζω από την όψη
που με βιά μετράει τη γη.
Απ' τα κόκκαλα βγαλμένη,
των Ελλήνων τα ιερά!
Και σαν πρώτα ανδρειωμένη,
χαίρε ω χαίρε Λευτεριά!
Και σαν πρώτα ανδρειωμένη,
χαίρε ω χαίρε Λευτεριά!
Και σαν πρώτα ανδρειωμένη,
χαίρε ω χαίρε Λευτεριά!

This is my own version of the anthem (punctuation, capitalization), although the lyrics are the original.

    Any builtins printing or returning this text are forbidden, just in case.
    The printed text must be exactly as above, with an optional trailing newline.
    The output must be in UTF-8, unless it can't be supported at all, in which case the output must be encoded in the closest supported alternative.

*/

#include <stdio.h>

int
main(void)
{
	static const char *text = u8"Σε γνωρίζω από την κόψη\n"
	                          "του σπαθιού την τρομερή.\n"
	                          "Σε γνωρίζω από την όψη\n"
	                          "που με βιά μετράει τη γη.\n"
	                          "Απ' τα κόκκαλα βγαλμένη,\n"
	                          "των Ελλήνων τα ιερά!\n"
	                          "Και σαν πρώτα ανδρειωμένη,\n"
	                          "χαίρε ω χαίρε Λευτεριά!\n"
	                          "Και σαν πρώτα ανδρειωμένη,\n"
	                          "χαίρε ω χαίρε Λευτεριά!\n"
	                          "Και σαν πρώτα ανδρειωμένη,\n"
	                          "χαίρε ω χαίρε Λευτεριά!\n";

	printf("%s", text);
	return 0;
}
