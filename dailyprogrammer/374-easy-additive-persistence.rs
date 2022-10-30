/*

Description

Inspired by this tweet, today's challenge is to calculate the additive persistence of a number, defined as how many loops you have to do summing its digits until you get a single digit number. Take an integer N:

    Add its digits

    Repeat until the result has 1 digit

The total number of iterations is the additive persistence of N.

Your challenge today is to implement a function that calculates the additive persistence of a number.
Examples

13 -> 1
1234 -> 2
9876 -> 2
199 -> 3

Bonus

The really easy solution manipulates the input to convert the number to a string and iterate over it. Try it without making the number a strong, decomposing it into digits while keeping it a number.

On some platforms and languages, if you try and find ever larger persistence values you'll quickly learn about your platform's big integer interfaces (e.g. 64 bit numbers).

*/

fn main() {
    assert_eq!(persistence(1), 1);
    assert_eq!(persistence(1234), 2);
    assert_eq!(persistence(9876), 2);
    assert_eq!(persistence(199), 3);
}

fn persistence(mut n: usize) -> usize {
    let mut r = 0;
    while n >= 10 {
        n = sum_digits(n);
        r += 1;
    }
    if r == 0 {
        r += 1;
    }
    r
}

fn sum_digits(mut n: usize) -> usize {
    let mut r = 0;
    while n != 0 {
        r += n % 10;
        n /= 10;
    }
    r
}
