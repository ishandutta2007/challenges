/*

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.


Constraints:

1 <= n <= 1000

*/

package main

import "fmt"

func main() {
	test(1000)
}

func test(n int) {
	f := Foobar{}
	f.Init()

	done := make(chan bool)
	go func() {
		for i := 0; i < n; i++ {
			f.Foo()
		}
		done <- true
	}()

	go func() {
		for i := 0; i < n; i++ {
			f.Bar()
		}
		done <- true
	}()

	<-done
	<-done
}

type Foobar struct {
	ch [2]chan bool
}

func (c *Foobar) Init() {
	for i := range c.ch {
		c.ch[i] = make(chan bool, 1)
	}
	c.ch[0] <- true
}

func (c *Foobar) Foo() { c.output("foo", 0) }
func (c *Foobar) Bar() { c.output("bar\n", 1) }

func (c *Foobar) output(s string, n int) {
	<-c.ch[n]
	fmt.Print(s)
	c.ch[(n+1)%len(c.ch)] <- true
}
