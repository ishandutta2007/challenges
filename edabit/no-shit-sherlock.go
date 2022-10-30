/*

On a crime scene, there are many pieces of evidence that point to a particular person having the murder weapon and motive to kill poor old Tom (although not poor at all).

Create a function that takes phrases/words as clues and forms a sentence formatted to have the murder's name, verb, "Tom as", Reason.
Sn	Weapon	Verb to be used	Reason
1	Poison	Poisoned	Only X could have such high-grade poison.
2	Knife	Butchered	Only X was in the kitchen.
3	Bat	Swatted	Only X is a baseball player.
4	Gun	Shot	Only X had a gun.
5	Briefcase	Smacked	Only X was after Tom's money.
Examples

sherlock("Mr.Red", "Knife") ➞ "Mr. Red butchered Tom as only he was in the kitchen."

sherlock("Ms.Blue", "Poison") ➞ "Ms. Blue poisoned Tom as only she could have such high-grade poison."

sherlock("Mr.Red", "Bat") ➞ "Mr. Red swatted Tom as only he was a baseball player."

Notes

    Ms/Mr gives you the gender of the murderer.
    Feel free to remove the dictionary if you want.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(sherlock("Mr.Red", "Knife") == "Mr.Red butchered Tom as only he was in the kitchen.")
	assert(sherlock("Ms.Blue", "Poison") == "Ms.Blue poisoned Tom as only she could have such high-grade poison.")
	assert(sherlock("Mr.Red", "Bat") == "Mr.Red swatted Tom as only he is a baseball player.")
	assert(sherlock("Ms.Purple", "Gun") == "Ms.Purple shot Tom as only she had a gun.")
	assert(sherlock("Mr.Brown", "Briefcase") == "Mr.Brown smacked Tom as only he was after Tom's money.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sherlock(p, w string) (r string) {
	var u string
	switch {
	case strings.HasPrefix(p, "Mr."):
		u = "he"
	case strings.HasPrefix(p, "Ms."):
		u = "she"
	default:
		return
	}

	var v, e string
	switch strings.ToLower(w) {
	case "poison":
		v = "poisoned"
		e = "could have such high-grade poison"
	case "knife":
		v = "butchered"
		e = "was in the kitchen"
	case "bat":
		v = "swatted"
		e = "is a baseball player"
	case "gun":
		v = "shot"
		e = "had a gun"
	case "briefcase":
		v = "smacked"
		e = "was after Tom's money"
	default:
		return
	}

	r = fmt.Sprintf("%s %s Tom as only %s %s.", p, v, u, e)
	return
}
