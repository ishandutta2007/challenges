#!/usr/bin/env python

"""

The challenge:

Input text from one file and output it to another. Solution should be a complete, working function.

Note: This is a code-trolling question. Please do not take the question and/or answers seriously. More information here.

"""

import shutil
import sys

def main():
    if len(sys.argv) != 3:
        print("usage: <from> <to>")
        sys.exit(2)
    
    shutil.copyfile(sys.argv[1], sys.argv[2])

main()
