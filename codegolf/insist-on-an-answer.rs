/*

At runtime, keep prompting for a line of input until the user inputs something (other than an empty newline), i.e. does not just press Enter or OK. Output or result is neither required nor prohibited.

Pseudo-code 1
myform = new form("GUI")
myform.mytxt = new editfield("")
myform.ok = new button("OK")
repeat
  waitfor(myform.ok,"click")
until myform.mytxt.content <> ""
Pseudo-code 2
LET TEXT = ""
WHILE TEXT = "" DO
  TEXT = PROMPT("")
ENDWHILE
Example 1
Program runs and immediately pops up a form with a single text field and an OK button.
User clicks the OK button.
Nothing happens.
User pastes "hello world" into the text field and clicks the OK button.
Program terminates.

Example 2
Function is called and immediately displays a blank line and a blinking cursor.
User presses Enter.
Cursor moves down one line.
User presses Enter.
Cursor moves down one line.
User presses PPCGEnter
Function returns.

*/

use std::io::*;

fn main() {
    input();
}

fn input() {
    text("> ");
    for line in stdin().lock().lines() {
        if line.unwrap() != "" {
            break;
        }
        text("> ");
    }
    println!();
}

fn text(s: &str) {
    print!("{}", s);
    stdout().flush().unwrap();
}
