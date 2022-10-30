"""

You can assign variables from lists like this:

lst = [1, 2, 3, 4, 5, 6, 7, 8]
first = lst[0]
second = lst[1]
third = lst[2]
other = lst[3:]

print(first) ➞ outputs 1
print(second) ➞ outputs 2
print(third) ➞ outputs 3
print(other) ➞ outputs [4, 5, 6, 7, 8]

Create variables first, second, third and other from the given list using Destructuring Assignment (check the Resources tab for some examples).

Examples

first ➞ 1

second ➞ 2

third ➞ 3

other ➞ [4, 5, 6, 7, 8]

Your task is to unpack the list writeyourcodehere into four variables, first, second, third, and other.
Notes

    Your solution should be just One Line code.
    If your solution is longer than one line of code, please check the Resources tab.
    Another version of this challenge.

"""

def main():
    lst = [1, 2, 3, 4, 5, 6, 7, 8]
    first, second, third, other = lst[0], lst[1], lst[2], lst[3:]
    assert(first == 1)
    assert(second == 2)
    assert(third == 3)
    assert(other == [4, 5, 6, 7, 8])

main()
