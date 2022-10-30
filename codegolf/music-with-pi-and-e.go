/*


Because I forgot to celebrate Pi Day (14.3), let's celebrate with π, e (Euler's number) and music!

Challenge
No, we don't have time to eat a pi-pizza, let's make a program.
What you need is 500 digits of π, and 10 digits of e.

The input is an integer n between 0 and 499 inclusive.

Then you should loop through the first n digits of π:

If the digit is:

0 then the note is C
1 then the note is D
2 then the note is E
3 then the note is F
4 then the note is G
5 then the note is A
6 then the note is B
7 then the note is C'
8 then the note is D'
9 then the note is E'
Next, for each digit in π, take a digit from e based on this mapping:

If the digit from π is 0, take the 1st digit from e
If the digit from π is 1, take the 2st digit from e
If the digit from π is 2, take the 3st digit from e
etc.
You need only 10 digits of e, because the digits in π are between 0 and 9.

Finally, take the note and the digit from e. Return a tuple (or equivalent) containing:

the note
the e digit divided by 4 (representing the beat)
Test cases
In:10
Out:
('D', 0.25)
('G', 2.0)
('D', 0.25)
('A', 0.25)
("E'", 1.0)
('E', 2.0)
('B', 2.0)
('A', 0.25)
('F', 0.5)
('A', 0.25)
In:5
Out:
('D', 0.25)
('G', 2.0)
('D', 0.25)
('A', 0.25)
("E'", 1.0)

Help
Here are 500 digits of π:

3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912

And 10 digits of e:
2.7182818284
Note that '3.' and '2.' don't count in the digits of π and e, and that we are using 0 indexing (so the 0th digit of π is 1 etc.).

Rules
This is code-golf so the shortest answer wins.
Optional; After every tuple or list output, there can be a trailing newline.
As one week is over, here is an ungolfed code in Python 2:
Python 2, 526 bytes
def music_maker(n):
 i=p=1;x=3*100**n
 while x:x=x*i/-~i/4;i+=2;p+=x/i
 pi_number=str(p)[:-1] #First 3 lines calculates Calculate Pi
 euler='7182818284'
 del x,i,p #You don't need those Variables any more. They were ment for calculating
 for i in range(n):
  current_pi = pi_number[i] #Current Pi
  current_e = euler[int(current_pi)] #Current e
  number_to_note = {0:"C", 1:"D",2:"E",3:"F",4:"G",5:"A",6:"B",7:"C'",8:"D'",9:"E'"} #Dict number to note
  print((number_to_note[int(current_pi)], int(current_e)/4)) #Prints result

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(10, []tuple{
		{"D", 0.25},
		{"G", 2.0},
		{"D", 0.25},
		{"A", 0.25},
		{"E'", 1.0},
		{"E", 2.0},
		{"B", 2.0},
		{"A", 0.25},
		{"F", 0.5},
		{"A", 0.25},
	})

	test(5, []tuple{
		{"D", 0.25},
		{"G", 2.0},
		{"D", 0.25},
		{"A", 0.25},
		{"E'", 1.0},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []tuple) {
	p := parse(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func parse(n int) []tuple {
	const pi = "14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912"
	const e = "7182818284"
	var notes = []string{"C", "D", "E", "F", "G", "A", "B", "C'", "D'", "E'"}

	r := []tuple{}
	for i := 0; i < n; i++ {
		c := pi[i%len(pi)] - '0'
		b := e[c] - '0'
		r = append(r, tuple{
			note: notes[c],
			beat: float64(b) / 4,
		})
	}
	return r
}

type tuple struct {
	note string
	beat float64
}
