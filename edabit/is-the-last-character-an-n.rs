/*

Create a function that takes a string (a random name). If the last character of the name is an "n", return true, otherwise return false.
Examples

isLastCharacterN("Aiden") ➞ true

isLastCharacterN("Piet") ➞ false

isLastCharacterN("Bert") ➞ false

isLastCharacterN("Dean") ➞ true

Notes

The function must return a boolean value ( i.e. true or false).

*/

fn main() {
    assert_eq!(islchn("Piet"), false);
    assert_eq!(islchn("Aiden"), true);
    assert_eq!(islchn("Roxy"), false);
    assert_eq!(islchn("Bert"), false);
    assert_eq!(islchn("Dean"), true);
    assert_eq!(islchn("Ian"), true);
    assert_eq!(islchn("Brian"), true);
    assert_eq!(islchn("Daniel"), false);
}

fn islchn(s: &str) -> bool {
    let l = s.len();
    return l > 0 && s.as_bytes()[l-1] == 'n' as u8;
}
