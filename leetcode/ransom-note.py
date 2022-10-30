#!/usr/bin/env python

"""

Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

1 <= ransomNote.length, magazine.length <= 10^5
ransomNote and magazine consist of lowercase English letters.

"""

def construct(s, t):
    m = {}
    for c in s:
        m[c] = m.get(c, 0) + 1

    for c in t:
        v = m.get(c, 0)
        if v == 0:
            return False
        m[c] = v - 1
    
    return True

def main():
    assert(construct("a", "b") == False)
    assert(construct("aa", "ab") == False)
    assert(construct("aa", "aab") == False)

main()
