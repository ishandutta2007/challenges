/*

It's simple, simply output text to STDERR containing the string EOF.

Input/Output
Your input will be none; however, you should output the message to STDERR.

Rules
Since this is code-golf, the shortest answer wins.
No standard loopholes please.
Any method approved by Standard I/O is allowed.
Your code may not contain the "EOF" that you will output as-is in your error.
Outputting "EOI" is technically allowed, because the input can also be considered as a separate file.

*/

fn main() {
    eprintln!("EOF");
}
