"""

Create a function that returns the value of x (the "unknown" in the equation). Each equation will be formatted like this:

x + 6 = 12

Examples

solveEquation("x + 43 = 50") ➞ 7

solveEquation("x - 9 = 10") ➞ 19

solveEquation("x + 300 = 100") ➞ -200

Notes

    "x" will always be in the same place (you will not find an equation like 6 + x = 12).
    Every equation will include either subtraction (-) or addition (+).
    "x" may be negative.

"""

def main():
    assert(solve("x + 6 = 12") == 6)
    assert(solve("6 + x = 12") == 6)
    assert(solve("x + 43 = 50") == 7)
    assert(solve("x - 9 = 10") == 19)
    assert(solve("x + 300 = 100") == -200)
    assert(solve("x - 0 = 0") == 0)
    assert(solve("x + 188 = 866") == 678)
    assert(solve("x + -500 = -200") == 300)

def solve(s):
    t = s.split('=')
    if len(t) != 2:
        raise Exception('invalid expression')
    
    x = 0
    a = eval(t[0])
    b = eval(t[1])
    return b - a

main()
