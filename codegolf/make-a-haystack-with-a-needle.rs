/*

(Essentially the inverse of Find the needle in the haystack)

Given two tuples, (w, h) and (x, y), generate a haystack composed of a single random printable ASCII character of w width and h height with a needle made of a different random printable ASCII character at (x, y) when measured from the upper-left.

For example, when given (5,4) for the width and height, and (3,1) (zero-indexed) for the location of the needle, a possible haystack could be the following:

#####
###N#
#####
#####
Another possibility could be

*****
***$*
*****
*****
among hundreds of others.

Rules and Clarifications
Input and output can be given by any convenient method. This means you can take input as a list of list of integers, as a single string, as two integers via command-line and a tuple via function argument, etc.
You can print the result to STDOUT or return it as a function result.
Either a full program or a function are acceptable.
You can choose whether the (x, y) tuple is zero-indexed or one-indexed, but please specify in your solution which you're using.
You do not get to pick which characters to use. That's part of the challenge - randomly selecting the characters.
Every possible output for a given input must have a non-zero chance of appearing, but the randomness doesn't need to be uniform.
The haystack is guaranteed to be at least 2x2 in size, so it's unambiguous which is the needle and which is the hay.
There is only ever one needle, and it's only ever one character in size, and it's guaranteed to be within the boundaries of the haystack.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

fn main() {
    haystack(5, 4, 3, 1, '#', 'N');
    haystack(5, 4, 3, 1, '*', '$');
}

fn haystack(w: isize, h: isize, x: isize, y: isize, a: char, b: char) {
    for i in 0..h {
        for j in 0..w {
            if j != x || i != y {
                print!("{}", a);
            } else {
                print!("{}", b);
            }
        }
        println!();
    }
    println!();
}
