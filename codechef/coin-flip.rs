/*

Little Elephant was fond of inventing new games. After a lot of research, Little Elephant came to know that most of the animals in the forest were showing less interest to play the multi-player games.
Little Elephant had started to invent single player games, and succeeded in inventing the new single player game named COIN FLIP.

In this game the player will use N coins numbered from 1 to N, and all the coins will be facing in "Same direction" (Either Head or Tail), which will be decided by the player before starting of the game.

The player needs to play N rounds. In the k-th round the player will flip the face of the all coins whose number is less than or equal to k. That is, the face of coin i will be reversed, from Head to Tail, or, from Tail to Head, for i≤k.

Elephant needs to guess the total number of coins showing a particular face after playing N rounds. Elephant really becomes quite fond of this game COIN FLIP so Elephant plays G times. Please help the Elephant to find out the answer.

Input:

The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow.

The first line of each test contains an integer G, denoting the number of games played by Elephant.
Each of the following G lines denotes a single game, and contains 3 space-separated integers I, N, Q, where I denotes the initial state of the coins, N denotes the number of coins and rounds, and Q, which is either 1, or 2 as explained below.

Here I=1 means all coins are showing Head in the start of the game, and I=2 means all coins are showing Tail in the start of the game.
Q=1 means Elephant needs to guess the total number of coins showing Head in the end of the game, and Q=2 means Elephant needs to guess the total number of coins showing Tail in the end of the game.

Output:

For each game, output one integer denoting the total number of coins showing the particular face in the end of the game.

Constraints:
1≤T≤10
1≤G≤2000
1≤N≤10
1≤I≤2
1≤Q≤2

*/

fn main() {
    assert_eq!(coins(1, 5, 1), 2);
    assert_eq!(coins(1, 5, 2), 3);
}

fn coins(i: isize, n: isize, q: isize) -> isize {
    if (n & 1) == 0 || i == q {
        n / 2
    } else {
        n / 2 + 1
    }
}
