/*

The domain server requires that all employees have a strong, random password conforming to the following rules:

    Exactly 15 characters long.
    Keyboard-typeable characters only (as shown in code-type below). Teaching the sales to use ALT+NUMPAD codes is not permitted.
    At least 1 lower case letter: abcdefghijklmnopqrstuvwxyz
    At least 1 upper case letter: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    At least 1 numeric digit: 0123456789
    At least 1 symbol: `~!@#$%^&*()_+-={}|[]\:";'<>?,./

For this purpose IT have commissioned and will be distributing a Random Password Generator to all employees.
All employees will be required to use the Random Password Generator.
The requirements for the Random Password Generator are, in addition to the password restrictions above:

    It must be able to generate all permutations of all allowable characters.
    It must display the generated password on the screen.
    The code is required to be as small as possible (in bytes).

Please submit your proposed solution within the next week.

*/

package main

import (
	"bytes"
	"crypto/rand"
	"fmt"
	"math/big"
)

func main() {
	for i := 0; i < 50; i++ {
		fmt.Println(gen(15))
	}
}

func gen(n int) string {
	tab := []string{
		"abcdefghijklmnopqrstuvwxyz",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"0123456789",
		"`~!@#$%^&*()_+-={}|[]\\:\";'<>?,./",
	}

	w := new(bytes.Buffer)
	f := uint(0)
	for i := 0; i < n; {
		n := len(tab)
		j := randn(n)
		if f&(1<<j) == 0 || f == (1<<n)-1 {
			k := randn(len(tab[j]))
			w.WriteByte(tab[j][k])
			f, i = f|(1<<j), i+1
		}
	}
	return w.String()
}

func randn(n int) int {
	i, err := rand.Int(rand.Reader, big.NewInt(int64(n)))
	if err != nil {
		panic(err)
	}
	return int(i.Int64())
}
