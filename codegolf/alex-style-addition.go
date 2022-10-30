/*

Inspired by Alex's glorious Learn you an R for great good, we are going to humbly recreate Alex's "one true R program" -- but with a twist.

Alex-style Addition works like this -- it has a 90% chance of simply returning the sum of the two numbers given and a 10% chance of recursively Alex-adding the first number and the second number + 1.
This means that, potentially, an addition could be off by 1 or more.
Challenge

Write a full program or function that takes two integers and Alex-adds them as defined. You may assume that your program will not stack overflow if your language doesn't have tail recursion.
(Note that you do not have to implement it recursively, as long as the probabilities are the same.)

Reference Implementation (Groovy)

int alexAdd(int a, int b) {
  int i = new Random().nextInt(11);
  if(i == 1) {
    return alexAdd(a,b+1);
  } else {
    return a + b;
  }
}

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 10; i++ {
		fmt.Println(alexadd(2, 4))
	}
}

func alexadd(a, b int) int {
	if rand.Intn(11) == 1 {
		return alexadd(a, b+1)
	}
	return a + b
}
