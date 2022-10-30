/*

Create a function which counts how many lone 1s appear in a given number. Lone means the number doesn't appear twice or more in a row.

Examples

countLoneOnes(101) ➞ 2

countLoneOnes(1191) ➞ 1

countLoneOnes(1111) ➞ 0

countLoneOnes(462) ➞ 0

Notes

Tests will include positive whole numbers only.

*/

fn ones(mut n: u128) -> isize {
    let mut p = [0, 0, 0];
    let mut r = 0;
    while n != 0 {
        p[1] = n % 10;
        p[2] = (n / 10) % 10;
        if p[1] == 1 && p[0] != 1 && p[2] != 1 {
            r += 1;
        }
        p[0] = p[1];
        
        n /= 10;
    }
    return r;
}

fn main() {
    assert_eq!(ones(101), 2);
    assert_eq!(ones(1191), 1);
    assert_eq!(ones(1111), 0);
    assert_eq!(ones(11101), 1);
    assert_eq!(ones(462), 0);
    assert_eq!(ones(12131415161718191), 9);
    assert_eq!(ones(11231212111), 2);
    assert_eq!(ones(1), 1);
    assert_eq!(ones(0), 0);
}
