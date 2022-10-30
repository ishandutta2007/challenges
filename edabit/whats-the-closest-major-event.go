/*

Given an array of objects containing some of the major historical events and a date object, you should return the name of the historical event that is closest to that date.

An historical event object contains 2 properties, this is an example:

{
  date: '2005-08-23',
  name: 'Hurricane Katrina'
}

⚠️ You can see the full array in the Tests tab.
Examples

closestEvent(events, new Date(1990, 0, 1)) ➞ Fall of the Berlin Wall

closestEvent(events, new Date(2005, 0, 1)) ➞ Indian Ocean Earthquake and Tsunami Disaster

closestEvent(events, new Date()) ➞ Fukushima Nuclear Disaster

Notes

N/A

*/

package main

import (
	"math"
	"time"
)

func main() {
	evtab := []Event{
		{date: "2005-08-23", name: "Hurricane Katrina"},
		{date: "2004-12-26", name: "Indian Ocean Earthquake and Tsunami Disaster"},
		{date: "1989-11-09", name: "Fall of the Berlin Wall"},
		{date: "2009-01-15", name: "Hudson River Plane Crash"},
		{date: "1986-01-28", name: "Challenger Spacecraft Explodes"},
		{date: "2001-09-11", name: "September 11 Attacks"},
		{date: "1986-04-26", name: "Chernobyl Nuclear Disaster"},
		{date: "2011-03-16", name: "Fukushima Nuclear Disaster"},
	}

	assert(closestevent(evtab, date(1970, 0, 1)) == "Challenger Spacecraft Explodes")
	assert(closestevent(evtab, date(1986, 2, 13)) == "Challenger Spacecraft Explodes")
	assert(closestevent(evtab, date(1986, 2, 14)) == "Chernobyl Nuclear Disaster")
	assert(closestevent(evtab, date(1990, 0, 1)) == "Fall of the Berlin Wall")
	assert(closestevent(evtab, date(1995, 9, 11)) == "Fall of the Berlin Wall")
	assert(closestevent(evtab, date(1995, 9, 12)) == "September 11 Attacks")
	assert(closestevent(evtab, date(2005, 0, 1)) == "Indian Ocean Earthquake and Tsunami Disaster")
	assert(closestevent(evtab, date(2006, 5, 16)) == "Hurricane Katrina")
	assert(closestevent(evtab, date(2007, 4, 12)) == "Hudson River Plane Crash")
	assert(closestevent(evtab, now()) == "Fukushima Nuclear Disaster")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Event struct {
	date string
	name string
}

func closestevent(e []Event, t time.Time) (r string) {
	d := time.Duration(math.MaxInt64)
	for _, e := range e {
		a := t
		b, err := time.Parse("2006-01-02", e.date)
		if err != nil {
			return err.Error()
		}

		if b.After(a) {
			a, b = b, a
		}

		if dt := a.Sub(b); dt < d {
			d, r = dt, e.name
		}
	}
	return
}

func date(y, m, d int) time.Time {
	return time.Date(y, time.Month(m+1), d, 0, 0, 0, 0, time.UTC)
}

func now() time.Time {
	return date(2011, 3, 16)
}
