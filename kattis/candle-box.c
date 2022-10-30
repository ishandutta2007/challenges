/*

Rita loves her Birthday parties. She is really happy when blowing the candles at the Happy Birthday’s clap melody. Every year since the age of four she adds her birthday candles (one for every year of age) to a candle box. Her younger daydreaming brother Theo started doing the same at the age of three. Rita’s and Theo’s boxes look the same, and so do the candles.

One day Rita decided to count how many candles she had in her box:

– No, no, no! I’m younger than that!

She just realized Theo had thrown some of his birthday candles in her box all these years. Can you help Rita fix the number of candles in her candle box?

Task

Given the difference between the ages of Rita and Theo, the number of candles in Rita’s box, and the number of candles in Theo’s box, find out how many candles Rita needs to remove from her box such that it contains the right number of candles.

Input

The first line of the input has one integer D, corresponding to the difference between the ages of Rita and Theo.

The second line has one integer R, corresponding to the number of candles in Rita’s box.

The third line has one integer T, corresponding to the number of candles in Theo’s box.

Constraints

1 <= D <= 20 Difference between the ages of Rita and Theo
4 <= R < 1000 Number of candles in Rita’s box
0 <= T < 1000 Number of candles in Theo’s box

Output

An integer representing the number of candles Rita must remove from her box such that it contains the right number of candles.

*/

#include <assert.h>

int
age(int c, int o)
{
	int x;

	c = (c + o) << 1;
	x = 0;
	while (x * x + x - c < 0)
		x++;
	return (x * x + x - c == 0) ? x : -1;
}

int
candles(int d, int r, int t)
{
	int c, x, y;

	for (c = 0;; c++) {
		x = age(r--, 6);
		y = age(t++, 3);
		if (x - y == d)
			break;
	}
	return c;
}

int
main(void)
{
	assert(candles(2, 26, 8) == 4);
	return 0;
}
