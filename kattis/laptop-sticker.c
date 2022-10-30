/*

Your school has provided you with a laptop computer! However, they insist on putting a laptop sticker with their logo on your new computer.
That sticker might be very large, and it can’t be rotated! Will it fit, with one centimeter to spare on all sides?

Input

The single line of input contains four integers wc, hc, ws and hs (1≤wc,hc,ws,hs≤1000), where wc is the width of your new laptop computer,
hc is the height of your new laptop computer, ws is the width of the laptop sticker, and hs
is the height of the laptop sticker. All measurements are in centimeters.

Output

Output a single integer, which is 1 if the laptop sticker will fit on your new laptop computer, without rotating, but with one centimeter space on all sides, and 0 if the laptop sticker won’t fit.

*/

#include <assert.h>

int
stickable(int wc, int hc, int ws, int hs)
{
	return (wc - ws >= 2) && (hc - hs >= 2);
}

int
main(void)
{
	assert(stickable(30, 30, 27, 27) == 1);
	assert(stickable(35, 30, 25, 29) == 0);
	assert(stickable(30, 35, 30, 35) == 0);

	return 0;
}
