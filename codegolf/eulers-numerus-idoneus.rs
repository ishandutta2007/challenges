/*

Euler's numerus idoneus, or idoneal numbers, are a finite set of numbers whose exact number is unknown, as it depends on whether or not the Generalized Riemann hypothesis holds or not.
If it does, there are exactly 65 idoneal numbers. If not, there are either 66 or 67.
For the purposes of this challenge, we'll revolutionise mathematics and say that the Generalised Riemann hypothesis is true (I'd prove it, but I'm trying to golf the challenge body).

Under this assumption, the idoneal numbers are

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18, 21, 22, 24, 25, 28, 30, 33, 37, 40, 42, 45, 48, 57, 58, 60, 70, 72, 78, 85, 88, 93, 102, 105, 112, 120, 130, 133, 165, 168, 177, 190, 210, 232, 240, 253, 273, 280, 312, 330, 345, 357, 385, 408, 462, 520, 760, 840, 1320, 1365, 1848

This is A000926, and many different ways to describe this sequence can be found there. However, we'll include two of the most standard ones here:

    A positive integer D

is idoneal if, for any integer expressible in the form x2±Dy2 in exactly one way (where x2 and Dy2

are co-prime), that integer is either a prime power, or twice a prime power.

For example, let D=3. 3 is idoneal, meaning that all integers that can be expressed as x2±3y2 for exactly one co-prime pair (x,y) are either primes p, powers of primes pn or twice a prime power 2pn.
As an example, (x,y)=(2,3) yields 29 as x2+3y2. 29 is a prime, and cannot be expressed in the form x2±3y2 for any other co-prime pair (x,y).

Alternatively (and rather more simply), a positive integer n is idoneal iff it cannot be written in the form ab+ac+bc for distinct positive integers a,b,c

For example, 11=1×2+1×3+2×3, therefore, 11

    is not idoneal.

This is a standard sequence challenge, you may choose one of the following three options:

    Take an integer n

(either 0≤n<65 or 0<n≤65, your choice) as input, and output the n
th (either 0 or 1 indexed, also your choice) idoneal number. You may choose how to order the idoneal numbers, so long as its consistent.
Take a positive integer 1≤n≤65
and output the first n

    idoneal numbers. Again, you may choose how to order the idoneal numbers.
    Output all 65 idoneal numbers, in any order, with no duplicates.

This is code-golf, so the shortest code in bytes wins

*/

fn main() {
    for i in 0..65 {
        println!("{}: {}", i, idoneal(i));
    }
}

fn idoneal(n: usize) -> usize {
    let tab: [usize; 65] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 16, 18, 21, 22, 24, 25, 28, 30, 33, 37, 40, 42, 45, 48, 57, 58, 60, 70, 72, 78, 85, 88, 93, 102, 105, 112, 120, 130, 133, 165, 168, 177, 190, 210, 232, 240, 253, 273, 280, 312, 330, 345, 357, 385, 408, 462, 520, 760, 840, 1320, 1365, 1848];

    if n >= tab.len() {
        return 0;
    }
    return tab[n];
}
