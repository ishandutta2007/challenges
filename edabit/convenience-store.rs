/*

Given a total due and an array representing the amount of change in your pocket, determine whether or not you are able to pay for the item.
Change will always be represented in the following order: quarters, dimes, nickels, pennies.

To illustrate: changeEnough([25, 20, 5, 0], 4.25) should yield true, since having 25 quarters, 20 dimes, 5 nickels and 0 pennies gives you 6.25 + 2 + .25 + 0 = 8.50.
Examples

changeEnough([2, 100, 0, 0], 14.11) ➞ false

changeEnough([0, 0, 20, 5], 0.75) ➞ true

changeEnough([30, 40, 20, 5], 12.55) ➞ true

changeEnough([10, 0, 0, 50], 3.85) ➞ false

changeEnough([1, 0, 5, 219], 19.99) ➞ false

Notes

    quarter: 25 cents / $0.25
    dime: 10 cents / $0.10
    nickel: 5 cents / $0.05
    penny: 1 cent / $0.01

*/

fn main() {
    assert_eq!(change_enough(&vec![2.0, 100.0, 0.0, 0.0], 14.11), false);
    assert_eq!(change_enough(&vec![0.0, 0.0, 20.0, 5.0], 0.75), true);
    assert_eq!(change_enough(&vec![30.0, 40.0, 20.0, 5.0], 12.55), true);
    assert_eq!(change_enough(&vec![10.0, 0.0, 0.0, 50.0], 13.85), false);
    assert_eq!(change_enough(&vec![1.0, 0.0, 5.0, 219.0], 19.99), false);
    assert_eq!(change_enough(&vec![1.0, 0.0, 2555.0, 219.0], 127.75), true);
    assert_eq!(change_enough(&vec![1.0, 335.0, 0.0, 219.0], 35.21), true);
}

fn change_enough(p: &Vec<f64>, v: f64) -> bool {
    let tab = vec![0.25, 0.1, 0.05, 0.01];
    let mut c = 0.0;
    for i in 0..p.len() {
        c += p[i]*tab[i]; 
    }
    return c >= v;
}
