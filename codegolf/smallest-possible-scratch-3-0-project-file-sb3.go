/*

The objective is to make the smallest SB3 file that can simply be imported into Scratch 3.0 without a "The project file that was selected failed to load" error.
Any means can be used, like editing the JSON or better compression.
Here's where I am with project.json, the only file inside mine:

{"targets":[{"isStage":true,"name":"Stage","variables":{},"lists":{},"broadcasts":{},"blocks":{},"comments":{},"costumes":[{"assetId":"00000000000000000000000000000000","name":"","md5ext":"00000000000000000000000000000000.svg","dataFormat":"svg"}],"sounds":[]}],"meta":{"semver":"3.0.0","vm":"0.0.0"}}

*/

package main

import "fmt"

func main() {
	fmt.Println(text)
}

const text = `{"targets":[{"isStage":true,"name":"Stage","variables":{},"lists":{},"broadcasts":{},"blocks":{},"comments":{},"costumes":[{"assetId":"00000000000000000000000000000000","name":"","md5ext":"00000000000000000000000000000000.svg","dataFormat":"svg"}],"sounds":[]}],"meta":{"semver":"3.0.0","vm":"0.0.0"}}`
