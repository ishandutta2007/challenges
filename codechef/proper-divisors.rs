/*

Given a natural number, calculate sum of all its proper divisors.
A proper divisor of a natural number is the divisor that is strictly less than the number.
For example, number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.

Input
The first line contains number of test cases T. Each line of test case contain a number N

Output
For each test case, output is sum of divisors.
 
Constraints
1 ≤ T ≤ 100
1 ≤ A≤ 10^6

*/

fn main() {
    assert_eq!(sum_divisors(20), 22);
    assert_eq!(sum_divisors(5), 1);
}

fn sum_divisors(n: isize) -> isize {
    let mut r = 0;
    for i in 1..n {
        if n % i == 0 {
            r += i;
        }
    }
    r
}
