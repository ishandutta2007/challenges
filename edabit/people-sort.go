/*

Given a list of people objects, create a function that sorts the list by an attribute name. The attribute to sort by will be given as a string.

The Person class will only include these attributes in the following order:

    firstname
    lastname
    age

Examples

p1 = Person("Michael", "Smith", 40)
p2 = Person("Alice", "Waters", 21)
p3 = Person("Zoey", "Jones", 29)

people_sort([p1, p2, p3], "firstname") ➞ [p2, p1, p3]
# Alice, Michael, Zoey

people_sort([p1, p2, p3], "lastname") ➞ [p3, p1, p2]
# Jones, Smith, Waters

people_sort([p1, p2, p3], "age") ➞ [p2, p3, p1]
# 21, 29, 40

Notes

    Sort the list in ASCENDING order.
    All objects will be valid.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	p := []Person{
		{"Michael", "Smith", 40},
		{"Alice", "Waters", 21},
		{"Zoey", "Jones", 29},
		{"Susan", "Heffley", 40},
		{"Bob", "Fredericson", 70},
		{"Braxton", "Leighsonley", 2},
		{"Joshua", "Senoron", 99999999999999},
	}

	test(p, "firstname", []Person{p[1], p[4], p[5], p[6], p[0], p[3], p[2]})
	test(p, "lastname", []Person{p[4], p[3], p[2], p[5], p[6], p[0], p[1]})
	test(p, "age", []Person{p[5], p[1], p[2], p[0], p[3], p[4], p[6]})
}

func test(p []Person, t string, r []Person) {
	v := peoplesort(p, t)
	fmt.Println(v)
	assert(reflect.DeepEqual(v, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Person struct {
	firstname string
	lastname  string
	age       uint64
}

func peoplesort(p []Person, t string) []Person {
	r := append([]Person{}, p...)
	var f func(i, j int) bool
	switch t {
	case "firstname":
		f = func(i, j int) bool { return r[i].firstname < r[j].firstname }
	case "lastname":
		f = func(i, j int) bool { return r[i].lastname < r[j].lastname }
	case "age":
		f = func(i, j int) bool { return r[i].age < r[j].age }
	default:
		return nil
	}
	sort.SliceStable(r, f)
	return r
}
