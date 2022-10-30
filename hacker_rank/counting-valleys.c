/*

Gary is an avid hiker. He tracks his hikes meticulously, paying close attention to small details like topography.
During his last hike he took exactly n steps. For every step he took, he noted if it was an uphill U, or a downhill D step.

Gary's hikes start and end at sea level and each step up or down represents a 1 unit change in altitude. We define the following terms

A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.

Given Gary's sequence of up and down steps during his last hike, find and print the number of valleys he walked through.

For example, if Gary's path is s=DDUUUUDD, he first enters a valley 2 units deep.
Then he climbs out an up onto a mountain 2 units high.
Finally, he returns to sea level and ends his hike.

*/

#include <stdio.h>

int
valleys(const char *s)
{
	size_t i;
	int b, c, n;

	n = 0;
	c = 0;
	for (i = 0; s[i] != '\0'; i++) {
		b = c;
		if (s[i] == 'D')
			c--;
		else if (s[i] == 'U')
			c++;
		else
			return -1;

		if (c == 0 && b < c)
			n++;
	}
	return n;
}

int
main(void)
{
	printf("%d\n", valleys("DDUUUUDD"));
	printf("%d\n", valleys("UDDDUDUU"));
	printf("%d\n", valleys("DDUUDDUDUUUD"));
	return 0;
}
