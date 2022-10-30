/*

Write a function that checks whether a person can watch an MA15+ rated movie. One of the following two conditions is required for admittance:

    The person is at least 15 years old.
    They have parental supervision.

The function accepts two parameters, age and isSupervised. Return a boolean.
Examples

acceptIntoMovie(14, true) ➞ true

acceptIntoMovie(14, false) ➞ false

acceptIntoMovie(16, false) ➞ true

Notes

    age is a decimal.
    isSupervised is a boolean.

*/

fn main() {
    assert_eq!(admit(14.0, true), true);
    assert_eq!(admit(15.0, true), true);
    assert_eq!(admit(16.0, true), true);
    assert_eq!(admit(14.0, false), false);
    assert_eq!(admit(15.0, false), true);
    assert_eq!(admit(16.0, false), true);
    assert_eq!(admit(14.99999, true), true);
    assert_eq!(admit(14.99999, false), false);
}

fn admit(age: f64, supervised: bool) -> bool {
    age >= 15.0 || supervised
}
