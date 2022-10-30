/*

The input for the continuous knapsack problem is as follows.

For each item 1...n we are given a positive weight and profit. Overall we are also given a positive capacity which is the maximum weight we can carry.

The goal is to pick items so that the profit is maximized without exceeding the capacity. This is hard if you can only pick either 1 or 0 of each item. But in the continuous version we are allowed to pick a fraction of an item as well.

A simple solution is to compute di=pi/wi for each item i (wi is the weight and pi is the profit for item i).
We can then sort the di from largest to smallest, picking each item from biggest to smallest while the capacity has not been reached and possibly a fraction of the final item which is chosen.
This take O(nlogn) time because of the sorting step.

Examples

Capacity 20

Profit Weight
9 6
11 5
13 9
15 7

Optimal profit 37.89.

For the optimal solution in this case we have chosen items with profits 11, 15 and 9 to start with. These have total weight 18 and profit 35. We now have 20-2 = 2 left before we reach weight capacity and the only remaining items has weight 9.
So we take 2/9 of that item which gives us 2/9 of the profit 13. 35+(2/9)*13 = 37.8888....

If you increase the capacity to 50, say, then the optimal profit is 9+11+13+15 = 48.

Capacity 879

Profit Weight
91 84
72 83
90 43
46 4
55 44
8 6
35 82
75 92
61 25
15 83
77 56
40 18
63 58
75 14
29 48
75 70
17 96
78 32
40 68
44 92

The optimal profit is 1036.93.

Here is a larger example:

Capacity 995

Profit Weight
94 485
506 326
416 248
992 421
649 322
237 795
457 43
815 845
446 955
422 252
791 9
359 901
667 122
598 94
7 738
544 574
334 715
766 882
994 367
893 984
633 299
131 433
428 682
700 72
617 874
874 138
720 856
419 145
794 995
196 529
997 199
116 277
908 97
539 719
707 242
569 107
537 122
931 70
726 98
487 600
772 645
513 267
81 972
943 895
58 213
303 748
764 487
536 923
724 29
789 674
479 540
142 554
339 467
641 46
196 710
494 553
66 191
824 724
208 730
711 988
800 90
314 340
289 549
401 196
466 865
689 678
833 570
225 936
244 722
849 651
113 123
379 431
361 508
65 585
486 853
686 642
286 992
889 725
24 286
491 812
891 859
90 663
181 88
214 179
17 187
472 619
418 261
419 846
356 192
682 261
306 514
201 886
385 530
952 849
500 294
194 799
737 391
324 330
992 298
224 790

The optimal profit in this example is 9279.65.

Challenge

You can take the input in any form you like although please make it as easy as possible for me to test. Your code must output the optimal profit correct to within +- 0.01.

Most importantly, your code must run in linear time. This means you cannot use sorting to solve the problem. Your code can be either worst case linear or expected running linear.

However, this is still a code-golf challenge, so the shortest submission in bytes per language wins, but the complexity is restricted to linear.

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	b1 := [][2]float64{
		{9, 6},
		{11, 5},
		{13, 9},
		{15, 7},
	}

	b2 := [][2]float64{
		{91, 84},
		{72, 83},
		{90, 43},
		{46, 4},
		{55, 44},
		{8, 6},
		{35, 82},
		{75, 92},
		{61, 25},
		{15, 83},
		{77, 56},
		{40, 18},
		{63, 58},
		{75, 14},
		{29, 48},
		{75, 70},
		{17, 96},
		{78, 32},
		{40, 68},
		{44, 92},
	}

	b3 := [][2]float64{
		{94, 485},
		{506, 326},
		{416, 248},
		{992, 421},
		{649, 322},
		{237, 795},
		{457, 43},
		{815, 845},
		{446, 955},
		{422, 252},
		{791, 9},
		{359, 901},
		{667, 122},
		{598, 94},
		{7, 738},
		{544, 574},
		{334, 715},
		{766, 882},
		{994, 367},
		{893, 984},
		{633, 299},
		{131, 433},
		{428, 682},
		{700, 72},
		{617, 874},
		{874, 138},
		{720, 856},
		{419, 145},
		{794, 995},
		{196, 529},
		{997, 199},
		{116, 277},
		{908, 97},
		{539, 719},
		{707, 242},
		{569, 107},
		{537, 122},
		{931, 70},
		{726, 98},
		{487, 600},
		{772, 645},
		{513, 267},
		{81, 972},
		{943, 895},
		{58, 213},
		{303, 748},
		{764, 487},
		{536, 923},
		{724, 29},
		{789, 674},
		{479, 540},
		{142, 554},
		{339, 467},
		{641, 46},
		{196, 710},
		{494, 553},
		{66, 191},
		{824, 724},
		{208, 730},
		{711, 988},
		{800, 90},
		{314, 340},
		{289, 549},
		{401, 196},
		{466, 865},
		{689, 678},
		{833, 570},
		{225, 936},
		{244, 722},
		{849, 651},
		{113, 123},
		{379, 431},
		{361, 508},
		{65, 585},
		{486, 853},
		{686, 642},
		{286, 992},
		{889, 725},
		{24, 286},
		{491, 812},
		{891, 859},
		{90, 663},
		{181, 88},
		{214, 179},
		{17, 187},
		{472, 619},
		{418, 261},
		{419, 846},
		{356, 192},
		{682, 261},
		{306, 514},
		{201, 886},
		{385, 530},
		{952, 849},
		{500, 294},
		{194, 799},
		{737, 391},
		{324, 330},
		{992, 298},
		{224, 790},
	}

	test(20, b1, 37.89)
	test(50, b1, 48)
	test(879, b2, 1036.93)
	test(995, b3, 9279.65)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(w float64, b [][2]float64, r float64) {
	p := knapsackf(w, b)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-2)
}

func knapsackf(w float64, b [][2]float64) float64 {
	d := make([]item, len(b))
	for i := range d {
		d[i].index = i
		d[i].value = b[i][0] / b[i][1]
	}
	sort.Slice(d, func(i, j int) bool {
		return d[i].value > d[j].value
	})

	p := 0.0
	r := 0.0
	for _, v := range d {
		i := v.index
		f := 1.0
		q := p + b[i][1]
		if q > w {
			f, q = (w-p)/b[i][1], w
		}

		r += b[i][0] * f
		if p = q; p >= w {
			break
		}
	}
	return r
}

type item struct {
	index int
	value float64
}
