/*

A new type of chocolate arrived in the local shop. The chocolate comes in bars, each bar consisting of N squares.
Bars are factory made and only come in sizes which are full powers of two. In other words a single bar has 1,2,4,8,16,… squares.

To fully asses the quality of chocolate Mirko must sample at least K squares. His friend Slavko would also like to try some of the chocolate.
Since Mirko is in a hurry to try the chocolate himself, he decides to break the bar he bought in pieces, such that he has exactly K squares, and leaves the rest (if any) to Slavko.
The bars are a bit brittle, so Mirko can break them only on their exact center. In other words, from one bar with D squares, he can get two bars with D/2 squares.

Write a program that will determine the minimal number of breaks Mirko must perform in order to obtain exactly K squares (not necessarily in one piece).
Also, determine the smallest bar size Mirko must buy in order to have at least K squares.

Input

The first and only line of input will contain one integer K (1≤K≤1000000), number of squares Mirko must sample.

Output

The first and only line of output should contain two integers, separated by a single space.
The first integer is the smallest bar size Mirko must buy. The second the smallest number of breaks.

*/

fn main() {
    assert_eq!(breaks(6), (8, 2));
    assert_eq!(breaks(7), (8, 3));
    assert_eq!(breaks(5), (8, 3));
}

fn next_power_of_two(n: usize) -> usize {
    let mut p = 1;
    while p < n {
        p <<= 1;
    }
    p
}

fn breaks(n: usize) -> (usize, usize) {
    let (mut b, mut s) = (next_power_of_two(n), n);
    let (p, mut c) = (b, 0);
    while s > 0 && s != b {
        b >>= 1;
        if s > b {
            s -= b;
        }
        c += 1;
    }
    (p, c)
}
