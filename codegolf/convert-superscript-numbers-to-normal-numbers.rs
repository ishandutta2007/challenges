/*

Introduction
My gnome friends are writing a programming language and have asked for my help. Due to their size, the gnomes can only handle small superscript numbers instead of big numbers.
However, the language they're writing the interpreter in only accepts big numbers!

Your Challenge
Given an input of a superscript number (a series of characters that can be any of ⁰¹²³⁴⁵⁶⁷⁸⁹), convert it to normal ASCII numbers and print the result.
This is code golf, so shortest answer wins!

Test Cases
¹ -> 1
⁵ -> 5
¹²³ -> 123
⁶⁵⁵³⁵ -> 65535
⁰¹²³ -> 123

*/

fn main() {
    assert_eq!(conv("¹"), 1);
    assert_eq!(conv("⁵"), 5);
    assert_eq!(conv("¹²³"), 123);
    assert_eq!(conv("⁶⁵⁵³⁵"), 65535);
    assert_eq!(conv("⁰¹²³"), 123);
    assert_eq!(conv("³⁰⁰⁰¹²³"), 3000123);
    assert_eq!(conv("0000000023"), 23);
}

fn conv(s: &str) -> isize {
    let mut r = 0;
    for c in s.chars() {
        let v = value(c);
        if v < 0 {
            return -1;
        }
        r = (r * 10) + v;
    }
    r
}

fn value(c: char) -> isize {
    match c {
        '0' | '⁰' => 0,
        '1' | '¹' => 1,
        '2' | '²' => 2,
        '3' | '³' => 3,
        '4' | '⁴' => 4,
        '5' | '⁵' => 5,
        '6' | '⁶' => 6,
        '7' | '⁷' => 7,
        '8' | '⁸' => 8,
        '9' | '⁹' => 9,
        _ => -1,
    }
}
