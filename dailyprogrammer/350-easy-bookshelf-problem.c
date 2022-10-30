/*

Description

You have an enormous book collection and want to buy some shelfs. You go to a bookshelfstore and they sell all kinds of shelfs. The wierd part is, some shelfs are different in length but they all cost the same.

You now want to puzzle your collection so that you can fit as many books on the least number of shelfs
Formal Inputs & Outputs
Input description

The first line are the available bookshelfs in the store, seperated by a space.

From the second line on you get the book collections with the width followed by a title
Example 1

150 150 300 150 150
70 A Game of Thrones
76 A Clash of Kings
99 A Storm of Swords
75 A Feasts for Crows
105 A Dance With Dragons

Example 2

500 500 500
1309 Artamene
303 A la recherche du temps perdu
399 Mission Earth

Output description

The number of bookshelfs you have to buy. If you can't fit them, even just one, you respond with imposible.
Example 1

2

Example 2

imposible

Challenge Input

270 142 501 865 384 957 947 603 987 428 907 10 691 707 397 917 492 750 935 672 935 712 234 683 702 508 822 379 36 59 382 280 867 155 829 756 360 995 526 52 559 250 450 843 523 446 972 555 55 985 81 831 43 802 473 379 461 639 910 529 128 878 914 426 569 59 139 913 69 649 501 889 470 112 92 6 80 571 220 22 676 91 889 799 115 194 555 477 277 718 378 838 822 358 178 562 674
96 b400786
69 b390773
174 b410413
189 b337528
80 b308576
194 b151872
190 b174310
157 b272731
45 b326576
112 b379689
177 b18459
122 b915759
138 b967342
96 b786519
184 b718074
75 b696975
192 b46366
168 b533904
45 b885475
186 b872991
63 b231207
162 b912709
123 b786720
7 b743805
120 b862301
54 b929784
89 b61876
168 b775890
87 b850242
60 b695331
0 b56157
139 b875241
78 b281324
122 b236962
1 b79403
68 b213353
103 b650997
97 b955752
177 b815100
139 b958679
43 b829736
163 b445471
94 b472821
167 b5429
57 b946679
13 b748794
146 b920913
17 b547056
33 b437091
12 b247401
120 b228908
178 b509018
98 b482352
152 b915322
14 b874214
71 b164605
11 b457140
35 b502201
5 b15232
49 b641136
166 b385360
183 b78285
199 b274935
195 b424221
79 b422570
150 b502699
41 b662132
63 b430898
111 b813368
100 b700970
157 b803925
140 b611243
25 b877197
136 b577201
94 b50211
56 b762270
120 b578094
21 b672002
9 b107630
156 b547721
186 b911854
71 b594375
32 b330202
3 b464002
36 b718293
44 b282975
130 b826246
77 b529800
117 b66381
89 b949447
133 b348326
178 b517646
184 b809038
105 b70260
182 b894577
123 b203409
79 b174217
159 b552286
40 b854638
78 b159990
139 b743008
1 b714402
153 b923819
107 b201001
48 b567066
138 b570537
100 b64396
139 b412215
132 b805036
121 b772401
120 b370907
51 b388905
77 b442295
152 b195720
46 b453542

Notes/Hints

If a book is 78 wide and a bookshelf is 80 you can't fit a book on it anymore and you lose that 2 space.
Bonus 1

List the shelfs you are going to use
Bonus 2

List the books on each shelf, if imposible list the books that don't fit.
Finally

Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

typedef struct {
	uvlong width;
	char title[32];
} Book;

int
wcmp(const void *a, const void *b)
{
	uvlong x, y;

	x = *(uvlong *)a;
	y = *(uvlong *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

uvlong
fit(uvlong *w, size_t nw, Book *b, size_t nb)
{
	size_t i;
	uvlong t;

	qsort(w, nw, sizeof(*w), wcmp);

	t = 0;
	for (i = 0; i < nb; i++)
		t += b[i].width;

	for (i = nw; i > 0; i--) {
		if (w[i - 1] >= t)
			return nw - i + 1;
		t -= w[i - 1];
	}

	return 0;
}

void
test(uvlong *w, size_t nw, Book *b, size_t nb, uvlong r)
{
	assert(fit(w, nw, b, nb) == r);
}

int
main(void)
{
	uvlong w1[] = {150, 150, 300, 150, 150};
	Book b1[] = {
	    {70, "A Game of Thrones"},
	    {76, "A Clash of Kings"},
	    {99, "A Storm of Swords"},
	    {75, "A Feasts for Crows"},
	    {105, "A Dance With Dragons"},
	};

	uvlong w2[] = {500, 500, 500};
	Book b2[] = {
	    {1309, "Artamene"},
	    {303, "A la recherche du temps perdu"},
	    {399, "Mission Earth"},
	};

	uvlong w3[] = {270, 142, 501, 865, 384, 957, 947, 603, 987, 428, 907, 10, 691, 707, 397, 917, 492, 750, 935, 672, 935, 712, 234, 683, 702, 508, 822, 379, 36, 59, 382, 280, 867, 155, 829, 756, 360, 995, 526, 52, 559, 250, 450, 843, 523, 446, 972, 555, 55, 985, 81, 831, 43, 802, 473, 379, 461, 639, 910, 529, 128, 878, 914, 426, 569, 59, 139, 913, 69, 649, 501, 889, 470, 112, 92, 6, 80, 571, 220, 22, 676, 91, 889, 799, 115, 194, 555, 477, 277, 718, 378, 838, 822, 358, 178, 562, 674};
	Book b3[] = {
	    {96, "b400786"},
	    {69, "b390773"},
	    {174, "b410413"},
	    {189, "b337528"},
	    {80, "b308576"},
	    {194, "b151872"},
	    {190, "b174310"},
	    {157, "b272731"},
	    {45, "b326576"},
	    {112, "b379689"},
	    {177, "b18459"},
	    {122, "b915759"},
	    {138, "b967342"},
	    {96, "b786519"},
	    {184, "b718074"},
	    {75, "b696975"},
	    {192, "b46366"},
	    {168, "b533904"},
	    {45, "b885475"},
	    {186, "b872991"},
	    {63, "b231207"},
	    {162, "b912709"},
	    {123, "b786720"},
	    {7, "b743805"},
	    {120, "b862301"},
	    {54, "b929784"},
	    {89, "b61876"},
	    {168, "b775890"},
	    {87, "b850242"},
	    {60, "b695331"},
	    {0, "b56157"},
	    {139, "b875241"},
	    {78, "b281324"},
	    {122, "b236962"},
	    {1, "b79403"},
	    {68, "b213353"},
	    {103, "b650997"},
	    {97, "b955752"},
	    {177, "b815100"},
	    {139, "b958679"},
	    {43, "b829736"},
	    {163, "b445471"},
	    {94, "b472821"},
	    {167, "b5429"},
	    {57, "b946679"},
	    {13, "b748794"},
	    {146, "b920913"},
	    {17, "b547056"},
	    {33, "b437091"},
	    {12, "b247401"},
	    {120, "b228908"},
	    {178, "b509018"},
	    {98, "b482352"},
	    {152, "b915322"},
	    {14, "b874214"},
	    {71, "b164605"},
	    {11, "b457140"},
	    {35, "b502201"},
	    {5, "b15232"},
	    {49, "b641136"},
	    {166, "b385360"},
	    {183, "b78285"},
	    {199, "b274935"},
	    {195, "b424221"},
	    {79, "b422570"},
	    {150, "b502699"},
	    {41, "b662132"},
	    {63, "b430898"},
	    {111, "b813368"},
	    {100, "b700970"},
	    {157, "b803925"},
	    {140, "b611243"},
	    {25, "b877197"},
	    {136, "b577201"},
	    {94, "b50211"},
	    {56, "b762270"},
	    {120, "b578094"},
	    {21, "b672002"},
	    {9, "b107630"},
	    {156, "b547721"},
	    {186, "b911854"},
	    {71, "b594375"},
	    {32, "b330202"},
	    {3, "b464002"},
	    {36, "b718293"},
	    {44, "b282975"},
	    {130, "b826246"},
	    {77, "b529800"},
	    {117, "b66381"},
	    {89, "b949447"},
	    {133, "b348326"},
	    {178, "b517646"},
	    {184, "b809038"},
	    {105, "b70260"},
	    {182, "b894577"},
	    {123, "b203409"},
	    {79, "b174217"},
	    {159, "b552286"},
	    {40, "b854638"},
	    {78, "b159990"},
	    {139, "b743008"},
	    {1, "b714402"},
	    {153, "b923819"},
	    {107, "b201001"},
	    {48, "b567066"},
	    {138, "b570537"},
	    {100, "b64396"},
	    {139, "b412215"},
	    {132, "b805036"},
	    {121, "b772401"},
	    {120, "b370907"},
	    {51, "b388905"},
	    {77, "b442295"},
	    {152, "b195720"},
	    {46, "b453542"},
	};

	test(w1, nelem(w1), b1, nelem(b1), 2);
	test(w2, nelem(w2), b2, nelem(b2), 0);
	test(w3, nelem(w3), b3, nelem(b3), 13);

	return 0;
}
