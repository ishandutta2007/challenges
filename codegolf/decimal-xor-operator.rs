/*

Many programming language provide operators for manipulating the binary (base-2) digits of integers. Here is one way to generalize these operators to other bases:

Let x and y be single-digit numbers in base B. Define the unary operator ~ and binary operators &, |, and ^ such that:

~x = (B - 1) - x
x & y = min(x, y)
x | y = max(x, y)
x ^ y = (x & ~y) | (y & ~x)
Note that if B=2, we get the familiar bitwise NOT, AND, OR, and XOR operators.

For B=10, we get the “decimal XOR” table:

^ │ 0 1 2 3 4 5 6 7 8 9
──┼────────────────────
0 │ 0 1 2 3 4 5 6 7 8 9
1 │ 1 1 2 3 4 5 6 7 8 8
2 │ 2 2 2 3 4 5 6 7 7 7
3 │ 3 3 3 3 4 5 6 6 6 6
4 │ 4 4 4 4 4 5 5 5 5 5
5 │ 5 5 5 5 5 4 4 4 4 4
6 │ 6 6 6 6 5 4 3 3 3 3
7 │ 7 7 7 6 5 4 3 2 2 2
8 │ 8 8 7 6 5 4 3 2 1 1
9 │ 9 8 7 6 5 4 3 2 1 0
For multi-digit numbers, apply the single-digit operator digit-by-digit. For example, 12345 ^ 24680 = 24655, because:

1 ^ 2 = 2
2 ^ 4 = 4
3 ^ 6 = 6
4 ^ 8 = 5
5 ^ 0 = 5
If the operands are different lengths, then pad the shorter one with leading zeros.

The challenge
Write, in as few bytes as possible, a program or function that takes as input two integers (which may be assumed to be between 0 and 999 999 999, inclusive) and outputs the “decimal XOR” of the two numbers as defined above.

Test cases
12345, 24680 → 24655
12345, 6789 → 16654
2019, 5779 → 5770
0, 999999999 → 999999999
0, 0 → 0

*/

fn main() {
    assert_eq!(decimal_xor(12345, 24680), 24655);
    assert_eq!(decimal_xor(12345, 6789), 16654);
    assert_eq!(decimal_xor(2019, 5779), 5770);
    assert_eq!(decimal_xor(0, 999999999), 999999999);
    assert_eq!(decimal_xor(0, 0), 0);
}

fn not(x: usize) -> usize {
    9 - x
}

fn and(x: usize, y: usize) -> usize {
    x.min(y)
}

fn or(x: usize, y: usize) -> usize {
    x.max(y)
}

fn xor(x: usize, y: usize) -> usize {
    or(and(x, not(y)), and(y, not(x)))
}

fn decimal_xor(mut x: usize, mut y: usize) -> usize {
    let mut d = vec![];
    loop {
        d.push(xor(x % 10, y % 10));

        x /= 10;
        y /= 10;
        if x == 0 && y == 0 {
            break;
        }
    }

    let mut n = d.len();
    let mut r = 0;
    while n > 0 {
        r = (r * 10) + d[n - 1];
        n -= 1;
    }
    r
}
