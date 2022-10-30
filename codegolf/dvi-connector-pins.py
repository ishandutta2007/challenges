#!/usr/bin/env python

"""

This is supposed to be a code golf challenge on the simpler end of the spectrum. But I figured it could be nice to bring out some micro-optimisation here.

There are three basic types of DVI connectors: DVI-A (analog), DVI-D (digital) and DVI-I (integrated). Furthermore, there are single-link and dual-link versions of the DVI-D and DVI-I connectors. Each of those five different connectors uses a different set of pins.

Given one of A, D1, D2, I1, I2 as an identifier for the type of connector, print the corresponding ASCII representation of the connector's pins:

A:
#   #  # # #       # #
=====  # # #
#   #  # #         # #

D1:
       # # #     # # #
=====  # # #     # # #
       # # #     # # #

D2:
       # # # # # # # #
=====  # # # # # # # #
       # # # # # # # #

I1:
#   #  # # #     # # #
=====  # # #     # # #
#   #  # # #     # # #

I2:
#   #  # # # # # # # #
=====  # # # # # # # #
#   #  # # # # # # # #

(The X: lines are not part of the output, you should only print 3 lines.)

You may write a program or function, taking input via STDIN, ARGV or function argument. The output must be printed to STDOUT, with an optional trailing line feed.

You may or may not include trailing spaces in the second line of the A connector. You must not use additional leading or trailing spaces anywhere else.

This is code golf, so the shortest answer (in bytes) wins.

"""

A = """
#   #  # # #       # #
=====  # # #
#   #  # #         # #
"""

D1 = """
       # # #     # # #
=====  # # #     # # #
       # # #     # # #
"""

D2 = """
       # # # # # # # #
=====  # # # # # # # #
       # # # # # # # #
"""

I1 = """
#   #  # # #     # # #
=====  # # #     # # #
#   #  # # #     # # #
"""

I2 = """
#   #  # # # # # # # #
=====  # # # # # # # #
#   #  # # # # # # # #
"""

def connector(kind):
    print(kind)
    if kind == 'A':
        print(A)
    elif kind == 'D1':
        print(D1)
    elif kind == 'D2':
        print(D2)
    elif kind == 'I1':
        print(I1)
    elif kind == 'I2':
        print(I2)

def main():
    connector('A')
    connector('D1')
    connector('D2')
    connector('I1')
    connector('I2')

main()
