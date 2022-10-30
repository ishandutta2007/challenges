/*

In this challenge, you'll create a function that takes the following three arguments:

    The electric-field vector E at some event in spacetime as measured in some inertial frame.
    The magnetic-field vector B at the same event as measured in the same frame.
    A velocity vector u.

Each of these vectors will be given as an array of its Cartesian components (e.g., the electric field will be given as [E_x, E_y, E_z]). Each component will be given as a number.

(There's no need to worry about units while solving; assume that E and B share a unit,
and also that we've set the speed of light to 1, which renders velocities unitless.)

Given valid parameters, your function will return the electric and magnetic fields as measured in a second inertial frame,
whose velocity as measured in the first frame is u (the third argument).
Each of these output-vectors should be an array of its Cartesian components as strings,
expressed in scientific notation to three significant digits (like "6.63e-34").
Return these vectors as the elements of an array, with the electric field coming first (i.e., [[E_x, E_y, E_z], [B_x, B_y, B_z]]).

(Assume that the Cartesian axes of the second frame are parallel to the corresponding axes of the first frame.)

To calculate the electric and magnetic fields in the second frame, use the following pair of vector equations, where "×" means the cross product and "•" means the dot product:

E′ = cosh(φ)E + sinh(φ)(û × B) - 2sinh²(.5φ)(û • E)û

B′ = cosh(φ)B - sinh(φ)(û × E) - 2sinh²(.5φ)(û • B)û

Here, the "primed" fields on the left (E′ and B′) are the fields as measured in the second frame, and the "unprimed" fields on the right (E and B) are the fields as measured in the first frame.

The quantity û is the unit vector pointing in the same direction as u.
Each of its Cartesian components is equal to the corresponding component of u divided by ||u||,
which is the magnitude of u (you can calculate ||u|| by taking the square root of the sum of the squares of u's Cartesian components).

Finally, the quantity φ that's fed to the hyperbolic functions is the relative rapidity of the frames,
defined as φ = artanh(||u||) (i.e., the inverse hyperbolic tangent of the frames' relative speed).

The parameters will be valid unless ||u|| ≥ 1 (because the relative speed of frames must be subluminal). If ||u|| ≥ 1, return "invalid velocity".

Examples

transformFields(
  [-26.24, 555.1, 53.32],  // electric field
  [1.030, 12.01, 287.8],  // magnetic field
  [-1, 0, 0] // velocity (too fast!)
) ➞ "invalid velocity"

transformFields(
  [-26.24, 555.1, 53.32],
  [1.030, 12.01, 287.8],
  [-.9999, 0, 0]  // (okay)
) ➞ [
  ["-2.62e+1", "5.96e+4", "2.92e+3"],
  ["1.03e+0", "-2.92e+3", "5.96e+4"]
]

transformFields(
  [1.234, 0, 0],
  [0, 1.234, 0],
  [.5, .5, 0]
) ➞ [
  ["1.49e+0", "-2.56e-1", "8.73e-1"],
  ["-2.56e-1", "1.49e+0", "8.73e-1"]
]

Notes

One way to verify that the results are accurate is by comparing E • B with E′ • B′.
The dot product of the electric field and the magnetic field is a Lorentz scalar, which means that it's
a quantity whose value all observers agree on, regardless of their relative motion. Another Lorentz scalar is ||E||² - ||B||².

Light is characterized by electric and magnetic fields that share a magnitude and are mutually perpendicular
(the Lorentz scalars mentioned in the previous paragraph guarantee that if these conditions are satisfied in one frame then they're satisfied in all frames).
The third example fits the bill.

Another interesting tidbit: in the second example, note that the x-components of the fields in the second
frame don't seem to differ from those in the first frame.
That's because u is parallel to the x-axis here,
and electromagnetic field-components parallel to the "boost" direction transform to themselves.

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
scale(vec3 a, float s)
{
	return (vec3){a.x * s, a.y * s, a.z * s};
}

double
dot(vec3 a, vec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3
cross(vec3 a, vec3 b)
{
	return (vec3){
	    a.y * b.z - a.z * b.y,
	    a.z * b.x - a.x * b.z,
	    a.x * b.y - a.y * b.x,
	};
}

double
length(vec3 a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

int
eq(vec3 a, vec3 b, double eps)
{
	return fabs(a.x - b.x) < eps &&
	       fabs(a.y - b.y) < eps &&
	       fabs(a.z - b.z) < eps;
}

int
transform(vec3 E, vec3 B, vec3 v, vec3 *Ep, vec3 *Bp)
{
	double p, cp, sp, sph;
	double l;
	vec3 u;

	l = length(v);
	if (l >= 1)
		return -1;

	p = atanh(l);
	u = (vec3){0, 0, 0};
	if (l != 0)
		u = scale(v, 1 / l);

	cp = cosh(p);
	sp = sinh(p);
	sph = sinh(0.5 * p);

	*Ep = scale(E, cp);
	*Ep = add(*Ep, scale(cross(u, B), sp));
	*Ep = sub(*Ep, scale(u, 2 * sph * sph * dot(u, E)));

	*Bp = scale(B, cp);
	*Bp = sub(*Bp, scale(cross(u, E), sp));
	*Bp = sub(*Bp, scale(u, 2 * sph * sph * dot(u, B)));

	return 0;
}

void
test(vec3 v[3], vec3 r[2], double eps)
{
	vec3 p[2];

	if (transform(v[0], v[1], v[2], &p[0], &p[1]) < 0)
		assert(r == NULL);
	else
		assert(eq(p[0], r[0], eps) && eq(p[1], r[1], eps));
}

int
main(void)
{
	vec3 v1[] = {
	    {-26.24, 555.1, 53.32},
	    {1.030, 12.01, 287.8},
	    {-1, 0, 0},
	};

	vec3 v2[] = {
	    {-26.24, 555.1, 53.32},
	    {1.030, 12.01, 287.8},
	    {-.9999, 0, 0},
	};
	vec3 r2[] = {
	    {-2.62e+1, 5.96e+4, 2.92e+3},
	    {1.03e+0, -2.92e+3, 5.96e+4},
	};

	vec3 v3[] = {
	    {1.234, 0, 0},
	    {0, 1.234, 0},
	    {.5, .5, 0},
	};
	vec3 r3[] = {
	    {1.49e+0, -2.56e-1, 8.73e-1},
	    {-2.56e-1, 1.49e+0, 8.73e-1},
	};

	vec3 v4[] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, -.99},
	};
	vec3 r4[] = {
	    {0.00e+0, 0.00e+0, 0.00e+0},
	    {0.00e+0, 0.00e+0, 0.00e+0},
	};

	vec3 v5[] = {
	    {24.23, 0.5208, 109.3},
	    {0.8391, 3.820, -12.29},
	    {.2001, -.1956, -.8332},
	};
	vec3 r5[] = {
	    {8.70e+1, -1.92e+1, 1.29e+2},
	    {4.29e+1, 9.89e+1, -2.45e+1},
	};

	test(v1, NULL, 0);
	test(v2, r2, 1.5e+0);
	test(v3, r3, 1e-3);
	test(v4, r4, 1e-8);
	test(v5, r5, 1e-1);

	return 0;
}
