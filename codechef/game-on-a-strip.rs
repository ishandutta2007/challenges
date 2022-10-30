/*

Tzuyu gave Nayeon a strip of N cells (numbered 1 through N) for her birthday.
This strip is described by a sequence A1,A2,…,AN, where for each valid i, the i-th cell is blocked if Ai=1 or free if Ai=0.
Tzuyu and Nayeon are going to use it to play a game with the following rules:

The players alternate turns; Nayeon plays first.
Initially, both players are outside of the strip. However, note that afterwards during the game, their positions are always different.
In each turn, the current player should choose a free cell and move there. Afterwards, this cell becomes blocked and the players cannot move to it again.
If it is the current player's first turn, she may move to any free cell.
Otherwise, she may only move to one of the left and right adjacent cells, i.e. from a cell c, the current player may only move to the cell c−1 or c+1 (if it is free).
If a player is unable to move to a free cell during her turn, this player loses the game.
Nayeon and Tzuyu are very smart, so they both play optimally. Since it is Nayeon's birthday, she wants to know if she can beat Tzuyu. Find out who wins.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output

For each test case, print a single line containing the string "Yes" if Nayeon wins the game or "No" if Tzuyu wins (without quotes).

Constraints

1≤T≤40,000
2≤N≤3⋅10^5
0≤Ai≤1 for each valid i
A1=AN=1
the sum of N over all test cases does not exceed 10^6 

*/

fn main() {
    assert_eq!(win(vec![1, 1, 0, 0, 0, 1, 1]), true);
    assert_eq!(win(vec![1, 0, 1, 1, 1, 0, 0, 1]), false);
    assert_eq!(win(vec![1, 1, 0, 1]), true);
    assert_eq!(win(vec![1, 1, 1, 1]), false);
}

fn win(a: Vec<isize>) -> bool {
    let (mut c, mut f, mut s) = (0, 0, 0);
    for v in a {
        if v != 1 {
            c += 1;
            continue;
        }

        if c == 0 {
            continue;
        }

        if c > f {
            s = f;
            f = c;
        } else if c > s {
            s = c;
        }
        c = 0;
    }

    (f & 1 != 0) && s < (f + 1) / 2
}
