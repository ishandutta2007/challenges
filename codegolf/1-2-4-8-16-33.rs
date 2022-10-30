/*

Challenge

Write a function/program that outputs either the n'th element, or the first n elements, in the well known number sequence:

         1, 2, 4, 8, 16 ...

Oh, wait... I forgot the first few numbers:

1, 1, 1, 1, 2, 4, 8, 16 ...

Heck, I'll add a few more for good measure:

1, 1, 1, 1, 2, 4, 8, 16, 33, 69, 146, 312, 673, 1463, 3202, 7050, 15605, 34705 ...

The numbers are Generalized Catalan numbers given by the (zero-indexed) formula:

a(n+1)=a(n)+∑k=2n−1a(k)⋅a(n−1−k)

where

a(0)=a(1)=a(2)=a(3)=1

This is OEIS A004149.

You may choose if you want to have the sequence zero- or one-indexed. The sequence must of course be the same, so you must rewrite the formula if you have it one-indexed.

*/

fn main() {
    for i in 1..20 {
        println!("{}", a(i));
    }
}

fn a(n: usize) -> usize {
    if n <= 3 {
        return 1;
    }
    
    let mut r = a(n - 1);
    for k in 2..n-1 {
        r += a(k) * a(n - 2 - k);
    }
    return r;
}
