#!/usr/bin/env python

"""

Problem:

In your choice of language, write the shortest function that returns the floor of the base-2 logarithm of an unsigned 64-bit integer, or –1 if passed a 0. (Note: This means the return type must be capable of expressing a negative value.)

Test cases:

Your function must work correctly for all inputs, but here are a few which help illustrate the idea:

               INPUT ⟶ OUTPUT

                   0 ⟶ -1
                   1 ⟶  0
                   2 ⟶  1
                   3 ⟶  1
                   4 ⟶  2
                   7 ⟶  2
                   8 ⟶  3
                  16 ⟶  4
               65535 ⟶ 15
               65536 ⟶ 16
18446744073709551615 ⟶ 63

Rules:

    You can name your function anything you like.
    Character count is what matters most in this challenge.
    You will probably want to implement the function using purely integer and/or boolean artithmetic. However, if you really want to use floating-point calculations, then that is fine so long as you call no library functions. So, simply saying return n?(int)log2l(n):-1; in C is off limits even though it would produce the correct result. If you're using floating-point arithmetic, you may use *, /, +, -, and exponentiation (e.g., ** or ^ if it's a built-in operator in your language of choice). This restriction is to prevent "cheating" by calling log() or a variant.
    If you're using floating-point operations (see #3), you aren't required that the return type be integer; only that that the return value is an integer, e.g., floor(log₂(n)).
    If you're using C/C++, you may assume the existence of an unsigned 64-bit integer type, e.g., uint64_t as defined in stdint.h. Otherwise, just make sure your integer type is capable of holding any 64-bit unsigned integer.
    If your langauge does not support 64-bit integers (for example, Brainfuck apparently only has 8-bit integer support), then do your best with that and state the limitation in your answer title. That said, if you can figure out how to encode a 64-bit integer and correctly obtain the base-2 logarithm of it using 8-bit primitive arithmetic, then more power to you!
    Have fun and get creative!

"""

def ilog2(n):
    p = 1
    c = 0
    while p <= n:
        p <<= 1
        c += 1
    return c - 1

def main():
    assert(ilog2(0) == -1)
    assert(ilog2(1) == 0)
    assert(ilog2(2) == 1)
    assert(ilog2(3) == 1)
    assert(ilog2(4) == 2)
    assert(ilog2(7) == 2)
    assert(ilog2(8) == 3)
    assert(ilog2(16) == 4)
    assert(ilog2(65535) == 15)
    assert(ilog2(65536) == 16)
    assert(ilog2(18446744073709551615) == 63)

main()
