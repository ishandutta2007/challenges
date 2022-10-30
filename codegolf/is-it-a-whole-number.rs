/*

A number is whole if it is a non-negative integer with no decimal part. So 0 and 8 and 233494.0 are whole, while 1.1 and 0.001 and 233494.999 are not.

Input

A floating-point number in the default base/encoding of your language.

For example, the default integer representation for Binary Lambda Calculus would be Church numerals. But the default integer representation for Python is base 10 decimal, not Unary.

Output

A truthy value if the input is whole, a falsy value if it is not.

Note that if your language only supports decimal precision to, say, 8 places, 1.000000002 can be considered whole.

Input and output may be done via any standard I/O methods.
Test cases

Input        -> Output
332          -> true
33.2         -> false
128239847    -> true
0.128239847  -> false
0            -> true
0.000000000  -> true
1.111111111  -> false
-3.1415926   -> false
-3           -> false

Scoring

As with code-golf, the shortest submission wins. Good luck!

*/

fn main() {
    assert_eq!(whole(8.0), true);
    assert_eq!(whole(233494.0), true);
    assert_eq!(whole(0.001), false);
    assert_eq!(whole(233494.999), false);
    assert_eq!(whole(332.0), true);
    assert_eq!(whole(33.2), false);
    assert_eq!(whole(128239847.0), true);
    assert_eq!(whole(0.128239847), false);
    assert_eq!(whole(0.0), true);
    assert_eq!(whole(0.000000000), true);
    assert_eq!(whole(1.111111111), false);
    assert_eq!(whole(-3.1415926), false);
    assert_eq!(whole(-3.0), false);
}

fn whole(x: f64) -> bool {
    x >= 0.0 && x.fract() == 0.0
}
