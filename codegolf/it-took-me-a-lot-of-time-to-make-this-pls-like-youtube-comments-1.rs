/*

Hold up..... this isn't trolling.

Background
These days on YouTube, comment sections are littered with such patterns:

S
St
Str
Stri
Strin
String
Strin
Stri
Str
St
S
where String is a mere placeholder and refers to any combination of characters. These patterns are usually accompanied by a It took me a lot of time to make this, pls like or something, and often the OP succeeds in amassing a number of likes.

The Task
Although you've got a great talent of accumulating upvotes on PPCG with your charming golfing skills, you're definitely not the top choice for making witty remarks or referencing memes in YouTube comment sections.
Thus, your constructive comments made with deliberate thought amass a few to no 'likes' on YouTube. You want this to change.
So, you resort to making the abovementioned clichéd patterns to achieve your ultimate ambition, but without wasting any time trying to manually write them.

Simply put, your task is to take a string, say s, and output 2*s.length - 1 substrings of s, delimited by a newline, so as to comply with the following pattern:

(for s = "Hello")

H
He
Hel
Hell
Hello
Hell
Hel
He
H
Input
A single string s. Input defaults of the community apply. You can assume that the input string will only contain printable ASCII characters.

Output
Several lines separated by a newline, constituting an appropriate pattern as explained above.
Output defaults of the community apply.
Leading and trailing blank (containing no characters or characters that cannot be seen, like a space) lines in the output are permitted.

Test Case
A multi-word test case:

Input => "Oh yeah yeah"

Output =>

O
Oh
Oh 
Oh y
Oh ye
Oh yea
Oh yeah
Oh yeah 
Oh yeah y
Oh yeah ye
Oh yeah yea
Oh yeah yeah
Oh yeah yea
Oh yeah ye
Oh yeah y
Oh yeah 
Oh yeah
Oh yea
Oh ye
Oh y
Oh 
Oh
O
Note that there are apparent distortions in the above test case's output's shape (for instance, line two and line three of the output appear the same). Those are because we can't see the trailing whitespaces. Your program need NOT to try to fix these distortions.

Winning Criterion
This is code-golf, so the shortest code in bytes in each language wins!

*/

fn main() {
    output("String");
    output("Hello");
    output("Oh yeah yeah");
    output("");
}

fn output(s: &str) {
    let r: Vec<char> = s.chars().collect();

    let n = r.len();
    if n == 0 {
        return;
    }

    for i in 0..n {
        text(&r, i);
    }
    for i in (0..n - 1).rev() {
        text(&r, i);
    }
}

fn text(r: &Vec<char>, n: usize) {
    for i in 0..n + 1 {
        print!("{}", r[i]);
    }
    println!();
}
