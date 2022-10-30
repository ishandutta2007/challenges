/*

Description

US presidents serve four year terms, with most presidents serving one or two terms. Unless a president dies in office, they then live after leaving office.

This challenge, then, given a list of presidents and their dates of birth and dates of death, is to figure out what year the most presidents - future, present, or previous - were alive.

Challenge Input

Below is a CSV input of presidential birthdates and death dates. Find what year in which the most number of people who would serve, are serving, or have served as presidents. The answer might be multiple years, or only a partial year.

PRESIDENT,	BIRTH DATE,	BIRTH PLACE,	DEATH DATE,	LOCATION OF DEATH
George Washington,	Feb 22 1732,	Westmoreland Co. Va.,	Dec 14 1799,	Mount Vernon Va.
John Adams,	Oct 30 1735,	Quincy Mass.,	July 4 1826,	Quincy Mass.
Thomas Jefferson,	Apr 13 1743,	Albemarle Co. Va.,	July 4 1826,	Albemarle Co. Va.
James Madison,	Mar 16 1751,	Port Conway Va.,	June 28 1836,	Orange Co. Va.
James Monroe,	Apr 28 1758,	Westmoreland Co. Va.,	July 4 1831,	New York New York
John Quincy Adams,	July 11 1767,	Quincy Mass.,	Feb 23 1848,	Washington D.C.
Andrew Jackson,	Mar 15 1767,	Lancaster Co. S.C.,	June 8 1845,	Nashville Tennessee
Martin Van Buren,	Dec 5 1782,	Kinderhook New York,	July 24 1862,	Kinderhook New York
William Henry Harrison,	Feb 9 1773,	Charles City Co. Va.,	Apr 4 1841,	Washington D.C.
John Tyler,	Mar 29 1790,	Charles City Co. Va.,	Jan 18 1862,	Richmond Va.
James K. Polk,	Nov 2 1795,	Mecklenburg Co. N.C.,	June 15 1849,	Nashville Tennessee
Zachary Taylor,	Nov 24 1784,	Orange County Va.,	July 9 1850,	Washington D.C
Millard Fillmore,	Jan 7 1800,	Cayuga Co. New York,	Mar 8 1874,	Buffalo New York
Franklin Pierce,	Nov 23 1804,	Hillsborough N.H.,	Oct 8 1869,	Concord New Hamp.
James Buchanan,	Apr 23 1791,	Cove Gap Pa.,	June 1 1868,	Lancaster Pa.
Abraham Lincoln,	Feb 12 1809,	LaRue Co. Kentucky,	Apr 15 1865,	Washington D.C.
Andrew Johnson,	Dec 29 1808,	Raleigh North Carolina,	July 31 1875,	Elizabethton Tenn.
Ulysses S. Grant,	Apr 27 1822,	Point Pleasant Ohio,	July 23 1885,	Wilton New York
Rutherford B. Hayes,	Oct 4 1822,	Delaware Ohio,	Jan 17 1893,	Fremont Ohio
James A. Garfield,	Nov 19 1831,	Cuyahoga Co. Ohio,	Sep 19 1881,	Elberon New Jersey
Chester Arthur,	Oct 5 1829,	Fairfield Vermont,	Nov 18 1886,	New York New York
Grover Cleveland,	Mar 18 1837,	Caldwell New Jersey,	June 24 1908,	Princeton New Jersey
Benjamin Harrison,	Aug 20 1833,	North Bend Ohio,	Mar 13 1901,	Indianapolis Indiana
William McKinley,	Jan 29 1843,	Niles Ohio,	Sep 14 1901,	Buffalo New York
Theodore Roosevelt,	Oct 27 1858,	New York New York,	Jan 6 1919,	Oyster Bay New York
William Howard Taft,	Sep 15 1857,	Cincinnati Ohio,	Mar 8 1930,	Washington D.C.
Woodrow Wilson,	Dec 28 1856,	Staunton Virginia,	Feb 3 1924,	Washington D.C.
Warren G. Harding,	Nov 2 1865,	Morrow County Ohio,	Aug 2 1923,	San Francisco Cal.
Calvin Coolidge,	July 4 1872,	Plymouth Vermont,	Jan 5 1933,	Northampton Mass.
Herbert Hoover,	Aug 10 1874,	West Branch Iowa,	Oct 20 1964,	New York New York
Franklin Roosevelt,	Jan 30 1882,	Hyde Park New York,	Apr 12 1945,	Warm Springs Georgia
Harry S. Truman,	May 8 1884,	Lamar Missouri,	Dec 26 1972,	Kansas City Missouri
Dwight Eisenhower,	Oct 14 1890,	Denison Texas,	Mar 28 1969,	Washington D.C.
John F. Kennedy,	May 29 1917,	Brookline Mass.,	Nov 22 1963,	Dallas Texas
Lyndon B. Johnson,	Aug 27 1908,	Gillespie Co. Texas,	Jan 22 1973,	Gillespie Co. Texas
Richard Nixon,	Jan 9 1913,	Yorba Linda Cal.,	Apr 22 1994,	New York New York
Gerald Ford,	July 14 1913,	Omaha Nebraska,	Dec 26 2006,	Rancho Mirage Cal.
Jimmy Carter,	Oct 1 1924,	Plains Georgia,	,
Ronald Reagan,	Feb 6 1911,	Tampico Illinois,	June 5 2004,	Los Angeles Cal.
George Bush,	June 12 1924,	Milton Mass.,	,
Bill Clinton,	Aug 19 1946,	Hope Arkansas,	,
George W. Bush,	July 6 1946,	New Haven Conn.,	,
Barack Obama,	Aug 4 1961,	Honolulu Hawaii,	,
via U.S. Presidents Birth and Death Information.

Challenge Output

Any of the following years is valid: 1822, 1823, 1824, 1825, 1826, 1831, 1833, 1834, 1835, 1836, 1837, 1838, 1839, 1840, 1841, 1843, 1844, 1845 (each year had 18 presidents, current, former, or to be, alive).

*/

package main

import (
	"encoding/csv"
	"fmt"
	"sort"
	"strings"
	"time"
)

func main() {
	fmt.Println(mostalive(input))
}

type President struct {
	Name       string
	Birthdate  time.Time
	Deathdate  time.Time
	Birthplace string
	Deathplace string
}

func mostalive(s string) (int, []int, error) {
	r := []int{}

	p, err := parse(s)
	if err != nil {
		return 0, r, err
	}

	m := 0
	t0, t1 := getrange(p)
	for t := t0; t.Before(t1); t = t.AddDate(1, 0, 0) {
		v := 0
		y := t.Year()
		for _, t := range p {
			a := t.Birthdate.Year()
			b := t.Deathdate.Year()
			if a <= y && (y <= b || t.Deathdate.IsZero()) {
				v++
			}
		}

		if v > m {
			m = v
			r = []int{y}
		} else if v == m {
			r = append(r, y)
		}
	}

	return m, r, nil
}

func getrange(p []President) (t0, t1 time.Time) {
	for i, t := range p {
		if i == 0 {
			t0 = t.Birthdate
			t1 = t.Birthdate
		}

		t0 = mintime(t0, mintime(t.Birthdate, t.Deathdate))
		t1 = maxtime(t1, maxtime(t.Birthdate, t.Deathdate))
	}
	return
}

func mintime(a, b time.Time) time.Time {
	if a.Before(b) {
		return a
	}
	return b
}

func maxtime(a, b time.Time) time.Time {
	if a.After(b) {
		return a
	}
	return b
}

func parse(s string) ([]President, error) {
	r := csv.NewReader(strings.NewReader(s))
	f, err := r.ReadAll()
	if err != nil {
		return nil, err
	}

	n := len(f)
	p := []President{}
	if n < 2 {
		return p, nil
	}

	for i := 1; i < n; i++ {
		if len(f[i]) != 5 {
			return nil, fmt.Errorf("malformed input at record %d", i)
		}

		for j := range f[i] {
			f[i][j] = strings.TrimSpace(f[i][j])
		}

		u, err := parsedate(f[i][1])
		v, xerr := parsedate(f[i][3])
		if u.IsZero() || err != nil || xerr != nil {
			return nil, fmt.Errorf("malformed time at record %d", i)
		}

		p = append(p, President{
			Name:       f[i][0],
			Birthdate:  u,
			Deathdate:  v,
			Birthplace: f[i][2],
			Deathplace: f[i][4],
		})
	}

	sort.SliceStable(p, func(i, j int) bool {
		x := p[i].Birthdate
		y := p[j].Birthdate
		return x.Before(y)
	})

	return p, nil
}

func parsedate(s string) (time.Time, error) {
	if s == "" {
		return time.Time{}, nil
	}

	t, err := time.Parse("Jan _2 2006", s)
	if err != nil {
		t, err = time.Parse("January _2 2006", s)
	}
	return t, err
}

const input = `PRESIDENT,	BIRTH DATE,	BIRTH PLACE,	DEATH DATE,	LOCATION OF DEATH
George Washington,	Feb 22 1732,	Westmoreland Co. Va.,	Dec 14 1799,	Mount Vernon Va.
John Adams,	Oct 30 1735,	Quincy Mass.,	July 4 1826,	Quincy Mass.
Thomas Jefferson,	Apr 13 1743,	Albemarle Co. Va.,	July 4 1826,	Albemarle Co. Va.
James Madison,	Mar 16 1751,	Port Conway Va.,	June 28 1836,	Orange Co. Va.
James Monroe,	Apr 28 1758,	Westmoreland Co. Va.,	July 4 1831,	New York New York
John Quincy Adams,	July 11 1767,	Quincy Mass.,	Feb 23 1848,	Washington D.C.
Andrew Jackson,	Mar 15 1767,	Lancaster Co. S.C.,	June 8 1845,	Nashville Tennessee
Martin Van Buren,	Dec 5 1782,	Kinderhook New York,	July 24 1862,	Kinderhook New York
William Henry Harrison,	Feb 9 1773,	Charles City Co. Va.,	Apr 4 1841,	Washington D.C.
John Tyler,	Mar 29 1790,	Charles City Co. Va.,	Jan 18 1862,	Richmond Va.
James K. Polk,	Nov 2 1795,	Mecklenburg Co. N.C.,	June 15 1849,	Nashville Tennessee
Zachary Taylor,	Nov 24 1784,	Orange County Va.,	July 9 1850,	Washington D.C
Millard Fillmore,	Jan 7 1800,	Cayuga Co. New York,	Mar 8 1874,	Buffalo New York
Franklin Pierce,	Nov 23 1804,	Hillsborough N.H.,	Oct 8 1869,	Concord New Hamp.
James Buchanan,	Apr 23 1791,	Cove Gap Pa.,	June 1 1868,	Lancaster Pa.
Abraham Lincoln,	Feb 12 1809,	LaRue Co. Kentucky,	Apr 15 1865,	Washington D.C.
Andrew Johnson,	Dec 29 1808,	Raleigh North Carolina,	July 31 1875,	Elizabethton Tenn.
Ulysses S. Grant,	Apr 27 1822,	Point Pleasant Ohio,	July 23 1885,	Wilton New York
Rutherford B. Hayes,	Oct 4 1822,	Delaware Ohio,	Jan 17 1893,	Fremont Ohio
James A. Garfield,	Nov 19 1831,	Cuyahoga Co. Ohio,	Sep 19 1881,	Elberon New Jersey
Chester Arthur,	Oct 5 1829,	Fairfield Vermont,	Nov 18 1886,	New York New York
Grover Cleveland,	Mar 18 1837,	Caldwell New Jersey,	June 24 1908,	Princeton New Jersey
Benjamin Harrison,	Aug 20 1833,	North Bend Ohio,	Mar 13 1901,	Indianapolis Indiana
William McKinley,	Jan 29 1843,	Niles Ohio,	Sep 14 1901,	Buffalo New York
Theodore Roosevelt,	Oct 27 1858,	New York New York,	Jan 6 1919,	Oyster Bay New York
William Howard Taft,	Sep 15 1857,	Cincinnati Ohio,	Mar 8 1930,	Washington D.C.
Woodrow Wilson,	Dec 28 1856,	Staunton Virginia,	Feb 3 1924,	Washington D.C.
Warren G. Harding,	Nov 2 1865,	Morrow County Ohio,	Aug 2 1923,	San Francisco Cal.
Calvin Coolidge,	July 4 1872,	Plymouth Vermont,	Jan 5 1933,	Northampton Mass.
Herbert Hoover,	Aug 10 1874,	West Branch Iowa,	Oct 20 1964,	New York New York
Franklin Roosevelt,	Jan 30 1882,	Hyde Park New York,	Apr 12 1945,	Warm Springs Georgia
Harry S. Truman,	May 8 1884,	Lamar Missouri,	Dec 26 1972,	Kansas City Missouri
Dwight Eisenhower,	Oct 14 1890,	Denison Texas,	Mar 28 1969,	Washington D.C.
John F. Kennedy,	May 29 1917,	Brookline Mass.,	Nov 22 1963,	Dallas Texas
Lyndon B. Johnson,	Aug 27 1908,	Gillespie Co. Texas,	Jan 22 1973,	Gillespie Co. Texas
Richard Nixon,	Jan 9 1913,	Yorba Linda Cal.,	Apr 22 1994,	New York New York
Gerald Ford,	July 14 1913,	Omaha Nebraska,	Dec 26 2006,	Rancho Mirage Cal.
Jimmy Carter,	Oct 1 1924,	Plains Georgia,	,
Ronald Reagan,	Feb 6 1911,	Tampico Illinois,	June 5 2004,	Los Angeles Cal.
George Bush,	June 12 1924,	Milton Mass.,	,
Bill Clinton,	Aug 19 1946,	Hope Arkansas,	,
George W. Bush,	July 6 1946,	New Haven Conn.,	,
Barack Obama,	Aug 4 1961,	Honolulu Hawaii,	,`
