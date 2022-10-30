/*

Given a list of tiles, place them so that their adjacent squares matched.
Tile order is sequential and tile placement is guaranteed to be unique by the test do not backtrack.
If this program is given input that has backtracking and
if more than one place where the tile can fit, it will fail and not find the right place
if the first successful placement is not the right place.

The algorithm used for this is just try placing a link one by one moving by 1 square at a time on
a grid and check if the constraint is satisfied. Really slow but simple.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Rect Rect;
typedef struct Grid Grid;
typedef struct Tile Tile;

struct Rect {
	size_t x, y, w, h;
};

struct Grid {
	char **square;
	size_t size;
	Rect bounds;

	Tile *tile;
	size_t ntile;
};

struct Tile {
	char **quadrant[4];
	size_t size;
	size_t orientation;
};

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
max(size_t a, size_t b)
{
	return (a > b) ? a : b;
}

size_t
min(size_t a, size_t b)
{
	return (a < b) ? a : b;
}

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (p == NULL) {
		perror("calloc");
		exit(1);
	}
	return p;
}

void
rotatequadrant(char **q, size_t s, int n)
{
	size_t x, y;
	int i;
	char c;

	n %= 4;
	if (n < 0)
		n += 4;

	for (i = 0; i < n; i++) {
		for (y = 0; y < s - 1; y++) {
			for (x = y; x < s; x++) {
				c = q[y][x];
				q[y][x] = q[x][y];
				q[x][y] = c;
			}
		}

		for (y = 0; y < s; y++) {
			for (x = 0; x < s / 2; x++) {
				c = q[y][x];
				q[y][x] = q[y][s - x - 1];
				q[y][s - x - 1] = c;
			}
		}
	}
}

void
freegrid(Grid *g)
{
	Tile *t;
	size_t i, j, k;

	if (g == NULL)
		return;

	for (i = 0; i < g->size; i++)
		free(g->square[i]);
	free(g->square);

	for (i = 0; i < g->ntile; i++) {
		t = &g->tile[i];
		for (j = 0; j < nelem(t->quadrant); j++) {
			for (k = 0; k < t->size; k++)
				free(t->quadrant[j][k]);
			free(t->quadrant[j]);
		}
	}

	free(g->tile);
	free(g);
}

Grid *
newgrid(const char **tiles)
{
	const char *p;
	size_t i, j, k, n;
	size_t x, y, w, h;
	Grid *g;
	Tile *t;

	if (tiles == NULL)
		return NULL;

	g = NULL;
	n = 0;
	w = h = 0;
	y = 0;
	for (i = 0;; i++) {
		p = tiles[i];
		if (p == NULL || *p == '\0') {
			if (n++ == 0)
				h = y;

			if (h != y) {
				fprintf(stderr, "tile #%zu has height mismatched at line %zu: (%zu != %zu)\n", n, i + 1, h, y);
				goto error;
			}

			if (p == NULL)
				break;

			y = 0;
			continue;
		}

		y++;
		for (x = 0; p[x] != '\0'; x++) {
			if (!isdigit(p[x])) {
				fprintf(stderr, "tile #%zu has non-valid digit at line %zu with char code '0x%x'\n", n, i + 1, p[x]);
				goto error;
			}
		}
		if (i == 0)
			w = x;

		if (w != x) {
			fprintf(stderr, "tile #%zu has width mismatched at line %zu: (%zu != %zu)\n", n, i + 1, w, x);
			goto error;
		}
	}

	if (w != h || w < 2) {
		fprintf(stderr, "tileset has invalid square dimension: %zux%zu\n", w, h);
		goto error;
	}

	g = ecalloc(1, sizeof(*g));

	g->ntile = n;
	g->tile = ecalloc(g->ntile, sizeof(*g->tile));
	for (i = 0; i < g->ntile; i++) {
		t = &g->tile[i];
		t->size = w;
		for (j = 0; j < nelem(t->quadrant); j++) {
			t->quadrant[j] = ecalloc(h, sizeof(*t->quadrant[j]));
			for (k = 0; k < t->size; k++)
				t->quadrant[j][k] = ecalloc(w, sizeof(*t->quadrant[j][k]));
		}
	}

	t = g->tile;
	for (y = i = 0;; i++) {
		p = tiles[i];
		if (p == NULL)
			break;
		if (*p == '\0') {
			y = 0;
			t++;
			continue;
		}

		for (j = 0; j < nelem(t->quadrant); j++)
			memmove(t->quadrant[j][y], p, w * sizeof(*p));

		y++;
	}
	for (i = 0; i < g->ntile; i++) {
		t = &g->tile[i];
		for (j = 0; j < nelem(t->quadrant); j++)
			rotatequadrant(t->quadrant[j], t->size, j);
	}

	g->size = w * n * 2 + 1;
	g->square = ecalloc(g->size, sizeof(*g->square));
	for (i = 0; i < g->size; i++)
		g->square[i] = ecalloc(g->size, sizeof(*g->square[i]));
	g->bounds = (Rect){g->size / 2, g->size / 2, 0, 0};

	return g;

error:
	fprintf(stderr, "detected error for given tileset, aborting!\n");
	freegrid(g);
	return NULL;
}

bool
freesquares(const Grid *g, size_t x, size_t y, size_t size)
{
	char **s;
	size_t i, j;

	s = g->square;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (isdigit(s[y + i][x + j]))
				return false;
		}
	}

	return true;
}

bool
adjtile(const Grid *g, const Tile *t, size_t tx, size_t ty, size_t sx, size_t sy, int *match, bool *adj)
{
	char **q, **s;

	s = g->square;
	q = t->quadrant[t->orientation];

	if (q[ty][tx] == s[sy][sx]) {
		*match += 1;
		return true;
	}

	if (isdigit(s[sy][sx]))
		*adj = false;

	return false;
}

bool
tilefit(const Grid *g, const Tile *t, size_t x, size_t y)
{
	size_t i, n;
	int match;
	bool adj;

	n = t->size;
	if (!freesquares(g, x, y, n))
		return false;

	match = 0;
	adj = true;

	if (!adjtile(g, t, 0, 0, x - 1, y, &match, &adj))
		adjtile(g, t, 0, 0, x, y - 1, &match, &adj);

	if (!adjtile(g, t, n - 1, 0, x + n - 1, y - 1, &match, &adj))
		adjtile(g, t, n - 1, 0, x + n, y, &match, &adj);

	if (!adjtile(g, t, 0, n - 1, x - 1, y + n - 1, &match, &adj))
		adjtile(g, t, 0, n - 1, x, y + n, &match, &adj);

	if (!adjtile(g, t, n - 1, n - 1, x + n, y + n - 1, &match, &adj))
		adjtile(g, t, n - 1, n - 1, x + n - 1, y + n, &match, &adj);

	for (i = 1; i < n - 1; i++) {
		adjtile(g, t, i, 0, x + i, y - 1, &match, &adj);
		adjtile(g, t, i, n - 1, x + i, y + n, &match, &adj);
		adjtile(g, t, 0, i, x - 1, y + i, &match, &adj);
		adjtile(g, t, n - 1, i, x + n, y + i, &match, &adj);
	}

	return match >= 2 && adj;
}

void
puttile(Grid *g, Tile *t, size_t x, size_t y)
{
	Rect *r;
	char **q, **s;
	size_t i, j, n;

	n = t->size;
	s = g->square;
	q = t->quadrant[t->orientation];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			s[y + i][x + j] = q[i][j];
	}

	r = &g->bounds;
	r->w = max(x + n, r->x + r->w) - min(r->x, x);
	r->h = max(y + n, r->y + r->h) - min(r->y, y);
	r->x = min(r->x, x);
	r->y = min(r->y, y);
}

void
printlink(const Grid *g, Rect r, const Tile *t, size_t nl)
{
	char **p, c;
	size_t x, y;

	p = g->square;

	printf("\nlink %zu", nl);
	if (t->orientation != 0)
		printf(" // note this tile had to be rotated %zu degrees clockwise", t->orientation * 90);
	printf("\n");

	for (y = 0; y < r.h; y++) {
		for (x = 0; x < r.w; x++) {
			c = p[r.y + y][r.x + x];
			printf("%c", isdigit(c) ? c : ' ');
		}
		printf("\n");
	}
}

bool
trylink(Grid *g, Tile *t)
{
	Rect r;
	size_t n, x, y, z;

	r = g->bounds;
	if (r.w == 0) {
		puttile(g, t, r.x, r.y);
		return true;
	}

	n = t->size;
	r.x -= n;
	r.y -= n;
	r.w += n;
	r.h += n;

	for (y = r.y; y <= r.y + r.h; y++) {
		for (x = r.x; x <= r.x + r.w; x++) {
			for (z = 0; z < 4; z++) {
				t->orientation = z;
				if (tilefit(g, t, x, y)) {
					puttile(g, t, x, y);
					return true;
				}
			}
		}
	}

	return false;
}

void
link(const char **tiles)
{
	Grid *g;
	Tile *t;
	size_t i, n;

	g = newgrid(tiles);
	if (g == NULL)
		return;

	n = g->ntile;
	t = g->tile;

	printf("%zu tiles\n", n);
	for (i = 0; i < n; i++, t++) {
		if (!trylink(g, t)) {
			printf("\nfailed to find a link on tile %zu\n", i + 1);
			break;
		}

		printlink(g, g->bounds, t, i + 1);
	}

	printf("\n\n");
	freegrid(g);
}

int
main(void)
{
	const char *tiles1[] = {
	    "11", // 1
	    "23",
	    "",
	    "44", // 2
	    "11",
	    "",
	    "16", // 3
	    "36",
	    "",
	    "51", // 4
	    "71",
	    "",
	    "46", // 5
	    "26",
	    "",
	    "14", // 6
	    "68",
	    0,
	};

	const char *tiles2[] = {
	    "12", // 1
	    "34",
	    "",
	    "36", // 2
	    "15",
	    "",
	    "56", // 3
	    "78",
	    "",
	    "78", // 4
	    "90",
	    "",
	    "46", // 5
	    "26",
	    "",
	    "88", // 6
	    "01",
	    "",
	    "93", // 7
	    "54",
	    0,
	};

	const char *tiles3[] = {
	    "11", // 1
	    "12",
	    "",
	    "12", // 2
	    "93",
	    "",
	    "93", // 3
	    "99",
	    "",
	    "39", // 4
	    "98",
	    "",
	    "95", // 5
	    "86",
	    "",
	    "57", // 6
	    "66",
	    "",
	    "77", // 7
	    "57",
	    "",
	    "13", // 8
	    "24",
	    "",
	    "45", // 9
	    "47",
	    "",
	    "24", // 10
	    "39",
	    0,
	};

	link(tiles1);
	link(tiles2);
	link(tiles3);

	return 0;
}
