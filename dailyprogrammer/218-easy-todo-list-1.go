/*

Description

Todays challenge will be something slightly different! Atleast I think the challenge is meant to be for today? Wait, am I meant to even be submitting today?

Okay maybe I need some help on organising my thoughts before I submit my challenge. A to-do list would be fine, just something so that I can organise my thoughts!

It should have the following basic functionality

    Add an item to the to-do list

    Delete a selected item from the to-do list

    And obviously, print out the list so I can see what to do!

Formal Inputs & Outputs
Output description

Any output that is created should be user-friendly. When I'm viewing my to-do list, I should be able to easily discern one list item from another.
Examples

Input:

addItem('Take a shower');
addItem('Go to work');
viewList();

Output:

Take a shower
Go to work

Further Input:

addItem('Buy a new phone');
deleteItem('Go to work');
viewList();

Outputs:

Take a shower
Buy a new phone

Finally

Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import "fmt"

func main() {
	var td Todo

	td.Add("Take a shower")
	td.Add("Go to work")
	td.View()
	td.Add("Buy a new phone")
	td.Delete("Go to work")
	td.View()
}

type Todo []string

func (t *Todo) Add(s string) {
	*t = append(*t, s)
}

func (t *Todo) Delete(s string) {
	j := 0
	for i := 0; i < len(*t); i++ {
		if (*t)[i] == s {
			continue
		}
		(*t)[j], j = (*t)[i], j+1
	}
	*t = (*t)[:j]
}

func (t Todo) View() {
	for _, s := range t {
		fmt.Println(s)
	}
	fmt.Println()
}
