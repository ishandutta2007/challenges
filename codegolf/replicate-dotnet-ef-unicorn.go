/*

.Net Technology is an incredible framework with marvellous functionalities, and among all of them, the most important one obviously stands out:

Console comand dotnet ef

Yep, your simple task is create a program that when it takes at input:

dotnet ef
It prints the following ascii art by output:

             /\__
       ---==/    \\
 ___  ___   |.    \|\
| __|| __|  |  )   \\\
| _| | _|   \_/ |  //|\\
|___||_|       /   \\\/\\
And you have to do it in the lowest number of bytes of course.

Rules

If the program doesn't receive dotnet ef by input it doesn't output anything
The program with the fewest bytes wins so this is a code golf challenge

*/

package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) != 2 || os.Args[1] != "ef" {
		return
	}
	fmt.Println(logo)
}

const logo = `
             /\__
       ---==/    \\
 ___  ___   |.    \|\
| __|| __|  |  )   \\\
| _| | _|   \_/ |  //|\\
|___||_|       /   \\\/\\
`
