#!/usr/bin/env python

"""

The Pauli matrices are a set of 2x2 matrices which appear very commonly in quantum physics (no, you don't need to know any quantum physics for this challenge). If we include the identity in the set, the four matrices are:

 σ0 =      σ1 =      σ2 =      σ3 = 
[1  0]    [0  1]    [0 -i]    [1  0]
[0  1]    [1  0]    [i  0]    [0 -1]

Multiplying two of these will always give another Pauli matrix, although it may be multiplied by one of the complex phases 1, i, -1, -i. For instance, σ1σ3 = -iσ2.

Your task is to multiply a number of Pauli matrices and return the resulting matrix and phase.
Input will be given as a non-empty string of digits 0 to 3 representing the matrices σ0 to σ3.
The output should be a string containing a single digit for the resulting matrix, optionally preceded by i, - or -i to indicate the phase (- is for -1).

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

You must not use any built-in (or 3rd-party) features related to Pauli matrices.

This is code golf, the shortest answer (in bytes) wins.

Test Cases
1 => 1
13 => -i2
000 => 0
123 => i0
03022 => 3
02132230 => -i3
1320130100032 => i2
311220321030322113103 => -2
0223202330203313021301011023230323 => -i0
1323130203022111323321112122313213130330103202032222223 => -1

"""

from sympy import *

def pauli(s):
    o0 = Matrix([[1, 0], [0, 1]])
    o1 = Matrix([[0, 1], [1, 0]])
    o2 = Matrix([[0, -I], [I, 0]])
    o3 = Matrix([[1, 0], [0, -1]])
    tab = {
        "0": o0,
        "1": o1,
        "2": o2,
        "3": o3,
        "-0": -o0,
        "-1": -o1,
        "-2": -o2,
        "-3": -o3,
        "i0": I*o0,
        "i1": I*o1,
        "i2": I*o2,
        "i3": I*o3,
        "-i0": -I*o0,
        "-i1": -I*o1,
        "-i2": -I*o2,
        "-i3": -I*o3,
    }

    if len(s) == 0:
        return ""

    m = o0
    for c in s:
        try:
            m *= tab[c]
        except:
            return ""

    for k in tab:
        if m == tab[k]:
            return k
    return ""

def main():
    assert(pauli("1") == "1")
    assert(pauli("13") == "-i2")
    assert(pauli("000") == "0")
    assert(pauli("123") == "i0")
    assert(pauli("03022") == "3")
    assert(pauli("02132230") == "-i3")
    assert(pauli("1320130100032") == "i2")
    assert(pauli("311220321030322113103") == "-2")
    assert(pauli("0223202330203313021301011023230323") == "-i0")
    assert(pauli("1323130203022111323321112122313213130330103202032222223") == "-1")

main()
