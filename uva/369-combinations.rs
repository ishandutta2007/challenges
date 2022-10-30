/*

Computing the exact number of ways that N things can be taken M at a time can be a great challenge when N and/or M become very large.
Challenges are the stuff of contests. Therefore, you are to make just such a computation given the following:

GIVEN:
5 ≤ N ≤ 100, and 5 ≤ M ≤ 100, and M ≤ N
Compute the EXACT value of:
C =N!/((N − M)! × M!)
You may assume that the final value of C will fit in a 32-bit Pascal LongInt or a C long.
For the record, the exact value of 100! is:
93,326,215,443,944,152,681,699,238,856,266,700,490,715,968,264,381,621,
468,592,963,895,217,599,993,229,915,608,941,463,976,156,518,286,253,
697,920,827,223,758,251,185,210,916,864,000,000,000,000,000,000,000,000

Input

The input to this program will be one or more lines each containing zero or more leading spaces, a value for N, one or more spaces, and a value for M.
The last line of the input file will contain a dummy N, M pair with both values equal to zero. Your program should terminate when this line is read.

Output

The output from this program should be in the form:
N things taken M at a time is C exactly.

Sample Input

100 6
20 5
18 6
0 0

Sample Output

100 things taken 6 at a time is 1192052400 exactly.
20 things taken 5 at a time is 15504 exactly.
18 things taken 6 at a time is 18564 exactly.

*/

fn main() {
    assert_eq!(combinations(100, 6), 1192052400);
    assert_eq!(combinations(20, 5), 15504);
    assert_eq!(combinations(18, 6), 18564);
    assert_eq!(combinations(20, 21), 0);
    assert_eq!(combinations(20, 20), 1);
}

fn combinations(mut n: isize, mut m: isize) -> isize {
    if m > n {
        return 0;
    }

    if n - m < m {
        m = n - m;
    }

    let mut r = 1;
    for i in 1..m + 1 {
        r = (r * n) / i;
        n = n - 1;
    }
    return r;
}
