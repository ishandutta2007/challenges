#!/bin/sh

cat << EOF > /dev/null

Write a stripped down version of the wc command. The program can simply open a file which does not need to be configurable or read from stdin until it encounters the end of file. When the program is finished reading, it should print:

    # bytes read
    # characters read
    # lines read
    max line length
    # words read

Program must at least work with ascii but bonus points if it works on other encodings.

Shortest code wins.

EOF

wc $@
