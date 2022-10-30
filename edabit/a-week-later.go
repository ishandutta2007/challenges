/*

Create a function which takes in a date as a string, and returns the date a week after.

Examples

weekAfter("12/03/2020") ➞ "19/03/2020"

weekAfter("21/12/1989") ➞ "28/12/1989"

weekAfter("01/01/2000") ➞ "08/01/2000"

Notes

	Note that dates will be given in day/month/year format.
	Single digit numbers should be zero padded.
	See Resources for some helpful tutorials on JavaScript dates.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(weekafter("12/03/2020") == "19/03/2020")
	assert(weekafter("21/12/1989") == "28/12/1989")
	assert(weekafter("01/01/2000") == "08/01/2000")
	assert(weekafter("24/09/1924") == "01/10/1924")
	assert(weekafter("21/07/1964") == "28/07/1964")
	assert(weekafter("14/07/2085") == "21/07/2085")
	assert(weekafter("25/04/1953") == "02/05/1953")
	assert(weekafter("02/01/2200") == "09/01/2200")
	assert(weekafter("06/01/2007") == "13/01/2007")
	assert(weekafter("07/04/2195") == "14/04/2195")
	assert(weekafter("04/09/2094") == "11/09/2094")
	assert(weekafter("20/08/1910") == "27/08/1910")
	assert(weekafter("12/12/1894") == "19/12/1894")
	assert(weekafter("02/11/2094") == "09/11/2094")
	assert(weekafter("22/12/1955") == "29/12/1955")
	assert(weekafter("18/04/1859") == "25/04/1859")
	assert(weekafter("17/03/1847") == "24/03/1847")
	assert(weekafter("17/03/2142") == "24/03/2142")
	assert(weekafter("26/01/2145") == "02/02/2145")
	assert(weekafter("03/12/1959") == "10/12/1959")
	assert(weekafter("01/06/1947") == "08/06/1947")
	assert(weekafter("26/12/1853") == "02/01/1854")
	assert(weekafter("27/10/2068") == "03/11/2068")
	assert(weekafter("05/05/2080") == "12/05/2080")
	assert(weekafter("22/12/2144") == "29/12/2144")
	assert(weekafter("12/05/1870") == "19/05/1870")
	assert(weekafter("07/01/1882") == "14/01/1882")
	assert(weekafter("16/06/2032") == "23/06/2032")
	assert(weekafter("02/10/2007") == "09/10/2007")
	assert(weekafter("24/03/1871") == "31/03/1871")
	assert(weekafter("19/08/1847") == "26/08/1847")
	assert(weekafter("24/07/2157") == "31/07/2157")
	assert(weekafter("28/12/1848") == "04/01/1849")
	assert(weekafter("20/07/1951") == "27/07/1951")
	assert(weekafter("14/11/2071") == "21/11/2071")
	assert(weekafter("07/12/2170") == "14/12/2170")
	assert(weekafter("01/03/2080") == "08/03/2080")
	assert(weekafter("28/04/1906") == "05/05/1906")
	assert(weekafter("15/06/2023") == "22/06/2023")
	assert(weekafter("11/08/1950") == "18/08/1950")
	assert(weekafter("15/11/2103") == "22/11/2103")
	assert(weekafter("23/11/1852") == "30/11/1852")
	assert(weekafter("08/01/1928") == "15/01/1928")
	assert(weekafter("14/11/2118") == "21/11/2118")
	assert(weekafter("11/10/2096") == "18/10/2096")
	assert(weekafter("02/12/1816") == "09/12/1816")
	assert(weekafter("10/10/1937") == "17/10/1937")
	assert(weekafter("28/11/1959") == "05/12/1959")
	assert(weekafter("27/05/2133") == "03/06/2133")
	assert(weekafter("28/04/1932") == "05/05/1932")
	assert(weekafter("23/02/2050") == "02/03/2050")
	assert(weekafter("23/05/2146") == "30/05/2146")
	assert(weekafter("24/07/2167") == "31/07/2167")
}

func weekafter(s string) string {
	var d, m, y int
	n, _ := fmt.Sscanf(s, "%d/%d/%d", &d, &m, &y)
	if n != 3 {
		return ""
	}
	t := time.Date(y, time.Month(m), d+7, 0, 0, 0, 0, time.UTC)
	p := fmt.Sprintf("%02d/%02d/%04d", t.Day(), t.Month(), t.Year())
	return p
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
