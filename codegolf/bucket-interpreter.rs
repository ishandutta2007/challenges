/*

Create a program that interprets the programming language Bucket.

Bucket works on two buckets: the first can hold A and the second can hold B units of liquid. The things you can do with these buckets are:

f: fill bucket A

F: fill bucket B

e: empty bucket A

E: empty bucket B

p: pour units of liquid from A to B until one is empty or the other is full, whichever happens first

P: same as the command p, but from B to A

o: output the value of bucket A

O: output the value of bucket B

These examples assume A is less than or equal to B in the tuple (A,B), which is the main tuple determining which variant of the language is to be interpreted. A is the lesser-or-equal value of a bucket here and B is the larger-or-equal value: substitute as you need.

Your program should ask for 3 inputs:

    the element A in the tuple (A,B):
    the element B in (A,B):
    the program to interpret.

The tuple (A,B) determines which variant of the language Bucket is interpreted.

As a general rule, make sure the first two inputs can range from 0 to 2,147,483,647.

Any characters in the third input other than fFeEpPoO do not need to be handled. Assume no characters other than these will be in the source.

Any commands equal to pouring more liquid in any bucket than it can hold do not need to be handled.

Assume the program will never try to pour liquid from an empty bucket.

This is code golf, so the shortest solution wins.

Any programs made before I changed the specifications to be correct are now non-competing.

*/

use std::cmp::min;

struct Bucket {
    ra: usize,
    rb: usize,
    a:  usize,
    b:  usize,
}

impl Bucket {
    fn new(a: usize, b: usize) -> Bucket {
        Bucket { ra: a, rb: b, a: a, b: b }
    }

    fn interpret(&mut self, code: &str) {
        for op in code.chars() {
            match op {
                'f' => self.a = self.ra,
                'F' => self.b = self.rb,
                'e' => self.a = 0,
                'E' => self.b = 0,
                'p' => {
                    let t = min(self.a, self.rb.saturating_sub(self.b));
                    self.a += t;
                    self.b -= t
                },
                'P' => {
                    let t = min(self.b, self.ra.saturating_sub(self.a));
                    self.b -= t;
                    self.a += t
                },
                'o' => println!("A: {}", self.a),
                'O' => println!("B: {}", self.b),
                _ => {},
            }
        }
    }
}

fn main() {
    let mut bt = Bucket::new(10, 20);
    bt.interpret("fFpPoOeEoO");
}

