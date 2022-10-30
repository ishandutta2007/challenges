/*

Your task is to calculate the square root of 2 using Newton's Method - with a slight twist.
Your program is to calculate an iteration using Newton's Method, and output the source code for the following iteration (which must be able to do the same).

Newton's method is fairly exhaustively described on Wikipedia

To calculate square root 2 using Newtons method, you:

Define f(x) = x^2 - 2
Define f'(x) = 2x
Define x[0] (the initial guess) = 1
Define x[n+1] = x[n] - (f[n] / f'[n])
Each iteration will move x[n] closer to the square root of two. So -

x[0] = 1
x[1] = x[0] - f(x[0])/f'(x[0]) = 1 - (1 ^ 2 - 2) / (2 * 1) = 1.5
x[2] = x[1] - f(x[1])/f'(x[1]) = 1.5 - (1.5 ^ 2 - 2) / (2 * 1.5) = 1.416666667
x[3] = x[2] - f(x[2])/f'(x[1]) = 1.416666667 - (1.416666667 ^ 2 - 2) / (2 * 1.416666667) = 1.414215686
and so on
Your program will:

Calculate x[n] where n is the amount of times the program has been run
Output the source code to a valid program in the same language which must calculate x[n+1] and satisfy the same criteria of this question.
The first line of the source code must be the calculate result, properly commented. If the source requires something particular (such as a shebang) on the first line, the result may be put on the second line.
Note that

Your program must use an initial guess of x[0] = 1
The Standard Loopholes apply
Any in-build power, square root or xroot functions are forbidden
Your program must not accept any input whatsoever. It must be entirely self contained.
Your score is the size of your initial program in UTF-8 bytes. The lowest score wins.

*/

use std::f64::consts::*;

fn main() {
    assert_eq!(true, (sqrt2() - SQRT_2).abs() < 1e-12);
}

fn sqrt2() -> f64 {
    let f = |x: f64| -> f64 { x * x - 2.0 };
    let df = |x: f64| -> f64 { 2.0 * x };

    let mut v = 1.0;
    for _ in 0..100 {
        v -= f(v) / df(v);
    }
    v
}
