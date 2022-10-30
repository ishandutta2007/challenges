/*

Challenge
You have one string of input bytes, output the last byte in it.

Rules
Your submission may be a program or function outputting the last byte in the input which

is either a string, stdin or command-line arguments, and
is non-empty.
I was trying to solve this with brainfuck, however all languages are allowed to participate. This is code-golf.

Examples
"?" -> "?"
"29845812674" -> "4"

*/

fn main() {
    assert_eq!(lastchar("?"), '?');
    assert_eq!(lastchar("29845812674"), '4');
}

fn lastchar(s: &'static str) -> char {
    let b = s.as_bytes();
    let n = b.len();
    if n == 0 {
        return '\0';
    }
    b[n - 1] as char
}
