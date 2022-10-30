/*

Provided a digit between 0 and 9 (inclusive), your function/subroutine should print all numbers between -100 and 100 (inclusive) that contain the given digit.

For example:

Input: 9
Output: -99 -98 -97 -96 -95 -94 -93 -92 -91 -90 -89 -79 -69 -59 -49 -39 -29 -19 -9 9 19 29 39 49 59 69 79 89 90 91 92 93 94 95 96 97 98 99
Rules:

You cannot use strings (in whatever way they are represented in your chosen language) or char arrays. (Except to print the answer to the console.)
You cannot use arrays.
Scoring:

Score = length of subroutine/function (whitespace will not be counted)

The answer with the lowest score wins.

Whitespace will NOT be counted. Please format your code properly!

Some answers are using regular expressions, which may violate the no strings rule, as pointed out by some members. These answers will not be accepted.

Please test your code with 0 before posting.

*/

fn main() {
    assert_eq!(
        gen(9),
        vec![
            -99, -98, -97, -96, -95, -94, -93, -92, -91, -90, -89, -79, -69, -59, -49, -39, -29,
            -19, -9, 9, 19, 29, 39, 49, 59, 69, 79, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
        ]
    );
}

fn gen(d: isize) -> Vec<isize> {
    let mut r = vec![];
    for i in -100..101 {
        if has(i, d) {
            r.push(i);
        }
    }
    return r;
}

fn has(mut n: isize, d: isize) -> bool {
    n = n.abs();
    loop {
        if n % 10 == d {
            return true;
        }

        n /= 10;
        if n == 0 {
            break;
        }
    }
    return false;
}
