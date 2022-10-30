/*

Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?

Return the total number of possible paths a salesman can travel, given n paths.
Examples

paths(4) ➞ 24

paths(1) ➞ 1

paths(9) ➞ 362880

Notes

Inspired by a video from Dr. Peter Merz.
https://www.youtube.com/watch?v=2iBR8v2i0pM&index=5&list=PLlnnSiqU0W2SuojKlqQ0yxowK9VqeQKmF

*/

fn main() {
    for i in 0..10 {
        println!("{}: {}", i, paths(i));
    }
}

fn paths(n: usize) -> usize {
    factorial(n)
}

fn factorial(n: usize) -> usize {
    let mut v = 1;
    for i in 1..n+1 {
        v *= i;
    }
    return v;
}
