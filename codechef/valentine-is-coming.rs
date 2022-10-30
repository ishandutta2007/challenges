/*

Valentine's Day is approaching and thus Chef wants to buy some chocolates for someone special.

Chef has a total of X rupees and one chocolate costs Y rupees. What is the maximum number of chocolates Chef can buy?

Input Format

First line will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, two integers X,Y - the amount Chef has and the cost of one chocolate respectively.

Output Format

For each test case, output the maximum number of chocolates Chef can buy.

Constraints
1≤T≤1000
1≤X,Y≤100

*/

fn main() {
    assert_eq!(chocolates(5, 10), 0);
    assert_eq!(chocolates(16, 5), 3);
    assert_eq!(chocolates(35, 7), 5);
    assert_eq!(chocolates(100, 1), 100);
}

fn chocolates(x: isize, y: isize) -> isize {
    if y == 0 {
        0
    } else {
        x / y
    }
}
