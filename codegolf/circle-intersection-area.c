/*

Description:

Given x and y positions of two circles along with their radii, output the area of intersection of the two circle.
Input:

You will be given following input :

array 1 = x and y positions of circle a
array 2 = x and y positions of circle b
radius  = radii of the two congruent circles

Input method :

([12 , 20] , [20 , 18] , 12)     ---> two array and number
([12 , 20 , 20 , 18] , 12)       ---> array and a number
(12 , 20 , 20 , 18 , 12)         ---> all five numbers
('12 20' , '20 18' , 12)         ---> 2 strings and a number
('12 20 20 18' , 12)             ---> string and a number
('12 20 20 18 12')               ---> one string

Output :

    A non-negative integer (no decimal) equal to area of intersection of two circles.

    A string equal to the above mentioned integer.

Note :

    Output must be >= 0, since area can't be negative.
    In case of decimal round down to nearest integer

Examples :

([0, 0], [7, 0], 5)                   ---> 14

([0, 0], [0, 10], 10)                 ---> 122

([5, 6], [5, 6], 3)                   ---> 28

([-5, 0], [5, 0], 3)                  ---> 0

([10, 20], [-5, -15], 20)             ---> 15

([-7, 13], [-25, -5], 17)             ---> 132

([-12, 20], [43, -49], 23)            ---> 0

Winning criteria :

This is code-golf so shortest code in bytes for each language wins.
Suggestions :

    Provide a TIO link so it can be tested.
    Provide an explanation so others can understand your code

These are only suggestions and are not mandatory.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

double
distance(Point a, Point b)
{
	double x, y;

	x = a.x - b.x;
	y = a.y - b.y;
	return hypot(x, y);
}

/*

This is based on a generic formula from MathWorld for non-congruent circles:

A = r².arccos((d² + r² - R²) / 2dr) +
    R².arccos((d² + R² - r²) / 2dR) -
    sqrt((-d + r + R)(d + r - R)(d -r + R)(d + r + R)) / 2

where d is the distance between the two centers and r and R are the radii.

With R = r, this is simplified to:

A = 2r².arccos(d / 2r) - d.sqrt((2r - d) * (2r + d)) / 2

And with r' = 2r:

A = (r'².arccos(d / r') - d.sqrt(r'² - d²)) / 2

Note: If d is greater than 2r, Math.acos() will return NaN, which is coerced to 0 when the right-shift is applied. This is the expected result, because d > 2r means that there's no area at all.

*/

double
area(Point a, Point b, double r)
{
	double d;

	d = distance(a, b);
	r = 2 * r;
	if (d > r)
		return 0;
	return (r * r * acos(d / r) - d * sqrt(r * r - d * d)) / 2;
}

void
test(Point a, Point b, int r, int R)
{
	int A;

	A = area(a, b, r);
	printf("%d\n", A);
	assert(A == R);
}

int
main(void)
{
	test((Point){0, 0}, (Point){7, 0}, 5, 14);
	test((Point){0, 0}, (Point){0, 10}, 10, 122);
	test((Point){5, 6}, (Point){5, 6}, 3, 28);
	test((Point){-5, 0}, (Point){5, 0}, 3, 0);
	test((Point){10, 20}, (Point){-5, -15}, 20, 15);
	test((Point){-7, 13}, (Point){-25, -5}, 17, 132);
	test((Point){-12, 20}, (Point){43, -49}, 23, 0);

	return 0;
}
