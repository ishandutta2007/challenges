#!/usr/bin/env python

"""

Binary search is the fastest method to search a sorted array.

Imagine you are an undercover agent and you're at a cocktail party hosted by the bad buys.
You sneak into the drug lords office looking for an important document.
Fortunately the drug lord has organized his files by number from lowest to highest.
You know the number of the file you are looking for is 3412.
Since there are thousands of files and you have very limited time you wouldn't start at 0 and check each one.
This would be the iterative approach. Instead you would look halfway through the stack and see what number it is,
if its less than 3412 you know that everything below it won't contain the file for so you discard the bottom pile and search the top.
Each time looking in the middle and discarding the half that won't contain the number you are looking for. This is a binary search.

Your challenge is to write a function that searches a sorted array and returns the index of the number you are searching for.

"BUT WAIT!!!" you say...

"Why don't I just used findIndex, or indexOf to get the index?" you ask.

Because both of those are iterative. They have a time complexity of O(n), in our spy scenario that is too long, they will find you searching the files and you'll go swimming with the fishes.
The binary search has a time complexity of O(logN). Meaning it is substantially faster.

Arguments

Array:The array over which you searching

Number: The number who's index you want to return

Returns Index || -1: If the number is found the index is returned, otherwise it returns -1
Examples

binary([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 2
returns 2

binary([11, 12, 21, 23, 40, 40, 42, 43, 54, 57, 92], 31)
return -1

binary([11, 12, 21, 23, 40, 40, 42, 43, 54, 57, 92], 40)
return 4

Notes

    This is part of my Data Structures series. A collection of common coding interview challenges used to test ones understanding of data structures.
    This entire series of challenges can be found here.

"""

def binary(a, v):
    n = len(a)
    lo = 0
    hi = n - 1
    if lo >= len(a) or v < a[lo]:
        return -1
    if v > a[hi]:
        return -1
    while hi-lo != 1:
        mid = lo + (hi - lo) // 2
        if a[mid] < v:
            lo = mid
        else:
            hi = mid
    
    if a[hi] != v:
        return -1
    return hi

def main():
    assert(binary([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 2) == 2)
    assert(binary([11, 12, 21, 23, 40, 40, 42, 43, 54, 57, 92], 31) == -1)
    assert(binary([11, 12, 21, 23, 40, 40, 42, 43, 54, 57, 92], 40) == 4)
    assert(binary([1, 1, 1, 3, 3, 5, 6, 7, 8, 9], 5) == 5)
    assert(binary([1, 3, 3, 4, 4, 6, 6, 7, 7, 9], 8) == -1)
    assert(binary([0, 1, 2, 3, 4, 5, 6, 7, 9], 6) == 6)
    assert(binary([10, 17, 21, 27, 31, 32, 4, 42, 44, 45, 55, 57, 57, 60, 69, 72, 74, 79, 88, 89, 91, 96], 44) == 8)
    assert(binary([11, 12, 21, 23, 40, 40, 42, 43, 54, 57, 92], 31) == -1)
    assert(binary([16, 18, 24, 27, 3, 33, 45, 5, 51, 52, 57, 67, 70, 71, 72, 77, 8, 80, 83, 87, 93, 99], 80) == 17)
    assert(binary([11, 13, 17, 19, 22, 23, 25, 36, 39, 39, 40, 46, 48, 51, 56, 77, 82, 83, 87, 89, 91, 98], 89) == 19)
    assert(binary([11, 18, 27, 32, 36, 39, 42, 48, 58, 6, 6, 60, 64, 67, 67, 74, 77, 82, 88, 89, 92, 95], 37) == -1)
    assert(binary([16, 23, 31, 35, 48, 56, 6, 66, 68, 69, 80, 82, 82, 86, 9, 91, 92, 93, 94, 96, 97, 99], 59) == -1)
    assert(binary([10, 13, 2, 22, 25, 27, 43, 44, 46, 47, 47, 51, 69, 78, 79, 83, 85, 85, 86, 90, 96, 98, 99], 54) == -1)
    assert(binary([0, 1, 2, 3, 4, 5, 6, 7, 9], 2) == 2)

main()
