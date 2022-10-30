/*

Given an integer n > 1,
1) Construct the range of numbers n, n-1, n-2, ... 3, 2, 1 and calculate the sum
2) Take the individual digits of that number and calculate the product
3) Take the individual digits of that number and calculate the sum
4) Repeat steps 2 and 3 until you reach a single digit. That digit is the result.

The first twenty terms of the sequence are below:

3, 6, 0, 5, 2, 7, 9, 2, 7, 9, 1, 9, 0, 0, 9, 6, 7, 0, 0, 6
Note: This sequence is NOT in OEIS.

I/O and Rules
Numbers will get very large quickly, so the solution must be able to handle input numbers up to 100,000 without failure (it's fine if your code can handle past that).
The input and output can be given by any convenient method.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

Examples
n     output
1234   9
3005   3
5007   5
9854   8
75849  8
100000 0

*/

fn main() {
    let tab = [3, 6, 0, 5, 2, 7, 9, 2, 7, 9, 1, 9, 0, 0, 9, 6, 7, 0, 0, 6];
    let mut i = 2;
    for v in tab {
        assert_eq!(amas(i), v);
        i += 1;
    }

    assert_eq!(amas(1234), 9);
    assert_eq!(amas(3005), 3);
    assert_eq!(amas(5007), 5);
    assert_eq!(amas(9854), 8);
    assert_eq!(amas(75849), 8);
    assert_eq!(amas(100000), 0);
}

fn amas(n: u128) -> u128 {
    let mut x = triangular(n);
    while x >= 10 {
        x = sumd(muld(x));
    }
    x
}

fn triangular(n: u128) -> u128 {
    n * (n + 1) / 2
}

fn sumd(mut n: u128) -> u128 {
    let mut r = 0;
    while n > 0 {
        r += n % 10;
        n /= 10;
    }
    r
}

fn muld(mut n: u128) -> u128 {
    if n == 0 {
        return 0;
    }

    let mut r = 1;
    while n > 0 {
        r *= n % 10;
        n /= 10;
    }
    r
}
