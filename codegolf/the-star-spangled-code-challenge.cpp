/*

The flag of the United States of America contains, in its canton, 50 stars, representing the 50 states.

50-star US flag

In the past, when there were fewer states, there were of course fewer stars, and they were arranged differently. For example, from 1912-1959 (after the admission of New Mexico and Arizona but before Alaska), there were 48 stars in a 6×8 rectangular arrangement.

48-star US flag

The 37-star flag used from 1867-1877 (after the admission of Nebraska but before Colorado) had an asymmetric star pattern.

37-star US flag

In case a 51st state is added in the future, the Army Institute of Heraldry has already developed a preliminary design for a new flag.

51-star US flag

But there's no general algorithm for arranging the stars, so let's make one!

The challenge
Write a program that will, for a given number of stars to place in the canton (blue part) of a US flag, output optimal coordinates at which to place those stars. The coordinate system is defined with the canton [not the flag as a whole] with 0≤x≤W and 0≤y≤H.

For the purpose of this challenge, an “optimal” arrangement is defined as one that minimizes the mean (Euclidean) distance between a point in the canton and the center of the nearest star.

A straightforward (if maybe suboptimal) algorithm to approximate this value is:

def mean_distance_to_nearest_star(stars, width, height, point_density=100):
   """
   Approximate the mean distance between a point in the rectangle
   0 < x < width and 0 < y < height, and the nearest point in stars.

   stars -- list of (x, y) points
   width, height -- dimensions of the canton
   """
   total = 0.0
   nx = round(width * point_density)
   ny = round(height * point_density)
   for ix in range(nx):
       x = (ix + 0.5) * width / nx
       for iy in range(ny):
          y = (iy + 0.5) * width / ny
          min_dist = float('inf')
          for sx, sy in stars:
              min_dist = min(min_dist, math.hypot(x - sx, y - sy))
          total += min_dist
   return total / (nx * ny)

   Your program shall take three command-line arguments (not counting the program name itself):

The number of stars to put in the canton.
The width of the canton. (Must accept floating-point values.)
The height of the canton. (Must accept floating-point values.)
(If your preferred programming language doesn't support command-line arguments, do something reasonably equivalent, and document it in your answer.)

The output should consist of comma-separated X and Y values, one to a line. (Order of the points doesn't matter.)

For example:

~$ flagstar 5 1.4 1.0
0.20,0.20
0.20,0.80
0.70,0.50
1.20,0.20
1.20,0.80

Additional rules & notes

I have the right to close loopholes in the rules at any time.
Deadline for answers is Friday, July 4 at 24:00 CDT (UTC-05:00). Due to lack of answers, the deadline has been extended. TBA.

Include in your answer:

Your program's code
An explanation of how it works
Its output with the command-line arguments 50 1.4 1.0
Your program must run within a reasonable amount of time: At most 5 min on a typical PC. I won't be ultra-strict about this, but will disqualify your program if it takes hours.
Your program must be deterministic, i.e., always give exactly the same output for the same arguments. So, don't depend on time() or rand(). Monte Carlo methods are OK as long as you roll your own PRNG.
Only the center points of the stars matter. Don't worry about trying to avoid overlap or anything like that.

Scoring

Minimize the mean distance from a point in the canton to the nearest star. (See above.)
You may be scored based on any historical US flags, between 13 and 50 stars. The exact algorithm for weighting scores into a single ranking will be posted later.
In case of a tie, the winner will be chosen by number of net upvotes.
I will probably post a program of my own, but will exclude myself from being eligible for the checkmark.

*/

#include <cstdio>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <vector>

using namespace std;

struct Point
{
	double x, y;
};

double mean_distance_to_nearest_star(const vector<Point> &stars, double width, double height, double point_density = 100)
{
	auto total = 0.0;
	int nx = round(width * point_density);
	int ny = round(height * point_density);
	for (auto ix = 0; ix < nx; ix++)
	{
		auto x = (ix + 0.5) * width / nx;
		for (auto iy = 0; iy < ny; iy++)
		{
			auto y = (iy + 0.5) * width / ny;
			auto min_dist = DBL_MAX;
			for (auto p : stars)
				min_dist = min(min_dist, hypot(x - p.x, y - p.y));
			total += min_dist;
		}
	}
	return total / (nx * ny);
}

int main()
{
	vector<Point> stars = {
		{ 0.20, 0.20 },
		{ 0.20, 0.80 },
		{ 0.70, 0.50 },
		{ 1.20, 0.20 },
		{ 1.20, 0.80 },
	};
	auto width = 1.4;
	auto height = 1.0;

	printf("%f\n", mean_distance_to_nearest_star(stars, width, height));

	return 0;
}
