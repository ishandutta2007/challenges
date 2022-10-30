/*

Sarthak and Anuradha are very good friends and are eager to participate in an event called Equinox.
It is a game of words. In this game, N strings S1,…,SN are given.
For each string Si, if it starts with one of the letters of the word “EQUINOX”, Sarthak gets A points and if not, Anuradha gets B points.
The one who has more points at the end of the game wins.
If they both the same number of points, the game is a draw..

Print the winner of the game, if any, otherwise print “DRAW”.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
The first line of each test case contains three integers N, A, B.
N lines follow, each containing a string Si.
All strings are in UPPERCASE.

Output

For each test case, print “SARTHAK” (case insensitive) if he has more points than Anuradha, print “ANURADHA” (case insensitive) if she has more points than Sarthak, otherwise print “DRAW” (case insensitive), without the quotes.

Constraints

1≤T≤100
1≤N≤100
1≤A, B≤10^9
1≤|Si|≤100

*/

fn main() {
    assert_eq!(winner(vec!["ABBBCDDE", "EARTH", "INDIA", "UUUFFFDDD"], 1, 3), "Draw");
    assert_eq!(winner(vec!["SDHHD", "XOXOXOXO"], 5, 7), "Anuradha");
}

fn winner(s: Vec<&'static str>, a: isize, b: isize) -> &'static str {
    let (mut x, mut y) = (0, 0);
    for p in s {
        if p.len() == 0 {
            continue;
        }
        
        let c = p.chars().nth(0).unwrap();
        match c {
            'E' | 'Q' | 'U' | 'I' | 'N' | 'O' | 'X' => x += a,
            _                                       => y += b,
        }
    }

    if x == y {
        "Draw"
    } else if x > y {
        "Sarthak"
    } else {
        "Anuradha"
    }
}
