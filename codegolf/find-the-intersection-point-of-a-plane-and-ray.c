/*

Given a ray with a point and a vector and a plane with a point and a normal vector to the plane. You have to find the intersection point of the plane and the ray..

So your job if you choose to accept is to write a shortest function that will do the job.

RULES:
The submission must be a complete program
And that's all

INPUT FORMAT:
x y z rx ry rz //gives the ray point and the ray vectors
x y z px py pz //gives the point on the plane and the vector normal to plane

OUTPUT FORMAT:
(x,y,z) //intersection point

Test Case:
2 3 4 0.577 0.577 0.577
7 1 3 1 0 0
(7,8,9)
The shortest codes in bytes win.

References: https://www.siggraph.org/education/materials/HyperGraph/raytrace/rayplane_intersection.htm thanks orlp for the reference

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y, z;
} vec3;

vec3
add(vec3 a, vec3 b)
{
	return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3
sub(vec3 a, vec3 b)
{
	return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3
scale(vec3 a, double s)
{
	return (vec3){a.x * s, a.y * s, a.z * s};
}

double
dot(vec3 a, vec3 b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

vec3
rayplane(vec3 x, vec3 v, vec3 r, vec3 n)
{
	double t;
	vec3 p;

	t = dot(sub(r, x), n) / dot(v, n);
	p = add(x, scale(v, t));
	return p;
}

void
test(vec3 v[4], vec3 r)
{
	static const double eps = 1e-8;
	vec3 p;

	p = rayplane(v[0], v[1], v[2], v[3]);
	printf("%f %f %f\n", p.x, p.y, p.z);

	assert(fabs(p.x - r.x) < eps);
	assert(fabs(p.y - r.y) < eps);
	assert(fabs(p.z - r.z) < eps);
}

int
main(void)
{
	vec3 v1[4] = {
	    {2, 3, 4},
	    {0.577, 0.577, 0.577},
	    {7, 1, 3},
	    {1, 0, 0},
	};
	vec3 r1 = {7, 8, 9};

	test(v1, r1);

	return 0;
}
