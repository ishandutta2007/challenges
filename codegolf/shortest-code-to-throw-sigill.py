#!/usr/bin/env python

"""

Background

We already have a challenge about throwing SIGSEGV, so why not a challenge about throwing SIGILL?
What is SIGILL?

SIGILL is the signal for an illegal instruction at the processor, which happens very rarely. The default action after receiving SIGILL is terminating the program and writing a core dump. The signal ID of SIGILL is 4. You encounter SIGILL very rarely, and I have absolutely no idea how to generate it in your code except via sudo kill -s 4 <pid>.
Rules

You will have root in your programs, but if you don't want to for any reasons, you may also use a normal user. I'm on a Linux computer with German locale and I do not know the English text which is displayed after catching SIGILL, but I think it's something like 'Illegal instruction'. The shortest program which throws SIGILL wins.

"""

import signal

signal.raise_signal(signal.SIGILL)

