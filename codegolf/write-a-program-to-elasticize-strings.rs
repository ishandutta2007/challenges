/*

Nice verb there, in the title.

Write a program that given an input string, will "elasticize" this string and output the result. Elasticizing a string is done as follows:

The first character is shown once. The second character is shown twice. The third character is shown thrice, and so on.

As you can see, the amount of duplications of a certain character is related to the character's index as opposed to its previous occurrences in the string.

You can expect to receive only printable ASCII characters. Based off the following link, these characters have decimal values 32-126.

Examples:

Why: Whhyyy

SKype: SKKyyyppppeeeee

LobbY: LoobbbbbbbYYYYY (Note how there are 7 b's since the first b is shown 3 times and the second b is shown 4 times, making a total of 7 b's).

A and B: A  aaannnnddddd      BBBBBBB

Shortest bytes wins :)

*/

fn main() {
    assert_eq!(elastic("Why"), "Whhyyy");
    assert_eq!(elastic("SKype"), "SKKyyyppppeeeee");
    assert_eq!(elastic("LobbY"), "LoobbbbbbbYYYYY");
    assert_eq!(elastic("A and B"), "A  aaannnnddddd      BBBBBBB");
}

fn elastic(s: &str) -> String {
    let mut r = String::new();
    let mut n = 0;
    for c in s.chars() {
        for _ in 0..n + 1 {
            r.push(c);
        }
        n += 1;
    }
    r
}
