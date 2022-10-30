/*

Write a program that determines whether its input is valid JSON.

    Input: ASCII text: [\x00-\x7F]*

    Note: if ASCII is problematic, feel free to use another encoding, but indicate it in your post.

    Output: Valid or Invalid. Trailing newline may be omitted.

    Example:

    $ echo '{"key": "value"}' | ./json-validate
    Valid
    $ echo '{key: "value"}' | ./json-validate
    Invalid

    Rules:
        Do not use a JSON parsing library.
        Partially-correct solutions are allowed, but frowned upon.
        Post your test suite score (see below).

The shortest correct solution wins.

Please run json-validate-test-suite.sh on your program, and post your score. Example:

$ ./json-validate-test-suite.sh ./buggy-prog
fail: should be invalid:  [ 0.1e ]
fail: should be invalid:  [ 0.1e+-1 ]
fail: should be invalid:  [ 0.1e-+1 ]
score: 297/300

Resources:

    json.org - Concise definition of the JSON grammar with easy-to-follow pictures.
    RFC 4627 - JSON specification
    json-validate.c - A 200-line implementation that passes the testsuite.

The JSON grammar is as follows:

json: object | array

object: '{' members? '}'
    members: pair (',' pair)*
    pair:    string ':' value

array: '[' elements? ']'
    elements: value (',' value)*

value: string
     | number
     | object
     | array
     | 'true'
     | 'false'
     | 'null'

string: '"' char* '"'
    char: [^"\\\x00-\x1F]
        | '\' escape
    escape: ["\\/bfnrt]
          | u [0-9A-Fa-f]{4}

number: '-'? (0 | [1-9][0-9]*) ('.' [0-9]+)? ([Ee] [+-]? [0-9]+)?

Also, whitespace can appear before or after any of the six structural characters {}[]:,

ws = [\t\n\r ]*

Bear in mind the following:

    Be careful with functions like isspace(). Whitespace in JSON is [\t\n\r ], but isspace() also treats \v (vertical tab) and \f (form feed) as space. Although word has it that isdigit() can accept more than just [0-9], should be okay to use here, as we assume input is in ASCII.
    \x7F is technically a control character, but the JSON RFC doesn't mention it (it only mentions [\x00-\x1F]), and most JSON parsers tend to accept \x7F characters in strings. Because of this ambiguity, solutions may choose to either accept them or not.

*/

package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"os"
)

func main() {
	buf, err := io.ReadAll(os.Stdin)
	if err != nil {
		log.Fatal(err)
	}

	if json.Valid(buf) {
		fmt.Println("Valid")
	} else {
		fmt.Println("Invalid")
	}
}
