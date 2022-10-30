/*

You are the Chief Engineer of a fast growing start-up. You wish to place K servers in some distinct locations from among N locations.
The locations, numbered 1,2,…,N are arranged in a circular manner. The distance between every adjacent location is 1 unit. 1 and N are adjacent.

You want to place the servers such that the maximum shortest distance between any two adjacent servers is as less as possible.
Find this minimum possible distance that can be achieved, and also the minimum number of pairs of adjacent servers separated by this distance.

Input:

The first line contains a single integer, T, denoting the number of test cases.
Each test case consists of a single line containing two space-separated integers N and K, denoting the number of locations, and the number of servers, respectively.

Output:

For test case, output two space-separated integers D and X, denoting the minimum possible maximum shortest distance that can be achieved between any two adjacent servers,
and the minimum number of pairs of servers separated by this distance, respectively, in a separate line.

Constraints
1≤T≤10^5
3≤K≤N≤10^9

*/

fn main() {
    assert_eq!(shortest(6, 3), (2, 3));
    assert_eq!(shortest(10, 6), (2, 4));
    assert_eq!(shortest(10, 4), (3, 2));
}

fn shortest(n: isize, k: isize) -> (isize, isize) {
    if n % k == 0 {
        (n / k, k)
    } else {
        (n / k + 1, n - (k * (n / k)))
    }
}
