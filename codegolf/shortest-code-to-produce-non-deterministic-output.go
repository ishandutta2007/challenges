/*

You need to produce output that is non-deterministic.

In this case, this will be defined to mean that the output will not always be the same result.

Rules:

    A pseudo-random number generator that always has the same seed does not count.

    You can rely on the program being run at a different (unknown) time each execution.

    Your code's process id (if it's not fixed by the interpreter) can be assumed to be non-deterministic.

    You may rely on web-based randomness.

    Your code may not take non-empty input. Related meta post.

    The program is not required to halt, but the output must be displayed.

*/

package main

import (
	"crypto/rand"
	"encoding/binary"
	"fmt"
)

func main() {
	var b [8]byte
	rand.Read(b[:])
	fmt.Printf("%#x\n", binary.LittleEndian.Uint64(b[:]))
}
