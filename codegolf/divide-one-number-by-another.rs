/*

Challenge
Given two numbers, output their quotient. In other words, integer divide one number by another.

Both divisor/dividend will be under 10001. Division must be performed using integer division, rounding down.

Here are some example inputs and outputs:

5       1       5
-4      2       -2
4       -2      -2
6       2       3
16      4       4
36      9       4
15      2       7
17      3       5
43      5       8
500     5       100
500     100     5
10000   2       5000
Or as CSV:

5,1,5
-4,2,-2
4,-2,-2
6,2,3
16,4,4
36,9,4
15,2,7
17,3,5
43,5,8
500,5,100
500,100,5
10000,2,5000
Rules
Standard loopholes not allowed
You must use integer division, not floating point division
This is code-golf. Shortest answer wins, but will not be selected.

The second input (denominator) will never be equal to 0.

Why?
I'm interested in seeing answers in esoteric languages, like Brainfuck and Retina. Answers in regular languages will be trivial, however I would really like to see answers in these languages.

I will be giving a bounty of +50 reputation to a Retina answer.

*/

fn main() {
    let tab = vec![
        [5, 1, 5],
        [-4, 2, -2],
        [4, -2, -2],
        [6, 2, 3],
        [16, 4, 4],
        [36, 9, 4],
        [15, 2, 7],
        [17, 3, 5],
        [43, 5, 8],
        [500, 5, 100],
        [500, 100, 5],
        [10000, 2, 5000],
    ];

    for v in tab {
        assert_eq!(v[0] / v[1], v[2]);
    }
}
