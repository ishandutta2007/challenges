/*

This challenge is the second of a series of fastest-code problems that should be written in the GOLF CPU. You can find the first here

For this problem, you are given the volume of a cuboid (A rectangular cube).
Each of the side lengths are integers.
You must return the number of distinct cuboids that have that volume.
This sequence matches A034836 (thanks Tylio)

Input:Output [List] [of] [cuboids]
1:1 [1,1,1]
5:1 [1,1,5]
8:3 [1,1,8] [1,2,4] [2,2,2]
24:6 [1,1,24] [1,2,12] [1,3,8] [1,4,6] [2,2,6] [2,3,4]
100:8 [1,1,100] [1,2,50] [1,4,25] [1,5,20] [1,10,10] [2,2,25] [2,5,10] [4,5,5]
1080:52
468719: 1
468720: 678
468721: 2

Your program should be written in GOLF CPU. For input/output you can either use STDIO or the registers. Hardcoding primes or answers isn't allowed.

*/

fn main() {
    assert_eq!(cuboids(1), 1);
    assert_eq!(cuboids(5), 1);
    assert_eq!(cuboids(8), 3);
    assert_eq!(cuboids(24), 6);
    assert_eq!(cuboids(100), 8);
    assert_eq!(cuboids(1080), 52);
    assert_eq!(cuboids(468719), 1);
    assert_eq!(cuboids(468720), 678);
    assert_eq!(cuboids(468721), 2);
}

// https://oeis.org/A034836 
fn cuboids(n: u128) -> u128 {
    let mut r = 0;
    for a in 1..n + 1 {
        for b in a..n + 1 {
            if a * b > n {
                break;
            }
            for c in b..n + 1 {
                if a * b * c > n {
                    break;
                }
                if a * b * c == n {
                    r += 1;
                }
            }
        }
    }
    r
}
