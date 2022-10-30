/*

Create a function that will find all primes below a given number. Return the result as an array.
Examples

primesBelowNum(5) ➞ [2, 3, 5]

primesBelowNum(10) ➞ [2, 3, 5, 7]

primesBelowNum(20) ➞ [2, 3, 5, 7, 11, 13, 17, 19]

Notes

If n is a prime, it is included in the array.

*/

fn main() {
    assert_eq!(primes(5), vec![2, 3, 5]);
    assert_eq!(primes(10), vec![2, 3, 5, 7]);
    assert_eq!(primes(20), vec![2, 3, 5, 7, 11, 13, 17, 19]);
    assert_eq!(primes(6), vec![2, 3, 5]);
    assert_eq!(primes(11), vec![2, 3, 5, 7, 11]);
    assert_eq!(primes(21), vec![2, 3, 5, 7, 11, 13, 17, 19]);
    assert_eq!(primes(7), vec![2, 3, 5, 7]);
    assert_eq!(primes(12), vec![2, 3, 5, 7, 11]);
    assert_eq!(primes(22), vec![2, 3, 5, 7, 11, 13, 17, 19]);
    assert_eq!(primes(8), vec![2, 3, 5, 7]);
    assert_eq!(primes(13), vec![2, 3, 5, 7, 11, 13]);
    assert_eq!(primes(23), vec![2, 3, 5, 7, 11, 13, 17, 19, 23]);
}

fn primes(n: usize) -> Vec<usize> {
    let mut p = Vec::new();
    if n >= 2 {
        p.push(2);
    }
    for i in (3..n+1).step_by(2) {
        if isprime(i) {
            p.push(i);
        }
    }
    return p;
}

fn isprime(n: usize) -> bool {
    if n <= 1 {
        return false;
    }
    if n == 2 {
        return true;
    }
    if n%2 == 0 {
        return false;
    }

    let f = n as f64;
    let l = f.sqrt() as usize;
    for i in (3..l+1).step_by(2) {
        if n%i == 0 {
            return false;
        }
    }
    return true;
}
