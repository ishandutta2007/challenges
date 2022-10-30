/*

Write a program or function with the following functionality:

The program/function first attempts to write the string Hello, world! to the standard output stream. (No other forms of output are acceptable for this challenge, as the focus is very much on the I/O rather than the trivial behaviour of the program itself.) Depending on whether it succeeded:
If it succeeded in outputting Hello, world!, the program/function exits without any further behaviour.
If it failed to produce the correct output due to an error, the program/function attempts to write the string Error writing "Hello, world!" to the standard error stream.
(For the purposes of this challenge, you don't need error handling for the error handling itself.)
Clarifications
Your program/function will be run with no input (unless it's written in a language which absolutely requires input to work, in which case it will be run with the simplest possible input).

When producing output, you may also produce a single trailing newline if you wish, but doing so is not mandatory.

The definition of "error writing to standard output" that your program implements must treat at least the following cases as errors:

Standard output being nonexistent (i.e. stdout is a closed filehandle, no file descriptor 1 exists, or however those cases translate to the language and OS you're using);
Standard output referring to a file on a disk that has no free space left;
Standard output connecting to another program, which has already closed its end of the connection.
and must treat at least the following cases as success (i.e. not an error):

Standard output connects to a terminal, and Hello, world! is displayed onscreen.
Standard output connects to a file, and Hello, world! is written into the file.
You can choose the details of what counts as an output error, so long as it's consistent with the above rules.

Your program/function should not crash upon encountering any of the error situations listed above. It's up to you what exit code you use.

Your program/function should not describe the nature of the encountered error on the standard error stream; it should just print the string specified above.
Extraneous output on standard error (e.g. compiler warnings) is only legal if it's produced unconditionally, regardless of whether an error is encountered or not.

Your program only needs to work on one operating system (although it must be one on which the errors listed above make sense;
I've tried to keep them general enough to work on most multitasking consumer operating systems, but weirder operating systems may well be excluded from this challenge).
If your program is nonportable, list the assumptions it needs to run in the title of your submission.

This task may not be possible in every language (not every language allows a program to handle output errors in a custom way). You'll have to pick a language where it is possible.

Make sure that your program/function works! Don't just trust the documentation of library functions to do what they say they do.
The error handling of simple output functions often turns out to be broken in practice, even if the functions claim to handle errors in theory.

Test cases
Here's a way to simulate each of the error conditions above using bash on Linux (you don't have to use Linux, but it's likely the easiest system to test this on):

your_program_here >&-           # nonexistent stdout
your_program_here > /dev/full   # out of disk space
mkfifo test  # note: change "test" to a filename that isn't in use
true < test &
your_program_here > test        # connecting to a program that doesn't want input
rm test      # clean up the FIFO we used earlier
The first two testcases are deterministic. The last isn't (it relies on a race condition);
for testing purposes, I recommend adding a delay between the start of your program and the actual output to standard output, in order to ensure that the race condition is resolved in the way that exposes the error.

*/

#define _GNU_SOURCE
#include <stdio.h>

int
main(void)
{
	static const char text[] = "Hello, world!";
	int r;

	r = dprintf(1, "%s\n", text);
	if (r < 0)
		dprintf(2, "Error writing \"%s\"\n", text);

	return 0;
}
