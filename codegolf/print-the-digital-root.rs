/*

This is different from My Word can beat up your Word as it is less complex and only requires you to calculate it, and not compare them.

To find the digital root, take all of the digits of a number, add them, and repeat until you get a one-digit number. For example, if the number was 12345, you would add 1, 2, 3, 4, and 5, getting 15. You would then add 1 and 5, giving you 6.

Your task

Given an integer N (0 <= N <= 10000) through STDIN, print the digital root of N.
Test cases

1 -> 1
45 -> 9
341 -> 8
6801 -> 6
59613 -> 6
495106 -> 7

Remember, this is code-golf, so the code with the smallest number of bytes wins.

*/

fn main() {
    assert_eq!(digital_root(1), 1);
    assert_eq!(digital_root(45), 9);
    assert_eq!(digital_root(341), 8);
    assert_eq!(digital_root(6801), 6);
    assert_eq!(digital_root(59613), 6);
    assert_eq!(digital_root(495106), 7);
}

fn digital_root(mut n: usize) -> usize {
    while n >= 10 {
        n = sum(n);
    }
    return n;
}

fn sum(mut n: usize) -> usize {
    let mut r = 0;
    while n != 0 {
        r += n % 10;
        n /= 10;
    }
    return r;
}
