/*

It is the World Cup Finals. Chef only finds a match interesting if the skill difference of the competing teams is less than or equal to D.

Given that the skills of the teams competing in the final are X and Y respectively, determine whether Chef will find the game interesting or not.

Input Format

The first line of input will contain a single integer T, denoting the number of testcases. The description of T testcases follows.
Each testcase consists of a single line of input containing three space-separated integers X, Y, and D — the skill levels of the teams and the maximum skill difference.

Output Format

For each testcase, output "YES" if Chef will find the game interesting, else output "NO" (without the quotes). The checker is case-insensitive, so "YeS" and "nO" etc. are also acceptable.

Constraints

1≤T≤2000
1≤X,Y≤100
0≤D≤100

*/

fn main() {
    assert_eq!(interesting(5, 3, 4), true);
    assert_eq!(interesting(5, 3, 1), false);
    assert_eq!(interesting(5, 5, 0), true);
}

fn interesting(x: isize, y: isize, d: isize) -> bool {
    (x - y).abs() <= d
}
