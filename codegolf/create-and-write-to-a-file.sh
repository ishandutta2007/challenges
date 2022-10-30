#!/bin/sh

set -e

cat << EOF > /dev/null

Challenge

Create a new file and write the string Hello World to it.
Restrictions

    Your challenge must write to a file on disk, in the file system.

    The file may not be a log file generated during normal operation of the interpreter.

    The file must contain only the string Hello World. It is allowed to contain a trailing newline or minimal whitespace. No other content.

    No command-line flags/pipes (etc) allowed, except when necessary to run the program. (e.g. perl -p)

Notes

    This is code-golf, so shortest program in bytes wins.

    Follow the spirit, not the letter, of the rules.

EOF

FILE="file.txt"
if [ ! -z "$1" ]; then
	FILE=$1
fi

echo -e "Hello World" > $FILE
