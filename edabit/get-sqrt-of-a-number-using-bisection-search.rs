/*

Create a function that uses bisection search to compute the approximative value of the square root of a number.

    Use any integer or float as an argument.
    Use a delta variable of 0.01 to know when a result is valid (i.e. if the result squared is between n - delta and n + delta, it's considered valid).

Examples

bisec_sqrt(69) ➞ 8.307

bisec_sqrt(16) ➞ 4.0

bisec_sqrt(12984771) ➞ 3603.439

bisec_sqrt(12.21) ➞ 3.494

Notes

    Round values up to 3 digits (round() method).
    Please use bisection search: it may take more lines but the efficiency is incredible!

*/

fn bisect_sqrt(n: f64) -> f64 {
    if n < 0.0 {
        return -1.0;
    }
    if n == 0.0 {
        return 0.0;
    }

    let eps = 1e-8;
    let mut lo = 0.0;
    let mut hi = n;
    let mut mid;
    loop {
        mid = lo + (hi-lo)/2.0;
        if hi-lo < eps {
            break;
        }

        if mid*mid < n {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return mid;
}

fn eq(x: f64, y: f64) {
    let eps = 1e-2;
    let r = bisect_sqrt(x);
    println!("{}", r);
    if (r-y).abs() >= eps {
        panic!("assertion failed");
    }
}

fn main() {
    eq(69.0, 8.307);
    eq(16.0, 4.0);
    eq(12984771.0, 3603.439);
    eq(12.21, 3.494);
    eq(121.4, 11.018);
}
