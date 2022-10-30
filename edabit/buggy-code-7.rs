/*

Mubashir wants to swap two given numbers!

It is not returning the right values. Can you help him fix it?

a = 100
b = 200
a, b = swap(a, b)
print(a, b) // Should print out "200, 100", but the function prints out "100, 100"

Examples

swap(100, 200) ➞ [200, 100]

swap(44, 33) ➞ [33, 44]

swap(21, 12) ➞ [12, 21]

Notes

N/A

*/

fn swap(a: &mut isize, b: &mut isize) {
    let t = *a;
    *a = *b;
    *b = t;
}

fn main() {
    let mut a = 100;
    let mut b = 200;
    swap(&mut a, &mut b);
    assert_eq!(a == 200 && b == 100, true);

    a = 44;
    b = 33;
    swap(&mut a, &mut b);
    assert_eq!(a == 33 && b == 44, true);

    a = 21;
    b = 12;
    swap(&mut a, &mut b);
    assert_eq!(a == 12 && b == 21, true);

    a = 10;
    b = 20;
    swap(&mut a, &mut b);
    assert_eq!(a == 20 && b == 10, true);
}
