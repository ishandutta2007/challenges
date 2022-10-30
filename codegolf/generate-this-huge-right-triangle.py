#!/usr/bin/env python

"""

Your task is to print out this exact text:

-
||
-|-
|---
|-|--
-|-|--
-|-----
|-|-----
|---|-|--
-|-----|--
---|-|-----
|---|-|-----
|---|-----|--
-----|---|-|--
-|-|---|-------
------|---|-----
|-|---------|-|--
---|-----|---|----
-|-----|-|---------
|-|---|-|-----------
|-----------|---|-|--
-|-----|-|---------|--
---|-----|-----|-|-----
|---|-|---------|-------
------|---|-|---|--------
-----|-----|---------|-|--
-|-----|-------|-----|-----
|---|-----|-------|---|-----
--|---------|-|---------|-|--
---|---|-----|-------|---|-|--
-|-----------|-------|---|-----
--|---|-----|-----------|-|-----
------------|-----|---------|----
-|-----|-|-----|---------|-----|--
---|-|-----|-----|---|-|-----------
|---------|-|---|-----|-----|-|-----
------|---|-----|-------|---------|--
-----|---------|-------|-----|-----|--
-|-------|-----|---|-------|---|-------
------|---------|-----------|-|---------

It at first look seems meaningless repititions of - and |, but it has a nice hidden pattern inside it. I won't reveal it now.

Binary matrix or 2D lists are not accepted as output. Exactly this text is required. But output can have trailing whitespace.

You can use any non-number character in place of - and |

Shortest code wins.

"""

import math

# https://en.wikipedia.org/wiki/Wilson%27s_theorem
# a number is prime iff (n-1)!+1 is divisible by n
def isprime(n):
    if n < 2:
        return False
    return ((math.factorial(n - 1) + 1) % n) == 0

def gen(n):
    p = 1
    for i in range(n):
        for j in range(i+1):
            print("|" if isprime(p) else "-", end="")
            p += 1
        print()

def main():
    gen(40)

main()
