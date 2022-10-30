#!/usr/bin/python

"""
You have an empty sequence, and you will be given  queries. Each query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the minimum/maximum element in the stack.

Execute each query
"""


def run(instructions):
    stack = []
    ranges = []

    for ip in instructions:
        if ip == "":
            continue
        op = ip[0]
        if op == '1':
            value = int(ip[1:])
            stack.append(value)

            minimum = value
            maximum = value
            if len(ranges) > 0:
                minimum = min(ranges[-1][0], minimum)
                maximum = max(ranges[-1][1], maximum)
            ranges.append([minimum, maximum])
        elif op == '2':
            if len(stack) > 0:
                stack.pop()
                ranges.pop()
        elif op == '3':
            if len(stack) > 0:
                print("min: %d max: %d" % (ranges[-1][0], ranges[-1][1]))
            else:
                print("min: 0 max: 0")


def main():
    run(["1 97", "2", "1 20", "2", "1 26", "1 20", "2", "3", "1 91", "3"])


main()
