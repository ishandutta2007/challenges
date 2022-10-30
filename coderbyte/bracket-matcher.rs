/*

Have the function BracketMatcher(str) take the str parameter being passed and return 1 if the brackets are correctly matched and each one is accounted for.
Otherwise return 0. For example: if str is "(hello (world))", then the output should be 1, but if str is "((hello (world))" the the output should be 0 because the brackets do not correctly match up.
Only "(" and ")" will be used as brackets. If str contains no brackets return 1.

Examples

Input: "(coder)(byte))"
Output: 0

Input: "(c(oder)) b(yte)"
Output: 1

*/

fn bracket_matcher(s: &str) -> isize {
    let mut p = 0;
    for c in s.chars() {
        if c == '(' {
            p += 1;
        } else if c == ')' {
            if p <= 0 {
                return 0;
            }
            p -= 1;
        }
    }

    if p != 0 {
        return 0;
    }
    return 1;
}

fn main() {
    assert_eq!(bracket_matcher("(hello (world))"), 1);
    assert_eq!(bracket_matcher("((hello (world))"), 0);
    assert_eq!(bracket_matcher("(coder)(byte))"), 0);
    assert_eq!(bracket_matcher("(c(oder)) b(yte)"), 1);
}
