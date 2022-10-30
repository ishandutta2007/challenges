/*

As Manuel wants to get rich fast and without too much work, he decided to make a career in gambling.
Initially, he plans to study the gains and losses of players, so that, he can identify patterns of consecutive wins and elaborate a win-win strategy.
But Manuel, as smart as he thinks he is, does not know how to program computers.
So he hired you to write programs that will assist him in elaborating his strategy.
Your first task is to write a program that identifies the maximum possible gain out of a sequence of bets.
A bet is an amount of money and is either winning (and this is recorded as a positive value), or losing (and this is recorded as a negative value).

Input

The input set consists of a positive number N ≤ 10000 , that gives the length of the sequence, followed by N integers.
Each bet is an integer greater than 0 and less than 1000.
The input is terminated with N = 0.

Output

For each given input set, the output will echo a line with the corresponding solution.
If the sequence shows no possibility to win money, then the output is the message ‘Losing streak.’

Sample Input

5
12 -4
-10 4
9
3
-2 -1 -2
0

Sample Output

The maximum winning streak is 13.
Losing streak.

*/

fn main() {
    assert_eq!(streak(vec![12, -4, -10, 4, 9]), "The maximum winning streak is 13.");
    assert_eq!(streak(vec![-2, -1, -2]), "Losing streak.");
}

fn streak(a: Vec<isize>) -> String {
    let mut c = 0;
    let mut m = 0;
    for v in a {
        c += v;
        if c < 0 {
            c = 0;
        }
        if m < c {
            m = c;
        }
    }
    if m <= 0 {
        return format!("Losing streak.");
    }
    return format!("The maximum winning streak is {}.", m);
}
