/*

Create a function that accepts a measurement value in inches and returns the equivalent of the measurement value in feet.

Examples

inches_to_feet(324) ➞ 27

inches_to_feet(12) ➞ 1

inches_to_feet(36) ➞ 3

Notes

    If inches are under 12, return 0.
    12 inches = 1 foot.

Test.assert_equals(inches_to_feet(12), 1) 

Test.assert_equals(inches_to_feet(360), 30) 

Test.assert_equals(inches_to_feet(3612), 301)

Test.assert_equals(inches_to_feet(324), 27)

Test.assert_equals(inches_to_feet(3012), 251)

Test.assert_equals(inches_to_feet(11), 0)

*/

fn in2ft(i: isize) -> isize {
    n/12
}

fn main() {
    assert_eq!(in2ft(12), 1);
    assert_eq!(in2ft(360), 30);
    assert_eq!(in2ft(3612), 301);
    assert_eq!(in2ft(324), 27);
    assert_eq!(in2ft(3012), 251);
    assert_eq!(in2ft(11), 0);
}
