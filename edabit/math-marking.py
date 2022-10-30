"""

Given an array of math equations (given as strings), return the percentage of correct answers as a string. Round to the nearest whole number.

Examples

markMaths(["2+2=4", "3+2=5", "10-3=3", "5+5=10"]) ➞ "75%"

markMaths(["1-2=-2"]), "0%"

markMaths(["2+3=5", "4+4=9", "3-1=2"]) ➞ "67%"

Notes

    You can expect only addition and subtraction.
    Note how there aren't any spaces in any given equation.

"""


def markmaths(s):
    c = 0
    for p in s:
        p = p.replace("=", "==")
        if eval(p) == True:
            c += 1
    r = "{}%".format(round(c*100/len(s)))
    return r


assert(markmaths(["2+2=4", "3+2=5", "10-3=3", "5+5=10"]) == "75%")
assert(markmaths(["1-2=-2"]) == "0%")
assert(markmaths(["2+3=5", "4+4=9", "3-1=2"]) == "67%")
assert(markmaths(["2+1=1", "2-1=2", "1+2=-2", "2-1=0", "1-2=0", "2+1=2",
                  "2-1=1", "1-2=0", "2+1=1", "1+2=-1", "1+2=1", "1+2=-1",
                  "1-2=-2", "1-1=2", "1+2=-1", "1-1=2", "2-1=0", "1-2=-2",
                  "2+1=-2", "1-1=-1", "1-1=1", "1+2=1", "1-1=2"]) == "4%")
assert(markmaths(["1+1=-1", "2+1=-2", "2+1=-2", "1-1=-2", "1-2=1", "1-1=-1", "2-2=-2", "2+2=1",
                  "2+1=-2", "1-2=0", "2+1=-2", "2-1=1", "2+2=-1", "1-2=-1", "1-2=0", "1-2=2"]) == "12%")
assert(markmaths(["1+2=0", "2+2=-2", "1+2=1", "1-1=-2", "2+2=-2",
                  "1+1=-1", "1+2=-1", "1-2=0", "1+1=1", "1-1=1"]) == "0%")
assert(markmaths(["2-2=1", "1-2=-2", "1+1=1", "1+1=-1",
                  "2-2=2", "1-2=-2", "1+1=-1", "2+2=2"]) == "0%")
assert(markmaths(["1-2=1", "1-1=0", "1-1=1", "1-2=1", "1-1=2", "2-2=-2", "1+1=-2",
                  "2+1=-2", "2+1=-1", "2+2=-1", "1-1=1", "1-1=-1", "2-1=2", "1-1=2",
                  "1-1=-2", "2-1=-2", "1-1=-1", "1+1=-2", "1-1=0", "1+2=2", "2+2=0",
                  "1+2=-2", "2-1=2", "1+2=-1", "2+2=-2", "2+2=0", "2+1=0", "1-1=-1",
                  "2-2=2", "1+2=2", "2-1=-1", "2+2=1", "1-1=-1", "2-2=-1", "1-2=2",
                  "1-2=2", "2+2=-1", "2-2=0", "1+1=2", "2+1=0", "1+2=0", "1+1=1",
                  "2+2=-1", "1-2=0", "1-2=-1", "2-1=1"]) == "13%")
assert(markmaths(["2+2=1", "2-1=-2", "1-1=2", "1+2=-1", "2-1=-2", "1+1=1", "2-1=-2", "2+1=1", "2-1=-1", "1-2=2", "2+2=2", "2-1=0", "1-2=1", "2+2=0", "1-2=-1", "2-1=-2", "2-1=2", "2+2=2", "2-1=-1", "2-1=-1", "1-1=2", "1+2=-2", "2-2=0", "2-1=-1", "2-2=-1", "1-1=0", "1-2=-2",
                  "2-2=2", "1+2=-1", "1+2=1", "1-2=-2", "2-1=-2", "1-1=-2", "1+1=-1", "1-2=0", "1-1=0", "1-2=1", "1-1=-2", "1+1=1", "2+2=-2", "2+1=-2", "1+1=2", "1+2=1", "1+2=2", "2-1=2", "2+1=1", "1-2=1", "2+1=-1", "2+2=-1", "2-1=1", "2-1=-2", "2-1=2", "2-1=0", "2-1=1", "1-1=-1"]) == "13%")
assert(markmaths(["1+1=-2", "1+2=1", "2-2=0", "1-1=0", "1-2=-1", "2+2=-1",
                  "1-2=2", "2-1=0", "2+1=-2", "1-2=2", "2+1=0", "2-2=-1"]) == "25%")
assert(markmaths(["1-2=2", "1+1=-2", "1-1=0", "2+1=2", "1+1=1", "2-1=2", "1-1=-2", "2-1=0", "2-2=2", "1+2=1", "1+2=-1", "2+2=2", "1+2=0", "2+2=2", "2+2=-1", "2-1=-2", "2-1=1", "2+1=1", "1+1=-1", "1-1=2",
                  "2-2=0", "1-1=0", "2-1=2", "2-2=0", "2-1=0", "1-2=1", "2+2=1", "1-1=-1", "2+1=0", "2-1=0", "1-1=0", "2-1=-1", "1-2=-2", "2-2=-1", "2-1=2", "1-2=0", "2+1=2", "2-2=0", "2+1=-2", "1+1=-1", "1+1=-2"]) == "17%")
assert(markmaths(["1-2=-2", "1+2=2", "2+1=-2", "1+1=2", "1-2=0", "2+1=-1", "2+1=1", "2+1=0", "1+2=1", "2-1=-2", "2+1=2", "1-1=2", "2-2=-1", "1-2=1", "1-2=0", "2+2=-2", "1-2=-1", "2-2=1", "1+2=2", "2-2=-2", "1+1=0", "2+1=2", "2-2=0", "1+2=-1", "1+1=-1", "1-1=-2", "1+1=1", "2-2=-1", "2+1=0", "1-2=0", "2+2=0", "1-1=2",
                  "1+1=1", "1+2=1", "2+1=-2", "2+2=-2", "1+2=0", "2-2=-2", "2-1=0", "2+2=1", "1-1=2", "2+2=1", "1-1=0", "1-2=-1", "1+2=1", "2-2=0", "1-2=-1", "1+1=2", "2-2=0", "2+2=0", "1-1=-1", "1+2=0", "2-1=1", "2-1=2", "1+2=0", "1-1=0", "2-1=0", "2+1=0", "2-2=1", "1+1=1", "1-1=-2", "1+2=2", "2+2=2", "2+1=0", "2-1=1"]) == "18%")
assert(markmaths(["1-2=-1", "1+1=0", "2+1=-2", "1-1=2", "1-2=-2", "2-1=-1", "1-2=2", "1+2=2", "1+1=2", "2+1=0", "2-1=0", "2-1=2", "2-1=-1", "2-1=-2", "1-1=-1", "1+2=2", "1-1=-1", "2+1=-2", "2+1=0", "2+1=1", "2+1=2", "2-2=1", "2+1=2", "2-2=1", "2+2=2", "1+2=1", "1+1=-1", "2+2=1", "1+1=0", "2+1=-1", "2+2=2", "2+2=-2",
                  "1+2=1", "2+2=1", "1+2=-2", "2-1=-1", "1-1=-1", "2-1=1", "2+1=1", "1-1=1", "2-1=1", "2-2=1", "2-1=1", "1-2=-2", "1-1=0", "1-2=-2", "2+1=-2", "2-1=-2", "1-1=-2", "2-2=2", "1+1=2", "1-1=-2", "2+2=-2", "2+1=1", "1+2=-1", "1+2=2", "2-1=0", "1+1=-2", "1+1=0", "2-2=0", "1-1=0", "2+1=-2", "2-2=0", "1-1=2", "1+2=0"]) == "15%")
assert(markmaths(["1+2=0", "1+1=2", "2-1=-2", "1-1=-1", "1-1=-1", "2-2=0", "2+1=0", "2-2=2", "1-1=1", "1+1=-1", "2+1=1", "2+2=2", "1+1=0", "1-1=0", "2-2=2", "1+1=0", "1-2=1", "1+1=-1", "1-1=1", "1-1=0", "2-2=-2", "2+2=-1",
                  "2-1=-1", "1-2=1", "1-1=-1", "1+2=-1", "2-1=2", "2-1=-1", "2-1=-2", "1+1=-2", "1-2=0", "1+1=1", "1+2=2", "1+2=1", "1-1=-1", "1-2=2", "1+1=1", "1+1=1", "2-1=-2", "2+1=-2", "1+2=2", "2+2=1", "1-2=2", "1+2=2", "2+1=-1"]) == "9%")
assert(markmaths(["2-2=-2", "1-1=2", "1-1=1", "2-1=0", "1+1=-1", "2-1=-1", "1+1=1", "1-1=-1", "1+1=0", "1-1=1", "1-2=0", "2+2=-2", "2+2=-2", "1+1=1",
                  "2-2=0", "2-2=0", "2+2=-1", "1-1=2", "2-2=2", "1+1=1", "1-1=-2", "2+1=-1", "1+1=-1", "2+1=1", "1+1=-1", "1+2=-1", "2-1=0", "1-1=2"]) == "7%")
assert(markmaths(["1-1=2", "2+2=0", "1-1=1", "2+1=1", "2+1=2", "2-1=-1", "1-2=-1", "1-1=-1", "1+2=0", "2-1=-2", "1-1=1", "1-1=2", "2-1=2", "1-1=2", "1+2=-1", "2-1=0", "2+2=-2", "1+2=2", "2+2=-2", "1-2=1", "1-1=-1", "2-1=0", "2-1=-2", "1+1=-1", "1+2=-1", "2-2=1", "1+2=0", "2-2=-1", "2-2=-2",
                  "2+1=1", "2+2=-1", "1+2=-2", "2+2=-1", "2-2=-1", "2+2=1", "2-1=-1", "1-2=1", "1+2=1", "1-2=0", "1-2=1", "1-2=0", "2-2=2", "2+2=1", "2-1=2", "1-2=-1", "1-2=2", "2-1=-1", "2+1=-1", "2-2=1", "1+1=-1", "1+1=-1", "2-2=2", "1+2=-2", "1-1=1", "2+2=2", "2-1=-2", "1+2=2", "1-1=0", "1+1=-1"]) == "5%")
assert(markmaths(["2-2=1", "2+2=2", "1+1=0", "1+1=0", "1-2=-2", "2-1=-2", "1+1=-2", "1+1=-1", "1-2=1", "2-1=1", "2-2=-1", "1-2=-2", "1+2=2", "2-1=-1", "1-1=0", "1+1=1",
                  "1+2=2", "1+2=-2", "2+2=-2", "1+2=0", "1-2=-1", "1+2=-1", "1-1=0", "1+2=1", "1+1=2", "1+1=-1", "1+2=2", "1+1=-2", "1-2=2", "2+2=-2", "2+2=2", "2+2=0", "1-1=0"]) == "18%")
assert(markmaths(["2+2=-1", "2+2=0", "2-2=-1", "2+2=2", "2+1=1", "2-2=-1", "2+2=-2", "2-2=1", "2-2=2", "2-2=-1", "2-1=1", "1-1=2", "2-1=-2", "1+2=1", "2-2=-2", "1+2=2", "1+2=-2", "1-2=-1", "2+1=-1", "1-1=1", "2+2=1", "1-1=1", "1-1=0", "2-1=0", "1-2=1", "1+1=-2",
                  "1-1=-2", "2-2=0", "2+1=0", "1+1=-1", "1+1=-2", "1-2=-2", "1+2=1", "2+1=0", "2-1=0", "2-1=2", "2+2=1", "2-2=-1", "2+1=0", "1+1=-1", "2-2=0", "1-1=1", "2+1=-1", "1+1=2", "1-2=-2", "2-2=1", "2-1=-2", "1+2=2", "2-2=1", "2+1=0", "1+1=-1", "2-1=1"]) == "13%")
assert(markmaths(["2-2=-2", "2+2=-1", "1+1=-2", "1-2=-1", "1-2=-1", "2+2=-2", "1-2=2", "2+1=-1", "1-1=0", "1+2=-1", "2-2=0", "1+1=2", "1+1=1", "2-1=-1", "1+2=0", "2-1=-1", "1+2=-1", "1-2=-2", "1+1=-1", "2-2=2", "1-1=0", "1-1=2", "1-2=1", "1-2=0", "1-2=-2", "2+2=2", "1+2=1", "1+1=-1", "1-1=0", "2-1=1", "2-2=1", "2-2=1", "2+2=1", "2+2=-1", "1-1=2",
                  "1-1=-2", "1-2=2", "1+2=0", "2-2=2", "2+2=-1", "1-2=-2", "2-2=-2", "2+1=1", "1-2=-2", "2-2=0", "2+2=0", "1-1=2", "2-2=-2", "2-1=-2", "2+1=2", "2-1=-1", "1-1=0", "1-2=-2", "2-1=0", "2-1=0", "1-1=2", "1+1=-1", "1-2=1", "1-1=-1", "1-1=-2", "2+2=-2", "2+2=0", "1+2=1", "1+2=0", "2+2=0", "1-1=-2", "2-2=-1", "2+2=1", "1+1=0", "2-1=2"]) == "14%")
assert(markmaths(["1-1=2", "2-1=2", "2-2=-2", "1-1=-2", "2-2=1", "2+1=-1", "1+2=-1", "1+1=0", "2-2=-1", "1-1=-2", "1-2=-1",
                  "1+2=-2", "2-1=-1", "2-1=0", "2+1=2", "1-1=-1", "2-1=-2", "2-1=1", "2-2=-1", "1-2=0", "1+2=-1", "2+1=2"]) == "9%")
assert(markmaths(["1-1=-1", "1-2=-2", "1-2=0", "2-2=-1", "2+1=0", "2+2=0", "2+1=-1", "2-1=0", "1+1=0", "2-1=2", "2-1=2", "1-1=-2", "2-1=-2",
                  "2+2=-1", "2+1=2", "2-2=-1", "2+2=-2", "2+1=-1", "2+2=2", "2-1=2", "1+2=1", "2+1=1", "1+2=2", "1+1=2", "2+1=-2", "1-1=1", "2+2=0"]) == "4%")
assert(markmaths(["1-1=2", "1-2=-1", "1-1=1", "1+2=-1", "1-2=-1", "2+1=1",
                  "2-1=-1", "1-1=-2", "2+1=-2", "2-1=1", "2+2=1", "2-1=-2", "2-2=1"]) == "23%")
assert(markmaths(["1+2=2", "1+2=1", "1-1=2", "1+1=-2", "2+1=-1", "2-1=0", "2-1=1", "1+1=2", "2-2=1", "2-1=0", "2+1=-1", "2+2=-2", "2-2=2", "2-2=0",
                  "1+1=1", "1-1=-2", "1-2=1", "2+2=-1", "2+2=-2", "2-2=2", "1-2=2", "2+1=0", "2-1=-1", "1-2=0", "2-2=0", "1+2=-1", "1-2=2", "1+1=1", "2-1=-1"]) == "14%")
assert(markmaths(["2-2=2", "2+2=-1", "2-1=0", "1+2=2", "1+2=2", "2+1=2", "2+2=2", "2+2=2", "1-1=1", "2-2=0", "1+1=1", "2-2=1", "2+2=2", "2-2=1", "2-2=-2", "2-1=-1", "1-2=1",
                  "1-2=1", "1-2=0", "2+1=2", "2-1=0", "2+1=-1", "2+1=-1", "2-2=2", "1+2=0", "2-2=2", "2-1=-2", "2+2=0", "2-2=-1", "2-2=0", "2+1=-2", "1+2=2", "1-2=-1", "1+2=0"]) == "9%")
assert(markmaths(["1+1=2", "1-1=1", "1-2=-1", "2-1=-1", "2+1=2", "2-1=-2", "1-1=-1", "2+1=0", "2+1=1", "2+2=1", "2+2=1", "2-1=-1", "2+2=-2", "2-1=1", "2+2=-2", "1-1=2", "2-1=1", "1-2=-1", "1+1=-2", "2+1=0", "2-1=1", "2+2=-2", "1+2=2", "1-1=1", "1-1=0", "1+1=-2", "2+1=-2", "2-2=-1", "2+1=-2", "2-2=2", "1+1=0",
                  "2-2=-1", "1-1=0", "2-1=2", "2-1=-2", "1+1=-1", "2-1=2", "2+1=-2", "2+2=0", "1-2=1", "1+1=1", "1+2=1", "1+1=0", "2+2=0", "1+2=-2", "1-2=-1", "2-1=-1", "1+2=1", "2-2=-1", "2-2=-2", "2+2=-2", "1+1=-2", "1+1=-1", "1+1=0", "2-1=1", "2-1=1", "1+2=-1", "2+2=2", "2-1=-2", "2-2=-1", "1+2=-1", "1-2=2"]) == "18%")
assert(markmaths(["1+2=2", "1-2=0", "2+1=1",
                  "2+2=-2", "2-2=2", "1-2=2"]) == "0%")
assert(markmaths(["1+1=2", "2-2=-1", "2+2=0", "2-1=-1", "1-1=-2", "2+2=1", "1+2=-2", "1-1=-2", "2+1=2", "1+1=0", "2-1=-1", "2+1=-2", "2+2=-2", "2-1=0", "1-1=0", "2+2=1", "2-2=0", "1+2=-1", "2-2=1", "1+1=0",
                  "2+1=1", "1-2=-2", "1-2=0", "1-1=1", "2+2=0", "1+2=-1", "1+2=-1", "1+1=-1", "2-1=-2", "2-2=-1", "1+2=-1", "1-1=0", "1-2=2", "2-1=1", "1+2=0", "1+1=-2", "2+1=-2", "1+2=1", "1-2=2", "1+2=-1"]) == "12%")
assert(markmaths(["2+2=1", "2-1=1", "1+2=1", "2-2=-2", "2+2=1", "2+2=0", "2-1=1", "1+1=0", "2+2=0", "2+2=1", "2+1=2", "1-2=-2", "2-1=1", "1-1=2",
                  "1-1=-1", "1-1=0", "2-2=0", "2-1=1", "2-1=-2", "2+2=-2", "2-1=-1", "1-2=-2", "1-2=0", "1-1=-2", "1-1=-2", "1+2=-2", "2-1=-1", "1-2=2"]) == "21%")
assert(markmaths(["1-2=1", "2+1=-1", "1-1=-1", "1+2=0",
                  "1+2=-2", "1+2=2", "2-1=2", "1-2=0", "2-1=2"]) == "0%")
assert(markmaths(["1+2=2", "2-1=1", "2-2=2", "2-2=-1", "1+2=-1", "1+1=0", "2+1=1", "1+1=-2", "2-1=2", "1-2=1", "2-1=0", "2-1=-2", "1+1=2", "1+1=0", "2-2=2", "2+1=2", "1+1=-2", "1+2=1", "1+1=-2", "2+1=-1", "2-2=-1", "1+2=-1",
                  "1+2=0", "1+2=2", "1-1=1", "1-2=-2", "1-2=2", "2+2=0", "1+1=-1", "1+2=-1", "2+2=-2", "2-2=1", "2+2=2", "1-2=1", "1-1=-1", "2-1=-1", "2+2=2", "1+2=1", "1+1=2", "2-1=-2", "2+2=-2", "1-2=2", "2+2=-2", "1-2=2"]) == "7%")
assert(markmaths(["2+1=-1", "2+1=0", "1+1=1", "1+1=0", "1+2=1", "2-1=2", "2-2=0", "1-2=-1", "1+2=0",
                  "1+2=1", "1-1=1", "2+1=1", "2-1=1", "2-1=-2", "2+2=-1", "1-1=2", "2+2=-2", "1+1=1", "2+1=-1"]) == "16%")
assert(markmaths(["1+2=0", "2-1=0", "1-2=-2", "2-1=2", "1+1=-1", "2+2=-2", "1-2=0", "1+1=-1", "1-1=-1", "1-1=-2", "2-1=1", "2+1=-1", "1+1=2", "2-1=-2", "1-1=2", "1+2=0", "1-1=2", "2+2=-1", "1+1=0", "1-2=0", "1+2=-2", "2+1=1", "2-2=0", "2-2=2", "1-2=-2", "2+1=-1", "1-2=-2", "2-1=1", "2+2=-2", "2+1=2", "2+2=1", "1+2=-2", "1-1=2",
                  "1-1=-1", "2+1=1", "2-2=-1", "1-1=-2", "2-2=0", "1+2=1", "1-2=1", "1+2=-2", "1-2=0", "2+1=0", "2+1=2", "2+2=-1", "2+1=1", "1+1=-1", "2-2=-1", "1-2=0", "2+2=2", "1-2=1", "2-1=1", "1+1=0", "2+2=1", "2+1=2", "1+1=-2", "2+2=2", "1-1=1", "1-2=2", "1+2=0", "2+2=-1", "1-1=-2", "1+1=-2", "2+1=-1", "2-1=-1", "2+1=1"]) == "9%")
assert(markmaths(["1-1=-1", "1+1=-2", "1+1=-2", "1-2=1"]) == "0%")
assert(markmaths(["2-1=-1", "1+2=0", "2+2=0", "2-2=-1", "2+1=1", "1-1=0", "2-2=-2", "2-1=-1",
                  "2+2=1", "2+2=0", "1-1=0", "2-1=-1", "1+2=0", "2-2=1", "1+2=2", "1+1=-1", "1+1=2"]) == "18%")
assert(markmaths(["1+1=2", "2+2=-1", "2-1=0", "1-2=-2", "2+2=2", "1+2=1", "2-1=-1", "2+2=-2", "2+1=-2", "1-2=0", "2+2=2", "2+1=-1", "2+1=-2", "2+2=-1", "1-2=-1", "1-2=2", "2+2=-1", "2-1=0", "1+1=-1", "2-2=-2", "1-2=-2", "1-2=-2", "2-1=-2", "1+2=-1", "2-2=1",
                  "1-2=-2", "1+2=2", "1-2=0", "2+2=2", "1-1=-1", "1-1=-1", "1-2=1", "1+2=1", "1-1=2", "1+2=0", "1+2=0", "2-2=-2", "1+2=-2", "1+1=0", "2-1=1", "2-1=-1", "2-1=1", "1-2=1", "2-1=2", "1+1=2", "2+1=1", "1+1=-1", "2+1=0", "2+1=1", "1+1=-2", "1-2=-1", "1-2=2"]) == "12%")
assert(markmaths(["2-1=-1", "2-2=0", "1-2=-2", "1+2=0", "1-1=0", "2+2=1", "1+1=2", "2+2=1", "2+2=-1", "1-2=1", "1+2=2", "1-1=2", "2+1=-1", "1-1=-2", "1-2=-2", "1+2=1", "2-1=2", "1+1=-1",
                  "1-2=0", "2-1=2", "1-1=0", "2+1=2", "2-2=0", "1-2=-1", "1-2=-1", "1+2=-1", "1+2=-1", "1+1=0", "2+1=1", "2-2=-2", "1-1=1", "1-2=-2", "1+1=0", "2-1=0", "1+2=0", "2-1=0", "1-1=-1"]) == "19%")
assert(markmaths(["1-1=1", "2+1=0", "2-2=0", "1+1=0", "2-1=-1", "1+2=-2", "1+1=0", "1+1=-2", "2-1=2", "2+1=-2", "1+2=0", "1-2=-1",
                  "1-1=1", "1+1=-1", "1+2=2", "2+2=0", "1-1=1", "2-1=-2", "1+2=-1", "1-2=-2", "1+1=-1", "1+1=-1", "1+1=1", "1+1=0", "1+1=2"]) == "12%")
assert(markmaths(["2-2=-1", "2+1=-2", "2-2=-1", "1+1=2", "1+2=0", "1-1=1", "1-1=-1", "1-2=1",
                  "2-2=0", "2-2=2", "1+2=1", "1-2=1", "2+2=2", "1-1=1", "1-1=2", "1+1=2", "2-2=2"]) == "18%")
assert(markmaths(["1-1=1", "1+1=2", "1+1=-2", "2+1=0", "1-1=0", "1-2=0", "2-1=-2", "2+1=1", "1+2=2", "1-1=-1", "2-1=1", "1+2=-1", "1-2=-1", "1-1=-1", "1-2=-1", "1-2=-1", "2-1=0", "2+1=0", "2+2=1", "1-2=-2", "1+2=2", "1+2=-1", "1+2=-1", "1+1=0", "1+2=2", "1+1=0", "2+1=-1", "1-1=-1", "1+1=-2", "1-2=-2", "1-2=0", "1+2=1", "1-2=-1", "1+2=2",
                  "2-1=-2", "2+1=-2", "2+1=2", "2-1=1", "1+1=-1", "2+1=1", "2+2=2", "2+2=1", "1-2=1", "2+2=1", "2+2=-2", "2-1=0", "1+1=-1", "2-1=-1", "1-2=1", "2-1=-2", "1-2=0", "2+1=-1", "1-2=1", "2-2=2", "2+1=0", "1+1=0", "2+1=-1", "2+1=-1", "2-1=-1", "1-2=0", "2+1=1", "1+2=0", "2-1=-2", "1+1=-2", "1+1=1", "1+2=1", "2+1=-2", "1-1=-2"]) == "12%")
assert(markmaths(["2-1=2", "1-2=-1", "2-1=-2", "2-1=1", "1-2=2", "2+2=2", "1+2=0", "2-1=-1", "2-2=-1", "2+1=-2", "1-1=2", "1-1=0", "1-2=-2", "1+1=2", "2-2=-1", "2+1=0", "1-1=1", "2-1=2", "2+1=0", "1-1=-2", "1+1=0", "1-2=0", "2-1=0", "2+2=2", "2+2=0", "2-1=-2", "1+2=-2", "2-1=-2", "2+2=-1", "2-2=2", "1-2=1", "2-2=2",
                  "1+1=2", "2+1=2", "2+1=1", "2+1=-1", "2-2=1", "2-2=2", "1-2=0", "1+2=2", "2+1=2", "1-2=0", "2-2=-2", "1-1=1", "1-1=1", "1+1=-1", "1-1=-2", "2-2=2", "1+2=-2", "1-2=2", "2+2=1", "2+2=0", "1-2=-2", "1-1=1", "2-1=-2", "2+2=-2", "2-1=0", "1+2=-2", "1-1=-2", "1-1=-1", "1-2=2", "1-1=2", "2-2=0", "1-2=-1"]) == "11%")
assert(markmaths(["1-1=-2", "1-1=1", "2-1=-1", "1-2=2", "2+2=-1", "1+2=-1", "2+1=1", "1-1=-2", "1-2=-1", "2+1=-2", "2+2=-2", "1+2=1", "2-1=2", "2-2=2", "1+1=2", "2-2=-2", "2+2=0", "2-2=0",
                  "1-1=-2", "2+1=1", "1+2=1", "2-2=1", "1-1=-1", "1-1=2", "2-1=-1", "2+1=2", "2+1=-1", "2+1=0", "1-1=-1", "2+1=1", "1+2=-1", "2-2=1", "1-2=2", "2-1=-2", "1-2=-2", "2-2=-2", "1-2=2"]) == "8%")
assert(markmaths(["2-2=-2", "2+2=2", "2+2=0", "1-2=-1", "1+2=0", "2-2=2", "1-1=2", "2-2=2", "1+2=-1", "2-1=1", "2+1=1", "1-2=1", "1+2=-1", "1+2=-1", "2-2=1", "2+1=-1",
                  "2-2=-1", "1+1=-1", "1-1=0", "2-2=0", "1-2=-1", "2+2=-1", "2-2=1", "2-2=2", "1-1=2", "2+2=2", "1+2=0", "2-1=-2", "1+1=1", "1+2=1", "2-1=2", "1+1=1"]) == "16%")
assert(markmaths(["2-2=1", "2+2=1", "2+1=0", "1-1=-1", "1+2=1", "2-2=0", "1-1=1", "2+1=-2", "1+1=-1", "1+2=-2", "2+2=-1",
                  "2-1=-2", "1-1=1", "1-2=2", "1+2=-2", "1-1=1", "1+2=-2", "1-2=-1", "1-1=2", "2+1=-2", "1+2=-2", "2+2=0"]) == "9%")
assert(markmaths(["1-2=-2", "1+2=2", "1+1=-1", "2+2=-2", "2+1=-2", "2-1=1", "1+2=-1", "2+2=1", "1-2=-2", "1+2=-2", "1+2=0", "2-2=1", "2+1=1", "1-1=0", "1-1=-2", "1+2=2", "2-2=0", "1+1=2", "1-1=1", "1-2=2", "1-2=2", "2+1=1", "2+1=1", "1+1=2", "1-1=1", "2-2=1", "1+2=1", "1+2=2", "1-2=2", "2+2=-1", "1-1=1", "2+2=-2", "1-1=0", "1-2=-1", "2+2=-2",
                  "1+2=1", "2-1=0", "1-2=-1", "1+1=1", "2-1=1", "2+2=1", "2+1=1", "2-1=1", "2-2=2", "1+1=2", "1-2=0", "1+2=0", "1+2=0", "2-1=1", "2+2=-2", "2+2=1", "2-2=1", "2-2=1", "1+1=0", "2+2=1", "2-2=-1", "1-1=-1", "1+2=0", "2-1=1", "2-1=-2", "2+2=-1", "1+1=-1", "2+2=0", "2-1=0", "2-1=0", "1+2=-2", "1-2=0", "1+1=-2", "1+1=0", "1-2=-2"]) == "19%")
assert(markmaths(["1+1=-1", "2+2=2", "1+2=0", "2+2=2", "2+1=0", "2-1=2", "2+2=2", "2+2=-2", "1-1=1", "2+1=0", "1-1=2", "2+1=-1", "2+1=-1", "1+1=-2", "1+2=2", "1-1=-2", "1-2=2", "2+1=-2", "1+1=-1", "2-2=2", "1+1=2", "1-2=-1",
                  "2+2=-1", "2-2=-2", "2-2=2", "2-1=1", "1+1=-2", "1+1=0", "2+2=0", "1+2=2", "1-2=0", "2-1=1", "2+1=-1", "2+2=-1", "2+2=2", "1+2=-1", "2+1=-2", "2-2=0", "2+1=-1", "2-1=-1", "2+1=1", "2+1=-2", "2+1=0", "1+2=-2"]) == "11%")
assert(markmaths(["1-2=-2", "1+2=2", "1+2=-2", "2+2=1", "2-1=2", "2+2=-1", "2+2=1", "1+1=0", "2-1=2", "1-2=2", "2-2=-2", "1-2=2", "2-1=-1", "2-1=-2", "1+1=-2", "1-1=0", "2+2=1", "2-2=-1", "2-2=0", "1+1=-2", "2-2=-2", "1+1=-2", "2+2=0", "2+2=-1", "1-2=1",
                  "2-1=-2", "2-1=2", "2-1=0", "2-1=-2", "2+1=-1", "1+1=-1", "1+1=2", "1+1=0", "2-2=-1", "2+1=1", "1+2=0", "1+2=0", "1+1=-1", "2-2=2", "2-1=0", "2+2=-1", "1+1=0", "2-2=-2", "2+1=1", "1+1=2", "2-1=0", "2+2=0", "1+1=0", "2-2=1", "1+1=-1"]) == "8%")
assert(markmaths(["2-2=-2", "2-1=-2", "2+2=-1", "1-1=1", "1+1=-2",
                  "1+1=2", "2+2=1", "2-1=2", "2-2=0", "1-1=0", "1+1=0"]) == "27%")
assert(markmaths(["2-1=2", "1+2=1", "1+1=-1", "2+1=1", "1-2=0", "1-2=-1", "2+2=-1", "1+2=2", "1+2=1", "2-2=-2", "2-1=0", "1+1=-1", "2+2=2", "2-1=-1", "1-1=-1", "1+2=-2", "1+1=-2", "2+2=0", "1+2=-1", "1+1=1", "2-1=-2", "2-1=-2", "1+2=1", "2+1=-1", "1-1=-1", "2-1=1", "1-2=-1",
                  "1+1=-2", "1+1=-2", "2-1=-2", "1+1=-1", "2+1=-1", "2+1=0", "2-1=-2", "1-1=2", "1+1=-2", "2+2=2", "2+1=2", "2+1=0", "1+1=0", "2-2=-1", "2+1=-1", "2-2=1", "2+1=-1", "2-1=0", "2-1=-1", "1-2=-1", "2-1=1", "2-1=0", "2+2=-2", "1-1=0", "2+1=-2", "2+2=1", "1-1=2"]) == "11%")
assert(markmaths(["1-1=-2", "2+1=-1", "2+1=-2", "1-1=1", "1+2=1", "2+1=1", "1+2=1", "1-2=-1", "2+2=1", "2+1=1", "2+1=1", "2+2=-1", "1-1=-1", "1+2=2", "1-2=0", "1+1=0", "1-1=1", "1+1=0", "1-2=2", "1-1=2", "1-1=2", "1-2=1", "1-2=-2", "2+2=2", "1+2=0",
                  "2-1=1", "2+1=1", "1+2=-2", "2+1=0", "2+2=-1", "2+1=0", "2-1=2", "1+1=2", "1+2=2", "2+2=0", "1-2=1", "2+1=1", "1+1=0", "2+1=-1", "1+2=1", "1-1=0", "2+2=0", "2+1=1", "1+1=-1", "1-2=2", "1+2=0", "2-1=-1", "2+2=-1", "1-2=0", "1+2=0"]) == "8%")
assert(markmaths(["1+1=-1", "2+2=2", "2+2=-1", "2-2=-2", "1-2=2", "2+2=2", "1+2=-1", "2-1=1", "1-1=-2", "1+2=-1", "1-1=0", "1-2=0", "2+1=-1", "2-1=0", "1-2=1", "2+2=2", "2+2=-1",
                  "1+2=1", "2-2=-2", "1+2=-2", "1-2=-2", "2-2=1", "2+2=-2", "2+2=0", "1-1=1", "2-2=0", "2-1=-2", "1-1=0", "1-1=0", "1-2=0", "2-2=1", "2-1=0", "2+2=-1", "2+1=-1", "2+2=1"]) == "14%")
assert(markmaths(["1-1=-2", "2+1=2", "2+1=-2", "1-2=-1", "2-2=-2", "1-1=1", "1+2=-1", "2-2=-1", "2-2=2", "2-1=2", "1-1=-2", "2+2=-1", "2+2=1", "2-1=1", "1+1=-2", "2-2=-1", "1-2=2", "1+1=2", "2-2=0", "1+2=-2", "1+2=1", "2+1=-2", "2+2=1", "1+2=2", "1+2=1", "1-2=-2", "2-1=1", "1+1=-2", "1-1=0",
                  "2+2=0", "2-2=2", "2+2=2", "1+1=-2", "1+1=-1", "2-1=0", "2-2=-2", "1-1=0", "1+2=0", "2-2=0", "1-2=-1", "1+2=0", "2+1=-2", "2+1=-2", "2+1=0", "1+2=1", "1+2=-2", "2+1=2", "1-2=2", "1+1=-1", "1+1=0", "2-2=-1", "1-1=-1", "2+2=1", "2-2=0", "2+2=0", "1+2=2", "1-1=-1", "2-1=-2", "1+1=2"]) == "19%")
assert(markmaths(["2+2=-1", "1-2=-1", "2-2=1", "2+1=2", "2+1=0", "2-1=2", "2+1=0", "1+2=2", "2+2=-1", "2+2=1", "2+2=1", "1-1=0",
                  "2-1=-2", "2-2=0", "2+2=-2", "1-2=-1", "1+2=-2", "2+1=0", "1+1=-1", "2-2=-2", "1+2=-2", "2+1=0", "2-2=2", "1+1=0", "2+1=0"]) == "16%")
