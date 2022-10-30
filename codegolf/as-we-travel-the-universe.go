/*

You'll be given the name of one of the 20 biggest objects in the Solar System. Your task is to return an approximation of its radius, expressed in kilometers.

This is a code-challenge where your score consists of the length of your code (in bytes) multiplied by a penalty ratio ≥1, based on your worst approximation. Therefore, the lowest score wins.

"As we travel the universe" is the last line of the song Planet Caravan by Black Sabbath, also later covered by Pantera.
The Solar System objects

Source: Wikipedia

NB: The rank is given for information only. The input is the name of the object.

  n | Object   | Radius (km)
----+----------+-------------
  1 | Sun      |   696342
  2 | Jupiter  |    69911
  3 | Saturn   |    58232
  4 | Uranus   |    25362
  5 | Neptune  |    24622
  6 | Earth    |     6371
  7 | Venus    |     6052
  8 | Mars     |     3390
  9 | Ganymede |     2634
 10 | Titan    |     2575
 11 | Mercury  |     2440
 12 | Callisto |     2410
 13 | Io       |     1822
 14 | Moon     |     1737
 15 | Europa   |     1561
 16 | Triton   |     1353
 17 | Pluto    |     1186
 18 | Eris     |     1163
 19 | Haumea   |      816
 20 | Titania  |      788

Or as copy-paste friendly lists:

'Sun', 'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Earth', 'Venus', 'Mars', 'Ganymede', 'Titan', 'Mercury', 'Callisto', 'Io', 'Moon', 'Europa', 'Triton', 'Pluto', 'Eris', 'Haumea', 'Titania'
696342, 69911, 58232, 25362, 24622, 6371, 6052, 3390, 2634, 2575, 2440, 2410, 1822, 1737, 1561, 1353, 1186, 1163, 816, 788

Your score

Let Rn be the expected radius of the nth object and let An be the answer of your program for this object.

Then your score is defined as:

S=⌈L×max1≤i≤20(max(AiRi,RiAi)2)⌉

where L is the length of your code in bytes.

Example:

If the size of your code is 100 bytes and your worst approximation is on the Moon with an estimated radius of 1000 km instead of 1737

km, then your score would be:

S=⌈100×(17371000)2⌉=302

The lower, the better.

Recommended header for your answer:

Language, 100 bytes, score = 302

You can use this script to compute your score (first line = code length, next 20 lines = your outputs, from Sun to Titania).
Rules

    You may take the name of the object in either full lowercase, full uppercase or exactly as described above (title case). Other mixed cases are not allowed.
    The input is guaranteed to be one of the 20 possible names.
    You may return either integers or floats. In both cases, the penalty must be computed directly with these values (not rounded values in case of floats).
    You must return positive values.
    Empty programs are not allowed.

*/

package main

import "fmt"

func main() {
	fmt.Println(radius("Sun"))
}

func radius(s string) int {
	m := map[string]int{
		"Sun":      696342,
		"Jupiter":  69911,
		"Saturn":   58232,
		"Uranus":   25362,
		"Neptune":  24622,
		"Earth":    6371,
		"Venus":    6052,
		"Mars":     3390,
		"Ganymede": 2634,
		"Titan":    2575,
		"Mercury":  2440,
		"Callisto": 2410,
		"Io":       1822,
		"Moon":     1737,
		"Europa":   1561,
		"Triton":   1353,
		"Pluto":    1186,
		"Eris":     1163,
		"Haumea":   816,
		"Titania":  788,
	}
	return m[s]
}
