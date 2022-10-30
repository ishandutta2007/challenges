/*

There are quite a few means in mathematics, such as the arithmetic mean, the geometric mean, and many others...

Definitions and Task
Note that these are the definitions for two positive integers*:

The root mean square is the square root of the sum of their squares halved (\sqrt{\frac{a^2+b^2}{2}}).

The arithmetic mean is their sum, halved (\frac{a+b}{2}).

The geometric mean is the square root of their product (\sqrt{a\cdot b}).

The harmonic mean is 2 divided by the sum of their inverses (\frac{2}{\frac{1}{a}+\frac{1}{b}} = \frac{2ab}{a+b}).

Given two integers a and b such that a, b ∈ [1, +∞), sum the means mentioned above of a and b. Your answers must be accurate to at least 3 decimal places, but you do not have to worry about rounding or floating-point precision errors.

Test Cases
a, b -> Output

7, 6 -> 25.961481565148972
10, 10 -> 40
23, 1 -> 34.99131878607909
2, 4 -> 11.657371451581236
345, 192 -> 1051.7606599443843
You can see the correct results for more test cases using this program. This is code-golf, so the shortest valid submissions that follows the standard rules wins.

* There are many other means, but for the purposes of this challenge we'll use the ones mentioned in the "Definitions" section.

*/

fn main() {
    println!("{}", means(7.0, 6.0));
    println!("{}", means(10.0, 10.0));
    println!("{}", means(23.0, 1.0));
    println!("{}", means(2.0, 4.0));
    println!("{}", means(345.0, 192.0));
}

fn means(a: f64, b: f64) -> f64 {
    rms(a, b) + arithmetic(a, b) + geometric(a, b) + harmonic(a, b)
}

fn rms(a: f64, b: f64) -> f64 {
    (((a * a) + (b * b)) / 2.0).sqrt()
}

fn arithmetic(a: f64, b: f64) -> f64 {
    (a + b) / 2.0
}

fn geometric(a: f64, b: f64) -> f64 {
    (a * b).sqrt()
}

fn harmonic(a: f64, b: f64) -> f64 {
    (2.0 * a * b) / (a + b)
}
