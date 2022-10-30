/*

Introduction

The ruler sequence is the sequence of the largest possible numbers an
such that 2^a_n∣n. It is so-called because its pin plot looks similar to a ruler's markings:

Pin plot of ruler sequence

However, with a slight modification, we can also get a similar sequence. This sequence is {a1,a2,a3,…}
where an is the largest power of 2 such that an∣n

(relevant OEIS).

The first 100 terms of this sequence are:

1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 16, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 32, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 16, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 64, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 16, 1, 2, 1, 4, 1, 2, 1, 8, 1, 2, 1, 4, 1, 2, 1, 32, 1, 2, 1, 4

Challenge

Your challenge is to do one of these three things:

    Take a positive integer n

as input and return the n
th term of this sequence.
Take a positive integer n
as input and return the first n

    terms of this sequence.
    Output the sequence infinitely.

Test Cases

12 -> 4
64 -> 64
93 -> 1
8 -> 8
0 -> (undefined behavior)

Rules

    You may output the sequence in any convenient format - e.g. as a list or some other iterable or separated by any non-digit separator, as long as it is constant between all terms.
    You may output the term(s) in any convenient format - e.g. as an integer, as an integer string, as a float with the decimal part consisting of only zeros, ditto but as a string, or as a Boolean (True) if and only if the term is 1.
    You may choose to use either zero- or one-indexing.
    Standard loopholes are forbidden.
    Trailing whitespace is allowed.
    If possible, please link to an online interpreter (e.g. TIO) to run your program on.
    Please explain your answer. This is not necessary, but it makes it easier for others to understand.
    This is code-golf, so shortest code in bytes wins!

*/

fn main() {
    assert_eq!(lp2(12), 4);
    assert_eq!(lp2(64), 64);
    assert_eq!(lp2(93), 1);
    assert_eq!(lp2(8), 8);
    assert_eq!(lp2(0), 0);
    for i in 1..100 {
        println!("{} {}", i, lp2(i));
    }
}

fn lp2(n: isize) -> isize {
    n&-n
}
