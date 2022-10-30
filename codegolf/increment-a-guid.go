/*

Inspired by a recent Daily WTF article...

Write a program or function that takes a GUID (string in the format XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX, where each X represents a hexadecimal digit), and outputs the GUID incremented by one.

Examples

>>> increment_guid('7f128bd4-b0ba-4597-8f35-3a2f2756dfbb')
'7f128bd4-b0ba-4597-8f35-3a2f2756dfbc'
>>> increment_guid('06b86883-f3e7-4f9d-87c5-a047e89a19fa')
'06b86883-f3e7-4f9d-87c5-a047e89a19fb'
>>> increment_guid('89f25f2f-2f7b-4aa6-b9d7-46a98e3cb2cf')
'89f25f2f-2f7b-4aa6-b9d7-46a98e3cb2d0'
>>> increment_guid('89f25f2f-2f7b-4aa6-b9d7-46a98e3cb29f')
'89f25f2f-2f7b-4aa6-b9d7-46a98e3cb2a0'
>>> increment_guid('8e0f9835-4086-406b-b7a4-532da46963ff')
'8e0f9835-4086-406b-b7a4-532da4696400'
>>> increment_guid('7f128bd4-b0ba-4597-ffff-ffffffffffff')
'7f128bd4-b0ba-4598-0000-000000000000'

Notes

    Unlike in the linked article, incrementing a GUID that ends in F must “carry” to the previous hex digit. See examples above.
    You may assume that the input will not be ffffffff-ffff-ffff-ffff-ffffffffffff.
    For hex digits above 9, you may use either upper (A-F) or lower (a-f) case.
    Yes, GUIDs may start with a 0.
    Your output must consist of exactly 32 hex digits and 4 hyphens in the expected format, including any necessary leading 0s.
    You do not have to preserve the version number or other fixed bits of the GUID. Assume it's just a 128-bit integer where none of the bits have any special meaning. Similarly, GUIDs are assumed to sort in straightforward lexicographical order rather than in the binary order of a Windows GUID struct.
    If writing a function, the input may be of any sequence-of-char data type: string, char[], List<char>, etc.

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	assert(incguid("7f128bd4-b0ba-4597-8f35-3a2f2756dfbb") == "7f128bd4-b0ba-4597-8f35-3a2f2756dfbc")
	assert(incguid("06b86883-f3e7-4f9d-87c5-a047e89a19fa") == "06b86883-f3e7-4f9d-87c5-a047e89a19fb")
	assert(incguid("89f25f2f-2f7b-4aa6-b9d7-46a98e3cb2cf") == "89f25f2f-2f7b-4aa6-b9d7-46a98e3cb2d0")
	assert(incguid("89f25f2f-2f7b-4aa6-b9d7-46a98e3cb29f") == "89f25f2f-2f7b-4aa6-b9d7-46a98e3cb2a0")
	assert(incguid("8e0f9835-4086-406b-b7a4-532da46963ff") == "8e0f9835-4086-406b-b7a4-532da4696400")
	assert(incguid("7f128bd4-b0ba-4597-ffff-ffffffffffff") == "7f128bd4-b0ba-4598-0000-000000000000")
	assert(incguid("ffffffff-ffff-ffff-ffff-ffffffffffff") == "00000000-0000-0000-0000-000000000000")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func incguid(s string) string {
	s = strings.Replace(s, "-", "", -1)

	x := new(big.Int)
	x.SetString(s, 16)
	x.Add(x, big.NewInt(1))

	p := fmt.Sprintf("%x", x)
	n := len(p)
	switch {
	case n < 32:
		p = strings.Repeat("0", 32-n) + p
	case n > 32:
		p = p[n-32:]
	}

	return fmt.Sprintf("%s-%s-%s-%s-%s", p[0:8], p[8:12], p[12:16], p[16:20], p[20:32])
}
