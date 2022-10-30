/*

OUTPUT: The number of seconds since midnight on January 1, 1 A.D., as an integer.

INPUT: None, you must pull the current timestamp yourself.

TASK: This is code-golf, shortest answer in bytes wins.

Standard loopholes apply.

*/

package main

import (
	"fmt"
	"math/big"
	"time"
)

func main() {
	fmt.Println(seconds())
}

func seconds() *big.Int {
	tab := []struct {
		d time.Duration
		v *big.Int
	}{
		{365 * 24 * time.Hour, big.NewInt(365 * 24 * 60 * 60)},
		{30 * 24 * time.Hour, big.NewInt(30 * 24 * 60 * 60)},
		{24 * time.Hour, big.NewInt(24 * 60 * 60)},
		{1 * time.Hour, big.NewInt(60 * 60)},
		{1 * time.Minute, big.NewInt(60)},
		{1 * time.Second, big.NewInt(1)},
	}

	r := new(big.Int)
	t0 := time.Date(1, time.January, 1, 0, 0, 0, 0, time.UTC)
	t1 := time.Now()
	for t0.Before(t1) {
		for i := range tab {
			p := &tab[i]
			t := t0.Add(p.d)
			if t.Before(t1) || i+1 >= len(tab) {
				r.Add(r, p.v)
				t0 = t
				break
			}
		}
	}
	return r
}
