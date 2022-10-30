/*

Background
Minkowski addition is a binary operation on two sets of points (usually geometric objects) in the Euclidean space. The Minkowski sum of two sets A and B is formally defined as follows:

A+B={a+b|a∈A, b∈B}

To say in plain English, given the origin and two figures, the Minkowski sum of the two figures is formed by the vector sum of each pair of points in the two figures. In the following image, the red shape is the Minkowski sum of the green and blue shapes.

It has an interesting property for two convex polygons: the edges of the original polygons are preserved (modulo translation) and sorted by polar angle (relevant info in Wikipedia),
and therefore can be computed in O(m+n) (where m and n denote the number of vertices of two polygons respectively).

Task
Given two convex polygons, compute their Minkowski sum.

Each polygon is given as an ordered list of (x,y) coordinates, and the output polygon should be represented in the same way.
You can choose the ordering of vertices (clockwise or counterclockwise), but your code should handle different starting points of the same polygon ((0,0), (0,1), (1,0) is the same as (0,1), (1,0), (0,0)).
A point that is in the middle of a straight edge is not a vertex, and therefore should not appear in the output. (See the first test case)

You may take each coordinate pair as a single complex number. The coordinates are guaranteed to be integers.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
A = [(0, 0), (0, 1), (1, 0)]
B = [(0, 0), (0, 1), (1, 1), (1, 0)]
A + B = [(0, 0), (0, 2), (1, 2), (2, 1), (2, 0)]

A = [(-1, 0), (0, 1), (1, 0)]
B = [(1, 0), (0, -1), (-1, 0)]
A + B = [(-2, 0), (-1, 1), (1, 1), (2, 0), (1, -1), (-1, -1)]

A = [(0, 0), (0, 1), (1, 3), (2, 4), (4, 5), (5, 5)]
B = [(0, 0), (1, 3), (3, 6), (6, 8), (9, 9)]
A + B = [
  (0, 0), (0, 1), (1, 4), (2, 6), (4, 9),
  (5, 10), (8, 12), (10, 13), (13, 14), (14, 14)]

A = [(0, 1), (0, 2), (1, 2), (1, 1)]
B = [(1, 0), (1, 1), (2, 1), (2, 0)]
A + B = [(1, 1), (1, 3), (3, 3), (3, 1)]

*/

#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct vec2
{
	int x, y;

	vec2 operator+(const vec2 &p)
	{
		return { x + p.x, y + p.y };
	}

	bool operator==(const vec2 &p)
	{
		return x == p.x && y == p.y;
	}
};

typedef vector<vec2> points;

void dump(const points &p)
{
	for (auto v : p)
		printf("(%d %d) ", v.x, v.y);
	printf("\n");
}

bool collinear(vec2 a, vec2 b, vec2 c)
{
	auto d = a.x * (b.y - c.y) +
			 b.x * (c.y - a.y) +
			 c.x * (a.y - b.y);
	return d == 0;
}

int dist(vec2 p, vec2 q)
{
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

int orientation(vec2 p, vec2 q, vec2 r)
{
	auto v = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (v == 0)
		return 0;
	return (v > 0) ? 1 : 2;
}

points jarvis(const points &p)
{
	auto n = p.size();
	auto l = 0u;
	for (auto i = 1u; i < n; i++)
	{
		if (p[i].x < p[l].x || (p[i].x == p[l].x && p[i].y < p[l].y))
			l = i;
	}

	auto h = points();
	auto a = l;
	do
	{
		h.push_back(p[a]);
		auto b = (a + 1) % n;
		for (auto i = 0u; i < n; i++)
		{
			if (orientation(p[a], p[i], p[b]) == 2)
				b = i;
		}
		a = b;
	} while (a != l);

	return h;
}

size_t ylb(const points &p)
{
	if (p.size() == 0)
		return 0;

	auto ym = p[0].y;
	auto n = 0u;
	for (auto i = 1u; i < p.size(); i++)
	{
		if (p[i].y < ym || (ym == p[i].y && p[i].x < p[n].x))
		{
			ym = p[i].y;
			n = i;
		}
	}
	return n;
}

void reorder(points &p)
{
	auto n = ylb(p);
	swap(p[0], p[n]);

	sort(p.begin() + 1, p.end(),
		 [&](const vec2 &a, const vec2 &b) -> bool {
			 auto d = orientation(p[0], a, b);
			 if (d == 0)
				 return dist(p[0], a) < dist(p[0], b);
			 return d == 1;
		 });
}

points prune(points &p)
{
	auto n = p.size();
	if (n < 3)
		return p;

	auto q = points();
	for (auto i = 0u; i < n; i++)
	{
		auto j = (i + 1) % n;
		auto k = (i + 2) % n;
		if (!collinear(p[i], p[j], p[k]))
			q.push_back(p[i]);
	}
	return q;
}

/*

https://cp-algorithms.com/geometry/minkowski.html
https://minkowski-sum.herokuapp.com/
http://groups.csail.mit.edu/graphics/classes/6.838/F01/lectures/MotionPlanning/MotionPlanning.pdf

*/

points minkowski(const points &a, const points &b)
{
	points c;
	for (auto p : a)
		for (auto q : b)
			c.push_back(p + q);
	c = jarvis(c);
	reorder(c);
	return prune(c);
}

void test(const points &a, const points &b, const points &r)
{
	auto p = minkowski(a, b);
	auto q = r;

	reorder(q);

	dump(p);
	dump(q);
	printf("\n");

	assert(equal(p.begin(), p.end(), q.begin()));
}

int main()
{
	test({ { 0, 0 }, { 0, 1 }, { 1, 0 } },
		 { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 0 } },
		 { { 0, 0 }, { 0, 2 }, { 1, 2 }, { 2, 1 }, { 2, 0 } });

	test({ { -1, 0 }, { 0, 1 }, { 1, 0 } },
		 { { 1, 0 }, { 0, -1 }, { -1, 0 } },
		 { { -2, 0 }, { -1, 1 }, { 1, 1 }, { 2, 0 }, { 1, -1 }, { -1, -1 } });

	test({ { 0, 0 }, { 0, 1 }, { 1, 3 }, { 2, 4 }, { 4, 5 }, { 5, 5 } },
		 { { 0, 0 }, { 1, 3 }, { 3, 6 }, { 6, 8 }, { 9, 9 } },
		 { { 0, 0 }, { 0, 1 }, { 1, 4 }, { 2, 6 }, { 4, 9 }, { 5, 10 }, { 8, 12 }, { 10, 13 }, { 13, 14 }, { 14, 14 } });

	test({ { 0, 1 }, { 0, 2 }, { 1, 2 }, { 1, 1 } },
		 { { 1, 0 }, { 1, 1 }, { 2, 1 }, { 2, 0 } },
		 { { 1, 1 }, { 1, 3 }, { 3, 3 }, { 3, 1 } });

	return 0;
}
