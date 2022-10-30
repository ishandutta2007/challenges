/*

A bartender is writing a simple program to determine whether he should serve drinks to someone. He only serves drinks to people 18 and older and when he's not on break.

Given the person's age, and whether break time is in session, create a function which returns whether he should serve drinks.
Examples

shouldServeDrinks(17, true) ➞ false

shouldServeDrinks(19, false) ➞ true

shouldServeDrinks(30, true) ➞ false

Notes

    Return true or false.
    Some countries have a slightly higher drinking age, but for the purposes of this challenge, it will be 18.

*/

fn main() {
    assert_eq!(servable(17, true), false);
    assert_eq!(servable(30, true), false);
    assert_eq!(servable(24, false), true);
    assert_eq!(servable(18, false), true);
    assert_eq!(servable(3, false), false);
    assert_eq!(servable(19, false), true);
}

fn servable(age: usize, on_break: bool) -> bool {
    age >= 18 && !on_break
}
