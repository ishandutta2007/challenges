"""

Create a function that returns the characters from an array or string r on odd or even positions, depending on the specifier s. The specifier will be "odd" for items on odd positions (1, 3, 5, ...) and "even" for items on even positions (2, 4, 6, ...).
Examples

charAtPos([2, 4, 6, 8, 10], "even") ➞ [4, 8]
// 4 & 8 occupy the 2nd & 4th positions

charAtPos("EDABIT", "odd") ➞ "EAI"
// "E", "A" and "I" occupy the 1st, 3rd and 5th positions

charAtPos(["A", "R", "B", "I", "T", "R", "A", "R", "I", "L", "Y"], "odd") ➞ ["A", "B", "T", "A", "I", "Y"]

Notes

    Arrays are zero-indexed, so, index+1 = position or position-1 = index.
    A slightly different version of this challenge is found here.
    A recursive version of this challenge is found here.

"""

def at(r, s):
    if s == "even":
        i = 1
    elif s == "odd":
        i = 0
    else:
        return []
    
    l = []
    while i < len(r):
        l.append(r[i])   
        i += 2
    
    if isinstance(r, str):
        l = ''.join(map(str, l))
    return l

assert(at([2, 4, 6, 8, 10], "even") == [4, 8])
assert(at([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], "odd") == [1, 3, 5, 7, 9])
assert(at("EDABIT", "even") == "DBT")
assert(at("EDABIT", "odd") == "EAI")
assert(at("QWERTYUIOP", "even") == "WRYIP")
assert(at("POIUYTREWQ", "odd") == "PIYRW")
assert(at("ASDFGHJKLZ", "odd") == "ADGJL")
assert(at("ASDFGHJKLZ", "even") == "SFHKZ")
assert(at(["!", "@", "#", "$", "%", "^", "&", "*", "(", ")"], "odd") == ["!", "#", "%", "&", "("])
assert(at([")", "(", "*", "&", "^", "%", "$", "#", "@", "!"], "odd") == [")", "*", "^", "$", "@"])
assert(at(["A", "R", "B", "I", "T", "R", "A", "R", "I", "L", "Y"], "odd") == ["A", "B", "T", "A", "I", "Y"])
