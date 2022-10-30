/*

A new 'hacky' phone is launched, which has the feature of connecting to any Wi-Fi network from any distance away,
as long as there aren't any obstructions between the hotspot and the phone.
Given a string, return how many Wi-Fi hotspots I'm able to connect to.

    The phone is represented as a P.
    A hotspot is represented as an *.
    An obstruction is represented as a #. You cannot access a hotspot if they are behind one of these obstructions.

Examples

nonstopHotspot("*   P  *   *") ➞ 3

nonstopHotspot("*  * #  * P # * #") ➞ 1

nonstopHotspot("***#P#***") ➞ 0

Notes

    There will be only one phone.
    No other characters, other than spaces, will appear in the tests.

*/

#include <assert.h>
#include <stdio.h>

size_t
hotspots(const char *s)
{
	size_t i, c;

	c = 0;
	for (i = 0; s[i] != 'P'; i++) {
		switch (s[i]) {
		case '\0':
			return 0;
		case '#':
			c = 0;
			break;
		case '*':
			c++;
			break;
		}
	}

	while (s[i] && s[i] != '#')
		c += (s[i++] == '*');

	return c;
}

int
main(void)
{
	assert(hotspots("*   P  *   *") == 3);
	assert(hotspots("*  * #  * P # * #") == 1);
	assert(hotspots("***#P#***") == 0);
	assert(hotspots("#P#") == 0);
	assert(hotspots("P") == 0);
	assert(hotspots("P       #") == 0);
	assert(hotspots("P     *  # *") == 1);
	assert(hotspots("*   # * P") == 1);
	assert(hotspots("# *****  **  P     ** #    ") == 9);

	return 0;
}
