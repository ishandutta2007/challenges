/*

Task

The input consists of a JSON object, where every value is an object (eventually empty), representing a directory structure. The output must be a list of the corresponding root-to-leaf paths.

Inspired by this comment on StackOverflow.

Input specifications
You can assume that that the input always contains a JSON object.
The input can be a empty JSON object ({}); in this case the output must be a empty list.
You can assume that the names/keys contain only printable ASCII characters, and they do not contain \0, \, /, ", ', nor `.
You can assume each JSON object does not contain duplicate names/keys.

Input format
The input can be:
a string;
a dictionary or an associative array in a language of your choice;
a list or array of tuples, where each tuples contains the name/key and the value (which is itself a list of tuples).
Output specifications
There is no need to escape any character.
You can use as directory separator either / or \, but you cannot have a mixed use of both (e.g. a/b/c and a\b\c are both valid, but a/b\c and a\b/c are not).
Each path can have a leading and/or trailing directory separator (e.g. a/b, /a/b, a/b/, and /a/b/ are equally valid).
If you output a newline-separated list, the output can have a trailing newline.
The paths must be in the same order of the input.

Test cases

Input 1:

{
    "animal": {
        "cat": {"Persian": {}, "British_Shorthair": {}},
        "dog": {"Pug": {}, "Pitbull": {}}
    },
    "vehicle": {
        "car": {"Mercedes": {}, "BMW": {}}
    }
}

Output 1:

animal/cat/Persian
animal/cat/British_Shorthair
animal/dog/Pug
animal/dog/Pitbull
vehicle/car/Mercedes
vehicle/car/BMW

Input 2

{
    "bin": {
        "ls": {}
    },
    "home": {},
    "usr": {
        "bin": {
            "ls": {}
        },
        "include": {
            "sys": {}
        },
        "share": {}
    }
}

Output 2:

/bin/ls
/home
/usr/bin/ls
/usr/include/sys
/usr/share

*/

package main

import (
	"encoding/json"
	"fmt"
	"log"
	"path"
	"sort"
)

func main() {
	test(data1)
	test(data2)
}

func test(data string) {
	fmt.Printf("%s\n", data)
	paths, err := convert(data)
	if err != nil {
		log.Fatal(err)
	}
	for _, path := range paths {
		fmt.Println(path)
	}
}

func convert(data string) (paths []string, err error) {
	var root object
	err = json.Unmarshal([]byte(data), &root)
	if err != nil {
		return
	}

	walk(&paths, root, "")
	sort.Strings(paths)
	return
}

func walk(result *[]string, object object, name string) {
	if len(object) == 0 {
		if name != "" {
			*result = append(*result, name)
			return
		}
	}

	for label, child := range object {
		nextname := path.Join(name, label)
		walk(result, child, nextname)
	}
}

type object map[string]object

const data1 = `
{
    "animal": {
        "cat": {"Persian": {}, "British_Shorthair": {}},
        "dog": {"Pug": {}, "Pitbull": {}}
    },
    "vehicle": {
        "car": {"Mercedes": {}, "BMW": {}}
    }
}
`

const data2 = `
{
    "bin": {
        "ls": {}
    },
    "home": {},
    "usr": {
        "bin": {
            "ls": {}
        },
        "include": {
            "sys": {}
        },
        "share": {}
    }
}
`
