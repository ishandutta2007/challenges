/*

I've been posting relatively hard challenges recently, so here goes an easy one.

Task

Given an array A
and a number n, calculate the sum of all numbers of A multiplied by n, except the last one. All numbers (the elements of A and the value of n) are positive integers, and A

is non-empty. Shortest code in bytes wins.

I have a 3-byte J solution. Can you find it (or beat it in a different language)?
Test cases

A           N   Ans   Explanation
3 1 4 1 5   10  95    (3+1+4+1)*10+5
3 1 4 1 5   1   14    (3+1+4+1)*1+5
1           999 1     1

*/

fn main() {
    assert_eq!(sum(&vec![3, 1, 4, 1, 5], 10), 95);
    assert_eq!(sum(&vec![3, 1, 4, 1, 5], 1), 14);
    assert_eq!(sum(&vec![1], 999), 1);
}

fn sum(a: &Vec<isize>, n: isize) -> isize {
    let mut r = 0;
    
    let l = a.len();
    for i in 0..l-1 {
        r += a[i];
    }
    r *= n;
    if l > 0 {
        r += a[l-1];
    }
    return r;
}

