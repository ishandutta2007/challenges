/*

In this challenge, submissions will be programs or function which, when given an emoticon such as :-), :(, or :D, will rate their happiness from 0 to 3.

An emoticon will be one of the following:

    :(: 0
    :|: 1
    :): 2
    :D: 3

Emoticons may also have noses (a - after the :).

Test cases:

:(  -> 0
:-| -> 1
:D  -> 3
:-) -> 2
:|  -> 1

This is a code golf challenge, shortest answer per language wins.

*/

fn main() {
    assert_eq!(happiness(":("), 0);
    assert_eq!(happiness(":|"), 1);
    assert_eq!(happiness(":)"), 2);
    assert_eq!(happiness(":D"), 3);
    assert_eq!(happiness(":X"), -1);
}

fn happiness(s: &str) -> isize {
    match s {
        ":(" => 0,
        ":|" => 1,
        ":)" => 2,
        ":D" => 3,
        _ => -1
    }
}
