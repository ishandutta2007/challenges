#!/usr/bin/env python

"""

Challenge
Given an input x, create a directory (AKA folder) in the file system with the name x.

Languages that are not able to create file system directories are excluded from this challenge.

The directory may be created anywhere, as long as the location is writable to the user running the program. Assume that the program is run as a non-privileged user on a modern Linux (or Windows if needed) desktop system.

Clarifications
Assume that the current directory is $HOME/%USERPROFILE%.
Assume that no file or directory exists with the name given.
Assume that the filename will only contain the characters abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.
Assume that the filename will always be 8 characters long or shorter.
Rules
The directory must actually be created. You can't just say "I made it in /dev/null".
Standard loopholes apply.

"""

import os
import sys

def usage():
    print("usage: <dir> ...")
    exit(2)

def main():
    if len(sys.argv) < 2:
        usage()
    for arg in sys.argv[1:]:
        try:
            os.makedirs(arg)
        except Exception as err:
            print(f"Failed to make directory: {err=}")

main()
