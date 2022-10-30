/*

For loops are used extensively in many languages, but what would you do if no languages supported them?

Create a way to execute a basic for loop without using any repetition structures (for, foreach, while, do, etc).

The basic for loop that you need to replicate is set up like this

for(i=0;i<1000;i++)

You must be able to replicate this without using repetition structures. It must also execute code in your language that would be in the body of the loop. Any form of eval is allowed, though it may not execute the for loop on its own.

You can test your code by having it print i with a space 100 times, add this test case to the end of your answer to verify your code with others.

There are no restrictions on what exactly it has to be, all it needs to do is replicate the for loop.

Winner will be decided based on upvotes at the time that it is chosen.


*/

package main

import "fmt"

func main() {
	f := func() { fmt.Println("Hello, World") }
	forage(loopy(f, 10))
}

func loopy(f func(), n int) *Counter {
	return &Counter{
		fun: f,
		end: n,
	}
}

type Counter struct {
	start, end int
	fun        func()
}

func (c *Counter) Init()      { c.start = 0 }
func (c *Counter) Cond() bool { return c.start <= c.end }
func (c *Counter) Body()      { c.fun() }
func (c *Counter) Post()      { c.start++ }

type Forager interface {
	Init()
	Cond() bool
	Body()
	Post()
}

func forage(f Forager) {
	f.Init()
top:
	if !f.Cond() {
		return
	}
	f.Body()
	f.Post()
	goto top
}
