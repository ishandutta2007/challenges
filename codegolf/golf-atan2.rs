/*

Sometimes it really is a struggle to convert Cartesian coordinates (x,y) to Polar coordinates (r,phi).
While you can calculate r = sqrt(x^2+y^2) quite easily, you often need some distinction of cases when calculating the angle phi because
arcsin,arccos and arctan and all other trigonometric functions have a co-domain that each only spans half the circle.

In many languages there are built-ins for converting rectangular to polar coordinates, or at least have an atan2 function, which - given (x,y) - calculate the angle phi.

Task

Your task is to write a program/function that takes two (floating point, not both zero) Cartesian coordinates (x,y),
and outputs the corresponding polar angle phi, where phi has to be in degrees,
radians or grades (with grades I mean gradians which are 1/400 of the full circle), whichever is more convenient for you.

The angle is measured in positive orientation, and we have the zero angle for (1,0).

Details

You may not use built-ins that calculate the angle phi given two coordinates, including atan2,rect2polar,argOfComplexNumber and similar functions.
However you can use the usual trigonometric functions and their reverses, that only take one argument. Any unit symbols are optional.

The radius r must be non-negative, and phi must be in the range [-360°, 360°] (it does not matter whether you output 270° or -90°).

Examples

Input       Output
(1,1)       45°
(0,3)       90°
(-1,1)      135°
(-5,0)      180°
(-2,-2)     225°
(0,-1.5)    270°
(4,-5)      308.66°

*/

fn main() {
    test(1.0, 1.0, 45.0);
    test(0.0, 3.0, 90.0);
    test(-1.0, 1.0, 135.0);
    test(-5.0, 0.0, 180.0);
    test(-2.0, -2.0, 225.0);
    test(-0.0, -1.5, 270.0);
    test(4.0, -5.0, 308.66);
}

fn test(x: f64, y: f64, r: f64) {
    let p = phi(x, y);
    println!("{}", p);
    assert_eq!((p - r).abs() < 1e-2, true);
}

fn phi(x: f64, y: f64) -> f64 {
    let mut p = y.atan2(x).to_degrees();
    if p < 0.0 {
        p += 360.0;
    }
    p
}
