#!/usr/bin/env python

"""

Write a function, f, that takes in a positive integer and returns a function.

The new function returned should be identical to f. However, when the "termination call" happens, f should instead return the sum of all integers passed.

For example, g=f(4) (if f is the first function) should set g to another function. h=g(3) will do the same. However, when you call h with no arguments (see below for details),
it should output 7, as that is the sum of the previous function arguments. Put another way, f(3)(4)() == 7.

Do note this is not the same as f(3,4)().

"Termination call" is one of the following options (your choice):

call w/o arguments
null as argument
any non-positive value
Arbitrary amount of function calls should be supported, there is no predefined limit.

It's guaranteed that total sum will not be bigger than 1'000.

We can assume that there is at least one call is made prior to "termination call".

Your code should not use static, per-program variables, so it should be possible to run the experiment multiple times in the same runtime and observe exactly the same behavior.

Examples:

f(1)() == 1
f(4)(2)(7)() == 13
f(4)(2)(7)(5)(2)() == 20

"""

class Curry:
    def __init__(self):
        self.value = 0

    def f(self, *args):
        if len(args) == 0:
            return self.value
        if len(args) == 1:
            self.value += args[0]
            return self.f
        raise Exception("invalid number of arguments")

def main():
    c1 = Curry()
    c2 = Curry()
    c3 = Curry()

    assert(c1.f(1)() == 1)
    assert(c2.f(4)(2)(7)() == 13)
    assert(c3.f(4)(2)(7)(5)(2)() == 20)

main()
