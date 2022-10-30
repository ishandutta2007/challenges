/*

There are 100 houses located on a straight line. The first house is numbered 1 and the last one is numbered 100. Some M houses out of these 100 are occupied by cops.

Thief Devu has just stolen PeePee's bag and is looking for a house to hide in.

PeePee uses fast 4G Internet and sends the message to all the cops that a thief named Devu has just stolen her bag and ran into some house.

Devu knows that the cops run at a maximum speed of x houses per minute in a straight line and they will search for a maximum of y minutes. Devu wants to know how many houses are safe for him to escape from the cops. Help him in getting this information.

Input

First line contains T, the number of test cases to follow.

First line of each test case contains 3 space separated integers: M, x and y.

For each test case, the second line contains M space separated integers which represent the house numbers where the cops are residing.

Output

For each test case, output a single line containing the number of houses which are safe to hide from cops.

Constraints
1 ≤ T ≤ 10^4
1 ≤ x, y, M ≤ 10

*/

fn main() {
    assert_eq!(safehouses(vec![12, 52, 56, 8], 7, 8), 0);
    assert_eq!(safehouses(vec![21,  75], 10, 2), 18);
    assert_eq!(safehouses(vec![10, 51], 5, 8), 9);
}

fn safehouses(c: Vec<isize>, x: isize, y: isize) -> isize {
    let mut s = 0;
    let d = x * y;
    'xloop: for i in 1..101 {
        for p in &c {
            let l = isize::max(p - d, 1);
            let r = isize::min(p + d, 100);
            if l <= i && i <= r {
                continue 'xloop;
            }
        }
        s += 1;
    }
    s
}
