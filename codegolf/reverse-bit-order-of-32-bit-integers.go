/*

Write the shortest code to reverse the bit order of a 32-bit integer.

Rules:

    Input is assumed to be a valid integer or string equivalent if your language doesn't support numerical values (e.g. Windows Batch).
    Output must be a valid integer or string equivalent if your language doesn't support numerical values (e.g. Windows Batch).
    Standard library only.
    It may be a function or a complete program.
    Input may be either from stdin or as a function argument.
    Output must be either stdout or as a returned value.
    If your language has a built-in or standard library function that does this in one step (e.g. rbit in ARM assembly), that cannot be used.

Examples:

Key:

    decimal
        binary
        (reverse)
        reversed binary
        decimal output

Examples:

    -90 (8-bit example for demonstration)
        10100110b
        (reverse)
        01100101b
        101

    486
        00000000000000000000000111100110b
        (reverse)
        01100111100000000000000000000000b
        1736441856

    -984802906
        11000101010011010001100110100110b
        (reverse)
        01100101100110001011001010100011b
        1704506019

Note: Omissions are free game. If I didn't say it, and it's not one of the standard loopholes, then it's completely allowed.

*/

package main

func main() {
	assert(rev32(486) == 1736441856)
	assert(rev32(-984802906) == 1704506019)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://graphics.stanford.edu/~seander/bithacks.html
func rev32(x int32) int32 {
	v := uint32(x)
	v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1)
	v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2)
	v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4)
	v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8)
	v = (v >> 16) | (v << 16)
	return int32(v)
}
