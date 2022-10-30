/*

Challenge

Write a program that takes as input a day from April 30, 1789 to August 21, 2019 and returns as output who was president of the USA that day.

Notes

For the list of US presidents, the format of their names, and the period of their presidency, see below:

April 30, 1789 - March 4, 1797          George Washington
March 4, 1797 - March 4, 1801           John Adams
March 4, 1801 - March 4, 1809           Thomas Jefferson
March 4, 1809 - March 4, 1817           James Madison
March 4, 1817 - March 4, 1825           James Monroe
March 4, 1825 - March 4, 1829           John Quincy Adams
March 4, 1829 - March 4, 1837           Andrew Jackson
March 4, 1837 - March 4, 1841           Martin Van Buren
March 4, 1841 - April 4, 1841           William Henry Harrison
April 4, 1841 - March 4, 1845           John Tyler
March 4, 1845 - March 4, 1849           James K. Polk
March 4, 1849 - July 9, 1850            Zachary Taylor
July 9, 1850 - March 4, 1853            Millard Fillmore
March 4, 1853 - March 4, 1857           Franklin Pierce
March 4, 1857 - March 4, 1861           James Buchanan
March 4, 1861 - April 15, 1865          Abraham Lincoln
April 15, 1865 - March 4, 1869          Andrew Johnson
March 4, 1869 - March 4, 1877           Ulysses S. Grant
March 4, 1877 - March 4, 1881           Rutherford B. Hayes
March 4, 1881 - September 19, 1881      James A. Garfield
September 19, 1881 - March 4, 1885      Chester A. Arthur
March 4, 1885 - March 4, 1889           Grover Cleveland
March 4, 1889 - March 4, 1893           Benjamin Harrison
March 4, 1893 - March 4, 1897           Grover Cleveland
March 4, 1897 - September 14, 1901      William McKinley
September 14, 1901 - March 4, 1909      Theodore Roosevelt
March 4, 1909 - March 4, 1913           William Howard Taft
March 4, 1913 - March 4, 1921           Woodrow Wilson
March 4, 1921 - August 2, 1923          Warren G. Harding
August 2, 1923 - March 4, 1929          Calvin Coolidge
March 4, 1929 - March 4, 1933           Herbert Hoover
March 4, 1933 - April 12, 1945          Franklin D. Roosevelt
April 12, 1945 - January 20, 1953       Harry S. Truman
January 20, 1953 - January 20, 1961     Dwight D. Eisenhower
January 20, 1961 - November 22, 1963    John F. Kennedy
November 22, 1963 - January 20, 1969    Lyndon B. Johnson
January 20, 1969 - August 9, 1974       Richard Nixon
August 9, 1974 - January 20, 1977       Gerald Ford
January 20, 1977 - January 20, 1981     Jimmy Carter
January 20, 1981 - January 20, 1989     Ronald Reagan
January 20, 1989 - January 20, 1993     George H. W. Bush
January 20, 1993 - January 20, 2001     Bill Clinton
January 20, 2001 - January 20, 2009     George W. Bush
January 20, 2009 - January 20, 2017     Barack Obama
January 20, 2017 - Incumbent            Donald Trump

A presidency is intended as first day included and last day excluded. For example, "March 4, 1861 - April 15, 1865; Abraham Lincoln" means that Lincoln was president from March 4, 1861 to April 14, 1865.

This is code-golf, the shortest program in each language wins.
Example

Input: "February 7, 1865" Output: "Abraham Lincoln"

*/

package main

import (
	"fmt"
	"sort"
	"time"
)

func main() {
	fmt.Println(president("April 29, 1789"))
	fmt.Println(president("April 30, 1789"))
	fmt.Println(president("February 7, 1865"))
	fmt.Println(president("December 31, 1999"))
	fmt.Println(president("July 31, 1969"))
}

func president(d string) string {
	const layout = "January 2, 2006"
	terms := []struct {
		date string
		name string
	}{
		{"April 30, 1789", "George Washington"},
		{"March 4, 1797", "John Adams"},
		{"March 4, 1801", "Thomas Jefferson"},
		{"March 4, 1809", "James Madison"},
		{"March 4, 1817", "James Monroe"},
		{"March 4, 1825", "John Quincy Adams"},
		{"March 4, 1829", "Andrew Jackson"},
		{"March 4, 1837", "Martin Van Buren"},
		{"March 4, 1841", "William Henry Harrison"},
		{"April 4, 1841", "John Tyler"},
		{"March 4, 1845", "James K. Polk"},
		{"March 4, 1849", "Zachary Taylor"},
		{"July 9, 1850", "Millard Fillmore"},
		{"March 4, 1853", "Franklin Pierce"},
		{"March 4, 1857", "James Buchanan"},
		{"March 4, 1861", "Abraham Lincoln"},
		{"April 15, 1865", "Andrew Johnson"},
		{"March 4, 1869", "Ulysses S. Grant"},
		{"March 4, 1877", "Rutherford B. Hayes"},
		{"March 4, 1881", "James A. Garfield"},
		{"September 19, 1881", "Chester A. Arthur"},
		{"March 4, 1885", "Grover Cleveland"},
		{"March 4, 1889", "Benjamin Harrison"},
		{"March 4, 1893", "Grover Cleveland"},
		{"March 4, 1897", "William McKinley"},
		{"September 14, 1901", "Theodore Roosevelt"},
		{"March 4, 1909", "William Howard Taft"},
		{"March 4, 1913", "Woodrow Wilson"},
		{"March 4, 1921", "Warren G. Harding"},
		{"August 2, 1923", "Calvin Coolidge"},
		{"March 4, 1929", "Herbert Hoover"},
		{"March 4, 1933", "Franklin D. Roosevelt"},
		{"April 12, 1945", "Harry S. Truman"},
		{"January 20, 1953", "Dwight D. Eisenhower"},
		{"January 20, 1961", "John F. Kennedy"},
		{"November 22, 1963", "Lyndon B. Johnson"},
		{"January 20, 1969", "Richard Nixon"},
		{"August 9, 1974", "Gerald Ford"},
		{"January 20, 1977", "Jimmy Carter"},
		{"January 20, 1981", "Ronald Reagan"},
		{"January 20, 1989", "George H. W. Bush"},
		{"January 20, 1993", "Bill Clinton"},
		{"January 20, 2001", "George W. Bush"},
		{"January 20, 2009", "Barack Obama"},
		{"January 20, 2017", "Donald Trump"},
	}

	t, err := time.Parse(layout, d)
	if err != nil {
		return err.Error()
	}

	i := sort.Search(len(terms), func(i int) bool {
		td, _ := time.Parse(layout, terms[i].date)
		return t.Before(td)
	})

	if i == 0 {
		return "N/A"
	}
	return terms[i-1].name
}
