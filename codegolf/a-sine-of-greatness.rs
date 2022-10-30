/*

Introduction
Everyone's heard of sine (sin), cosine (cos), tangent (tan), cotangent (cot), secant (sec), and cosecant (csc). Nearly every angle has them.

Far less known, or remembered, are the exsecant (exsec), excosecant (excsc), versine (versin), and coversine (cvs). Nearly every angle has those as well. There are some that are even less known, but we'll just stick to these.

I've created a visualization of these for angle θ, which is 45°.

The Challenge

Create a program that takes an input of an angle n, in degrees, and will output:

the sine of angle n

the cosine of angle n

the tangent of angle n

the secant of angle n

at least one of the following. Every additional item from this list will earn a bonus -5%, for a maximum of -25%.

exsecant of angle n

cosecant of angle n

excosecant of angle n

versine of angle n

coversine of angle n

cotangent of angle n

If your score is a decimal after applying a bonus, round up to the nearest whole number.

Input

You may accept your input through STDIN or through a function call. A single argument, n, will be passed.

n will always be a whole integer that is greater than 0, but less than or equal to 90.

Output

Here is an example of the output for sine of 45°. All output items must be in this format. The order of the items does not matter.

sine: 0.70710678118
All items must have exactly 4 numbers after the decimal (precision to the ten-thousandths). Below are a few examples of rounding.

0 -> 0.0000
1 -> 1.0000
0.2588190451 -> 0.2588
5.67128181962 -> 5.6713
10 -> 10.0000
12.4661204396 -> 12.4661
Any nonexistent/undefined results should default to 0.

Example

myprogram(60)

sine: 0.8660
cosine: 0.5000
tangent: 1.7321
secant: 2.0000
exsecant: 1.0000
cosecant: 1.1547
excosecant: 0.1547
versine: 0.5000
coversine: 0.1340
cotangent: 0.5774

*/

use std::f64::consts::PI;

fn main() {
    output(60.0);
}

fn output(d: f64) {
    let r = deg2rad(d);
    println!("sine: {:.4}", sine(r));
    println!("cosine: {:.4}", cosine(r));
    println!("tangent: {:.4}", tangent(r));
    println!("secant: {:.4}", secant(r));
    println!("exsecant: {:.4}", exsecant(r));
    println!("cosecant: {:.4}", cosecant(r));
    println!("excosecant: {:.4}", excosecant(r));
    println!("versine: {:.4}", versine(r));
    println!("coversine: {:.4}", coversine(r));
    println!("cotangent: {:.4}", cotangent(r));
}

fn deg2rad(x: f64) -> f64 {
    x * PI / 180.0
}

fn sine(x: f64) -> f64 {
    f64::sin(x)
}

fn cosine(x: f64) -> f64 {
    f64::cos(x)
}

fn tangent(x: f64) -> f64 {
    f64::tan(x)
}

fn secant(x: f64) -> f64 {
    1.0 / cosine(x)
}

fn cosecant(x: f64) -> f64 {
    1.0 / sine(x)
}

fn excosecant(x: f64) -> f64 {
    cosecant(x) - 1.0
}

fn exsecant(x: f64) -> f64 {
    secant(x) - 1.0
}

fn versine(x: f64) -> f64 {
    1.0 - cosine(x)
}

fn coversine(x: f64) -> f64 {
    1.0 - sine(x)
}

fn cotangent(x: f64) -> f64 {
    1.0 / tangent(x)
}
