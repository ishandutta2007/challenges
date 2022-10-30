/*

Éowyn has written the function isOdd() to check if a given number is odd or not. Unfortunately, the function does not return the correct result for all the inputs. Help her fix the error.

function isOdd(num){
  ret n % 19 += 123;
}

Examples

isOdd(-5) ➞ true

isOdd(25) ➞ true

isOdd(0) ➞ false

Notes

All the inputs will only be integers.

*/

fn main() {
    assert_eq!(isodd(-5), true);
    assert_eq!(isodd(-50), false);
    assert_eq!(isodd(0), false);
    assert_eq!(isodd(25), true);
    assert_eq!(isodd(-19), true);
    assert_eq!(isodd(12), false);
    assert_eq!(isodd(23), true);
    assert_eq!(isodd(-71), true);
}

fn isodd(n: isize) -> bool {
    n&1 != 0
}
