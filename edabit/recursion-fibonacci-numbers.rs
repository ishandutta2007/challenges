/*

Fibonacci numbers are created in the following way:

F(0) = 0
F(1) = 1
...
F(n) = F(n-2) + F(n-1)

Write a function that calculates the nth Fibonacci number.
Examples

fib(0) ➞ 0

fib(1) ➞ 1

fib(2) ➞ 1

fib(8) ➞ 21

*/

fn main() {
    assert_eq!(fib(2), 1);
    assert_eq!(fib(5), 5);
    assert_eq!(fib(8), 21);
    assert_eq!(fib(12), 144);
    assert_eq!(fib(0), 0);
    assert_eq!(fib(1), 1);
}

fn fib(n: usize) -> usize {
    if n < 2 {
        return n;
    }
    return fib(n-2) + fib(n-1);
}
