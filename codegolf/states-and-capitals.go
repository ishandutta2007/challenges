/*

Given a string as input, output the US state whose capital it is if it is a state capital, the capital of the state if it is a state, or Arstotzka if it is neither.

Examples:

Austin -> Texas
Alaska -> Juneau
The Nineteenth Byte -> Arstotzka
All the capitals and their respective states:

Baton Rouge, Louisiana
Indianapolis, Indiana
Columbus, Ohio
Montgomery, Alabama
Helena, Montana
Denver, Colorado
Boise, Idaho
Austin, Texas
Boston, Massachusetts
Albany, New York
Tallahassee, Florida
Santa Fe, New Mexico
Nashville, Tennessee
Trenton, New Jersey
Jefferson, Missouri
Richmond, Virginia
Pierre, South Dakota
Harrisburg, Pennsylvania
Augusta, Maine
Providence, Rhode Island
Dover, Delaware
Concord, New Hampshire
Montpelier, Vermont
Hartford, Connecticut
Topeka, Kansas
Saint Paul, Minnesota
Juneau, Alaska
Lincoln, Nebraska
Raleigh, North Carolina
Madison, Wisconsin
Olympia, Washington
Phoenix, Arizona
Lansing, Michigan
Honolulu, Hawaii
Jackson, Mississippi
Springfield, Illinois
Columbia, South Carolina
Annapolis, Maryland
Cheyenne, Wyoming
Salt Lake City, Utah
Atlanta, Georgia
Bismarck, North Dakota
Frankfort, Kentucky
Salem, Oregon
Little Rock, Arkansas
Des Moines, Iowa
Sacramento, California
Oklahoma City, Oklahoma
Charleston, West Virginia
Carson City, Nevada

Rules
No built-ins or libraries/modules that provide a mapping from states to capitals or capitals to states, or lists of capitals and/or states (for example, Mathematica's CityData built-in)
Standard loopholes apply
This is code-golf, so shortest answer in bytes wins!

*/

package main

import (
	"bufio"
	"strings"
)

func main() {
	assert(identify("Austin") == "Texas")
	assert(identify("Alaska") == "Juneau")
	assert(identify("The Nineteenth Byte") == "Arstotzka")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func identify(s string) string {
	r := strings.NewReader(places)
	p := bufio.NewScanner(r)
	for p.Scan() {
		l := p.Text()
		t := strings.Split(l, ",")
		if len(t) != 2 {
			continue
		}
		for i := range t {
			t[i] = strings.TrimSpace(t[i])
			if s == t[i] {
				return strings.TrimSpace(t[1-i])
			}
		}
	}
	return "Arstotzka"
}

const places = `
Baton Rouge, Louisiana
Indianapolis, Indiana
Columbus, Ohio
Montgomery, Alabama
Helena, Montana
Denver, Colorado
Boise, Idaho
Austin, Texas
Boston, Massachusetts
Albany, New York
Tallahassee, Florida
Santa Fe, New Mexico
Nashville, Tennessee
Trenton, New Jersey
Jefferson, Missouri
Richmond, Virginia
Pierre, South Dakota
Harrisburg, Pennsylvania
Augusta, Maine
Providence, Rhode Island
Dover, Delaware
Concord, New Hampshire
Montpelier, Vermont
Hartford, Connecticut
Topeka, Kansas
Saint Paul, Minnesota
Juneau, Alaska
Lincoln, Nebraska
Raleigh, North Carolina
Madison, Wisconsin
Olympia, Washington
Phoenix, Arizona
Lansing, Michigan
Honolulu, Hawaii
Jackson, Mississippi
Springfield, Illinois
Columbia, South Carolina
Annapolis, Maryland
Cheyenne, Wyoming
Salt Lake City, Utah
Atlanta, Georgia
Bismarck, North Dakota
Frankfort, Kentucky
Salem, Oregon
Little Rock, Arkansas
Des Moines, Iowa
Sacramento, California
Oklahoma City, Oklahoma
Charleston, West Virginia
Carson City, Nevada
`
