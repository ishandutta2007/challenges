/*

The Sum Squared Digits function, SSD(b,n) of a positive integer n, in base b is defined by representing n in base b as in:

n=a0+a1∗b+a2∗b2+… then:

SSD(b,n)=a20+a21+a22+… is the sum of squares of the digits of the representation.

Write a program to compute the Sum Squared Digits function of an input positive number.

Input

The first line of input contains a single decimal integer P, (1≤P≤1000), which is the number of data sets that follow. Each data set should be processed identically and independently.

Each data set consists of a single line of input.
It contains the data set number, K, followed by the base, b (3≤b≤16) as a decimal integer, followed by the positive integer, n (as a decimal integer) for which the Sum Squared Digits function is to be computed with respect to the base b.
n will fit in a 32 bit unsigned integer. The data set number K starts at 1 and is incremented by 1 for each data set.

Output

For each data set there is a single line of output.

The single line of output consists of the data set number, K, followed by a single space followed by the value of SSD(b,n) as a decimal integer.

*/

fn main() {
    assert_eq!(ssd(1, 10, 1234), (1, 30));
    assert_eq!(ssd(2, 3, 98765), (2, 19));
    assert_eq!(ssd(3, 16, 987654321), (3, 696));
}

fn ssd(k: isize, b: isize, mut n: isize) -> (isize, isize) {
    let mut r = 0;
    while n > 0 {
        r += (n % b) * (n % b);
        n /= b;
    }
    (k, r)
}
