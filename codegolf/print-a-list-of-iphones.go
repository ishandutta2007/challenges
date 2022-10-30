/*

Write the shortest program that prints, in order, a complete list of iPhone iterations, according to this site:

iPhone
iPhone 3G
iPhone 3GS
iPhone 4
iPhone 4S
iPhone 5
iPhone 5c
iPhone 5s
iPhone 6
iPhone 6 Plus
iPhone 6s
iPhone 6s Plus
iPhone SE
iPhone 7
iPhone 7 Plus
iPhone 8
iPhone 8 Plus
iPhone X
iPhone XR
iPhone XS
iPhone XS Max
iPhone 11
iPhone 11 Pro
iPhone 11 Pro Max
Output should be printed exactly as specified, though trailing newlines are allowed (as well as additional whitespace at the end of each line).

This is code golf, so the shortest answer in bytes, per language, wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(MODELS)
}

const MODELS = `iPhone
iPhone 3G
iPhone 3GS
iPhone 4
iPhone 4S
iPhone 5
iPhone 5c
iPhone 5s
iPhone 6
iPhone 6 Plus
iPhone 6s
iPhone 6s Plus
iPhone SE
iPhone 7
iPhone 7 Plus
iPhone 8
iPhone 8 Plus
iPhone X
iPhone XR
iPhone XS
iPhone XS Max
iPhone 11
iPhone 11 Pro
iPhone 11 Pro Max`
