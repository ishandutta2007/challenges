#!/usr/bin/env julia

#=

Background
Inspired by Octave's (and, by extension, MATL's) very convenient interpretation of truthy/falsy matrices, Jelly got the Ȧ (Octave-style all) atom.

Ȧ takes an array as input and returns 1 if the array is non-empty and does not contain the number 0 (integer, float, or complex) anywhere in the tree structure; otherwise, it returns 0.

For example, the array [[]] is truthy because it is non-empty and contains no zeroes, but [[0]] is falsy because it contains a 0 at the innermost level.

Task
In a programming language of your choice, write a full program or a function that takes a possibly empty, possibly jagged array of integers as input and prints or returns a truthy or falsy value that indicates if Ȧ would return 1 or 0, respectively.

Your submission must abide to the following rules.

The truthy and falsy values must be consistent for all inputs, i.e, all arrays for which Ȧ returns 1 must map to the same truthy value, and all arrays for which Ȧ returns 0 must map to the same falsy value.

Since full programs can only take string representations of arrays as input, this is allowed. However, you must use the canocical representation of your language, as returned by repr or similar.

In particular you cannot assume that the first element of the array will be preceded by a space.

If (and only if) your language cannot represent jagged arrays natively, you may take a string representation of the input, using the canonical syntax of any pre-existing programming language.

If your language has several ways of representing jagged arrays (e.g., lists and tuples), you only have to support one of them.

If your language has a built-in that is itself a valid submission to this challenge, you may not use it in your answer. All other built-ins are allowed.

You are encouraged to post answers using both array and string manipulation, even if one is significantly shorter than the other.

All standard code-golf rules apply.

May the shortest code in bytes win!

Truthy test cases
[1]
[10]
[[]]
[[[[1]]]]
[[], [1], [1, 2]]
[[1], [1, [2]], [1, [2, [3]]]]
[[8], [8, [9]], [8, [9, [10]]]]

Falsy test cases
[]
[0]
[0, -1]
[-1, 0]
[[[[0]]]]
[[0], [1, 2], [3, 4, 5]]
[[8], [8, [9]], [8, [9, [1, 0]]]]
[-1, 0, 0, 0]

=#

a(x::Int) = x != 0
a(x)      = all(a, x)
A(x)      = x != [] && a(x)

@assert(A([1]) == true)
@assert(A([10]) == true)
@assert(A([[]]) == true)
@assert(A([[[[1]]]]) == true)
@assert(A([[], [1], [1, 2]]) == true)
@assert(A([[1], [1, [2]], [1, [2, [3]]]]) == true)
@assert(A([[8], [8, [9]], [8, [9, [10]]]]) == true)

@assert(A([]) == false)
@assert(A([0]) == false)
@assert(A([0, -1]) == false)
@assert(A([-1, 0]) == false)
@assert(A([[[[0]]]]) == false)
@assert(A([[0], [1, 2], [3, 4, 5]]) == false)
@assert(A([[8], [8, [9]], [8, [9, [1, 0]]]]) == false)
@assert(A([-1, 0, 0, 0]) == false)
