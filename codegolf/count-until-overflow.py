#!/usr/bin/env python

"""

Assuming you have X collections, each collection Ci has a name Ni and a capacity Ni of elements - Determine which collection will be overflowed first while counting the occurrences of the names in a cyclic list.
Also print how many cycles of the list occurred.

Example:

4 Collections are available:

Name: "cat", Capacity: 3
Name: "dog", Capacity: 4
Name: "parrot", Capacity: 1
Name: "otter", Capacity: 5
Given the list: ["dog","cat","parrot","otter","otter","cat","parrot","cat","cat","dog"], "parrot" collection will be overflowed first, since we've counted two "parrot"s to the "parrot" collection which has a capacity of 1.
At the point of the overflow, there were only 1 dog, 2 cats, 2 otters - these collection are still capable to get more elements. 0 cycles occurred in that case.

Another example that demonstrate the cyclic property:

For the same collections, given the list: ["dog","cat","cat","parrot","otter"], "cat" collection will be overflowed first, since after reading the last element "otter",
we continue reading the list again from the start ("dog"), and we are reaching 4 cats before any other collection reaches the capacity. 1 cycle occurred in that case.

Assumptions:
Collections with Ci=0 are possible.
In case there will never be an overflow, the program should print falsely value.
It is possible to meet elements in the list that has no collection to be counted into, although you can assume all elements in the list contains [A-Za-z] characters only.
Name of a collection contains [A-Za-z] characters only.
Names of collections and elements are case sensitive.
It is possible to get no collections or an empty list as an input.

Input:
A list of collections, each collection has a name and capacity. (You can pass the names and the capacities in two different arguments that keep the relative order).
A list of elements, each element.
You can pass the input in any sensible way. Possible options:

[[["cat",3],["dog",4],["parrot",1],["otter",5]],["dog","cat","parrot","otter","otter","cat","parrot","cat","cat","dog"]]


[["cat",3,"dog",4,"parrot",1,"otter",5],["dog","cat","parrot","otter","otter","cat","parrot","cat","cat","dog"]]


["cat","dog","parrot","otter"],[3,4,1,5],["dog","cat","parrot","otter","otter","cat","parrot","cat","cat","dog"]]


cat,3
dog,4
parrot,1
otter,5
dog,cat,parrot,otter,otter,cat,parrot,cat,cat,dog

Output:
The name of the collection that will overflow first.
The amount of reading cycles on the list.
or falsely if no collection will ever be overflowed.

Scoring:
Since this is code-golf, lowest bytes wins.

Test Cases:
[[["cat",3],["dog",4],["parrot",1],["otter",5]],["dog","cat","parrot","otter","otter","cat","parrot","cat","cat","dog"]] --> "parrot",0

[[["cat",3],["dog",4],["parrot",1],["otter",5]],["dog","cat","cat","parrot","otter"]] --> "cat",1

[[["cat",7],["dog",8]],["dog","cat"]] --> "cat",7

[[["cat",7],["dog",8]],["woof","meow"]] --> False

[[["cat",7],["dog",8]],["Cat","Dog"]] --> False

[[["cat",1],["dog",0]],[]] --> False

[[["cat",0],["dog",0],["parrot",1],["otter",5]],["otter","otter","otter","otter","otter","parrot","dog"]] --> "dog",0

[[],["dog","cat"]] --> False

"""

def count(c, a):
    if len(a) == 0:
        return False

    m = {}
    for v in c:
        m[v[0]] = v[1]
   
    n = 0
    while True:
        for v in a:
            if not v in m:
                return False
            if m[v] <= 0:
                return [v, n]
            m[v] -= 1
        n += 1

def main():
    assert(count([["cat", 3], ["dog", 4], ["parrot", 1], ["otter", 5]], ["dog", "cat", "parrot", "otter", "otter", "cat", "parrot", "cat", "cat", "dog"]) == ["parrot", 0])
    assert(count([["cat", 3], ["dog", 4], ["parrot", 1], ["otter", 5]], ["dog", "cat", "cat", "parrot", "otter"]) == ["cat", 1])
    assert(count([["cat", 7], ["dog", 8]], ["dog", "cat"]) == ["cat", 7])
    assert(count([["cat", 7], ["dog", 8]], ["woof", "meow"]) == False)
    assert(count([["cat", 7], ["dog", 8]], ["Cat", "Dog"]) == False)
    assert(count([["cat", 1], ["dog", 0]], []) == False)
    assert(count([["cat", 0], ["dog", 0], ["parrot", 1], ["otter", 5]], ["otter", "otter", "otter", "otter", "otter", "parrot", "dog"]) == ["dog", 0])
    assert(count([], ["dog", "cat"]) == False)

main()
