#!/usr/bin/env gnuplot

# Challenge
#
# Given an input of an integer, n
# (where 0<n<50), output the graph of y=Re((−n)x) from x=−3 to x=3 inclusive.
# Where Re(p) is the real part of the complex number p.
# 
# Note that Re((−n)x)=nxcos(πx)
#
# Output
#
# The output may be in any form you wish (e.g. an image or a window etc.). ASCII art is disallowed.
#
# The graph does not need to have axes (to allow languages without built-in graphing functions to compete).
#
# If an image is output, it each side must be longer than 500 pixels. Similarly, the plot must fill the image as best it can.
#
# The minimum interval between plots is 0.05.
#
# Vector graphics are allowed.
# Examples
#
# For an input of 2:
#
# For an input of 1:
#
# You must put your corresponding outputs in your answer (n = 1 and n = 2).
# Winning
#
# The shortest code in bytes wins.

f(n, x) = abs(n)**x * cos(pi*x)

set xrange [-10:10]
set yrange [-10:10]
plot for [i=-3:3] f(i, x) title 'f('.i.')'
pause -1
