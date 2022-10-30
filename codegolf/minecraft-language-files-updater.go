/*

In 1.13, Minecraft language files were switched from being a simple multi-line key=value format to JSON.

Challenge
Write a program converting from the original format returning a JSON string. Input can be taken using any standard input method, output must be json from any standard output method

The original format contains lines with key=value pairs, for example

tile.dirt.name=Dirt
advMode.nearestPlayer=Use "@p" to target nearest player

build.tooHigh=Height limit for building is %s blocks
Should be converted to one large JSON object with key=value

{
    "tile.dirt.name": "Dirt",
    "advMode.nearestPlayer": "Use \"@p\" to target nearest player",
    "build.tooHigh": "Height limit for building is %s blocks"
}
Some details
Any valid JSON is allowed as long as it contains only the correct key/value pairs. Trailing commas are allowed because Minecraft allows them.
The only things that must be escaped are quotes. (No newlines, backslashes, or other json-breaking things existed in the language file prior to 1.13)
Empty lines should be ignored
Lines contain exactly one equals
Test Cases
Input:

tile.dirt.name=Dirt
advMode.nearestPlayer=Use "@p" to target nearest player

build.tooHigh=Height limit for building is %s blocks
Output:

{
    "tile.dirt.name": "Dirt",
    "advMode.nearestPlayer": "Use \"@p\" to target nearest player",
    "build.tooHigh": "Height limit for building is %s blocks"
}
Input:

translation.test.none=Hello, world!
translation.test.complex=Prefix, %s%2$s again %s and %1$s lastly %s and also %1$s again!
translation.test.escape=%%s %%%s %%%%s %%%%%s
translation.test.invalid=hi %
translation.test.invalid2=hi %  s
translation.test.args=%s %s
translation.test.world=world
Output:

{
  "translation.test.none": "Hello, world!",
  "translation.test.complex": "Prefix, %s%2$s again %s and %1$s lastly %s and also %1$s again!",
  "translation.test.escape": "%%s %%%s %%%%s %%%%%s",
  "translation.test.invalid": "hi %",
  "translation.test.invalid2": "hi %  s",
  "translation.test.args": "%s %s",
  "translation.test.world": "world",
}
Input:

stat.mineBlock=%1$s Mined
stat.craftItem=%1$s Crafted
stat.useItem=%1$s Used
stat.breakItem=%1$s Depleted
Output:

{
    "stat.mineBlock": "%1$s Mined",
    "stat.craftItem": "%1$s Crafted",
    "stat.useItem": "%1$s Used",
    "stat.breakItem": "%1$s Depleted"
}

*/

package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"strings"
)

func main() {
	fmt.Println(kv2json(cfg1))
	fmt.Println(kv2json(cfg2))
	fmt.Println(kv2json(cfg3))
}

func kv2json(s string) (string, error) {
	m := make(map[string]string)
	r := bufio.NewScanner(strings.NewReader(s))
	for n := 1; r.Scan(); n++ {
		s := strings.TrimSpace(r.Text())
		if s == "" {
			continue
		}

		t := strings.Split(s, "=")
		if len(t) != 2 {
			return "", fmt.Errorf("error on line %d", n)
		}
		for i := range t {
			t[i] = strings.TrimSpace(t[i])
		}
		m[t[0]] = t[1]
	}

	b, err := json.MarshalIndent(m, "", "\t")
	if err != nil {
		return "", err
	}
	return string(b), nil
}

const cfg1 = `
tile.dirt.name=Dirt
advMode.nearestPlayer=Use "@p" to target nearest player

build.tooHigh=Height limit for building is %s blocks
`

const cfg2 = `
translation.test.none=Hello, world!
translation.test.complex=Prefix, %s%2$s again %s and %1$s lastly %s and also %1$s again!
translation.test.escape=%%s %%%s %%%%s %%%%%s
translation.test.invalid=hi %
translation.test.invalid2=hi %  s
translation.test.args=%s %s
translation.test.world=world
`

const cfg3 = `
stat.mineBlock=%1$s Mined
stat.craftItem=%1$s Crafted
stat.useItem=%1$s Used
stat.breakItem=%1$s Depleted
`
