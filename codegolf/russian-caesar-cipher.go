/*

The objective

Given a Russian text, encrypt it with Caesar cipher with key 16.
The basic Cyrillic alphabets

The basic Cyrillic alphabets are: (U+0410 – U+042F)

АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ

By the Caesar cipher, they are mapped to:

РСТУФХЦЧШЩЪЫЬЭЮЯАБВГДЕЖЗИЙКЛМНОП

The small letters (U+0430 – U+044F) are also mapped likewise.

Note the absence of Ё.
Rules

    Ё (U+0401) and ё (U+0451) are not considered basic, and are mapped to Х̈ (U+0425 U+0308) and х̈ (U+0445 U+0308), respectively.

    Any other characters are preserved.

Example

The following sentence:

В чащах юга жил бы цитрус? Да, но фальшивый экземпляр!

Is encrypted to:

Т зрйре оур цшы сл жшвагб? Фр, эю дрымиштлщ нъчхьяыпа!

*/

package main

import (
	"bytes"
)

func main() {
	assert(encrypt("АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == "РСТУФХЦЧШЩЪЫЬЭЮЯАБВГДЕЖЗИЙКЛМНОП")
	assert(encrypt("В чащах юга жил бы цитрус? Да, но фальшивый экземпляр!") == "Т зрйре оур цшы сл жшвагб? Фр, эю дрымиштлщ нъчхьяыпа!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encrypt(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		w.WriteRune(rotru(r, 16))
	}
	return w.String()
}

func rotru(r, n rune) rune {
	switch {
	case r == 0x401:
		return 0x425
	case r == 0x451:
		return 0x308
	case 0x410 <= r && r <= 0x42f:
		return 0x410 + ((r - 0x410 + n) & 31)
	case 0x430 <= r && r <= 0x44f:
		return 0x430 + ((r - 0x430 + n) & 31)
	}
	return r
}
