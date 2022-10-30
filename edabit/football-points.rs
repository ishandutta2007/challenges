/*

Create a function that takes the number of wins, draws and losses and calculates the number of points a football team has obtained so far. A win receives 3 points, a draw 1 point and a loss 0 points.
Examples

footballPoints(3, 4, 2) ➞ 13

footballPoints(5, 0, 2) ➞ 15

footballPoints(0, 0, 1) ➞ 0

Notes

Inputs will be numbers greater than or equal to 0.

*/

fn main() {
    assert_eq!(football_points(3, 4, 2), 13);
    assert_eq!(football_points(5, 0, 2), 15);
    assert_eq!(football_points(0, 0, 1), 0);
    assert_eq!(football_points(1, 2, 3), 5);
    assert_eq!(football_points(5, 5, 5), 20);
    assert_eq!(football_points(1, 0, 0), 3);
    assert_eq!(football_points(0, 7, 1), 7);
    assert_eq!(football_points(0, 0, 15), 0);
}

fn football_points(wins: usize, draws: usize, _losses: usize) -> usize {
    3*wins + 1*draws
}
