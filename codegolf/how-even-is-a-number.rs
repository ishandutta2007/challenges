/*

The ancient Greeks had these things called singly and doubly even numbers. An example of a singly even number is 14.
It can be divided by 2 once, and has at that point become an odd number (7), after which it is not divisible by 2 anymore. A doubly even number is 20. It can be divided by 2 twice, and then becomes 5.

Your task is to write a function or program that takes an integer as input, and outputs the number of times it is divisible by 2 as an integer, in as few bytes as possible.
The input will be a nonzero integer (any positive or negative value, within the limits of your language).

Test cases:

14 -> 1

20 -> 2

94208 -> 12

7 -> 0

-4 -> 2
The answer with the least bytes wins.

Tip: Try converting the number to base 2. See what that tells you.

*/

fn main() {
    assert_eq!(eveness(14), 1);
    assert_eq!(eveness(20), 2);
    assert_eq!(eveness(94208), 12);
    assert_eq!(eveness(7), 0);
    assert_eq!(eveness(-4), 2);
}

fn eveness(mut x: isize) -> isize {
    let mut c = 0;
    while (x & 1) == 0 {
        x >>= 1;
        c += 1;
    }
    c
}
