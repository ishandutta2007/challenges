/*

Background

This is a standard textbook example to demonstrate for loops.

This is one of the first programs I learnt when I started learning programming ~10 years ago.

Task

You are to print this exact text:

**********
**********
**********
**********
**********
**********
**********
**********
**********
**********

Specs

    You may have extra trailing newlines.
    You may have extra trailing spaces (U+0020) at the end of each line, including the extra trailing newlines.

Scoring

This is code-golf. Shortest answer in bytes wins.

*/

fn main() {
    grid(10);
}

fn grid(n: isize) {
    for _ in 0..n {
        for _ in 0..n {
            print!("*");
        }
        println!();
    }
}
