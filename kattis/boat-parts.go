/*

Boating season is over for this year, and Theseus has parked his boat on land. Of course, the boat looks nothing like it did as of the beginning of the season; it never does.
You see, Theseus is constantly looking for ways to improve his boat.

At every day of the boating season, Theseus bought exactly one type of item at his local supply store, and replaced the existing part on his boat with it.
Now, as the season has ended, Theseus wonders what day he replaced all the parts from the previous season.

Input

The first line of the input consists of two space-separated integers P
and N, representing the number of parts the boat consists of, and the number of days in the boating season respectively.
Then follows N lines, each line has a single word wi, the type of boat part that Theseus bought on day i.

Output

Output the day Theseus ended up replacing the last existing part from the previous season, or paradox avoided if Theseus never ended up replacing all the different parts.

Limits

    1≤P≤N≤1000.

Each word w[i] will consist only of the letters a–z and _ (underscore).
Each word w[i] will be between 1 and 20 characters long.
The number of distinct w[i] will be at most P.

*/

package main

func main() {
	assert(boating(3, 5, []string{"left_oar", "right_oar", "left_oar", "hull", "right_oar"}) == 4)
	assert(boating(4, 5, []string{"motor", "hull", "left_oar", "hull", "motor"}) == "paradox avoided")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func boating(p, n int, a []string) interface{} {
	m := make(map[string]bool)
	for i, v := range a {
		if i >= n {
			break
		}
		if m[v] = true; len(m) >= p {
			return i + 1
		}
	}
	return "paradox avoided"
}
