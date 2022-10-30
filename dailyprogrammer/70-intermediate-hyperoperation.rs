/*

Implement the hyperoperator as a function hyper(n, a, b), for non-negative integers n, a, b.

hyper(1, a, b) = a + b, hyper(2, a, b) = a * b, hyper(3, a, b) = a ^ b, etc.

Bonus points for efficient implementations.

thanks to noodl for the challenge at r/dailyprogrammer_ideas ! .. If you think yo have a challenge worthy for our sub, do not hesitate to submit it there!

*/

fn main() {
    assert_eq!(hyperoperation(2, 2, 3), 6);
    assert_eq!(hyperoperation(3, 2, 3), 8);
    assert_eq!(hyperoperation(4, 2, 3), 16);
    assert_eq!(hyperoperation(3, 3, 5), 243);
}

fn hyperoperation(n: isize, a: isize, b: isize) -> isize {
    if n < 0 {
        return 0;
    }
    if n == 0 {
        return b + 1;
    }
    if n == 1 && b == 0 {
        return a;
    }
    if n == 2 && b == 0 {
        return 0;
    }
    if n >= 3 && b == 0 {
        return 1;
    }
    return hyperoperation(n - 1, a, hyperoperation(n, a, b - 1));
}
