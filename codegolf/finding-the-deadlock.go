/*

Finding the Deadlock
When programming a multithreading application one must take good care to avoid deadlocking the various threads when accessing shared resources.
A deadlock occurs when a thread attempts to access a resource that's locked in another thread at the same time that the other thread is trying to access a resource locked by the first.
This is the simple case, but it can get more complex with longer resource chains.

The challenge
You should write a program or function that can detect a possible deadlock situation in a list of the resources accessed by each thread. This is code-golf, so shortest answer in bytes wins.

Every thread is started at the same time, but after that they can run at any combination of interleaving.
If there are 2 threads with 4 actions each, it could be run as (where each number is an action taken by the thread with that id)
1,1,1,1,2,2,2,2, 2,2,2,2,1,1,1,1, 1,2,1,2,1,2,1,2, 1,1,2,2,2,2,1,1, or any other possible combination.

Input
You will receive, via STDIN, function parameter, or closest alternative, a list of strings. Each string will be in the format +a -b.
Every one of this strings represents the locking(+)/unlocking(-) of a resource by the thread.
Between every thread will be a --- separator. It is guaranteed that a thread won't try to lock a resource it already has locked, and that all threads will explicitly unlock all the resources they have locked before exiting.
Following is an example to demonstrate:

+a    # Lock resource a
+b    # Lock resource b
-a    # Unlock resource a
-b    # Unlock resource b
---   # Thread separator
+b    # Lock resource b
-b    # Unlock resource b
Output
The output shall be falsy if the input doesn't contain any deadlock possibility, and truthy if it contains a possible deadlock situation. For example:

true
false
1
0
are all valid outputs, but anything clearly defined as truthy/falsy will be accepted.

Examples
+a
-a
---
+a
-a
Output: false

+a
+b
-b
-a
---
+b
+a
-a
-b
Output true

Deadlock when trying to acquire b,a respectively for threads 1,2

+a
+b
-a
-b
---
+a
+b
-b
-a
Output false

+a
+b
-b
-a
---
+b
+c
-c
-b
---
+c
+a
-a
-c
Output: true

Deadlock in threads 1,2,3 when trying to acquire b,c,a respectively.

http://pastebin.com/vMYRZxtW

Output false

http://pastebin.com/V5MVgNgS

Output true

Deadlock in threads 1,2,3 when trying to aquire b,d,a respectively.

Of course this could get a lot more complex, with more threads, more resources for each one, and so on, but I believe these tests cover the basics.

Bonus
Since it's very very sad when you find deadlock situations when writing a program, there is a -8 byte bonus to answers outputting :( and :) as truthy/falsy respectively.

*/

package main

import (
	"bufio"
	"fmt"
	"strings"
)

func main() {
	assert(deadlock(seq1) == false)
	assert(deadlock(seq2) == false)
	assert(deadlock(seq3) == true)
	assert(deadlock(seq4) == false)
	assert(deadlock(seq5) == true)
	assert(deadlock(seq6) == false)
	assert(deadlock(seq7) == true)
	assert(deadlock(seq8) == false)
	assert(deadlock(seq9) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

A simple brute force way to check for deadlocks:
1) iterate through all the thread orderings, simulating locking/unlocking operations
2) for each of those sequences, create wait-for graph and check for cycles
3) if there is a cycle, then there is a deadlock

This is too slow as the number of orderings can grow factorially.

The problem defined above allows us to assume more about the input, leading to a more specialized but faster algorithm.
1) Decompose a lock sequence into a pair of lock sequences
2) For all locks, set the starting graph traversal node to that lock and then traverse through all pairs of lock sequences.
3) If there is a cycle detected through the traversal, there is a deadlock.

Example:
For lock sequence
+a, +b, +c, +d
we can make a lock sequence pair of
(a, b) (b, c), (c, d)

Then we would use
a, b, c, d
as starting points for the graph nodes and traverse through it.
Since there is no cycle here, there is no deadlock.

*/

func deadlock(s string) bool {
	c := readlockops(s)
	if !checklockseq(c) {
		panic("unsupported locking sequence")
	}
	p := getpairs(c)

	for i := range p {
		if cycles(i, p) {
			return true
		}
	}

	return false
}

func readlockops(s string) [][]Lockop {
	c := [][]Lockop{}
	p := []Lockop{}
	r := strings.NewReader(s)
	z := bufio.NewScanner(r)
	for z.Scan() {
		l := z.Text()
		l = strings.TrimSpace(l)
		if len(l) < 2 {
			continue
		}
		if strings.HasPrefix(l, "---") {
			c = append(c, p)
			p = []Lockop{}
			continue
		}

		p = append(p, Lockop{l[0], l[1]})
	}
	if len(p) > 0 {
		c = append(c, p)
	}

	return c
}

func checklockseq(c [][]Lockop) bool {
	for i := range c {
		m := make(map[byte]int)
		for _, x := range c[i] {
			switch x.op {
			case '+':
				if m[x.id]++; m[x.id] > 1 {
					return false
				}

			case '-':
				if m[x.id]--; m[x.id] < 0 {
					return false
				}
			default:
				return false
			}
		}

		for _, v := range m {
			if v != 0 {
				return false
			}
		}
	}
	return true
}

func getpairs(c [][]Lockop) [][]string {
	var r [][]string
	for i := range c {
		m := make(map[string]bool)
		p := []string{}
		s := ""
		for _, x := range c[i] {
			switch x.op {
			case '+':
				s += string(x.id)
			case '-':
				s = strings.Replace(s, string(x.id), "", -1)
			}

			n := len(s)
			if n < 2 {
				continue
			}

			v := fmt.Sprintf("%c%c", s[n-2], s[n-1])
			if !m[v] {
				p, m[v] = append(p, v), true
			}
		}
		r = append(r, p)
	}
	return r
}

func getids(p []string) []byte {
	r := []byte{}
	m := make(map[byte]bool)
	for i := range p {
		for j := range p[i] {
			c := p[i][j]
			if !m[c] {
				r, m[c] = append(r, c), true
			}
		}
	}
	return r
}

func getnodes(p [][]string) []string {
	r := []string{}
	m := make(map[string]bool)
	for i := range p {
		for _, s := range p[i] {
			if !m[s] {
				r, m[s] = append(r, s), true
			}
		}
	}
	return r
}

func cycles(k int, p [][]string) bool {
	V := getids(p[k])
	E := getnodes(p)

	for _, v := range V {
		m := make(map[byte]bool)
		q := []byte{v}

		for len(q) > 0 {
			n := len(q)
			u := q[n-1]
			q = q[:n-1]
			if m[u] {
				continue
			}

			m[u] = true
			for _, e := range E {
				x, y := e[0], e[1]
				if u == x {
					if m[y] && len(p) > 1 {
						return true
					}
					q = append(q, y)
				}
			}
		}
	}
	return false
}

type Lockop struct {
	op byte
	id byte
}

const seq1 = `
+a    # Lock resource a
+b    # Lock resource b
-a    # Unlock resource a
-b    # Unlock resource b
---   # Thread separator
+b    # Lock resource b
-b    # Unlock resource b
`

const seq2 = `
+a
-a
---
+a
-a
`

const seq3 = `
+a
+b
-b
-a
---
+b
+a
-a
-b
`

const seq4 = `
+a
+b
-a
-b
---
+a
+b
-b
-a
`

const seq5 = `
+a
+b
-b
-a
---
+b
+c
-c
-b
---
+c
+a
-a
-c
`

const seq6 = `
+a
+b
-b
-a
+a
+c
-c
+b
-b
-a
---
+a
+b
-b
-a
+a
+c
-c
+b
-b
-a
---
+d
+a
-a
-d
`

const seq7 = `
+a
+b
-b
-a
+a
+c
-c
+b
-b
-a
---
+a
+b
-b
-a
+a
+c
-c
+b
+d
-d
-b
-a
---
+d
+a
-a
-d
`

const seq8 = `
+a
+b
-a
-b
+b
+a
-b
-a
`

const seq9 = `
+a
+b
+c
+d
-a
-b
-c
-d
`
