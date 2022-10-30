#!/usr/bin/env python

"""

Problem definition

Print out the powerset of a given set. For example:

[1, 2, 3] => [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]

Each element is to be printed on a separate line, so the above example would be printed as:

[]
[1]
[2]
...
[1, 2, 3]

Example code (in D, python example here):

import std.stdio;

string[][] powerset(string[] set) {
    if (set.length == 1) {
        return [set, []];
    }

    string[][] ret;
    foreach (item; powerset(set[1 .. $])) {
        ret ~= set[0]~item;
        ret ~= item;
    }

    return ret;
}

void main(string[] argv) {
    foreach (set; powerset(argv[1 .. $]))
        writeln(set);
}

Input

Elements will be passed as arguments. For example, the example provided above would be passed to a program called powerset as:

powerset 1 2 3

Arguments will be alphanumeric.
Rules

    No libraries besides io
    Output does not have to be ordered
    Powerset does not have to be stored, only printed
    Elements in the set must be delimited (e.g. 1,2,3, [1,2,3] and ['1','2','3'] are acceptable, but 123 is not
        Trailing delimiters are fine (e.g. 1,2,3, == 1,2,3)
    Best is determined based on number of bytes

The best solution will be decided no less than 10 days after the first submission.

"""

def powerset(a):
    l = []
    n = 1 << len(a)
    for i in range(n):
        p = []
        for j in range(len(a)):
            if i&(1<<j) != 0:
                p.append(a[j])
        l.append(p)
    return l

def main():
    print(powerset([1, 2, 3]))
    print(powerset(['a', 'b']))

main()
