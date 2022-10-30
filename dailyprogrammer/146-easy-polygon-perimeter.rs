/*

(Easy): Polygon Perimeter

A Polygon is a geometric two-dimensional figure that has n-sides (line segments) that closes to form a loop.
Polygons can be in many different shapes and have many different neat properties, though this challenge is about Regular Polygons.
Our goal is to compute the permitter of an n-sided polygon that has equal-length sides given the circumradius. This is the distance between the center of the Polygon to any of its vertices; not to be confused with the apothem!
Formal Inputs & Outputs
Input Description

Input will consist of one line on standard console input. This line will contain first an integer N, then a floating-point number R.
They will be space-delimited. The integer N is for the number of sides of the Polygon, which is between 3 to 100, inclusive. R will be the circumradius, which ranges from 0.01 to 100.0, inclusive.
Output Description

Print the permitter of the given N-sided polygon that has a circumradius of R. Print up to three digits precision.
Sample Inputs & Outputs
Sample Input 1

5 3.7

Sample Output 1

21.748

Sample Input 2

100 1.0

Sample Output 2

6.282

*/

use std::f64::consts::PI;

fn main() {
    println!("{}", perimeter(5.0, 3.7));
    println!("{}", perimeter(100.0, 1.0));
}

fn perimeter(n: f64, r: f64) -> f64 {
    2.0*n*r*(PI/n).sin()
}
