/*

Given N items (0 < N <= 50) with prices (which are always integers) P0 ... PN-1 and given amounts of each item A0 ... AN-1, determine how much the total cost will be.

Examples
N: 2
P0: 2
P1: 3
A0: 1
A1: 4
Result: 14

N: 5
P0: 2
P1: 7
P2: 5
P3: 1
P4: 9
A0: 1
A1: 2
A2: 3
A3: 2
A4: 3
Result: 60

*/

fn main() {
    assert_eq!(cost(vec![2, 3], vec![1, 4]), 14);
    assert_eq!(cost(vec![2, 7, 5, 1, 9], vec![1, 2, 3, 2, 3]), 60);
}

fn cost(p: Vec<isize>, a: Vec<isize>) -> isize {
    let mut r = 0;
    let mut i = 0;
    while i < p.len() && i < a.len() {
        r += p[i] * a[i];
        i += 1;
    }
    r
}
