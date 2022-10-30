#!/usr/bin/env python

"""

Given a number n (0 <= n <= 2642245), check if n and n3 have the same set of digits, and output a truthy or falsey value accordingly.

For example, let's check the number 100.

1003 is 1000000.

The set of digits in 100 is {0, 1}.

The set of digits in 1000000 is {0, 1}.

Therefore, 100 should give a truthy value.

Test cases
0 -> True
1 -> True
10 -> True
107624 -> True
251894 -> True
251895 -> False
102343 -> False
Remember, this is code-golf, so the code with the fewest bytes wins.

OEIS A029795

"""

# http://oeis.org/A029795
def equivalence(n):
    return set(str(n)) == set(str(n**3))

def main():
    assert(equivalence(0) == True)
    assert(equivalence(1) == True)
    assert(equivalence(10) == True)
    assert(equivalence(107624) == True)
    assert(equivalence(251894) == True)
    assert(equivalence(251895) == False)
    assert(equivalence(102343) == False)

main()
