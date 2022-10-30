/*

Chef is currently facing the north direction. Each second he rotates exactly 90 degrees in clockwise direction.
Find the direction in which Chef is facing after exactly X seconds.

Note: There are only 4 directions: North, East, South, West (in clockwise order).

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single integer X.

Output Format
For each testcase, output the direction in which Chef is facing after exactly X seconds.

Constraints
1≤T≤100
1≤X≤1000

*/

fn main() {
    assert_eq!(direction(1), "East");
    assert_eq!(direction(3), "West");
    assert_eq!(direction(6), "South");
}

fn direction(n: usize) -> &'static str {
    match n&3 {
        0 => "North",
        1 => "East",
        2 => "South",
        _ => "West"
    }
}
