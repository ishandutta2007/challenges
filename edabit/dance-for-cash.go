/*

Your local bank has decided to upgrade its ATM machines by incorporating motion sensor technology. The machines now interpret a series of consecutive dance moves in place of a PIN number.

Create a program that converts a customer's PIN number to its dance equivalent. There is one dance move per digit in the PIN number. A list of dance moves is given in the code.
Examples

danceConvert("0000") ➞ ["Shimmy", "Shake", "Pirouette", "Slide"]

danceConvert("3856") ➞ [ "Slide", "Arabesque", "Pop", "Arabesque" ]

danceConvert("9999") ➞ [ "Arabesque", "Shimmy", "Shake", "Pirouette" ]

danceConvert("32a1") ➞ ["Invalid input."]

Notes

    Each dance move will be selected from a list by index based on the current digit's value plus that digit's index value. If this value is greater than the last index value of the dance list, it should cycle to the beginning of the list.
    Valid input will always be a string of four digits. Output will be a string array.
    If the input is not four valid numbers, return the array with a single element: "Invalid input."

*/

package main

func main() {
	eq(danceconv("0000"), []string{"Shimmy", "Shake", "Pirouette", "Slide"})
	eq(danceconv("3856"), []string{"Slide", "Arabesque", "Pop", "Arabesque"})
	eq(danceconv("9999"), []string{"Arabesque", "Shimmy", "Shake", "Pirouette"})
	eq(danceconv("32a1"), []string{"Invalid input."})
	eq(danceconv("5555"), []string{"Headspin", "Dosado", "Pop", "Lock"})
	eq(danceconv("8888"), []string{"Lock", "Arabesque", "Shimmy", "Shake"})
	eq(danceconv("0123"), []string{"Shimmy", "Pirouette", "Box Step", "Dosado"})
	eq(danceconv("8765"), []string{"Lock", "Lock", "Lock", "Lock"})
	eq(danceconv("9104"), []string{"Arabesque", "Pirouette", "Pirouette", "Pop"})
	eq(danceconv("3619"), []string{"Slide", "Pop", "Slide", "Pirouette"})
	eq(danceconv("9742"), []string{"Arabesque", "Lock", "Dosado", "Headspin"})
	eq(danceconv("a95f"), []string{"Invalid input."})
	eq(danceconv("834"), []string{"Invalid input."})
	eq(danceconv("+493"), []string{"Invalid input."})
	eq(danceconv("-324"), []string{"Invalid input."})
}

func danceconv(s string) []string {
	tab := []string{
		"Shimmy", "Shake", "Pirouette", "Slide", "Box Step",
		"Headspin", "Dosado", "Pop", "Lock", "Arabesque",
	}
	err := []string{"Invalid input."}

	var p []string
	for i, r := range s {
		if !('0' <= r && r <= '9') {
			return err
		}
		j := (i + int(r) - '0') % len(tab)
		p = append(p, tab[j])
	}
	if len(p) != 4 {
		return err
	}
	return p
}

func eq(s, t []string) {
	assert(len(s) == len(t))
	for i := range s {
		assert(s[i] == t[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
