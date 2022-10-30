/*

Create a function that calculates an energy bill.

Given a billing start date and end date, start and end meter reading, a unit price in pence, and a standing charge (a daily rental fee for your meter) as arguments, calculate your bill.

An energy bill is calculated by multiplying the difference between meter readings with the unit price and adding the number of days multiplied by the standing charge. You then have to add 5% tax.

(days between dates x standing charge) + (diference bewteen meter readings x unit price) + 5% tax

Examples

energyBill("2020,01,01", "2020,04,01", 1000, 2000, 0.188, 0.243),  = "£220.62"
"2020,04,01" (end date) - "2020,01,01" ( start date ),  = 91 days
  2000 ( end meter read )- 1000 ( start meter read ) = 1000 units used
  1000 (units) * 0.188p (each unit cost) = £188
  91 (days) * 0.243p (standing charge) == £22.113
  22.113 (Total standing charge cost) + £188 (total unit cost) = £210.113
  210.113 (cost) * 0.05 (uk tax on energy) = 10.50565
  210.113 (cost) + 10.50565 (tax) = 220.61865
  answer = "£220.62"

Notes

    If the end date is an earlier date from the start date return "Invalid date".
    If the end meter reading is less then the start meter reading return "Invalid meter readings".
    Please bring to my attention any clarity issues.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(bill("2020,01,01", "2020,04,01", 1000, 2000, 0.188, 0.243) == "£220.62")
	assert(bill("1987,11,01", "1989,02,21", 874, 6253, 0.061, 0.124) == "£406.76")
	assert(bill("2011,09,02", "2012,09,05", 3297, 4721, 0.151, 0.176) == "£293.97")
	assert(bill("1970,01,01", "2020,11,22", 0, 22456, 0.0213, 0.1671) == "£3763.59")
	assert(bill("1980,06,15", "1980,12,25", 7650, 9912, 0.0534, 0.054) == "£137.77")
	assert(bill("2010,01,01", "2020,01,01", 2000, 2000, 0.171, 0.213) == "£816.77")
	assert(bill("2010,01,01", "2020,01,01", 2785, 12874, 0.128, 0.148) == "£1923.48")
	assert(bill("2017,03,01", "2017,06,01", 6348, 7559, 0.142, 0.20) == "£199.88")
	assert(bill("1984,04,19", "1991,04,10", 2000, 1000, 0.61, 0.074) == "Invalid meter readings")
	assert(bill("2020,01,01", "2019,01,01", 1000, 2000, 0.171, 0.243) == "Invalid date")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bill(d0, d1 string, sm, em, up, sc float64) string {
	t0, err := time.Parse("2006,01,02", d0)
	t1, xerr := time.Parse("2006,01,02", d1)
	if err != nil || xerr != nil || t1.Before(t0) {
		return "Invalid date"
	}
	if em < sm {
		return "Invalid meter readings"
	}

	dt := t1.Sub(t0) / 24
	p := (em-sm)*up + dt.Hours()*sc
	p *= 1.05
	s := fmt.Sprintf("£%.2f", p)
	return s
}
