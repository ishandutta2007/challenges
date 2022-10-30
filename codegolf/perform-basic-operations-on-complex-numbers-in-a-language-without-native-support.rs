/*

Your code has to provide the following functions:

read(x)
Reads a complex number from the standard input. It has to accept and evaluate something in the form of for example 1.42 + 3i.

print(x)
Prints the complex number in the form of, for example 1.23 - 4.32i

add(x,y)
sub(x,y)
mult(x,y)
div(x,y)
Adds, subtracts, multiplies and respectively divides the two complex numbers.

It is enough if your functions are accurate to two digits after the decimal point, of course, it can be more if you so wish. The input will never have more than two digits after the decimal point.

Any language without native support for complex numbers may be used. Similarly, libraries or other language features which deal with complex numbers are not permitted.
The point is, you have to do all the handling of complex numbers by yourself.

Scoring
This is a code golf. The score is the sum of the lengths of the function bodies. For example, int add(int a, int b) {return a+b;} will have a length of 11 because of return a+b.
Your solution must have a main program which demonstrates the use of the functions (for easier evaluation of your solution), but it will not be part of the scoring.

You can store the complex numbers in any way you wish, but the functions must have exactly the same amount of parameters as in the above description.

EDIT: For languages that support it, you can use operator overloading instead of the add, sub, etc. functions.

EDIT 2: To prohibit the cheap #define all_your_code_here A, I'll try to clarify the "only function bodies count" better:
every character in the code counts, except for the overhead required to declare and define the functions and the libraries required to do basic I/O.
By basic I/O I still mean no language features which directly deal with complex numbers.
The main or equivalent where you call these functions don't count but you are not allowed to do anything besides using those functions for demonstrative purpose.

*/

use std::ops::*;

#[derive(Debug, Copy, Clone, PartialEq)]
struct Complex {
    r: f64,
    i: f64,
}

impl Add<Complex> for Complex {
    type Output = Self;

    fn add(self, other: Complex) -> Complex {
        Complex {
            r: self.r + other.r,
            i: self.i + other.i,
        }
    }
}

impl Sub<Complex> for Complex {
    type Output = Self;

    fn sub(self, other: Complex) -> Complex {
        Complex {
            r: self.r - other.r,
            i: self.i - other.i,
        }
    }
}

impl Mul<Complex> for Complex {
    type Output = Self;

    fn mul(self, other: Complex) -> Complex {
        Complex {
            r: (self.r * other.r) - (self.i * other.i),
            i: (self.r * other.i) + (self.i * other.r),
        }
    }
}

impl Div<Complex> for Complex {
    type Output = Self;

    fn div(self, other: Complex) -> Complex {
        let (a, b) = (self.r, self.i);
        let (c, d) = (other.r, other.i);
        let s = (c * c) + (d * d);
        Complex {
            r: ((a * c) + (b * d)) / s,
            i: ((b * c) - (a * d)) / s,
        }
    }
}

impl AddAssign for Complex {
    fn add_assign(&mut self, other: Self) {
        *self = self.add(other);
    }
}

impl SubAssign for Complex {
    fn sub_assign(&mut self, other: Self) {
        *self = self.sub(other);
    }
}

impl MulAssign for Complex {
    fn mul_assign(&mut self, other: Self) {
        *self = self.mul(other);
    }
}

impl DivAssign for Complex {
    fn div_assign(&mut self, other: Self) {
        *self = self.div(other);
    }
}

fn main() {
    let mut a = Complex { r: 1.2, i: 3.4 };
    let b = Complex { r: 4.5, i: 5.0 };
    a += b;
    a -= b;
    a *= b;
    a /= b;
    println!("{:?}", a);
}
