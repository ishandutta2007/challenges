/*

The median of a set of integers is the midpoint value of the data set for which an equal number of integers are less than and greater than the value.
To find the median, you must first sort your set of integers in non-decreasing order, then:

If your set contains an odd number of elements, the median is the middle element of the sorted sample. In the sorted set
{1, 2, 3}, 2 is the median.

If your set contains an even number of elements, the median is the average of the two middle elements of the sorted sample. In the sorted set
{1, 2, 3, 4} (2+3)/2 = 2.5 is the median.

Given an input stream of n integers, you must perform the following task for each ith integer:

Add the ith integer to a running list of integers.
Find the median of the updated list (i.e., for the first element through the ith element).
Print the list's updated median on a new line. The printed value must be a double-precision number scaled to 1 decimal place (i.e., 12.3format).

*/

package main

import (
	"container/heap"
	"fmt"
)

func main() {
	fmt.Println(median([]int{1, 2, 3}, false))
	fmt.Println(median([]int{1, 2, 3, 4}, false))
	median([]int{12, 4, 5, 3, 8, 7}, true)
}

func median(a []int, pr bool) float64 {
	if len(a) == 0 {
		return 0
	}
	if len(a) == 1 {
		return float64(a[0])
	}

	var ma maxInts
	var mi minInts
	get := func() float64 {
		if ma.Len() == mi.Len() {
			return float64(ma.Value()+mi.Value()) / 2
		}
		return float64(ma.Value())
	}

	for _, v := range a {
		switch {
		case ma.Len() == 0:
			heap.Push(&ma, v)
		case ma.Len() == mi.Len():
			if v < mi.Value() {
				heap.Push(&ma, v)
			} else {
				heap.Push(&mi, v)
				heap.Push(&ma, heap.Pop(&mi))
			}
		case ma.Len() > mi.Len():
			if v > ma.Value() {
				heap.Push(&mi, v)
			} else {
				heap.Push(&ma, v)
				heap.Push(&mi, heap.Pop(&ma))
			}
		default:
			panic("unreachable")
		}
		if pr {
			fmt.Printf("%.1f\n", get())
		}
	}
	return get()
}

type intSlice []int

func (p intSlice) Len() int            { return len(p) }
func (p intSlice) Swap(i, j int)       { p[i], p[j] = p[j], p[i] }
func (p *intSlice) Push(x interface{}) { (*p) = append((*p), x.(int)) }
func (p *intSlice) Pop() interface{} {
	x := (*p)[len(*p)-1]
	(*p) = (*p)[:len(*p)-1]
	return x
}
func (p intSlice) Value() int { return p[0] }

type minInts struct {
	intSlice
}

func (p *minInts) Less(i, j int) bool { return p.intSlice[i] < p.intSlice[j] }

type maxInts struct {
	intSlice
}

func (p *maxInts) Less(i, j int) bool { return p.intSlice[i] > p.intSlice[j] }
