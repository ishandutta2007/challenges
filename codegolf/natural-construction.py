#!/usr/bin/env python

"""

The natural numbers including 0 are formally defined as sets, in the following way:

Number 0 is defined as the empty set, {}
For n ≥ 0, number n+1 is defined as n ∪ {n}.
As a consequence, n = {0, 1, ..., n-1}.

The first numbers, defined by this procedure, are:

0 = {}
1 = {{}}
2 = {{}, {{}}}
3 = {{}, {{}}, {{}, {{}}}}

Challenge

Given n, output its representation as a set.

Rules
The output can consistently use any bracket character such as {}, [], () or <>. Arbitrary characters (such as 01) are not allowed.

Instead of a comma as above, the separator can be any punctuation sign; or it may be inexistent.

Spaces (not newlines) may be included arbitrarily and inconsistently.

For example, number 2 with square brackets and semicolon as separator is [[]; [[]]], or equivalently [ [ ]; [ [ ] ] ], or even [  [ ] ;[  []]]

The order in which elements of a set are specified doesn't matter. So you can use any order in the representation. For example, these are some valid outputs for 3:

{{},{{}},{{},{{}}}}
{{{}},{{},{{}}},{}}
{{{}},{{{}},{}},{}}
You can write a program or function. Output may be a string or, if using a function, you may return a nested list or array whose string representation conforms to the above.

Test cases
0  ->  {}
1  ->  {{}}
2  ->  {{},{{}}}
3  ->  {{},{{}},{{},{{}}}}
4  ->  {{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}
5  ->  {{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}}
6  ->  {{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}}}
7  ->  {{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}}}}

"""

def construct(n):
    if n < 0:
        return ""

    m = { 0: "{}" }
    for i in range(0, n):
        s = "{"
        for j in range(0, i+1):
            s += m[j]
            if j+1 < i+1:
                s += ","
        s += "}"
        m[i+1] = s
    return m[n]

def main():
    assert(construct(0) == "{}")
    assert(construct(1) == "{{}}")
    assert(construct(2) == "{{},{{}}}")
    assert(construct(3) == "{{},{{}},{{},{{}}}}")
    assert(construct(4) == "{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}")
    assert(construct(5) == "{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}}")
    assert(construct(6) == "{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}}}")
    assert(construct(7) == "{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}},{{},{{}},{{},{{}}},{{},{{}},{{},{{}}}}}}}}")

main()
