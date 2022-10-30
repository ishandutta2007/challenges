/*

I want format a JSON string into human-readable form. A string like this:

'{"foo":"hello","bar":"world","c":[1,55,"bye"]}'

would be formatted as:

{
  "foo": "hello",
  "bar": "world",
  "c": [
    1,
    55,
    "bye"
  ]
}

Rules:

    For objects and arrays properties and items should be starting in new line with indent of +2 as you see in the above mentioned example.

    Space after colon is mandatory

    This is code-golf. Shortest code in bytes wins!

please be aware that json string should be part of the answer (but we will omit that from number of bytes, example:

echo '{"foo":"hello","bar":"world","c":[1,55,"bye"]}'|npx json

will be counted as 14 bytes => echo |npx json after omitting the string

*/

package main

import (
	"bytes"
	"encoding/json"
	"fmt"
)

func main() {
	fmt.Println(jsonfmt(`{"foo":"hello","bar":"world","c":[1,55,"bye"]}`))
}

func jsonfmt(s string) (string, error) {
	w := new(bytes.Buffer)
	err := json.Indent(w, []byte(s), "", "\t")
	if err != nil {
		return "", err
	}
	return w.String(), nil
}
