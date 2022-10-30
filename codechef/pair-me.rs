/*

Chef is always trying to find patterns within integers. Today Chef has 3 positive integers and he wonders if any one of them can be written as the sum of the other two integers.

Input:

First line will contain the number 5, which is the number of testcases. Then the testcases follow.
Each testcase contains a single line of input, with three space-separated positive integers x, y, and z.

Output:

For each testcase, output in a single line, "YES" if it's possible to represent any integer among the three integers as the sum of the other two integers, and "NO" if not.

NOTE: The output is case insensitive, meaning both uppercase and lowercase characters can be used at any position of the output string.

Constraints
1<=x,y,z<=1000

*/

fn main() {
    assert_eq!(pairable(1, 1, 2), true);
    assert_eq!(pairable(1, 3, 2), true);
    assert_eq!(pairable(2, 2, 2), false);
    assert_eq!(pairable(100, 100, 201), false);
    assert_eq!(pairable(11, 22, 33), true);
}

fn pairable(x: usize, y: usize, z: usize) -> bool {
    let mut a = [x, y, z];
    a.sort();
    a[0] + a[1] == a[2]
}
