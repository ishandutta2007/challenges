/*

Create a function which validates whether a number n is exclusively within the bounds of lower and upper. Return false if n is not an integer.
Examples

intWithinBounds(3, 1, 9) ➞ true

intWithinBounds(6, 1, 6) ➞ false

intWithinBounds(4.5, 3, 8) ➞ false

Notes

    Exclusively means that a number is considered not within the bounds if it is equal to the upper bound (see example #2).
    Bounds will be always given as integers.

*/

fn main() {
    assert_eq!(int_within_bounds(3.0, 1, 9), true);
    assert_eq!(int_within_bounds(6.0, 1, 6), false);
    assert_eq!(int_within_bounds(4.5, 3, 8), false);
    assert_eq!(int_within_bounds(-5.0, -10, 6), true);
    assert_eq!(int_within_bounds(4.0, 0, 0), false);
    assert_eq!(int_within_bounds(10.0, 9, 11), true);
    assert_eq!(int_within_bounds(6.3, 2, 6), false);
    assert_eq!(int_within_bounds(6.3, 2, 10), false);
    assert_eq!(int_within_bounds(9.0, 2, 3), false);
    assert_eq!(int_within_bounds(9.0, 9, 9), false);
    assert_eq!(int_within_bounds(-3.0, -5, -2), true);
    assert_eq!(int_within_bounds(-3.0, -5, -3), false);
    assert_eq!(int_within_bounds(-3.0, -10, 10), true);
    assert_eq!(int_within_bounds(0.0, -3, 3), true);
    assert_eq!(int_within_bounds(0.0, 0, 1), true);
    assert_eq!(int_within_bounds(7.0, 7, 12), true);
}

fn int_within_bounds(x: f64, a: isize, b: isize) -> bool {
    x.fract() == 0.0 && (a as f64) <= x && x < (b as f64)
}
