/*

The sum of the squares of the first ten natural numbers is, 12+22+⋯+102=385

The square of the sum of the first ten natural numbers is,

(1+2+...+10)2=552=3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is

3025−385=2640

For a given input n, find the difference between the sum of the squares of the first n natural numbers and the square of the sum.

Test cases

1       => 0
2       => 4
3       => 22
10      => 2640
24      => 85100
100     => 25164150

This challenge was first announced at Project Euler #6.
Winning Criteria

    There are no rules about what should be the behavior with negative or zero input.

    The shortest answer wins.

*/

fn main() {
    assert_eq!(ssd(1), 0);
    assert_eq!(ssd(2), 4);
    assert_eq!(ssd(3), 22);
    assert_eq!(ssd(10), 2640);
    assert_eq!(ssd(24), 85100);
    assert_eq!(ssd(100), 25164150);
}

fn ssd(n: isize) -> isize {
    ssn(n)*ssn(n) - ssq(n)
}

fn ssq(n: isize) -> isize {
    n*(n+1)*(2*n+1)/6
}

fn ssn(n: isize) -> isize {
    n*(n+1)/2
}
