"""
Dividing by 0 is a huge mistake and should be avoided at all costs.

Create a function that when given a math expression as a string, return True if at any point, the expression involves dividing by 0.
Examples

catchZeroDivision("2 / 0") ➞ true

catchZeroDivision("4 / (2 + 3 - 5)") ➞ true

catchZeroDivision("2 * 5 - 10") ➞ false

Notes

Multiplication signs will be given as an asterisk *.
"""

def collapsible(s):
    try:
        eval(s)
    except ZeroDivisionError:
        return True
    return False

def main():
    assert(collapsible('2 / 0') == True)
    assert(collapsible('4 / (2 + 3 - 5)') == True)
    assert(collapsible('2 * 5 - 3') == False)
    assert(collapsible('3 / 0') == True)
    assert(collapsible('23 - 23 / 23') == False)
    assert(collapsible('0 + 1 + 2 + 3 + 0') == False)
    assert(collapsible('0+0+0+0+0+0+0') == False)
    assert(collapsible('0-0-0-0-0-0-0-0-0-0') == False)
    assert(collapsible('4 / 3') == False)
    assert(collapsible('5343456787543234567 / 743044830483009043909003') == False)
    assert(collapsible('0 / 0') == True)
    assert(collapsible('(-100 + 50 + 50) / (60 - 50 - 10)') == True)
    assert(collapsible('0 + 0 + (3 / (3 - 3))') == True)
    assert(collapsible('7 / ((7**2) - ((-7)**2))') == True)

main()
