/*

A man lives in the north-west corner (0, 0) of a town with height h and width w . Everyday he walks from his home to the border (?, w) or (h, ?). In the following example, the man goes to (3, 3) today.

(0, 0) +--+  +  +  . (0, 4)
          |
       +  +--+--+  .
                |
       +  +  +  +  .
                |
(3, 0) .  .  .  .  . (3, 4)
The man records a bit at each points (+ in example above). Every time he reaches a point, he goes east if the bit is 1 and south otherwise. The bit is flipped after he leaves. For example:

Day 1: 1--0  1  1    Day 2: 0  1  1  1    Day 3: 1--1--1--1--  Day 4: 0  0  0  0
          |                 |                                         |
       0  1--0  0           0  0  1  0           1  0  1  0           1--0  1  0
             |              |                                            |
       1  0  1--0           1--0  0  1           0  1  0  1           0  1--0  1
                |              |                                            |
Destination: (3, 3)  Destination: (3, 1)  Destination: (0, 4)  Destination: (3, 2)
Given the size of the town and the man's record, calculate the man's destination after n days.

Input:
In the first line are three integers, h, w and n.

In the following h lines are w integers, denoting the man's record.

h <= 1000, w <= 1000, n <= 1000000000

Output:
Two integers, denoting the man's destination after n days.

Sample Input:
3 4 3
1 0 1 1
0 1 0 0
1 0 1 0
Sample Output:
0 4

Sample Code:
#include <iostream>
using namespace std;
bool d[1000][1000];
int main(){
    int h, w, n;
    cin >> h >> w >> n;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> d[i][j];
    int i, j;
    while(n--)
        for(i = 0, j = 0; i < h && j < w;){
            bool &b = d[i][j];
            d[i][j] ? j++ : i++;
            b = !b;
        }
    cout << i << " " << j << endl;
}

Scoring:

Lowest byte count in UTF-8 wins.
If the running time of your code is independent of n, reduce your score by 50%.
Don't just calculate the results of all 1000000000 days or do anything similarly stupid to get this bonus. Find an efficient algorithm!

*/

package main

import "fmt"

func main() {
	fmt.Println(destination([][]int{
		{1, 0, 1, 1},
		{0, 1, 0, 0},
		{1, 0, 1, 0},
	}, 3))
}

func destination(m [][]int, n int) (int, int) {
	if len(m) == 0 || len(m[0]) == 0 {
		return 0, 0
	}

	h, w := len(m), len(m[0])
	i, j, v := 0, 0, 0
	for ; n > 0; n-- {
		for i, j = 0, 0; i < h && j < w; {
			v, m[i][j] = m[i][j], flip(m[i][j])
			if v != 0 {
				j++
			} else {
				i++
			}
		}
	}

	return i, j
}

func flip(v int) int {
	if v != 0 {
		return 0
	}
	return 1
}
