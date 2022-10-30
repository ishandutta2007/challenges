/*

Computing the volume of a circle is pretty straight-forward: Pi x Radius x Radius, or simply Pi x r 2.

What if we wanted to computer the volume of two circles? Easy, just sum it! Yet, what about two intersecting circles, much like the classic Venn diagram?

Your goal is to write a program that takes two unit-circles (radius of one) at given locations, and compute that shape's volume. You must make sure to not double-count the intersecting volume! (i.e. you must not sum this red area twice).

As a starting point, check out how to compute circle segments.

Formal Inputs & Outputs
Input Description
On standard input you will be given four floating-point space-delimited values: x y u w. x and y are the first circle's position in Cartesian coordinates. The second pair u and w are the second circle's position.

Note that the given circles may not actually intersect. If this is the case, return the sum of both circles (which will always be Pi x 2 since our circles are unit-circles).

Output Description
Print the summed volume of the two circles, up to an accuracy of 4 digits after the decimal place.

Sample Inputs & Outputs

Sample Input
-0.5 0 0.5 0

Sample Output
5.0548

*/

use std::f64::consts::PI;

fn main() {
    test(-0.5, 0.0, 0.5, 0.0, 5.0548);
    test(5.0, 5.0, 10.0, -10.0, PI * 2.0);
}

fn test(x1: f64, y1: f64, x2: f64, y2: f64, a: f64) {
    let p = venn_area(x1, y1, x2, y2);
    println!("{}", p);
    assert_eq!(f64::abs(p - a) < 1e-4, true);
}

fn venn_area(x1: f64, y1: f64, x2: f64, y2: f64) -> f64 {
    let r = 1.0;
    (2.0 * PI * r * r) - intersection(x1, y1, x2, y2, r)
}

fn intersection(x1: f64, y1: f64, x2: f64, y2: f64, mut r: f64) -> f64 {
    let d = distance(x1, y1, x2, y2);
    r *= 2.0;
    if d > r {
        0.0
    } else {
        (r * r * f64::acos(d / r) - d * f64::sqrt(r * r - d * d)) / 2.0
    }
}

fn distance(x1: f64, y1: f64, x2: f64, y2: f64) -> f64 {
    let dx = x2 - x1;
    let dy = y2 - y1;
    f64::hypot(dx, dy)
}
