/*

Chef is playing badminton today. The service rules of this singles game of badminton are as follows:

The player who starts the game serves from the right side of their court.
Whenever a player wins a point, they serve next.
If the server has won an even number of points during a game, then they will serve from the right side of the service court for the subsequent point.
Chef will be the player who begins the game.

Given the number of points P obtained by Chef at the end of the game, please determine how many times Chef served from the right side of the court.

Please see the sample cases below for explained examples.

Input Format

The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line containing one integer P, the points obtained by Chef.

Output Format

For each test case, output in a single line the number of times Chef served from the right side of the court.

Constraints
1≤T≤10^3
0≤P≤10^9

*/

fn main() {
    assert_eq!(serves(2), 2);
    assert_eq!(serves(9), 5);
    assert_eq!(serves(53), 27);
    assert_eq!(serves(746), 374);
}

fn serves(p: isize) -> isize {
    (p / 2) + 1
}
