/*

Kuznetsov's Sequence
(I made the name up, don't bother with Wikipedia or Google)
Given any number n > 0, let r represent the reverse of the number n. Iterate until the final result is zero, passing the result of each iteration back into the function using recursion or a methodology of your choice by performing the below operation:

If r > n for that iteration the result is r % n.
If n > r for that iteration the result is n % r.
If n % r = 0 or r % n = 0, you terminate iteration.
Take the intermediate result of each execution and store them in an array for the final answer. The initial number n is not part of the sequence, nor is 0; the examples should make everything a little more obvious.

Lets walk through an example where n=32452345.

54325423 % 32452345 = 21873078 # r > n, uses r % n
87037812 % 21873078 = 21418578 # r > n, uses r % n
87581412 % 21418578 = 1907100  # r > n, uses r % n
1907100 % 17091 = 9999         # n > r, uses n % r
9999 % 9999 = 0                # r % n = n % r = 0, terminated

Result: [21873078, 21418578, 1907100, 9999]     
Another example n=12345678:

87654321 % 12345678 = 1234575 # r > n, uses r % n
5754321 % 1234575 = 816021    # r > n, uses r % n
816021 % 120618 = 92313       # n > r, uses n % r
92313 % 31329 = 29655         # n > r, uses n % r
55692 % 29655 = 26037         # r > n, uses r % n
73062 % 26037 = 20988         # r > n, uses r % n
88902 % 20988 = 4950          # r > n, uses r % n
4950 % 594 = 198              # n > r, uses n % r
891 % 198 = 99                # r > n, uses r % n
99 % 99 = 0                   # r % n = n % r = 0, terminated

Result: [1234575, 816021, 92313, 29655, 26037, 20988, 4950, 198, 99]
A final example n=11000:

11000 % 11 = 0 # n % r = 0, terminated

Result: []
This is code-golf lowest byte-count wins.

*/

fn main() {
    assert_eq!(kuznetsov(32452345), vec![21873078, 21418578, 1907100, 9999]);
    assert_eq!(
        kuznetsov(12345678),
        vec![1234575, 816021, 92313, 29655, 26037, 20988, 4950, 198, 99]
    );
    assert_eq!(kuznetsov(11000), vec![]);
}

fn kuznetsov(mut n: usize) -> Vec<usize> {
    let mut v = vec![];
    loop {
        let r = reverse(n);
        let m = n.max(r) % n.min(r);
        if m == 0 {
            break;
        }
        n = m;
        v.push(n);
    }
    v
}

fn reverse(mut n: usize) -> usize {
    let mut r = 0;
    while n > 0 {
        r = (r * 10) + (n % 10);
        n /= 10;
    }
    r
}
