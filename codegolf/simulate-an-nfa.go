/*

A nondeterministic finite automaton is a finite state machine where a tuple (state,symbol) is mapped to multiple states. Ie. we replace the usual δ:Q×Σ→Q  transition function of a DFA with another function Δ:Q×Σ→P(Q).

If you know what an NFA is you might want to skip the next section.

Formal Definition
An NFA is uniquely described by

Q a finite set of states
Σ a finite set of symbols
Δ:Q×Σ→P(Q) the transition function
q0∈Q the initial state
F⊆Q a set of final states
The machine starts out in q0 and reads a finite string of symbols w∈Σ∗, for each symbol it will simultaneously apply the transition function function with a current state and add each new set of states to the set of current states.

Challenge
For this challenge we will ignore F  to simplify it, furthermore the alphabet will always be the (lower-case) letters a  to z  and the set of states will be {0…N} for some non-negative integer N. The initial state will always be 0.

Given a word w∈{a…z}∗ and a description of the NFA, your task is to determine all the final states.

Example
Consider the string abaab and the following description:

state, symbol, new-states
0, 'a', [1]
1, 'a', [0]
1, 'b', [1,2]
The machine will start in q0=0:

read an a: new states {1}
read a b: new states {1,2}
read an a: new states {0}
read an a: new states {1}
read a b: new states {1,2}
So the final states and thus the output would be {1,2}.

Note: In step (2) the transition of state 2 maps to ∅ as the description only includes transitions to non-empty sets.

Rules
The input will consist of a string and some kind of description of the NFA (without ϵ-transitions):

the input string will always be element of {a…z}∗
valid inputs (not limited to):
list/array of tuples/lists
new-line separated input
the description of the NFA will only contain transitions with non-empty sets as result
you may abbreviate rules with the same characters if their result is the same (eg. rules 0,'a',[1,2] and 0,'b',[1,2] could be abbreviated with 0,"ab",[1,2]
you may take each rule separate (eg. rule 0,'a',[1,2] can be 0,'a',[1] and 0,'a',[2])
you may choose upper-case letters if you want
you may take the number of states as input
you may assume some kind of ordering of the inputs (eg. ordered by state or symbols)
The output will be a list/set/new-line separated output etc. of the final states

order doesn't matter
no duplicates (as it's a set)
Test cases
These examples will be in the format description  word -> states where description is a list of tuples (state,symbol,new-states):

[]  "x" -> []
[]  "" -> [0]
[(0,'a',[1]),(1,'a',[0]),(1,'b',[1,2])]  "abaab" -> [1,2]
[(0,'a',[1]),(1,'a',[0]),(1,'b',[1,2])]  "abc" -> []
[(0,'p',[0,1]),(0,'g',[2]),(1,'c',[1]),(1,'g',[4]),(1,'p',[2]),(2,'c',[0])]  "ppcg" -> [2,4]
[(0,'f',[1]),(1,'o',[1,2]),(2,'b',[3]),(3,'a',[4]),(4,'r',[0,4])]  "foobar" -> [0,4]
[(0,'f',[1]),(1,'o',[1,2]),(2,'b',[3]),(3,'a',[4]),(4,'r',[0,4])]  "fooooooobar" -> [0,4]
[(0,'f',[1]),(1,'o',[1,2]),(2,'b',[3]),(3,'a',[4]),(4,'r',[0,4])]  "fobarfo" -> [1,2]
[(0,'f',[1]),(1,'o',[1,2]),(2,'b',[3]),(3,'a',[4]),(4,'r',[0,4])]  "foobarrf" -> [1]
[(0,'d',[1,2]),(1,'u',[2]),(2,'u',[2,3]),(2,'p',[3]),(3,'p',[3])]  "dup" -> [3]
[(0,'a',[0,2]),(0,'b',[3]),(1,'a',[1]),(1,'b',[1]),(2,'b',[1,4]),(4,'b',[2])]  "aab" -> [3,1,4]
[(0,'a',[0,2]),(0,'b',[3]),(1,'a',[1]),(1,'b',[1]),(2,'b',[1,4]),(4,'b',[2])]  "abb" -> [1,2]

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(Transition{}, "x", []int{})

	test(Transition{}, "", []int{0})

	test(Transition{
		{0, 'a'}: {1},
		{1, 'a'}: {0},
		{1, 'b'}: {1, 2},
	}, "abaab", []int{1, 2})

	test(Transition{
		{0, 'a'}: {1},
		{1, 'a'}: {0},
		{1, 'b'}: {1, 2},
	}, "abc", []int{})

	test(Transition{
		{0, 'p'}: {0, 1},
		{0, 'g'}: {2},
		{1, 'c'}: {1},
		{1, 'g'}: {4},
		{1, 'p'}: {2},
		{2, 'c'}: {0},
	}, "ppcg", []int{2, 4})

	test(Transition{
		{0, 'f'}: {1},
		{1, 'o'}: {1, 2},
		{2, 'b'}: {3},
		{3, 'a'}: {4},
		{4, 'r'}: {0, 4},
	}, "foobar", []int{0, 4})

	test(Transition{
		{0, 'f'}: {1},
		{1, 'o'}: {1, 2},
		{2, 'b'}: {3},
		{3, 'a'}: {4},
		{4, 'r'}: {0, 4},
	}, "fooooooobar", []int{0, 4})

	test(Transition{
		{0, 'f'}: {1},
		{1, 'o'}: {1, 2},
		{2, 'b'}: {3},
		{3, 'a'}: {4},
		{4, 'r'}: {0, 4},
	}, "fobarfo", []int{1, 2})

	test(Transition{
		{0, 'f'}: {1},
		{1, 'o'}: {1, 2},
		{2, 'b'}: {3},
		{3, 'a'}: {4},
		{4, 'r'}: {0, 4},
	}, "foobarrf", []int{1})

	test(Transition{
		{0, 'd'}: {1, 2},
		{1, 'u'}: {2},
		{2, 'u'}: {2, 3},
		{2, 'p'}: {3},
		{3, 'p'}: {3},
	}, "dup", []int{3})

	test(Transition{
		{0, 'a'}: {0, 2},
		{0, 'b'}: {3},
		{1, 'a'}: {1},
		{1, 'b'}: {1},
		{2, 'b'}: {1, 4},
		{4, 'b'}: {2},
	}, "aab", []int{1, 3, 4})

	test(Transition{
		{0, 'a'}: {0, 2},
		{0, 'b'}: {3},
		{1, 'a'}: {1},
		{1, 'b'}: {1},
		{2, 'b'}: {1, 4},
		{4, 'b'}: {2},
	}, "abb", []int{1, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(t Transition, s string, r []int) {
	p := sim(t, s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func sim(t Transition, s string) []int {
	p := []int{0}
	q := []int{}
	m := make(map[int]int)
	for i, r := range s {
		q = q[:0]
		for _, u := range p {
			k := [2]int{u, int(r)}
			for _, v := range t[k] {
				if m[v] <= i {
					q = append(q, v)
				}
				m[v] = i + 1
			}
		}
		p, q = q, p
	}
	sort.Ints(p)
	return p
}

type Transition map[[2]int][]int
