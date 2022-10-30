#!/usr/bin/env python

"""

Your program or function should output all the 36 4-perfect numbers in increasing order separated by newlines.

An n positive integer is a k-perfect number (multiply perfect number) if the sum of its divisors including itself (i.e. the sigma function of n) equals k*n.

For example 120 is a 3-perfect number because 1 + 2 + 3 + 4 + 5 + 6 + 8 + 10 + 12 + 15 + 20 + 24 + 30 + 40 + 60 + 120 = 360 = 3*120.

Details
Your entry should actually produce the output and terminate on your machine before you submit your answer. (i.e. the program should terminate in a reasonable time)
Hardcoding is allowed.
Built-in functions or data closely related to the problem (e.g. sigma function) are disallowed.
This is code-golf but as the task is non-trivial without major hardcoding non-golfed entries are welcomed too.
(This is a great detailed page about the history of all multiply perfect numbers.)

"""

def perfect4(n):
    values = (30240, 32760, 2178540, 23569920, 45532800, 142990848, 1379454720, 43861478400, 66433720320, 153003540480, 403031236608, 704575228896, 181742883469056, 6088728021160320, 14942123276641920, 20158185857531904, 275502900594021408, 622286506811515392, 71065075104190073088, 203820700083634254643200, 63583020166602943198789632, 156036748944739017459105792, 1612532860097932682386735104, 3638193973609385308194865152, 24862223033124742964111030747136, 27255271098894367673389500334080, 61013466228291299819132525346816, 66886157385030640039109307924480, 630532357710420079508428362350592, 1422606063264005633932239197700096, 1928622300236318049928258133164032, 58234847911585743639191150258791907328, 142911996309794733796329290979468115968, 21571439852601139426707905057216142508032, 651350717502447739281012140234441171379683328, 1598455815964665104598224777343146075218771968)
    
    if n < 1 or n > len(values):
        return -1
    return values[n-1]

def main():
    for i in range(1, 37):
        print(perfect4(i))

main()
