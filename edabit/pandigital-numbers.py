"""

A pandigital number contains all digits (0-9) at least once. Write a function that takes an integer, returning true if the integer is pandigital, and false otherwise.

Examples

isPandigital(98140723568910) ➞ true

isPandigital(90864523148909) ➞ false
// 7 is missing.

isPandigital(112233445566778899) ➞ false

Notes

Think about the properties of a pandigital number when all duplicates are removed.

"""

def pandigital(n):
    m = [0] * 10
    while n != 0:
        i = n % 10
        m[i] += 1
        n //= 10

    for i in range(len(m)):
        if m[i] == 0:
            return False
    return True

def main():
    assert(pandigital(112233445566778899) == False)
    assert(pandigital(546732965015) == False)
    assert(pandigital(6781235184590) == True)
    assert(pandigital(9432821089765) == True)
    assert(pandigital(629764) == False)
    assert(pandigital(90864523148909) == False)
    assert(pandigital(7296012) == False)
    assert(pandigital(647380265483206) == False)
    assert(pandigital(38165975424790) == True)
    assert(pandigital(8146327815320) == False)
    assert(pandigital(768431605430) == False)
    assert(pandigital(4920124852367763) == True)
    assert(pandigital(60543981597247) == True)
    assert(pandigital(10282343456789) == True)

main()
