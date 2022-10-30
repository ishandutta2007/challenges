/*

I like pizza!

Task
Given the radius of a pizza and a list of ingredients, create the corresponding ascii pizza!

Example size 4 pizza with mozzarella cheese, olives and ham:

  #####
 #@@@@M#
#H@O@@@@#
#M@@@H@@#
#@OO@@@@#
#@@H@@@@#
#M@M@@@@#
 #O@@@H#
  #####
Input
A positive integer r for the size of the pizza and a (possibly empty) list of ingredients (non-empty strings). The list of ingredients can be given in a series of convenient formats, including but not limited to:

a list of ingredients, such as ["tomato", "ham", "cheese"];
a list of the initials, such as ["t", "h", "c"];
a list of left- or right-padded ingredients, such as ["tomato", "ham   ", "cheese"] or ["tomato", "   ham", "cheese"];
a string with the initials, such as "thc".
Output specs
The pizza is built on a square of size 2r+1 characters, with the centre character having coordinates (0,0) for the purposes of this explanation. All characters in the square have integer coordinates. Then,

a position is crust # if its coordinates x,y satisfy r+1 > sqrt(x^2 + y^2) >= r
a position is dough @ if its coordinates x,y satisfy r > sqrt(x^2 + y^2)
Then, the ingredients must be put randomly on the pizza. Each ingredient will be represented by its initial and you must place r of each ingredient randomly in the dough characters.
You can assume there will be enough space in the pizza. Ingredients cannot be placed on top of eachother, so in the final pizza there must be exactly rl non-dough symbols, in groups of r, if the ingredients list has size l.

For the randomness in the distributions of ingredients on top of the pizza, it suffices that for a fixed r and ingredient list, all ingredient distributions obeying the specs have non-zero probability of occurring.

Examples
r = 1, no ingredients

###
#@#
###
r = 2, no ingredients

#####
#@@@#
#@@@#
#@@@#
#####
r = 5, no ingredients

  #######
 ##@@@@@##
##@@@@@@@##
#@@@@@@@@@#
#@@@@@@@@@#
#@@@@@@@@@#
#@@@@@@@@@#
#@@@@@@@@@#
##@@@@@@@##
 ##@@@@@##
  #######
r = 4, ingredients = ["bacon", "mozzarela", "tomato"]

  #####
 #@@b@m#
#@@@@@b@#
#@@@btb@#
#@@@@@@t#
#@@@@@@@#
#@mt@@@@#
 #t@mm@#
  #####
Reference implementation

Please include one or two of your favourite pizzas in your answer :)

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	pizza(4, "MOH")
	pizza(2, "")
	pizza(5, "")
	pizza(4, "bmt")
	pizza(26, "abcdefghijklmnopwrstuvwxyz")
}

func pizza(r int, t string) {
	n := 2*r + 1
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			fmt.Printf("%c", topping(x-r, y-r, r, t))
		}
		fmt.Println()
	}
	fmt.Println()
}

func topping(x, y, r int, t string) rune {
	p := x*x + y*y
	ri := r * r
	ro := (r + 1) * (r + 1)
	if p < ri {
		n := rand.Intn(len(t) + 1)
		if n == 0 {
			return '@'
		}
		return rune(t[n-1])
	}
	if ri <= p && p < ro {
		return '#'
	}
	return ' '
}
