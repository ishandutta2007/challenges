/*

A disease is spreading through ChefLand!

The disease spreads as follows:

At the end of day 0, a single person is infected with the disease.
During the next 10 days, the number of infected people doubles each day, until the disease has spread to all people in ChefLand.
From day 11 onwards, the number of infected people triples each day, until the disease has spread to all people in ChefLand.
You are given the population of ChefLand N and a day D. How many people in ChefLand are infected at the end of day D?

Input Format

The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line containing two space-separated integers N and D — the population of ChefLand and the day for which you need to find the number of infected people, respectively.

Output Format

For each test case, print one line containing a single integer — the number of infected people in ChefLand at the end of day D.

Constraints
1≤T≤300
1≤N≤10^8
0≤D≤10^8

*/

fn main() {
    assert_eq!(infected(100, 3), 8);
    assert_eq!(infected(2000, 10), 1024);
    assert_eq!(infected(6000, 11), 3072);
    assert_eq!(infected(10, 11), 10);
}

fn infected(n: isize, d: isize) -> isize {
    let mut p = 1;
    for i in 0..d {
        if i < 10 {
            p *= 2;
        } else {
            p *= 3;
        }

        if p >= n {
            break;
        }
    }
    return isize::min(n, p);
}
