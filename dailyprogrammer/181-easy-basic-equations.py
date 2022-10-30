#!/usr/bin/env python

"""

Today, we'll be creating a simple calculator, that we may extend in later challenges. Assuming you have done basic algebra, you may have seen equations in the form y=ax+b, where a and b are constants.
This forms a graph of a straight line, when you plot y in respect to x. If you have not explored this concept yet, you can visualise a linear equation such as this using this online tool, which will plot it for you.

The question is, how can you find out where two such 'lines' intersect when plotted - ie. when the lines cross?
Using algebra, you can solve this problem easily. For example, given y=2x+2 and y=5x-4, how would you find out where they intersect?
This situation would look like this. Where do the red and blue lines meet? You would substitute y, forming one equation, 2x+2=5x-4, as they both refer to the same variable y.
Then, subtract one of the sides of the equation from the other side - like 2x+2-(2x+2)=5x-4-(2x+2) which is the same as 3x-6=0 - to solve, move the -6 to the other side of the = sign by adding 6 to both sides, and divide both sides by 3: x=2.
You now have the x value of the co-ordinate at where they meet, and as y is the same for both equations at this point (hence why they intersect) you can use either equation to find the y value, like so.
So the co-ordinate where they insersect is (2, 6). Fairly simple.

Your task is, given two such linear-style equations, find out the point at which they intersect.
Formal Inputs and Outputs
Input Description

You will be given 2 equations, in the form y=ax+b, on 2 separate lines, where a and b are constants and y and x are variables.
Output Description

You will print a point in the format (x, y), which is the point at which the two lines intersect.
Sample Inputs and Outputs
Sample Input

y=2x+2
y=5x-4

Sample Output

(2, 6)

Sample Input

y=-5x
y=-4x+1

Sample Output

(-1, 5)

Sample Input

y=0.5x+1.3
y=-1.4x-0.2

Sample Output

(-0.7895, 0.9053)

Notes

If you are new to the concept, this might be a good time to learn regular expressions. If you're feeling more adventurous, write a little parser.
Extension

Draw a graph with 2 lines to represent the inputted equations - preferably with 2 different colours. Draw a point or dot representing the point of intersection.

"""

from sympy import *
from sympy.abc import *

def linear_solve(eq):
    r = solve(eq, (x, y))
    return (r[x], r[y])

def main():
    print(linear_solve([Eq(2*x+2, y), Eq(5*x-4, y)]))
    print(linear_solve([Eq(-5*x, y), Eq(-4*x+1, y)]))
    print(linear_solve([Eq(0.5*x+1.3, y), Eq(-1.4*x-0.2, y)]))

main()
