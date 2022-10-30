/*

Background:

A sequence of infinite naturals is a sequence that contains every natural number infinitely many times.

To clarify, every number must be printed multiple times!
The Challenge:

Output a sequence of infinite naturals with the shortest code.
Rules:

    Each number must be separated by a (finite) amount of visible, whitespace or new line characters that aren't a digit.
    The program cannot terminate (unless you somehow wrote all numbers).
    Any way of writing such a sequence is acceptable.

Examples:

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6 7
...

1, 1, 2, 1, 2, 3, 1, 2, 3, 4...

Notice that we write all naturals from 1 to N for all N ∈ ℕ.

Feedback and edits to the question are welcome. Inspired by my Calculus exam.

*/

fn main() {
    let mut i: u128 = 1;
    loop {
        for j in 1..i {
            println!("{}", j);
        }
        i += 1;
    }
}
