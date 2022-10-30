#!/usr/bin/env julia

#=

Description
A fraction exists of a numerator (top part) and a denominator (bottom part) as you probably all know.

Simplifying (or reducing) fractions means to make the fraction as simple as possible. Meaning that the denominator is a close to 1 as possible. This can be done by dividing the numerator and denominator by their greatest common divisor.

Formal Inputs & Outputs
Input description
You will be given a list with 2 numbers seperator by a space. The first is the numerator, the second the denominator

4 8
1536 78360
51478 5536
46410 119340
7673 4729
4096 1024
Output description
The most simplified numbers

1 2
64 3265
25739 2768
7 18
7673 4729
4 1

Notes/Hints

Most languages have by default this kind of functionality, but if you want to challenge yourself, you should go back to the basic theory and implement it yourself.

Bonus
Instead of using numbers, we could also use letters.

For instance

ab   a
__ = _
cb   c
And if you know that x = cb, then you would have this:

ab   a
__ = _
x    c
and offcourse:

a    1
__ = _
a    1

aa   a
__ = _
a    1
The input will be first a number saying how many equations there are. And after the equations, you have the fractions.

The equations are a letter and a value seperated by a space. An equation can have another equation in it.

3
x cb
y ab
z xa
ab cb
ab x
x y
z y
z xay

output:

a c
a c
c a
c 1
1 ab
Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

=#

@assert(4//8 == 1//2)
@assert(1536//78360 == 64//3265)
@assert(51478//5536 == 25739//2768)
@assert(46410//119340 == 7//18)
@assert(7673//4729 == 7673//4729)
@assert(4096//1024 == 4//1)
