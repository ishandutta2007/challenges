/*

One way to estimate the area of a circle is to draw a square that just encompasses the circle and mark points randomly (with uniform probability) with a marker.
Then, when you get tired of marking points, count up the number of points that you marked that landed in the circle and divide it by the total number of points that you marked.
That gives you an idea of how large the circle is relative to the square. Your job is to judge how accurate this is for given circles and experiment outcomes.

\includegraphics[width=0.30\textwidth ]{circle}

Figure 1: An illustration of the random marking process.

Input

Input contains up to 1000 test cases, one test case per line.
Each line has three space-separated numbers: r m c, where 0<r≤1000 is a real number with at most 5 digits past the decimal indicating the true radius of the circle,
1≤m≤100000 is an integer indicating the total number of marked points, and 0≤c≤m is an integer indicating the number of marked points that fall in the circle.
Input ends with a line containing three zeros, which should not be processed.

Output

For each test case, print a line containing two numbers: the true area of the circle and the estimate according to the experiment.
Both numbers may have a relative error of at most 10^-5.

*/

use std::f64::consts::*;

fn main() {
    test(1.0, 100.0, 75.0, 3.141592654, 3.0);
    test(10.0, 5000.0, 4023.0, 314.1592654, 321.84);
    test(3.0, 21.0, 17.0, 28.27433388, 29.14285714);
}

fn test(r: f64, m: f64, c: f64, ra: f64, rb: f64) {
    let eps = 1e-5;
    let (a, b) = circle_area(r, m, c);
    println!("{} {}", a, b);
    assert_eq!((ra - a).abs() < eps, true);
    assert_eq!((rb - b).abs() < eps, true);
}

fn circle_area(r: f64, m: f64, c: f64) -> (f64, f64) {
    let a = PI * r * r;
    let b = (r * r * 4.0 * c) / m;
    (a, b)
}
