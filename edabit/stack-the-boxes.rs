/*

Here's an image of four models. Some of the cubes are hidden behind other cubes. Model one consists of one cube. Model two consists of four cubes, and so on...

Stack the Boxes

https://edabit-challenges.s3.amazonaws.com/stack_the_boxes.png

Write a function that takes a number n and returns the number of stacked boxes in a model n levels high, visible and invisible.
Examples

stackBoxes(1) ➞ 1

stackBoxes(2) ➞ 4

stackBoxes(0) ➞ 0

Notes

Step n is a positive integer.

*/

fn main() {
    assert_eq!(stack_boxes(1), 1);
    assert_eq!(stack_boxes(2), 4);
    assert_eq!(stack_boxes(0), 0);
    assert_eq!(stack_boxes(5), 25);
    assert_eq!(stack_boxes(27), 729);
    assert_eq!(stack_boxes(196), 38416);
    assert_eq!(stack_boxes(512), 262144);
}

fn stack_boxes(n: usize) -> usize {
    n*n
}
