/*

Danya gave integers a, b and n to Archi. Archi wants to compare a^n and b^n. Help Archi with this task.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers a, b and n.

Output

For each test case, print a single line containing one integer: 1 if an>bn, 2 if an<bn or 0 if an=bn.

Constraints
1≤T≤1,000
|a|,|b|≤10^9
1≤n≤10^9

*/

fn main() {
    assert_eq!(cmp(3, 4, 5), 2);
    assert_eq!(cmp(-3, 2, 4), 1);
    assert_eq!(cmp(2, 2, 2), 0);
}

fn cmp(a: isize, b: isize, n: isize) -> isize {
    let p = n as u32;
    let x = isize::pow(a, p);
    let y = isize::pow(b, p);
    if x > y {
        1
    } else if x < y {
        2
    } else {
        0
    }
}
