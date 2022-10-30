/*

The sieve of Eratosthenes is a famous algorithm to find all prime numbers up to N. The algorithm is:

Write down all integers between 2 and N, inclusive.

Find the smallest number not already crossed out and call it P; P is prime.

Cross out P and all its multiples that aren’t already crossed out.

If not all numbers have been crossed out, go to step 2.

Write a program that, given N and K, find the K-th integer to be crossed out.

Input

The integers N and K (1≤K<N≤100000).

Output

Output the K-th number to be crossed out.

*/

fn main() {
    assert_eq!(sieve(7, 3), 6);
    assert_eq!(sieve(15, 12), 7);
    assert_eq!(sieve(10, 7), 9);
}

fn sieve(n: usize, k: usize) -> usize {
    let mut a = vec![true; n+1];
    a[0] = false;
    a[1] = false;
   
    let mut c = 0;
    for i in 2..n+1 {
        if !a[i] {
            continue;
        }

        for j in (i..n+1).step_by(i) {
            if !a[j] {
                continue;
            }
            a[j] = false;
            
            c += 1;
            if c == k {
                return j;
            }
        }
    }
    return 0;
}
