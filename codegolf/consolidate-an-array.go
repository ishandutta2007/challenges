/*

The task is simple: consolidate an array of ints. Consolidating this array consists of the following:

All instances of 0 need to be moved to the end of the array.
There should be no 0s between the non-zero integers.
All non-zero indices should retain their order.

Challenge
Consolidate an array in the least amount of bytes.

You are consolidating an array of random length with a size up to your language's max with random integers. Input may be any natural way for your language.

Examples

Input

0 5 8 8 3 5 1 6 8 4 0 3 7 5 6 4 4 7 5 6 7 4 4 9 1 0 5 7 9 3 0 2 2 4 3 0 4 8 7 3 1 4 7 5 1 2 1 8 7 8 7 7 2 6 3 1 2 8 5 1 4 2 0 5 0 6 0 3
Output

5 8 8 3 5 1 6 8 4 3 7 5 6 4 4 7 5 6 7 4 4 9 1 5 7 9 3 2 2 4 3 4 8 7 3 1 4 7 5 1 2 1 8 7 8 7 7 2 6 3 1 2 8 5 1 4 2 5 6 3 0 0 0 0 0 0 0 0

Input

-1 -7 -6 5 1 -5 -2 7 -3 -8 0 8 9 1 -8 -1 6 -4 1 -2 1 -7 5 4 -6 7 -3 9 8 3 -1 0 -5 -7 3 8 1 1 3 -3 -2 -2 0 -7 0 -4 8 6 -3 6 0 5 3 2 2 2 -2 -7 -3 9 -1 6 0 6 -7 9 4 -2 8 -8 -4 1 -8 4 3 7 3 5 1 0 3 3 7 -1 -5 1 -3 4 -7 0 3 2 -2 7 -3 0 0 2 -5 8 -3 -2 -7 -5 7 -3 -9 -7 5 8 -3 9 6 7 -2 4 7

Output

-1 -7 -6 5 1 -5 -2 7 -3 -8 8 9 1 -8 -1 6 -4 1 -2 1 -7 5 4 -6 7 -3 9 8 3 -1 -5 -7 3 8 1 1 3 -3 -2 -2 -7 -4 8 6 -3 6 5 3 2 2 2 -2 -7 -3 9 -1 6 6 -7 9 4 -2 8 -8 -4 1 -8 4 3 7 3 5 1 3 3 7 -1 -5 1 -3 4 -7 3 2 -2 7 -3 2 -5 8 -3 -2 -7 -5 7 -3 -9 -7 5 8 -3 9 6 7 -2 4 7 0 0 0 0 0 0 0 0 0 0

Example Code (Java)
public class Consolidate {
    public static void main(String[] args) throws Exception {
        int[] toConsolidate = new int[args.length];
        for (int i=0; i<args.length; i++){
            toConsolidate[i]=Integer.parseInt(args[i]);
        }
        for (int i=0; i<toConsolidate.length; i++) {
            for (int k=0; k<toConsolidate.length-1; k++) {
                if (toConsolidate[k] == 0){
                    toConsolidate[k] = toConsolidate[k+1];
                    toConsolidate[k+1] = 0;
                }
            }
        }
        for (int i:toConsolidate)
            System.out.print(i+" ");
    }
}

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{0, 5, 8, 8, 3, 5, 1, 6, 8, 4, 0, 3, 7, 5, 6, 4, 4, 7, 5, 6, 7, 4, 4, 9, 1, 0, 5, 7, 9, 3, 0, 2, 2, 4, 3, 0, 4, 8, 7, 3, 1, 4, 7, 5, 1, 2, 1, 8, 7, 8, 7, 7, 2, 6, 3, 1, 2, 8, 5, 1, 4, 2, 0, 5, 0, 6, 0, 3},
		[]int{5, 8, 8, 3, 5, 1, 6, 8, 4, 3, 7, 5, 6, 4, 4, 7, 5, 6, 7, 4, 4, 9, 1, 5, 7, 9, 3, 2, 2, 4, 3, 4, 8, 7, 3, 1, 4, 7, 5, 1, 2, 1, 8, 7, 8, 7, 7, 2, 6, 3, 1, 2, 8, 5, 1, 4, 2, 5, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0},
	)

	test(
		[]int{-1, -7, -6, 5, 1, -5, -2, 7, -3, -8, 0, 8, 9, 1, -8, -1, 6, -4, 1, -2, 1, -7, 5, 4, -6, 7, -3, 9, 8, 3, -1, 0, -5, -7, 3, 8, 1, 1, 3, -3, -2, -2, 0, -7, 0, -4, 8, 6, -3, 6, 0, 5, 3, 2, 2, 2, -2, -7, -3, 9, -1, 6, 0, 6, -7, 9, 4, -2, 8, -8, -4, 1, -8, 4, 3, 7, 3, 5, 1, 0, 3, 3, 7, -1, -5, 1, -3, 4, -7, 0, 3, 2, -2, 7, -3, 0, 0, 2, -5, 8, -3, -2, -7, -5, 7, -3, -9, -7, 5, 8, -3, 9, 6, 7, -2, 4, 7},
		[]int{-1, -7, -6, 5, 1, -5, -2, 7, -3, -8, 8, 9, 1, -8, -1, 6, -4, 1, -2, 1, -7, 5, 4, -6, 7, -3, 9, 8, 3, -1, -5, -7, 3, 8, 1, 1, 3, -3, -2, -2, -7, -4, 8, 6, -3, 6, 5, 3, 2, 2, 2, -2, -7, -3, 9, -1, 6, 6, -7, 9, 4, -2, 8, -8, -4, 1, -8, 4, 3, 7, 3, 5, 1, 3, 3, 7, -1, -5, 1, -3, 4, -7, 3, 2, -2, 7, -3, 2, -5, 8, -3, -2, -7, -5, 7, -3, -9, -7, 5, 8, -3, 9, 6, 7, -2, 4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	consolidate(a)
	fmt.Println(a)
	assert(reflect.DeepEqual(a, r))
}

func consolidate(a []int) []int {
	n := len(a)
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			if a[j] == 0 {
				a[j], a[j+1] = a[j+1], 0
			}
		}
	}
	return a
}
