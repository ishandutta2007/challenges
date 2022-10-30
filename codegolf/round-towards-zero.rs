/*

This is a simple task. Given a positive or negative real number, round it to the next whole integer closer to zero.

The challenge
Take input through any reasonable form (stdin, function, etc.) of one positive or negative real number.

Round this number "towards zero" - this means if it is positive you will round down, and if it is negative you will round up.

Return the number or output it to the console.

Test cases
 1.1   =>  1
-1.1   => -1
 500.4 =>  500
-283.5 => -283
 50    =>  50
-50    => -50

Rules

This is code-golf, so least score in bytes wins.

Be mindful of the standard loopholes.

*/

fn main() {
    assert_eq!(round(1.1), 1.0);
    assert_eq!(round(-1.1), -1.0);
    assert_eq!(round(500.4), 500.0);
    assert_eq!(round(-283.5), -283.0);
    assert_eq!(round(50.0), 50.0);
    assert_eq!(round(-50.0), -50.0);
}

fn round(x: f64) -> f64 {
    if x > 0.0 {
        x.floor()
    } else {
        x.ceil()
    }
}
