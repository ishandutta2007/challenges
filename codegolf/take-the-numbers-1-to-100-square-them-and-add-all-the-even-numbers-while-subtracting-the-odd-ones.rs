/*

Description

The task is simple enough:
Take the numbers 1 to 100, square them, and add all the even numbers while subtracting the odd ones.

It is taken from this blog post: R Coding Challenge: 7 (+1) Ways to Solve a Simple Puzzle

Output

The result should be 5050.

Rules

No cheating: it can be shown that this boils down to adding the numbers 1 to 100, yet the the algo has to do the actual work described above!

*/

fn main() {
    assert_eq!(number(), 5050)
}

fn number() -> isize {
    let mut r = 0;
    for i in 1..101 {
        let v = i*i;
        if v&1 == 0 {
            r += v;
        } else {
            r -= v;
        }
    }
    r
}
