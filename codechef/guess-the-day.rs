/*

You are given the N i.e number of days. If today is sunday what day it will be on Nth day from now.

Example
If N=100. we know that today is sunday. we have to calculate what day it will be on 100th day from now.

The answer is Tuesday. It will be tuesday on 100th day from now.(i.e from sunday).

Note: You can print the answers like (monday,Monday,MONDAY) anyway you want all answers are case insensitive.

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input N.(i.e Number of Days).

Output:

For each testcase, output in a single line answer i.e What day it will be on Nth Day from sunday.

Constraints
1≤T≤1000
1≤N≤10^9

*/

fn main() {
    assert_eq!(day(100), "Tuesday");
    assert_eq!(day(250), "Friday");
}

fn day(n: usize) -> &'static str {
    match n % 7 {
        0 => "Sunday",
        1 => "Monday",
        2 => "Tuesday",
        3 => "Wednesday",
        4 => "Thursday",
        5 => "Friday",
        _ => "Saturday",
    }
}
