#!/usr/bin/env python

"""

A quine is a computer program which takes no input and produces a copy of its own source code as its only output which, in turn, compiles and print out itself

"""

_='_=%r; print (_%%_)'; print (_%_)
