/*

Given three sides of a triangle, print area of this triangle.

Test cases:

In: 2,3,4

Out: 2.90473750965556

In: 3,4,5

Out: 6

Given the sides a, b, and c, you can assume that a>0, b>0, c>0, a+b>c, b+c>a, and c+a>b.

This is code-golf, shortest answer per language in bytes wins.

*/

fn main() {
    println!("{}", heron(2.0, 3.0, 4.0));
    println!("{}", heron(3.0, 4.0, 5.0));
}

fn heron(a: f64, b: f64, c: f64) -> f64 {
    let s = (a + b + c) / 2.0;
    (s*(s-a)*(s-b)*(s-c)).sqrt()
}

