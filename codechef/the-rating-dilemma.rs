/*

Chef really likes to compete on Codechef, and he has gained an impressive rating of X, where X>0.
There is also a parallel universe, where ratings on Codechef are negative instead.
The only thing that remains unchanged in the parallel universe is Chef's love for competing on Codechef.
Chef's rating on Codechef in the parallel universe is Y, where Y<0.

Due to some cosmic event, the parallel universe has been destroyed, resulting in Chef forgetting both X and Y. He only remembers the sum S=X+Y. He wonders what the maximum possible product of his ratings is, given that he knows the sum of his ratings.

Input Format
The first line of input will contain an integer T — the number of test cases. The description of T test cases follows.
The first and only line of each test case contains an integer S, the sum of Chef's ratings.

Output Format
For each test case, output the maximum possible product of Chef's ratings, given that he knows the sum of his ratings.

Constraints
1≤T≤10^3
0≤S≤10^9

*/

fn main() {
    assert_eq!(rating(0), -1);
    assert_eq!(rating(1), -2);
}

fn rating(s: isize) -> isize {
    if s < 0 {
        s - 1
    } else if s == 0 {
        -1
    } else {
        -s - 1
    }
}
