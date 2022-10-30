/*

A large flat field measures 50x50 kilometers.
At a time t = 0, a bomb explodes somewhere on the field.
There are 3 scattered sensors with synchronized clocks that record the exact time (in seconds) that the sound of the exploding bomb reaches them.

Given the x, y coordinates of each of the 3 sensors and the recorded time of each, find the location of the bomb:

bomb([[x1, y1, t1], [x2, y2, t2], [x3, y3, t3]]) ➞ [xb, yb]
// Bomb location

Examples

bomb([[0, 0, 72.886], [0, 50, 72.886], [25, 25, 72.886]]) ➞ [0, 25]

bomb([[0, 50, 145.773], [50, 50, 206.154], [50, 0, 145.773]]) ➞ [0, 0]

bomb([[5, 8, 48.872], [12, 21, 35.107], [24, 20, 22.203]]) ➞ [21, 13]

bomb([[18, 42, 35.558], [39, 16, 106.004], [7, 24, 32.202]]) ➞ [8, 35]

Notes

    The origin is at one corner of the square field so all the coordinates are positive integers in km units.
    The bomb's coordinates are integers.
    The speed of sound in air is 0.343 km/sec.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x, y;
} Vec2i;

typedef struct {
	double x, y;
} Vec2;

typedef struct {
	double x, y, r;
} Circle;

int
intersect(Circle c1, Circle c2, Vec2 r[2])
{
	double r0 = c1.r;
	double r1 = c2.r;

	double dx = c2.x - c1.x;
	double dy = c2.y - c1.y;
	double d = sqrt(dx * dx + dy * dy);
	if (d > r0 + r1 || d < fabs(r0 - r1))
		return -1;
	if (d == 0 && r0 == r1)
		return 1;

	double a = (r0 * r0 - r1 * r1 + d * d) / (2 * d);
	double h = sqrt(r0 * r0 - a * a);
	double x2 = c1.x + (dx * a) / d;
	double y2 = c1.y + (dy * a) / d;
	double rx = -dy * (h / d);
	double ry = dx * (h / d);

	r[0] = (Vec2){x2 + rx, y2 + ry};
	r[1] = (Vec2){x2 - rx, y2 - ry};
	return 0;
}

Circle
circle(double p[3])
{
	return (Circle){p[0], p[1], p[2] * 0.34321};
}

Vec2i
mode(Vec2i *p, size_t n)
{
	size_t i, j, k;
	size_t c, m;

	if (n == 0)
		return (Vec2i){-1, -1};

	k = 0;
	m = 0;
	for (i = 0; i < n; i++) {
		c = 1;
		for (j = i + 1; j < n; j++) {
			if (p[i].x == p[j].x && p[i].y == p[j].y)
				c++;
		}
		if (c > m) {
			m = c;
			k = i;
		}
	}
	return p[k];
}

/*

https://en.wikipedia.org/wiki/Multilateration

The sound is traveling out radially from a point source in this scenario.

Since the point of intersection is symmetric for the destination and the source for a radial shape,
we can treat it as if the sound is radiating out of a sensor in the shape of a circle with
center = sensor position
radius = speed of sound * time traveled

The intersection of all the sensor circles gives the point of the bomb.
The point of the bomb also occurs when there is no intersection but one of the sensor has a time reading of 0 (the bomb is at that sensor).

*/

Vec2i
bomb(double v[][3])
{
	size_t i, j, k, l;
	Circle c[3];
	Vec2i p[16];
	Vec2 r[2];

	for (i = 0; i < 3; i++) {
		c[i] = circle(v[i]);
		if (c[i].r == 0)
			return (Vec2i){c[i].x, c[i].y};
	}

	l = 0;
	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < 3; j++) {
			if (intersect(c[i], c[j], r) != 0)
				return (Vec2i){-1, -1};

			for (k = 0; k < 2; k++)
				p[l++] = (Vec2i){round(r[k].x), round(r[k].y)};
		}
	}
	return mode(p, l);
}

void
test(double v[][3], Vec2i r)
{
	Vec2i p;

	p = bomb(v);
	assert(!memcmp(&r, &p, sizeof(p)));
}

int
main(void)
{
	double v1[][3] = {
	    {5, 8, 48.872},
	    {12, 21, 35.107},
	    {24, 20, 22.203},
	};
	Vec2i r1 = {21, 13};

	double v2[][3] = {
	    {18, 42, 35.558},
	    {39, 16, 106.004},
	    {7, 24, 32.202},
	};
	Vec2i r2 = {8, 35};

	double v3[][3] = {
	    {42, 19, 98.004},
	    {3, 17, 122.484},
	    {28, 29, 61.294},
	};
	Vec2i r3 = {29, 50};

	double v4[][3] = {
	    {46, 23, 89.434},
	    {19, 8, 73.119},
	    {17, 33, 0.0},
	};
	Vec2i r4 = {17, 33};

	double v5[][3] = {
	    {9, 39, 35.468},
	    {15, 27, 44.407},
	    {31, 18, 73.119},
	};
	Vec2i r5 = {21, 41};

	double v6[][3] = {
	    {3, 49, 127.815},
	    {16, 27, 58.672},
	    {11, 40, 92.792},
	};
	Vec2i r6 = {34, 18};

	double v7[][3] = {
	    {48, 40, 169.849},
	    {18, 36, 105.683},
	    {12, 42, 116.691},
	};
	Vec2i r7 = {3, 3};

	double v8[][3] = {
	    {10, 20, 38.013},
	    {4, 18, 53.6},
	    {36, 29, 55.7},
	};
	Vec2i r8 = {17, 31};

	double v9[][3] = {
	    {0, 0, 72.886},
	    {0, 50, 72.886},
	    {25, 25, 72.886},
	};
	Vec2i r9 = {0, 25};

	double v10[][3] = {
	    {5, 5, 0},
	    {5, 5, 0},
	    {5, 5, 0},
	};
	Vec2i r10 = {5, 5};

	double v11[][3] = {
	    {0, 50, 145.773},
	    {50, 50, 206.154},
	    {50, 0, 145.773},
	};
	Vec2i r11 = {0, 0};

	test(v1, r1);
	test(v2, r2);
	test(v3, r3);
	test(v4, r4);
	test(v5, r5);
	test(v6, r6);
	test(v7, r7);
	test(v8, r8);
	test(v9, r9);
	test(v10, r10);
	test(v11, r11);

	return 0;
}
