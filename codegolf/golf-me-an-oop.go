/*

Two important components of object-oriented programming are inheritance and composition.
Together, they allow for creating simple yet powerful class hierarchies to solve problems.
Your task is to parse a series of statements about a class hierarchy, and answer questions about the hierarchy.

Input
A series of statements and questions about a class hierarchy, read from a file or standard input, whichever is best for your language.
If you use the file option, the filename will be passed as the first argument to your code (function argument or command line argument, whichever you choose). The format is as follows:

<statement> : <name> is a <name>. | <name> has a <name>.
<question> : Is <name> a <name>? | Does <name> have a <name>?
<name> : a-z | A-Z | sequence of alphanumerics or underscores, starting with a letter
The input will always be statements, then questions. All class names will begin with an uppercase English letter (A-Z), and all member names will begin with a lowercase English letter (a-z). All names are case-sensitive - ABC123 is not the same class as Abc123.

There will not be any cyclical inheritance - if B inherits from A, A will not inherit from B or any of B's children.

Only class names will be a part of a hierarchy - statements such as foo is a bar. or document has a name. will not occur.

Output
A series of truthy or falsey values, as answers to the queries, written to standard output or as the return value of your function.
If you do not have enough information to answer a question (e.g. questions that involve names you have not seen in the statements), answer with a falsey value.

Test Cases
Case 1:

Input:

B is a A.
C is a B.
A has a foo.
Does B have a foo?
Is C a A?
Is D a A?
Output:

True
True
False
Case 2:

Input:

Cop is a Person.
Criminal is a Person.
Sheriff is a Cop.
Crooked_Cop is a Cop.
Crooked_Cop is a Criminal.
BankRobber is a Criminal.
Cop has a badge.
Criminal has a criminal_record.
Person has a name.
Is Crooked_Cop a Person?
Does Criminal have a name?
Is Crooked_Cop a BankRobber?
Does Person have a potato?
Is Cop a Cop?
Output:

True
True
False
False
True
Rules
You may answer with a function or a program
Standard loopholes are forbidden
This is code-golf, so shortest correct answer in bytes wins
The winning answer will be chosen in one week
Good luck, and may the OOP be with you!

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	test([]string{
		"B is a A.",
		"C is a B.",
		"A has a foo.",
		"Does B have a foo?",
		"Is C a A?",
		"Is D a A?",
	})

	test([]string{
		"Cop is a Person.",
		"Criminal is a Person.",
		"Sheriff is a Cop.",
		"Crooked_Cop is a Cop.",
		"Crooked_Cop is a Criminal.",
		"BankRobber is a Criminal.",
		"Cop has a badge.",
		"Criminal has a criminal_record.",
		"Person has a name.",
		"Is Crooked_Cop a Person?",
		"Does Criminal have a name?",
		"Is Crooked_Cop a BankRobber?",
		"Does Person have a potato?",
		"Is Cop a Cop?",
	})
}

func test(l []string) {
	h := newhierarchy()
	for _, s := range l {
		err := h.Process(s)
		if err != nil {
			panic(err)
		}
	}
	fmt.Println()
}

type Hierarchy struct {
	types map[string]*Type
}

type Closure struct {
	types   map[*Type]bool
	members map[string]bool
}

type Type struct {
	name    string
	parents []*Type
	members []string
	closure *Closure
}

func newhierarchy() *Hierarchy {
	return &Hierarchy{
		types: make(map[string]*Type),
	}
}

func (h *Hierarchy) Process(s string) error {
	tab := []struct {
		format  string
		handler func(string, string) error
	}{
		{"%s is a %s.", h.inherit},
		{"%s has a %s.", h.compose},
		{"Is %s a %s?", h.is},
		{"Does %s have a %s?", h.has},
	}

	for _, p := range tab {
		var a, b string
		n, _ := fmt.Sscanf(s, p.format, &a, &b)
		if n == 2 {
			b = strings.TrimSuffix(b, ".")
			b = strings.TrimSuffix(b, "?")
			return p.handler(a, b)
		}
	}
	return fmt.Errorf("unknown command: %q", s)
}

func (h *Hierarchy) lookup(s string) *Type {
	x := h.types[s]
	if x == nil {
		x = &Type{}
		x.name = s
		x.closure, _ = h.closure(x)
		h.types[s] = x
	}
	return x
}

func (h *Hierarchy) closure(x *Type) (u *Closure, err error) {
	u = &Closure{
		types:   make(map[*Type]bool),
		members: make(map[string]bool),
	}

	v := make(map[*Type]bool)
	q := []*Type{x}
	for len(q) > 0 {
		p := q[0]

		if v[p] {
			err = fmt.Errorf("closure of type contains a cycle")
			return
		}
		v[p] = true

		for _, m := range p.members {
			u.members[m] = true
		}

		u.types[p] = true
		for _, n := range p.parents {
			u.types[n] = true
			q = append(q, n)
		}

		q = q[1:]
	}

	return
}

func (h *Hierarchy) inherit(a, b string) error {
	x := h.lookup(a)
	y := h.lookup(b)

	u := x.closure
	v := y.closure
	if v.types[x] {
		return fmt.Errorf("%q is already a parent of %q", b, a)
	}
	if u.types[y] {
		return fmt.Errorf("%q is a child of %q", b, a)
	}

	x.parents = append(x.parents, y)
	x.closure, _ = h.closure(y)

	return nil
}

func (h *Hierarchy) compose(a, b string) error {
	x := h.lookup(a)

	u := x.closure
	if u.members[b] {
		return fmt.Errorf("%q is already a member of %q", b, a)
	}

	x.members = append(x.members, b)
	x.closure, _ = h.closure(x)

	return nil
}

func (h *Hierarchy) is(a, b string) error {
	x := h.lookup(a)
	y := h.lookup(b)
	u := x.closure
	fmt.Println(u.types[y])

	return nil
}

func (h *Hierarchy) has(a, b string) error {
	x := h.lookup(a)
	x.closure, _ = h.closure(x)
	u := x.closure
	fmt.Println(u.members[b])

	return nil
}
