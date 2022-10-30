/*

You need to write a simple software auditor for tracking employees entering and exiting your building using their access cards (each card uniquely identifies the employee holding the card).
Your software needs to look at the access log and determine if there are any anomalies. There are two types of anomalies your software should detect:

    a user entering the building when, according to the log, they are already supposed to be in the building

    a user exiting the building when, according to the log, they are not supposed to be in the building

When your software sees someone enter a building (even if it’s an anomaly), that person is assumed to be inside the building from that point on, until he exits.
Similarly, if your software sees someone exit the building (even if it’s an anomaly), that person is assumed to not be in the building from that point on, until he enters again. At the beginning of the log, everyone is assumed to be outside the building.

Input

Input starts with a number 1≤n≤1000 indicating the length of the log. This is followed by n lines, each line describing either an entry or exit by an employee.
Each description is of the form ‘entry name’ or ‘exit name’, where name is a string of up to 20 uppercase and/or lowercase characters (a-z).

Output

For each person’s entry or exit, print the name of the person, followed by entered or exited. If the action is anomalous, print (ANOMALY) afterward.

*/

package main

import "fmt"

func main() {
	audit([]string{
		"entry Abbey",
		"entry Abbey",
		"exit Abbey",
		"entry Tyrone",
		"exit Mason",
		"entry Demetra",
		"exit Latonya",
		"entry Idella",
	})
}

func audit(s []string) {
	m := make(map[string]bool)
	for _, v := range s {
		var (
			t, p string
			f    bool
		)

		n, _ := fmt.Sscanf(v, "%s %s", &t, &p)
		if n != 2 {
			continue
		}

		switch t {
		case "entry":
			fmt.Printf("%s entered", p)
			f, m[p] = m[p], true

		case "exit":
			fmt.Printf("%s exited", p)
			f, m[p] = !m[p], false

		default:
			continue
		}

		if f {
			fmt.Printf(" (ANOMALY)")
		}
		fmt.Printf("\n")
	}
}
