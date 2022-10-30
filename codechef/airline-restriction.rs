/*

Chef has 3 bags that she wants to take on a flight. They weigh A, B, and C kgs respectively. She wants to check-in exactly two of these bags and carry the remaining one bag with her.

The airline restrictions says that the total sum of the weights of the bags that are checked-in cannot exceed D kgs and the weight of the bag which is carried cannot exceed E kgs. Find if Chef can take all the three bags on the flight.

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
Each testcase contains a single line of input, five space separated integers A,B,C,D,E.

Output Format

For each testcase, output in a single line answer "YES" if Chef can take all the three bags with her or "NO" if she cannot.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤36000
1≤A,B,C≤10
15≤D≤20
5≤E≤10

*/

fn main() {
    assert_eq!(takeable(1, 1, 1, 15, 5), true);
    assert_eq!(takeable(8, 7, 6, 15, 5), false);
    assert_eq!(takeable(8, 5, 7, 15, 6), true);
}

fn takeable(a: isize, b: isize, c: isize, d: isize, e: isize) -> bool {
    (a+b <= d && c <= e) || (a+c <= d && b <= e) || (c+b <= d && a <= e)
}
