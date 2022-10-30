/*

You should write 3 programs and/or functions in one language.

All of these programs should solve the same task but they all should give different (but valid) outputs. (I.e. for every pair of programs their should be some input which generates different (but valid) sets of output numbers.)

The task
You are given an integer n, greater than 1
You should return or output n distinct positive integers, and none of them should be divisible by n.
The order of the numbers doesn't matter and a permutation of numbers doesn't count as different outputs.
A valid triplet of programs with some input => output pairs:

program A:
    2 => 5 9
    4 => 5 6 9 10
    5 => 2 4 8 7 1

program B:
    2 => 1 11
    4 => 6 9 1 2
    5 => 4 44 444 4444 44444

program C (differs only in one number from program B):
    2 => 1 13
    4 => 6 9 1 2
    5 => 4 44 444 4444 44444
Scoring
Your score is the sum of the lengths of the 3 programs or functions.
Lower score is better.
If your programs/functions share code, the shared code should be counted into the length of every program that uses the code.

*/

package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(thrice(2))
	fmt.Println(thrice(3))
	fmt.Println(thrice(5))
}

func thrice(n int) [3][]int {
	var (
		wg sync.WaitGroup
		mu sync.Mutex
		db = make(map[int]bool)
	)

	var r [3][]int
	wg.Add(3)
	for i := 0; i < 3; i++ {
		go gen(n, &r[i], db, &mu, &wg)
	}
	wg.Wait()

	return r
}

func gen(n int, r *[]int, db map[int]bool, mu *sync.Mutex, wg *sync.WaitGroup) {
	for i := 0; i < n; {
		mu.Lock()
		x := rand.Intn(n * 10)
		if x%n != 0 && !db[x] {
			*r, i, db[x] = append(*r, x), i+1, true
		}
		mu.Unlock()
	}
	wg.Done()
}
