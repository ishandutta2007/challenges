/*

Superbowl Sunday is nearly here. In order to pass the time waiting for the half-time commercials and wardrobe malfunctions, the local hackers have organized a betting pool on the game.
Members place their bets on the sum of the two final scores, or on the absolute difference between the two scores.

Given the winning numbers for each type of bet, can you deduce the final scores?

Input

The first line of input contains n, the number of test cases. n lines follow, each representing a test case.
Each test case gives s and d, non-negative integers representing the sum and (absolute) difference between the two final scores.
You can assume that 0≤s,d≤1000.

Output

For each test case, output a line giving the two final scores, largest first. If there are no such scores, output a line containing “impossible”. Recall that football scores are always non-negative integers.

*/

fn main() {
    assert_eq!(scores(40, 20), (30, 10));
    assert_eq!(scores(20, 40), (-1, -1));
}

fn scores(s: isize, d: isize) -> (isize, isize) {
    if s < d || (s+d)%2 == 1 {
        return (-1, -1);
    }

    let x = (s + d) / 2;
    let y = s - x;
    return (isize::max(x, y), isize::min(x, y));
}
