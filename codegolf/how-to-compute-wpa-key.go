/*

WPA2, the actual encryption standard that secures all modern wifi networks, has been cracked...
This challenge has nothing to do with the way that the WPA2 was cracked, however is is about computing the 64-digit hexadecimal key that corresponds to a given WPA-PSK pass-phrase.

A wireless network with WPA-PSK encryption requires a pass-phrase to be entered to get access to the network. Most wireless drivers accept the pass-phrase as a string of at most 63 characters, and internally convert the pass-phrase to a 256-bit key. However, some systems also allow the key to be entered directly in the form of 64 hexadecimal digits. So the challenge is to calculate the 64-digit hexadecimal key that corresponds to a given pass-phrase.

The hexadecimal key is computed from the pass-phrase and the network SSID (an SSID is a unique ID that consists of 32 characters).

Details of the calculation

For WPA-PSK encryption, the binary key is derived from the pass-phrase according to the following formula: Key = PBKDF2(pass-phrase, SSID, 4096, 256)

The function PBKDF2 is a standardized method to derive a key from a pass-phrase. It is specified in RFC2898 with a clear explanation on how to compute it.
The function needs an underlying pseudo-random function. In the case of WPA, the underlying function is HMAC-SHA1.

SHA1 is a function that computes a 160-bit hash from an arbitrary amount of input data. It is clearly explained in RFC3174. HMAC is a standardized method to turn a cryptographic hash function into a keyed message authentication function. It is specified in RFC2104.

To summarize, the key derivation process involves iterating a HMAC-SHA1 function 4096 times, and then doing that again to produce more key bits.

Inputs

    SSID a string of at most 32 characters (e.g. stackexchange)
    pass-phrase a string of at most 63 characters (e.g. <ra(<@2tAc<$)

Output any reasonable output of the 64 hexadecimal digits

    e.g. 24343f69e98d3c08236a6db407584227cf2d1222b050e48f0cf25dee6563cd55
    it is the result of the previous inputs

This is code-golf, so please make your program as short as possible!

*/

package main

import (
	"crypto/sha1"
	"fmt"

	"golang.org/x/crypto/pbkdf2"
)

func main() {
	assert(gen("<ra(<@2tAc<$", "stackexchange") == "24343f69e98d3c08236a6db407584227cf2d1222b050e48f0cf25dee6563cd55")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(phrase, ssid string) string {
	dk := pbkdf2.Key([]byte(phrase), []byte(ssid), 4096, 32, sha1.New)
	return fmt.Sprintf("%x", dk)
}
