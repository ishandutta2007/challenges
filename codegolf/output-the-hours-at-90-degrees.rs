/*

Today while playing with my kids I noticed that an apparently simple toy in the park hid a challenge.

Clock

The wheel has a triangle that points to a number, but also has three circles that point to the numbers every 90 degrees from the first one. So:

Challenge (really simple)

Given an integer between 1 and 12 (the one pointed by the triangle) in any acceptable form, output also in any acceptable form and order the three numbers pointed by the circles (the ones every 90 degrees).

Test cases

In       Out
1        4, 7, 10
2        5, 8, 11
3        6, 9, 12
4        7, 10, 1
5        8, 11, 2
6        9, 12, 3
7        10, 1, 4
8        11, 2, 5
9        12, 3, 6
10       1, 4, 7
11       2, 5, 8
12       3, 6, 9
This is code-golf, so may the shortest code for every language win!

*/

fn main() {
    assert_eq!(ticks(1), (4, 7, 10));
    assert_eq!(ticks(2), (5, 8, 11));
    assert_eq!(ticks(3), (6, 9, 12));
    assert_eq!(ticks(4), (7, 10, 1));
    assert_eq!(ticks(5), (8, 11, 2));
    assert_eq!(ticks(6), (9, 12, 3));
    assert_eq!(ticks(7), (10, 1, 4));
    assert_eq!(ticks(8), (11, 2, 5));
    assert_eq!(ticks(9), (12, 3, 6));
    assert_eq!(ticks(10), (1, 4, 7));
    assert_eq!(ticks(11), (2, 5, 8));
    assert_eq!(ticks(12), (3, 6, 9));
}

fn ticks(n: usize) -> (usize, usize, usize) {
    let t1 = ((n + 2) % 12) + 1;
    let t2 = ((n + 5) % 12) + 1;
    let t3 = ((n + 8) % 12) + 1;
    (t1, t2, t3)
}
