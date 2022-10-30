#!/usr/bin/env python

"""

Based on an idea suggested by Zgarb.

A spaceship is moving around a regular 3D grid. The cells of the grid are indexed with integers in a right-handed coordinate system, xyz. The spaceship starts at the origin, pointing along the positive x axis, with the positive z axis pointing upwards.

The spaceship will fly along a trajectory defined by a non-empty sequence of movements.
Each movement is either F(orward) which makes the spaceship move one cell in the direction its facing, or one of the six rotations UDLRlr.
These corresponds to pitch, yaw and roll as follows:

PYR
Thanks to Zgarb for creating the diagram.

Up and Down change the pitch of the spaceship by 90 degrees (where the direction corresponds to the movement of the spaceship's nose).
Left and Right change the yaw of the spaceship by 90 degrees. They are just regular left and right turns.
left and right are 90 degree rolling movements, where the direction indicates which wing moves downwards.
Note that these should always be interpreted relative to the spaceship so the relevant axes rotate along with it.

In mathematical terms, the spaceship is initially at position (0, 0, 0), pointing along the (1, 0, 0) vector, with (0, 0, 1) pointing upwards. The rotations correspond to the following matrices applied to the coordinate system:

U = ( 0  0 -1     D = ( 0  0  1
      0  1  0           0  1  0
      1  0  0 )        -1  0  0 )

L = ( 0 -1  0     R = ( 0  1  0
      1  0  0          -1  0  0
      0  0  1 )         0  0  1 )

l = ( 1  0  0     r = ( 1  0  0
      0  0  1           0  0 -1
      0 -1  0 )         0  1  0 )
You should output the final position of the spaceship as three integers x, y, z. Output may be three separate integers or a list or string containing them. They may be in any consistent order as long as you specify it.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

Standard code-golf rules apply.

Test Cases
F                                                   => (1, 0, 0)
FDDF                                                => (0, 0, 0)
FDDDF                                               => (1, 0, 1)
LrDDlURRrr                                          => (0, 0, 0)
UFLrRFLRLR                                          => (1, 0, 1)
FFrlFULULF                                          => (3, 0, -1)
LLFRLFDFFD                                          => (-2, 0, -2)
FrrLFLFrDLRFrLLFrFrRRFFFLRlFFLFFRFFLFlFFFlUFDFDrFF  => (1, 5, 7)
FUrRLDDlUDDlFlFFFDFrDrLrlUUrFlFFllRLlLlFFLrUFlRlFF  => (8, 2, 2)
FFLrlFLRFFFRFrFFFRFFRrFFFDDLFFURlrRFFFlrRFFlDlFFFU  => (1, 2, -2)
FLULFLFDURDUFFFLUlFlUFLFRrlDRFFFLFUFrFllFULUFFDRFF  => (-3, -2, -3)
Worked example
Here are the intermediate steps of the UFLrRFLRLR test case. Here, all intermediate coordinates and direction vectors are given in the initial, global coordinate system (as opposed to one local to the spaceship):

Cmd.  Position    Forward     Up
      ( 0, 0, 0)  ( 1, 0, 0)  ( 0, 0, 1)
U     ( 0, 0, 0)  ( 0, 0, 1)  (-1, 0, 0)
F     ( 0, 0, 1)  ( 0, 0, 1)  (-1, 0, 0)
L     ( 0, 0, 1)  ( 0, 1, 0)  (-1, 0, 0)
r     ( 0, 0, 1)  ( 0, 1, 0)  ( 0, 0, 1)
R     ( 0, 0, 1)  ( 1, 0, 0)  ( 0, 0, 1)
F     ( 1, 0, 1)  ( 1, 0, 0)  ( 0, 0, 1)
L     ( 1, 0, 1)  ( 0, 1, 0)  ( 0, 0, 1)
R     ( 1, 0, 1)  ( 1, 0, 0)  ( 0, 0, 1)
L     ( 1, 0, 1)  ( 0, 1, 0)  ( 0, 0, 1)
R     ( 1, 0, 1)  ( 1, 0, 0)  ( 0, 0, 1)

"""

import numpy as np

def go(s):
    p = np.array([0, 0, 0])
    m = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    for c in s:
        if c == 'U':
            m = np.dot(m, np.array([[0, 0, -1], [0, 1, 0], [1, 0, 0]]))
        elif c == 'D':
            m = np.dot(m, np.array([[0, 0, 1], [0, 1, 0], [-1, 0, 0]]))
        elif c == 'L':
            m = np.dot(m, np.array([[0, -1, 0], [1, 0, 0], [0, 0, 1]]))
        elif c == 'R':
            m = np.dot(m, np.array([[0, 1, 0], [-1, 0, 0], [0, 0, 1]]))
        elif c == 'l':
            m = np.dot(m, np.array([[1, 0, 0], [0, 0, 1], [0, -1, 0]]))
        elif c == 'r':
            m = np.dot(m, np.array([[1, 0, 0], [0, 0, -1], [0, 1, 0]]))
        elif c == 'F':
            p += np.dot(m, np.array([1, 0, 0]))
    return p

def test(s, r):
    p = go(s)
    print(p)
    assert(np.array_equal(p, np.array(r)))

def main():
    test("F", [1, 0, 0])
    test("FDDF", [0, 0, 0])
    test("FDDDF", [1, 0, 1])
    test("LrDDlURRrr", [0, 0, 0])
    test("UFLrRFLRLR", [1, 0, 1])
    test("FFrlFULULF", [3, 0, -1])
    test("LLFRLFDFFD", [-2, 0, -2])
    test("FrrLFLFrDLRFrLLFrFrRRFFFLRlFFLFFRFFLFlFFFlUFDFDrFF", [1, 5, 7])
    test("FUrRLDDlUDDlFlFFFDFrDrLrlUUrFlFFllRLlLlFFLrUFlRlFF", [8, 2, 2])
    test("FFLrlFLRFFFRFrFFFRFFRrFFFDDLFFURlrRFFFlrRFFlDlFFFU", [1, 2, -2])
    test("FLULFLFDURDUFFFLUlFlUFLFRrlDRFFFLFUFrFllFULUFFDRFF", [-3, -2, -3])

main()
