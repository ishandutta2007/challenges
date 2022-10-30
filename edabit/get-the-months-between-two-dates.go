/*

Create a function that, given 2 dates, returns the names of the months that are present between them (inclusive).

Examples

Input

var january = new Date(2017, 0, 1);
var march = new Date(2017, 2, 1);

monthsInterval(january, march)

Output

['January', 'February', 'March']

Input

var december = new Date(2017, 11, 1);
var january = new Date(2018, 0, 1);

monthsInterval(december, january)

Output

['January', 'December']

Input

var january2017 = new Date(2017, 0, 1);
var january2018 = new Date(2018, 0, 1);

monthsInterval(january2017, january2018)

Output

['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']

(Notice that January is not duplicated!)
Notes

    The returned array should include the months of dateStart and dateEnd (inclusive)
    The returned array must not include duplicate values
    The month names returned by the function should be sorted (not alphabetically, but ordered by which comes first (January = 1st month, February = 2nd month, … , December = 12th month))
    The function should produce the same output even if dateStart is greater than dateEnd

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"time"
)

func main() {
	test(date(2017, 0, 1), date(2017, 0, 1), []string{"January"})
	test(date(2016, 0, 1), date(2017, 0, 1), []string{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"})
	test(date(2017, 0, 1), date(2016, 0, 1), []string{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"})
	test(date(2017, 3, 1), date(2017, 7, 1), []string{"April", "May", "June", "July", "August"})
	test(date(2017, 7, 1), date(2017, 3, 1), []string{"April", "May", "June", "July", "August"})
	test(date(2017, 11, 1), date(2018, 0, 1), []string{"January", "December"})
	test(date(2018, 0, 1), date(2017, 11, 1), []string{"January", "December"})
	test(date(2017, 3, 1), date(2019, 3, 1), []string{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"})
	test(date(2019, 3, 1), date(2017, 3, 1), []string{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"})
	test(date(2017, 3, 1), date(2043, 9, 1), []string{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"})
	test(date(2043, 9, 1), date(2017, 3, 1), []string{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"})
}

func test(a, b time.Time, r []string) {
	p := months(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func months(a, b time.Time) []string {
	if a.After(b) {
		a, b = b, a
	}

	var p []time.Month
	for {
		p = append(p, a.Month())
		a = a.AddDate(0, 1, 0)
		if len(p) >= 12 || a.After(b) {
			break
		}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i] < p[j]
	})

	r := make([]string, len(p))
	for i := range r {
		r[i] = p[i].String()
	}

	return r
}

func date(y, m, d int) time.Time {
	return time.Date(y, time.Month(m+1), d, 0, 0, 0, 0, time.UTC)
}
