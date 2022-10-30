/*

You are programming a cup stacking module for your robot. This robot is equiped with several sensors that can accurately determine the radius and color of a cup.
The problem is that there is a glitch in the robot’s core routine that processess sensor inputs so the radius is doubled, if the result of the color sensor arrives to the routine after the radius.

For instance, for a red cup with a radius of 5 units, your module will receive either “red 5” or “10 red” message.

Given a list of messages from the core routine, each describing a different cup, can you put the cups in order of the smallest to the largest?

Input

The first line of the input file contains an integer N, the number of cups (1≤N≤20). Next N lines will contain two tokens each, either as “color radius” or “diameter color”.
The radius of a cup R will be a positive integer less than 1000. The color of a cup C will be a non-empty string of lower case English letters of length at most 20.
All cups will be different in both size and color.

Output

Output colors of cups, one color per line, in order of increasing radius.

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(cups([]string{
		"red 10",
		"10 blue",
		"green 7",
	}))
}

func cups(s []string) []cup {
	var (
		p []cup
		c cup
	)
	for _, t := range s {
		n, _ := fmt.Sscanf(t, "%s %d", &c.name, &c.radius)
		if n != 2 {
			n, _ = fmt.Sscanf(t, "%d %s", &c.radius, &c.name)
			c.radius /= 2
		}
		if n != 2 {
			continue
		}

		p = append(p, c)
	}

	sort.Slice(p, func(i, j int) bool {
		if p[i].radius == p[j].radius {
			return p[i].name < p[j].name
		}
		return p[i].radius < p[j].radius
	})

	return p
}

type cup struct {
	name   string
	radius int
}
