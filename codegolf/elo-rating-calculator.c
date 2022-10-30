/*

Task

Your task is to calculate the new Elo rating (FIDE rating system) for a player after winning, losing or drawing a game of chess.

To calculate the Elo rating two formulas are needed:

R' = R0 + K*(S - E)
E = 1 / (1 + 10 ^ ((R1 - R0) / 400))
where:

R' is the new rating for player0,
R0 is the current rating of player0 and R1 is the current rating of player1,
S is the score of the game: 1 if player0 wins, 0 if player0 loses or 0.5 if player0 draws,
K = 40 if the given history has a length < 30, even if it exceeds 2400
K = 20 if the given history has a length >= 30 and never exceeds 2400 (<2400),
K = 10 if the given history has a length >= 30 and exceeds 2400 at any point (>=2400)
(if history has a length < 30 but a max value >= 2400 K will equal 40)

Input
History of player0's ratings as an array of positive integers greater than 0, where the last item is the players current rating. If no history is given, the current rating will be 1000
Rating of player1 as an integer
Score, either 1, 0 or 0.5

Output
R', A decimal integer of player0's new rating

Examples
input: [], 1500, 1
  K = 40 (length of history is less than 30)
  E = 1 / (1 + 10 ^ ((1500 - 1000) / 400)) = 0.0532
  R' = 1000 + 40*(1 - 0.0532) = 1038

output: 1038

input: [1000, 1025, 1050, 1075, 1100, 1125, 1150, 1175, 1200, 1225, 1250, 1275, 1300, 1325, 1350, 1375, 1400, 1425, 1450, 1475, 1500, 1525, 1550, 1575, 1600, 1625, 1650, 1675, 1700, 1725], 1000, 0
  K = 20 (length of history is more than 30 but never exceeds 2400)
  E = 1 / (1 + 10 ^ ((1000 - 1725) / 400)) = 0.9848
  R' = 1725 + 20*(0 - 0.9848) = 1705

output: 1705

input: [1000, 1025, 1050, 1075, 1100, 1125, 1150, 1175, 1200, 1225, 1250, 1275, 1300, 1325, 1350, 1375, 1400, 1425, 1450, 1475, 1500, 1525, 1550, 1575, 1600, 1625, 1650, 1800, 2100, 2500], 2200, 0.5
  K = 10 (length of history is more than 30 and exceeds 2400)
  E = 1 / (1 + 10 ^ ((2200 - 2500) / 400)) = 0.8490
  R' = 2500 + 10*(0.5 - 0.8490) = 2497

output: 2497

Test cases:
[2256,25,1253,1278,443,789], 3999, 0.5 -> 809
[783,1779,495,1817,133,2194,1753,2169,834,521,734,1234,1901,637], 3291, 0.5 -> 657
[190,1267,567,2201,2079,1058,1694,112,780,1182,134,1077,1243,1119,1883,1837], 283, 1 -> 1837
[1665,718,85,1808,2546,2193,868,3514,436,2913,6,654,797,2564,3872,2250,2597,1208,1928,3478,2359,3909,581,3892,1556,1175,2221,3996,3346,238], 2080, 1 -> 248
[1543,2937,2267,556,445,2489,2741,3200,528,964,2346,3467,2831,3746,3824,2770,3207,613,2675,1692,2537,1715,3018,2760,2162,2038,2637,741,1849,41,193,458,2292,222,2997], 3814, 0.5 -> 3002

Notes

You won't get an input with fewer scores than 30 and a maximum score higher than 2400

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
elo(int *h, size_t n, int r1, double s)
{
	double k, r, e;
	int r0, rm;
	size_t i;

	rm = 0;
	for (i = 0; i < n; i++)
		rm = max(rm, h[i]);

	r0 = 1000;
	if (n)
		r0 = h[n - 1];

	if (n < 30)
		k = 40;
	else if (n >= 30 && rm < 2400)
		k = 20;
	else
		k = 10;

	e = 1.0 / (1 + pow(10, ((r1 - r0) / 400.0)));
	r = r0 + k * (s - e);
	r = round(r);
	return r;
}

void
test(int *h, size_t n, int r1, double s, int r)
{
	int p;

	p = elo(h, n, r1, s);
	printf("%d\n", p);
	assert(p == r);
}

int
main(void)
{
	int a1[] = {1000, 1025, 1050, 1075, 1100, 1125, 1150, 1175, 1200, 1225, 1250, 1275, 1300, 1325, 1350, 1375, 1400, 1425, 1450, 1475, 1500, 1525, 1550, 1575, 1600, 1625, 1650, 1675, 1700, 1725};
	int a2[] = {1000, 1025, 1050, 1075, 1100, 1125, 1150, 1175, 1200, 1225, 1250, 1275, 1300, 1325, 1350, 1375, 1400, 1425, 1450, 1475, 1500, 1525, 1550, 1575, 1600, 1625, 1650, 1800, 2100, 2500};
	int a3[] = {2256, 25, 1253, 1278, 443, 789};
	int a4[] = {783, 1779, 495, 1817, 133, 2194, 1753, 2169, 834, 521, 734, 1234, 1901, 637};
	int a5[] = {190, 1267, 567, 2201, 2079, 1058, 1694, 112, 780, 1182, 134, 1077, 1243, 1119, 1883, 1837};
	int a6[] = {1665, 718, 85, 1808, 2546, 2193, 868, 3514, 436, 2913, 6, 654, 797, 2564, 3872, 2250, 2597, 1208, 1928, 3478, 2359, 3909, 581, 3892, 1556, 1175, 2221, 3996, 3346, 238};
	int a7[] = {1543, 2937, 2267, 556, 445, 2489, 2741, 3200, 528, 964, 2346, 3467, 2831, 3746, 3824, 2770, 3207, 613, 2675, 1692, 2537, 1715, 3018, 2760, 2162, 2038, 2637, 741, 1849, 41, 193, 458, 2292, 222, 2997};

	test(NULL, 0, 1500, 1, 1038);
	test(a1, nelem(a1), 1000, 0, 1705);
	test(a2, nelem(a2), 2200, 0.5, 2497);
	test(a3, nelem(a3), 3999, 0.5, 809);
	test(a4, nelem(a4), 3291, 0.5, 657);
	test(a5, nelem(a5), 283, 1, 1837);
	test(a6, nelem(a6), 2080, 1, 248);
	test(a7, nelem(a7), 3814, 0.5, 3002);

	return 0;
}
