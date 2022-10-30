/*

C++ has a logical operator &&, which can also be written as "and" (for users without & on their keyboard). The && operator is very useful, it takes in two values. For example, a&&b works like:

    a is checked if it is true or false.
    Same with b if a is true. If a is false, return false
    Return true if a and b are true and false otherwise.

The && operator is equivalent to this function (it doesn't use any shortcuts so it is easier to understand for beginners):

bool AND(bool a, bool b){
  if (a == false) {
    return false; // stops function and returns false
  }
  else if (b == true){ // "a" must be true because it would return otherwise
    return true;
  } else {
    return false;
  }
}

So, && will only return true for true&&true.

Make a function using &&.
Examples

andAnd(true, false) ➞ false

andAnd(true, true) ➞ true

andAnd(false, true) ➞ false

andAnd(false, false) ➞ false

*/

fn main() {
    assert_eq!(and_and(true, false), false);
    assert_eq!(and_and(true, true), true);
    assert_eq!(and_and(false, true), false);
    assert_eq!(and_and(false, false), false);
}

fn and_and(a: bool, b: bool) -> bool {
    a && b
}
