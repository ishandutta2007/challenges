/*

After acquiring a new integer and showing it off to other couples at a cocktail party, Alice and Bob headed home for a good night of sleep.
As their integer was quite large, they were forced to carry it together. Then, on the Boole Boulevard, right by the Bayes Bay, disaster struck.
History does not tell us which of our two protagonists stumbled first, but stumble they did, and their integer shattered into n positive integral pieces on the pavement in front of them.

The couple’s marriage, already under financial stress due to the expensive integer acquisition, did not survive this event, and Bob and Alice resolved to separate.
Thus the question was raised on how to split the remnants of their integer.
Bob and Alice decided to play a game with the remaining n pieces: the two would repeatedly choose pieces in alternating turns until none were left.

Bob and Alice, both very materialistic, seek to acquire the largest possible sum of integers possible. Compute the value of the integers each of them ends up with.
Assume both players play optimally. Since A comes before B in the alphabet, Alice moves first.

Input

The input consists of two lines.

    A single integer 1≤n≤15, the number of pieces.

The values of the pieces a0,a1,…,an−1, space-separated. It is given that 1≤ai≤100.

Output

Output a single line containing two integers, the combined value of Alice’s pieces, and the combined value of Bob’s pieces.

*/

fn main() {
    assert_eq!(score(vec![3, 1, 2]), (4, 2));
    assert_eq!(score(vec![1, 2, 2, 1]), (3, 3));
}

fn score(mut a: Vec<isize>) -> (isize, isize) {
    let (mut x, mut y) = (0, 0);
    
    a.sort();
    for (i, v) in a.iter().enumerate() {
        if i&1 == 0 {
            x += v;
        } else {
            y += v;
        }
    }

    (x, y)
}
