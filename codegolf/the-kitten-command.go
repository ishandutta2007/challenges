/*

A kitten is much like a cat. Some of the main differences are cuteness, lack of intelligence, and size.
Similarly, the cat command is different from the kitten command.
Fortunately, there is only one difference in this case.
In the kitten command, all uppercase letters are replaced with lowercase letters.

Objective

To implement a program that behaves similarly to cat. All characters [A-Z] are outputted lowercase.
Input

A list of files as command line arguments. If no files are listed, then read from standard input. The input may contain unprintable characters and characters outside the ASCII range.
Output

If input is a bunch of files, concatenate the contents and output all characters as lowercase. If reading from STDIN, output the contents of STDIN with all uppercase letters as lowercase.

Note: Only make the characters [A-Z] lowercase. It is unacceptable if any other characters are made lowercase.
Examples

$ echo "HelLo" > file.txt
$ kitten file.txt
hello
$ echo "Good Bye" | kitten
good bye
$ echo "Ä" | kitten
Ä

As usual with code-golf, least bytes wins.
Leaderboards

Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

# Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the leaderboard snippet:

# [><>](http://esolangs.org/wiki/Fish), 121 bytes

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		kitten(os.Stdin, os.Stdout)
	} else {
		for _, name := range flag.Args() {
			f, err := os.Open(name)
			if err != nil {
				fmt.Fprintln(os.Stderr, "kitten:", err)
				continue
			}
			kitten(f, os.Stdout)
			f.Close()
		}
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <file> ...")
	flag.PrintDefaults()
	os.Exit(2)
}

func kitten(r io.Reader, w io.Writer) {
	br := bufio.NewReader(r)
	bw := bufio.NewWriter(w)
	defer bw.Flush()
	for {
		ch, _, err := br.ReadRune()
		if err != nil {
			break
		}

		if 'A' <= ch && ch <= 'Z' {
			ch = (ch - 'A') + 'a'
		}
		bw.WriteRune(ch)
	}
}
