/*

You have two arrays. One shows the names of the people names, while the other shows their occupation jobs.
Your task is to create an object displaying each person to their respective occupation.

Names	Jobs
Annie	Teacher
Steven	Engineer
Lisa	Doctor
Osman	Cashier
Example

const names = ["Dennis", "Vera", "Mabel", "Annette", "Sussan"]
const jobs = ["Butcher", "Programmer", "Doctor", "Teacher", "Lecturer"]

assignPersonToJob(names, jobs) ➞ {
  Dennis: "Butcher",
  Vera: "Programmer",
  Mabel: "Doctor",
  Annette: "Teacher",
  Sussan: "Lecturer"
}

Notes

    The two arrays have the same length.
    The index of a name in the names array is the same as the index of the person's job in the jobs array, as shown in the table above.
    Check Resources for some useful information that can help with this challenge.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	names1 := []string{"Annie", "Steven", "Lisa", "Osman"}
	jobs1 := []string{"Teacher", "Engineer", "Doctor", "Cashier"}
	res1 := map[string]string{
		"Annie":  "Teacher",
		"Steven": "Engineer",
		"Lisa":   "Doctor",
		"Osman":  "Cashier",
	}

	names2 := []string{"Victor", "Paul", "Eddie"}
	jobs2 := []string{"Vet", "Nurse", "Web Developer"}
	res2 := map[string]string{
		"Victor": "Vet",
		"Paul":   "Nurse",
		"Eddie":  "Web Developer",
	}

	names3 := []string{"Dennis", "Vera", "Mabel", "Annette", "Sussan"}
	jobs3 := []string{"Butcher", "Programmer", "Doctor", "Teacher", "Lecturer"}
	res3 := map[string]string{
		"Dennis":  "Butcher",
		"Vera":    "Programmer",
		"Mabel":   "Doctor",
		"Annette": "Teacher",
		"Sussan":  "Lecturer",
	}

	test(names1, jobs1, res1)
	test(names2, jobs2, res2)
	test(names3, jobs3, res3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(names, jobs []string, res map[string]string) {
	db := assign(names, jobs)
	fmt.Println(db)
	assert(reflect.DeepEqual(db, res))
}

func assign(names, jobs []string) map[string]string {
	if len(names) != len(jobs) {
		return nil
	}

	db := make(map[string]string)
	for i := range names {
		db[names[i]] = jobs[i]
	}
	return db
}
