"""

A Pythagorean Triple is comprised of three positive integers, a, b, c, such that a**2 + b**2 = c**2. One special case is when a and b differ by only 1. The first five examples of this are:

    (3, 4, 5), (20, 21, 29), (119, 120, 169), (696, 697, 985), (4059, 4060, 5741)

    Devise a function that takes an integer n and returns the nth member of this sequence.
    Examples

    triple(1) ➞ (3, 4, 5)

    triple(4) ➞ (696, 697, 985)

    triple(10) ➞ (27304196, 27304197, 38613965)

    Notes

    N/A

"""

from math import *

def pell(n):
    a = 0
    b = 1
    for i in range(n):
        a, b = b, 2*b + a
    return a

"""

https://en.wikipedia.org/wiki/Pythagorean_triple#Enumeration_of_primitive_Pythagorean_triples

The pythagorean triples can be generated using the formula
a = m^2 - n^2
b = 2mn
c = m^2 + n^2

If m and n are consecutive pell numbers, then a and b will differ by 1

"""

def triple(n):
    x = pell(n)
    y = pell(n+1)
    a = y*y - x*x
    b = 2*x*y
    c = y*y + x*x
    return (min(a, b), max(a, b), c)

assert(triple(1) == (3, 4, 5))
assert(triple(4) == (696, 697, 985))
assert(triple(10) == (27304196, 27304197, 38613965))
assert(triple(20) == (1235216565974040, 1235216565974041, 1746860020068409))
assert(triple(40) == (2527961881478169961048032963696, 2527961881478169961048032963697, 3575077977948634627394046618865))
assert(triple(100) == (21669693148613788330547979729286307164015202768699465346081691992338845992696, 21669693148613788330547979729286307164015202768699465346081691992338845992697, 30645573943232956180057972969833245887630954508753693529117371074705767728665))
