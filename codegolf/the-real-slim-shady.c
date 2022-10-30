/*

Echo the following in as few bytes as possible:

I'm Slim Shady. Yes, I'm the real Shady.
All you other Slim Shadys are just imitating.
So, won't the real Slim Shady please stand up?
Please stand up. Please stand up.
The following five words must appear EXACTLY ONCE in your code:

I'm
Slim
Shady
real
stand

*/

#include <stdio.h>

int
main(void)
{
	static const char *txt = "I'm Slim Shady. Yes, I'm the real Shady.\n"
	                         "All you other Slim Shadys are just imitating.\n"
	                         "So, won't the real Slim Shady please stand up?\n"
	                         "Please stand up. Please stand up.";

	printf("%s\n", txt);
	return 0;
}
