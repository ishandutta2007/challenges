/*

yes, from coreutils, is 91 lines long. Many of them are comments, but that is still WAY too long.

Edit from September 2019: the source file grew over the past five years and is now 126 lines long.

Write a program that imitates yes:

    outputting to stdout an infinite stream of "y\n"'s
    there must be an option to stop it other than killing the process with SIGKILL: but SIGINT and SIGPIPE are fine
    you are not allowed to use "y" or "\n" or their ASCII values (121, 0x79, 0171, 10, 0xA or 012)

Shortest answer wins.

Bonus:

    subtract 10 from your code length, if you can receive a phrase in stdin and print it out instead of "y" (but still including the line-break). The program doesn't have to print y on an empty input.

*/

fn main() {
    loop {
        println!("y");
    }
}
