/*

Alice (A) and Bob (B) decided to have a battle.
Each combatant has 10 health.
They take turns to roll a 6 sided die for damage.
That damage is removed from their opponent's health.
In the end either Alice or Bob, will vanquish their foe.
Show me how the battle went. Outputting these codes for the actions which have taken place.

Attack

B a A
^ Combatant
  ^ Action (attack)
    ^ Target
Roll

B r 4
^ Combatant
  ^ Action (roll)
    ^ Value
Health change

A h 6
^ Combatant
  ^ Attribute (health)
    ^ Value
Win

A w
^ Combatant
  ^ Action (win)
Example output:

A a B
A r 4
B h 6
B a A
B r 6
A h 4
A a B
A r 6
B h 0
A w
Here are the rules:

Write in any language.
A single roll of the die should have an equal chance of resulting in any one of the numbers 1, 2, 3, 4, 5, or 6.
Alice always starts (Bob is chivalrous, in an old-fashioned way).
Output an action for each turn.
You must report the attack, roll, damage and win actions.
Combatants are upper case, actions are lower case.
It must not consistently produce the same result.
There must be at least one whitespace character between an output combatant, action and value.
The win action takes place when the opponent has zero or less health.
All parts of an action must be on the same line.
There should be one action per line.
Fewest bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fight()
}

func fight() {
	const I = "AB"
	a, b, p := 10, 10, 0
	for {
		d, h := 1+rand.Intn(6), 0
		switch p {
		case 0:
			a = max(a-d, 0)
			h = a
		case 1:
			b = max(b-d, 0)
			h = b
		}

		fmt.Printf("%c a %c\n", I[p], I[1-p])
		fmt.Printf("%c r %d\n", I[p], d)
		fmt.Printf("%c h %d\n", I[1-p], h)
		if h == 0 {
			fmt.Printf("%c w\n", I[p])
			break
		}
		p = 1 - p
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
