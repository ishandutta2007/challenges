/*

Input:

An integer
Output:

Sum of the input itself + the length of the input + each individual digit of the input.

nr + nr-length + {sum of digits} = output

Examples:

Input: 99
Output: 99 (nr) + 2 (nr-length) + (9 + 9) (digits) → 119

Input: 123
Output: 123 + 3 + (1 + 2 + 3) → 132
Challenge rules:

    The input can also contain negative input, which are resolved special. The -/minus-sign is also +1 for the length, and is part of the first digit.
    For example:

    Input: -123
    Output: -123 + 4 + (-1 + 2 + 3) → -115
    You can assume that the input nor output will ever be outside the range of an (32-bit) integer.

General rules:

    This is code-golf, so shortest answer in bytes wins.
    Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
    Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
    Default Loopholes are forbidden.
    If possible, please add a link with a test for your code.
    Also, please add an explanation if necessary.

Test cases:

87901 → 87931
123 → 132
99 → 119
5 → 11
1 → 3
0 → 1
-3 → -4
-123 → -115
-900 → -905
-87901 → -87886

Semi-related: Count Sum of all Digits

*/

fn main() {
    assert_eq!(ild(87901), 87931);
    assert_eq!(ild(123), 132);
    assert_eq!(ild(99), 119);
    assert_eq!(ild(5), 11);
    assert_eq!(ild(0), 1);
    assert_eq!(ild(-3), -4);
    assert_eq!(ild(-123), -115);
    assert_eq!(ild(-900), -905);
    assert_eq!(ild(-87901), -87886);
}

fn ild(x: isize) -> isize {
    let (c, v) = digit_sum(x);
    return x + c + v;
}

fn digit_sum(mut x: isize) -> (isize, isize) {
    let mut c = 0;
    let mut v = 0;
    let mut u;
    let mut s = false;

    if x < 0 {
        x = -x;
        s = true;
    }
    loop {
        u = x % 10;
        v += u;
        c += 1;
        x /= 10;
        if x == 0 {
            break
        }
    }
    if s {
        c += 1;
        v -= 2*u;
    }
    return (c, v);
}
