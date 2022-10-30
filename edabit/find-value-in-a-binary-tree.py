#!/usr/bin/env python

"""

An array that represents a Binary Tree is in the following form:

binaryTree = [val, arrLeft, arrRight]

When arrLeft is the left side of the tree and arrRight is the right side of the tree.

To illustrate:

const arr1 = [3, [ 8, [ 5, null, null], null], [ 7, null, null]]

// arr1 represents the following Binary Tree:

                    3
                   / \
                  8   7
                 /\   /\
                5  N N  N
               /\
               N N

// Where N represents null.

Create a function that takes an array that represent a Binary Tree and a value and return true if the value is in the tree and, false otherwise.
Examples

valueInTree(arr1, 5) ➞ true

valueInTree(arr1, 9) ➞ false

valueInTree(arr2, 51) ➞ false

Notes

The tree will contain integers only and will be presented by an array in the specified format.

"""

def intree(a, v):
    if a == None:
        return False
    if v == a[0]:
        return True
    return intree(a[1], v) or intree(a[2], v)

def main():
    lst1 = [3, [7, [1, None, None], [8, None, None]], [5, None, [4, None, None]]]
    lst2_8 = [2, None, None]
    lst2_6 = [24, None, None]
    lst2_7 = [18, None, None]
    lst2_4 = [4, lst2_8, None]
    lst2_3 = [12, None, lst2_4]
    lst2_2 = [10, None, lst2_3]
    lst2_1 = [15, lst2_2, None]
    lst2_5 = [6, lst2_6, lst2_7]
    lst2 = [9, lst2_1, lst2_5]
    lst3_1 = [4, None, None]
    lst3_2 = [9, None, None]
    lst3_3 = [21, None, None]
    lst3_4 = [17, None, None]
    lst3_5 = [25, None, None]
    lst3_6 = [18, lst3_5, None]
    lst3_7 = [20, lst3_3, lst3_4]
    lst3_8 = [91, lst3_2, None]
    lst3_9 = [75, None, lst3_1]
    lst3_10 = [45, None, None]
    lst3_11 = [71, None, None]
    lst3_12 = [34, None, None]
    lst3_13 = [11, None, None]
    lst3_14 = [10, lst3_6, lst3_13]
    lst3_15 = [3, lst3_7, lst3_12]
    lst3_16 = [26, lst3_8, lst3_11]
    lst3_17 = [1, lst3_9, lst3_10]
    lst3_18 = [66, lst3_14, lst3_17]
    lst3_19 = [52, lst3_16, lst3_15]
    lst3 = [97, lst3_18, lst3_19]

    assert(intree(lst1, 7) == True)
    assert(intree(lst1, 4) == True)
    assert(intree(lst1, 15) == False)
    assert(intree(lst2, 18) == True)
    assert(intree(lst2, 51) == False)
    assert(intree(lst2, 23) == False)
    assert(intree(lst3, 52) == True)
    assert(intree(lst3, 120) == False)
    assert(intree(lst3, -2) == False)
    assert(intree(lst3, 91) == True)

main()
