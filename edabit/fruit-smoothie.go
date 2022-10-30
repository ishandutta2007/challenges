/*

Create a class Smoothie and do the following:

    Create a constructor property called ingredients.
    Create a getCost method which calculates the total cost of the ingredients used to make the smoothie.
    Create a getPrice method which returns the number from getCost plus the number from getCost multiplied by 1.5. Round to 2 decimal places.
    Create a getName method which gets the ingredients and puts them in alphabetical order into a nice descriptive sentence. If there are multiple ingredients, add the word 'Fusion' to the end but otherwise, add 'Smoothie'. Remember to change '-berries to '-berry'. See the examples below.

Ingredient	Price
Strawberries	$1.50
Banana	$0.50
Mango	$2.50
Blueberries	$1.00
Raspberries	$1.00
Apples	$1.75
Pineapple	$3.50
Examples

s1 = new Smoothie(["Banana"])

s1.ingredients ➞ ["Banana"]

s1.getCost() ➞ "$0.50"

s1.getPrice() ➞ "$1.25"

s1.getName() ➞ "Banana Smoothie"

s2 = Smoothie(["Raspberries", "Strawberries", "Blueberries"])

s2.ingredients ➞ ["Raspberries", "Strawberries", "Blueberries"]

s2.getCost() ➞ "$3.50"

s2.getPrice() ➞ "$8.75"

s2.getName() ➞ "Blueberry Raspberry Strawberry Fusion"

*/

package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	s1 := NewSmoothie([]string{"Banana"})
	s2 := NewSmoothie([]string{"Raspberries", "Strawberries", "Blueberries"})
	s3 := NewSmoothie([]string{"Mango", "Apple", "Pineapple"})
	s4 := NewSmoothie([]string{"Pineapple", "Strawberries", "Blueberries", "Mango"})
	s5 := NewSmoothie([]string{"Blueberries"})

	fmt.Println(s1.Ingredients)
	fmt.Println(s1.Cost())
	fmt.Println(s1.Price())
	fmt.Println(s1.Name())

	fmt.Println(s2.Ingredients)
	fmt.Println(s2.Cost())
	fmt.Println(s2.Price())
	fmt.Println(s2.Name())

	fmt.Println(s3.Ingredients)
	fmt.Println(s3.Cost())
	fmt.Println(s3.Price())
	fmt.Println(s3.Name())

	fmt.Println(s4.Ingredients)
	fmt.Println(s4.Cost())
	fmt.Println(s4.Price())
	fmt.Println(s4.Name())

	fmt.Println(s5.Ingredients)
	fmt.Println(s5.Cost())
	fmt.Println(s5.Price())
	fmt.Println(s5.Name())
}

type Smoothie struct {
	Ingredients []string
}

func NewSmoothie(ingredients []string) *Smoothie {
	return &Smoothie{
		Ingredients: ingredients,
	}
}

func (c *Smoothie) calc() float64 {
	m := map[string]float64{
		"Strawberries": 1.50,
		"Banana":       0.50,
		"Mango":        2.50,
		"Blueberries":  1.00,
		"Raspberries":  1.00,
		"Apple":        1.75,
		"Pineapple":    3.50,
	}

	p := 0.0
	for _, s := range c.Ingredients {
		p += m[s]
	}
	return p
}

func (c *Smoothie) Cost() string {
	return fmt.Sprintf("$%.2f", c.calc())
}

func (c *Smoothie) Price() string {
	p := c.calc()
	return fmt.Sprintf("$%.2f", p+p*1.5)
}

func (c *Smoothie) Name() string {
	var s []string
	for _, p := range c.Ingredients {
		s = append(s, p)
	}
	sort.Strings(s)

	n := ""
	for _, r := range s {
		r = strings.Replace(r, "berries", "berry", -1)
		n += r + " "
	}

	if len(s) < 2 {
		n += "Smoothie"
	} else {
		n += "Fusion"
	}
	return n
}
