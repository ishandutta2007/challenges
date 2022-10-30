/*

Given the coordinates (x,y) of a point in 2-D plane. Find if it is possible to reach (x,y) from (0,0). The only possible moves from any coordinate (i,j) are as follows:

Go to the point with coordinates (i+1,j+1).
Go to the point with coordinates (i+1,j−1)
Go to the point with coordinates (i−1,j+1).
Go to the point with coordinates (i−1,j−1).

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, two integers x,y.

Output Format

For each test case, print YES if it is possible to reach (x,y) from (0,0), otherwise print NO.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤2⋅10^4
−10^9≤x,y≤10^9

*/

fn main() {
    assert_eq!(reachable(0, 2), true);
    assert_eq!(reachable(1, 2), false);
    assert_eq!(reachable(-1, -3), true);
    assert_eq!(reachable(-1, 0), false);
    assert_eq!(reachable(-3, 1), true);
    assert_eq!(reachable(2, -1), false);
}

fn reachable(x: isize, y: isize) -> bool {
    (x + y) % 2 == 0
}
