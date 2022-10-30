/*

A baseball player's batting average is calculated by the following formula:

BA = (number of hits) / (number of official at-bats)

Batting averages are always expressed rounded to the nearest thousandth with no leading zero. The top 3 MLB batting averages of all-time are:

    Ty Cobb .366
    Rogers Hornsby .358
    Shoeless Joe Jackson .356

The given list represents a season of games. Each list item indicates a player's [hits, official at bats] per game. Return a string with the player's seasonal batting average rounded to the nearest thousandth.

Examples

batting_avg([[0, 0], [1, 3], [2, 2], [0, 4], [1, 5]]) ➞ ".286"

batting_avg([[2, 5], [2, 3], [0, 3], [1, 5], [2, 4]]) ➞ ".350"

batting_avg([[2, 3], [1, 5], [2, 4], [1, 5], [0, 5]]) ➞ ".273"

Notes

    The number of hits will not exceed the number of official at-bats.
    The list includes official at-bats only. No other plate-appearances (walks, hit-by-pitches, sacrifices, etc.) are included in the list.
    HINT: Think in terms of total hits and total at-bats.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
batting(int (*a)[2], size_t n, char *b, size_t l)
{
	char s[128], *p;
	double h, t;
	size_t i;

	h = t = 0;
	for (i = 0; i < n; i++) {
		h += a[i][0];
		t += a[i][1];
	}
	if (t == 0 || h > t)
		return NULL;

	snprintf(s, sizeof(s), "%.3f", h / t);
	p = (s[0] == '0') ? (s + 1) : s;
	snprintf(b, l, "%s", p);
	return b;
}

void
test(int (*a)[2], size_t n, const char *r)
{
	char b[128];

	assert(batting(a, n, b, sizeof(b)));
	assert(!strcmp(b, r));
}

int
main(void)
{
	int a1[][2] = {{0, 0}, {1, 3}, {2, 2}, {0, 4}, {1, 5}};
	int a2[][2] = {{2, 5}, {2, 3}, {0, 3}, {1, 5}, {2, 4}};
	int a3[][2] = {{2, 3}, {1, 5}, {2, 4}, {1, 5}, {0, 5}};
	int a4[][2] = {{1, 4}, {0, 5}, {4, 4}, {1, 5}, {0, 5}};
	int a5[][2] = {{3, 3}, {0, 5}, {0, 4}, {3, 5}, {1, 5}};
	int a6[][2] = {{0, 5}, {1, 2}, {1, 1}, {4, 5}, {1, 6}, {2, 5}, {0, 4}, {3, 3}, {0, 4}, {0, 3}};
	int a7[][2] = {{1, 6}, {1, 4}, {0, 4}, {3, 6}, {2, 5}, {1, 4}, {1, 6}, {0, 1}, {2, 5}, {2, 6}};
	int a8[][2] = {{2, 4}, {1, 6}, {2, 6}, {1, 4}, {4, 4}, {3, 6}, {2, 5}, {0, 4}, {0, 5}, {0, 5}};
	int a9[][2] = {{2, 6}, {0, 3}, {2, 5}, {1, 3}, {4, 6}, {1, 4}, {0, 5}, {0, 5}, {0, 6}, {3, 3}};
	int a10[][2] = {{1, 6}, {0, 5}, {0, 6}, {0, 3}, {2, 4}, {3, 3}, {1, 6}, {3, 4}, {0, 5}, {1, 5}};
	int a11[][2] = {{1, 1}, {1, 5}, {0, 3}, {1, 3}, {2, 6}, {0, 4}, {0, 5}, {1, 5}, {1, 6}, {2, 2}};
	int a12[][2] = {{2, 6}, {0, 5}, {1, 4}, {2, 4}, {4, 5}, {1, 6}, {2, 2}, {0, 4}, {1, 5}, {0, 5}};
	int a13[][2] = {{0, 3}, {1, 5}, {3, 4}, {0, 6}, {1, 2}, {3, 4}, {4, 5}, {0, 5}, {0, 5}, {1, 5}};
	int a14[][2] = {{3, 3}, {0, 1}, {0, 3}, {3, 5}, {1, 5}, {1, 1}, {2, 6}, {0, 4}, {1, 5}, {2, 6}};
	int a15[][2] = {{1, 6}, {1, 5}, {1, 6}, {3, 5}, {3, 5}, {1, 5}, {1, 4}, {2, 6}, {1, 5}, {3, 6}};

	test(a1, nelem(a1), ".286");
	test(a2, nelem(a2), ".350");
	test(a3, nelem(a3), ".273");
	test(a4, nelem(a4), ".261");
	test(a5, nelem(a5), ".318");
	test(a6, nelem(a6), ".316");
	test(a7, nelem(a7), ".277");
	test(a8, nelem(a8), ".306");
	test(a9, nelem(a9), ".283");
	test(a10, nelem(a10), ".234");
	test(a11, nelem(a11), ".225");
	test(a12, nelem(a12), ".283");
	test(a13, nelem(a13), ".295");
	test(a14, nelem(a14), ".333");
	test(a15, nelem(a15), ".321");

	return 0;
}
