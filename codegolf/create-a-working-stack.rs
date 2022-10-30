/*

Your mission, if you choose to accept it, is to create a stack that can do basic math operations.

Explanation: Your stack must be able to do basic arithmetic (+ - * /) and must support normal base 10 numbers (0123456879); numbers will only be one character long.

Programming: Input from stdin will be loaded as a program. After the program has finished running, the contents of the stack will be printed with no spaces in between after the program runs.

Each character in the program does a different thing to the stack:

A number will push itself
A math operation will take the top two numbers on the stack and push the output.
Example I/O:

Input:

45+
Output:
9
Input:

235234
Output:
235234
Input:

566*+
Output:
41
Input:

243+-
Output:
-5
Input:

78+243+-
Output:
15-5
Division is shown as a integer if it has .0:

Input:

63/
Output:
2
Repeating Decimals are cut off at 2 places:

Input:

43/
Output:
1.33
Rules:

You stack must have a length of least 128.
Your stack must be double/float based.
No eval-ing!
Scoring: Your score is you byte count with a couple modifiers.

x0.9 if you include mod (%) and pow (^).
x0.8 if you parse numbers in base 36 (0-9A-Z).
x0.7 if you parse strings (each character of the string will be pushed as separate numbers)
"Hi" pushes 72 and 105, which will output 72105.

*/

fn main() {
    assert_eq!(rpn("45+"), "9");
    assert_eq!(rpn("235234"), "235234");
    assert_eq!(rpn("566*+"), "41");
    assert_eq!(rpn("243+-"), "-5");
    assert_eq!(rpn("78+243+-"), "15-5");
    assert_eq!(rpn("63/"), "2");
    assert_eq!(rpn("43/"), "1.33");
}

fn rpn(expr: &str) -> String {
    let mut stack = vec![];
    for ch in expr.chars() {
        match ch {
            '+' | '-' | '*' | '/' => binop(ch, &mut stack),
            '0'..='9' => digit(ch, &mut stack),
            _ => (),
        }
    }
    return number(&mut stack);
}

fn binop(op: char, stack: &mut Vec<f64>) {
    if stack.len() < 2 {
        return;
    }

    let x = stack.pop().unwrap();
    let y = stack.pop().unwrap();
    match op {
        '+' => stack.push(y + x),
        '-' => stack.push(y - x),
        '*' => stack.push(y * x),
        '/' => stack.push(y / x),
        _ => (),
    }
}

fn digit(ch: char, stack: &mut Vec<f64>) {
    let x = ch as isize;
    let y = '0' as isize;
    let v = (x - y) as f64;
    stack.push(v);
}

fn number(stack: &mut Vec<f64>) -> String {
    let mut r = String::new();
    for v in stack {
        let s: String;
        if v.fract() == 0.0 {
            s = format!("{}", *v as isize);
        } else {
            s = format!("{:.2}", v);
        }
        r.push_str(&s);
    }
    r
}
