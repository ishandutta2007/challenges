/*

Given a string containing the English word for one of the single-digit numbers, return the number without using any of the words in your code. Examples:

eng_to_dec('zero') # => 0
eng_to_dec('four') # => 4

Note: there is no right or wrong way to complete this challenge. Be creative with your solutions!

Thanks to HazierPhonics for posting this idea on r/dailyprogrammer_ideas! If you have a problem that you think would be good for us, head over there and contribute!

*/

package main

import (
	"crypto/sha512"
	"fmt"
)

func main() {
	tab := []string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
	for i, s := range tab {
		assert(digit(s) == i)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func digit(s string) int {
	m := map[string]int{
		"2dc48a941c39b33a018574c517260c7887c7ba528c4ad68d7b792c4b2037a0ceb0f8d8c166d4a9f2d0b92ec0246df0a2f936a9f6e9da2e03a37cc9600abc3c7b": 0,
		"05f70341078acf6a06d423d21720f9643d5f953626d88a02636dc3a9e79582aeb0c820857fd3f8dc502aa8360d2c8fa97a985fda5b629b809cad18ffb62d3899": 1,
		"928d50d1e24dab7cca62cfe84fcdcf9fc695160a278f91b5c0af22b709d82f8aa3b4955b3de9ba6d0a0eb7d932dc64c4d5c63fc2de87441ad2e5b929f9b67c5e": 2,
		"62758e4a57b76feb1fc878387c4d2639e4bfbded06afb5f22227835d9fc63bfbd30df34447ae21ece6b1659c0abebd716f350e81c3439a3799172dca9b05f78f": 3,
		"39a52bfc3af78ae6cb5a2c110014a610134bb7c3d67678a5bee8b5ab86a733509fe50a69d0d4d5e8a84eef546713d6334f1d5207112f1140de025e6b77413d32": 4,
		"71471f1accd118982f790f9503c368c72914b099b69a5333579dc8edb4378080fba9e67707c276a179301ead88b70cf618fb015fe62272c1d5580a31e844cefa": 5,
		"6c02bea31ac9996e6da800d38796ec5278b6dd151dd53d30fcc3333f26c49f97c54dae012cb57eab95d6831def50694505bb617b127621a4d09fa7fbc4b52b6d": 6,
		"35ad15b2d691a1f51ce3fc7205e31dc0632587d910952c9e3cd4bef9340d1919b2778841b0e72ae22228d50967595f0e8a0fa5cadb6c80a4981cb9d47b536898": 7,
		"b26ca1695872a06fc11268e609464dff4b98377a81a7513b05187b90d3f314ba3b74c7d3aa70a8865267bd2454322c4d64179e6400ecde2c27eeca5671a8e69c": 8,
		"aa84334bdf3487c9fcb3f6cffb9425aa234c52b3dc3e1626d40972911c2c1dde69504ecda7f08bae5ee86ca028eb1e560bf0870b8779d0a01421050f4198135d": 9,
	}

	k := fmt.Sprintf("%x", sha512.Sum512([]byte(s)))
	if v, f := m[k]; f {
		return v
	}
	return -1
}
