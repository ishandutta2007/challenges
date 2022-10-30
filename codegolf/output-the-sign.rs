/*

Given a number N, output the sign of N:

    If N is positive, output 1
    If N is negative, output -1
    If N is 0, output 0

N will be an integer within the representable range of integers in your chosen language.
The Catalogue

The Stack Snippet at the bottom of this post generates the catalogue from the answers a) as a list of shortest solution per language and b) as an overall leaderboard.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

## Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

## Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

## Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the snippet:

## [><>](https://esolangs.org/wiki/Fish), 121 bytes

*/

fn main() {
    assert_eq!(sign(10), 1);
    assert_eq!(sign(-10), -1);
    assert_eq!(sign(0), 0);
}

fn sign(n: isize) -> isize {
    if n < 0 {
        -1
    } else if n > 0 {
        1
    } else {
        0
    }
}
