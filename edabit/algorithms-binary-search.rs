/*

Create a function that finds a target number in a list of prime numbers. Implement a binary search algorithm in your function. The target number will be from 2 through 97. If the target is prime then return "yes" else return "no".
Examples

var primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]


isPrime(primes, 3) ➞ "yes"

isPrime(primes, 4) ➞ "no"

isPrime(primes, 67) ➞ "yes"

isPrime(primes, 36) ➞ "no"

Notes

    You could use built-in functions to solve this, but the point of this challenge is to see if you understand the binary search algorithm.
    The solution is in the Resources tab.

*/

fn main() {
    for i in 1..100 {
        if isprime(i) == "yes" {
            print!("{}\n", i);
        }
    }
    assert_eq!(isprime(3), "yes");
    assert_eq!(isprime(4), "no");
    assert_eq!(isprime(67), "yes");
    assert_eq!(isprime(36), "no");
}

fn isprime(n: isize) -> &'static str {
    let primes = vec![2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97];
    let i = binsearch(&primes, n);
    if primes[i] == n {
        return "yes";
    }
    return "no";
}

fn binsearch(arr: &Vec<isize>, val: isize) -> usize {
    let mut lo = 0;
    let mut hi = arr.len() - 1;
    if val <= arr[lo] {
        return lo;
    }
    if val >= arr[hi] {
        return hi;
    }
    while hi-lo != 1 {
        let mid = lo + (hi-lo)/2;
        if arr[mid] < val {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return hi;
}
