/*

Meliodas and Ban are fighting over chocolates. Meliodas has X chocolates, while Ban has Y.
Whoever has lesser number of chocolates eats as many chocolates as he has from the other's collection.
This eatfest war continues till either they have the same number of chocolates, or atleast one of them is left with no chocolates.
Can you help Elizabeth predict the total no of chocolates they'll be left with at the end of their war?

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, which contains two integers X,Y, the no of chocolates Meliodas and Ban have, respectively.

Output:

For each testcase, output in a single line the no of chocolates that remain after Ban and Meliodas stop fighting.

Constraints
1≤T≤100000
0≤X,Y≤10^9

*/

fn main() {
    assert_eq!(chocolates(5, 3), 2);
    assert_eq!(chocolates(10, 10), 20);
    assert_eq!(chocolates(4, 8), 8);
}

fn chocolates(x: isize, y: isize) -> isize {
    if x == y {
        x + y
    } else if y > x {
        chocolates(y, x)
    } else if x%y == 0 {
        2 * y
    } else {
        chocolates(y, x % y)
    }
}
