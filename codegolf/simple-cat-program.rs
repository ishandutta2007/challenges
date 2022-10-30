/*

One of the most common standard tasks (especially when showcasing esoteric programming languages) is to implement a "cat program": read all of STDIN and print it to STDOUT.
While this is named after the Unix shell utility cat it is of course much less powerful than the real thing, which is normally used to print (and concatenate) several files read from disc.

Task

You should write a full program which reads the contents of the standard input stream and writes them verbatim to the standard output stream.
If and only if your language does not support standard input and/or output streams (as understood in most languages), you may instead take these terms to mean their closest equivalent in your language (e.g. JavaScript's prompt and alert).
These are the only admissible forms of I/O, as any other interface would largely change the nature of the task and make answers much less comparable.

The output should contain exactly the input and nothing else. The only exception to this rule is constant output of your language's interpreter that cannot be suppressed, such as a greeting, ANSI color codes or indentation.
This also applies to trailing newlines. If the input does not contain a trailing newline, the output shouldn't include one either! (The only exception being if your language absolutely always prints a trailing newline after execution.)

Output to the standard error stream is ignored, so long as the standard output stream contains the expected output.
In particular, this means your program can terminate with an error upon hitting the end of the stream (EOF), provided that doesn't pollute the standard output stream.
If you do this, I encourage you to add an error-free version to your answer as well (for reference).

As this is intended as a challenge within each language and not between languages, there are a few language specific rules:

    If it is at all possible in your language to distinguish null bytes in the standard input stream from the EOF, your program must support null bytes like any other bytes (that is, they have to be written to the standard output stream as well).
    If it is at all possible in your language to support an arbitrary infinite input stream (i.e. if you can start printing bytes to the output before you hit EOF in the input), your program has to work correctly in this case. As an example yes | tr -d \\n | ./my_cat should print an infinite stream of ys. It is up to you how often you print and flush the standard output stream, but it must be guaranteed to happen after a finite amount of time, regardless of the stream (this means, in particular, that you cannot wait for a specific character like a linefeed before printing).

Please add a note to your answer about the exact behaviour regarding null-bytes, infinite streams, and extraneous output.
Additional rules

    This is not about finding the language with the shortest solution for this (there are some where the empty program does the trick) - this is about finding the shortest solution in every language. Therefore, no answer will be marked as accepted.

    Submissions in most languages will be scored in bytes in an appropriate preexisting encoding, usually (but not necessarily) UTF-8.

    Some languages, like Folders, are a bit tricky to score. If in doubt, please ask on Meta.

    Feel free to use a language (or language version) even if it's newer than this challenge. Languages specifically written to submit a 0-byte answer to this challenge are fair game but not particularly interesting.

    Note that there must be an interpreter so the submission can be tested. It is allowed (and even encouraged) to write this interpreter yourself for a previously unimplemented language.

    Also note that languages do have to fulfil our usual criteria for programming languages.

    If your language of choice is a trivial variant of another (potentially more popular) language which already has an answer (think BASIC or SQL dialects, Unix shells or trivial Brainfuck derivatives like Headsecks or Unary), consider adding a note to the existing answer that the same or a very similar solution is also the shortest in the other language.

    Unless they have been overruled earlier, all standard code-golf rules apply, including the http://meta.codegolf.stackexchange.com/q/1061.

As a side note, please don't downvote boring (but valid) answers in languages where there is not much to golf; these are still useful to this question as it tries to compile a catalogue as complete as possible. However, do primarily upvote answers in languages where the author actually had to put effort into golfing the code.
Catalogue

The Stack Snippet at the bottom of this post generates the catalogue from the answers a) as a list of shortest solution per language and b) as an overall leaderboard.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

## Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

## Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

## Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the snippet:

## [><>](http://esolangs.org/wiki/Fish), 121 bytes

*/

use std::io;

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    io::copy(&mut stdin.lock(), &mut stdout.lock()).unwrap();
}
