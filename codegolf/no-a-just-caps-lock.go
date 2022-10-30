/*

What happens when the CapsLock key on your keyboard doesn't have a notch in it?

"This hPPENS."

The goal of this program is to consistently emulate keyboard misses where each A press is replaced with CapsLock. Uppercase 'A's from the source should yield the same effect. When CapsLock is enabled, capitalization is reversed.

Test Cases

"The quick brown fox jumps over the lazy dog."
-> "The quick brown fox jumps over the lZY DOG."

"Compilation finished successfully."
-> "CompilTION FINISHED SUCCESSFULLY."

"What happens when the CapsLock key on your keyboard doesn't have a notch in it?"
-> "WhT Hppens when the CPSlOCK KEY ON YOUR KEYBOrd doesn't hVE  notch in it?"

"The end of the institution, maintenance, and administration of government, is to secure the existence of the body politic, to protect it, and to furnish the individuals who compose it with the power of enjoying in safety and tranquillity their natural rights, and the blessings of life: and whenever these great objects are not obtained, the people have a right to alter the government, and to take measures necessary for their safety, prosperity and happiness."
-> "The end of the institution, mINTENnce, ND dministrTION OF GOVERNMENT, IS TO SECURE THE EXISTENCE OF THE BODY POLITIC, TO PROTECT IT, nd to furnish the individuLS WHO COMPOSE IT WITH THE POWER OF ENJOYING IN Sfety ND TRnquillity their nTURl rights, ND THE BLESSINGS OF LIFE: nd whenever these greT OBJECTS re not obtINED, THE PEOPLE Hve  RIGHT TO lter the government, ND TO Tke meSURES NECESSry for their sFETY, PROSPERITY nd hPPINESS."

"aAaaaaAaaaAAaAa"
-> "" (Without the notch, no one can hear you scream)

"CapsLock locks cAPSlOCK"
-> "CPSlOCK LOCKS CPSlOCK"

"wHAT IF cAPSlOCK IS ALREADY ON?"
-> "wHt if CPSlOCK IS lreDY ON?"

The winning criterion is, as usual, the size of the submitted program's source code.


*/

package main

import (
	"bytes"
	"unicode"
)

func main() {
	assert(notched("The quick brown fox jumps over the lazy dog.") == "The quick brown fox jumps over the lZY DOG.")
	assert(notched("Compilation finished successfully.") == "CompilTION FINISHED SUCCESSFULLY.")
	assert(notched("What happens when the CapsLock key on your keyboard doesn't have a notch in it?") == "WhT Hppens when the CPSlOCK KEY ON YOUR KEYBOrd doesn't hVE  notch in it?")
	assert(notched("The end of the institution, maintenance, and administration of government, is to secure the existence of the body politic, to protect it, and to furnish the individuals who compose it with the power of enjoying in safety and tranquillity their natural rights, and the blessings of life: and whenever these great objects are not obtained, the people have a right to alter the government, and to take measures necessary for their safety, prosperity and happiness.") == "The end of the institution, mINTENnce, ND dministrTION OF GOVERNMENT, IS TO SECURE THE EXISTENCE OF THE BODY POLITIC, TO PROTECT IT, nd to furnish the individuLS WHO COMPOSE IT WITH THE POWER OF ENJOYING IN Sfety ND TRnquillity their nTURl rights, ND THE BLESSINGS OF LIFE: nd whenever these greT OBJECTS re not obtINED, THE PEOPLE Hve  RIGHT TO lter the government, ND TO Tke meSURES NECESSry for their sFETY, PROSPERITY nd hPPINESS.")
	assert(notched("aAaaaaAaaaAAaAa") == "")
	assert(notched("CapsLock locks cAPSlOCK") == "CPSlOCK LOCKS CPSlOCK")
	assert(notched("wHAT IF cAPSlOCK IS ALREADY ON?") == "wHt if CPSlOCK IS lreDY ON?")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func notched(s string) string {
	w := new(bytes.Buffer)
	f := false
	for _, r := range s {
		if r == 'A' || r == 'a' {
			f = !f
		} else {
			w.WriteRune(char(f, r))
		}
	}
	return w.String()
}

func char(f bool, r rune) rune {
	if !f {
		return r
	}

	switch {
	case unicode.IsUpper(r):
		r = unicode.ToLower(r)
	case unicode.IsLower(r):
		r = unicode.ToUpper(r)
	}
	return r
}
