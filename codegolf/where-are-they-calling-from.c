/*

When making phone calls internationally, phone numbers are prefixed with a code indicating what country the number is located in. These codes are prefix codes, meaning that no code is a prefix of another.

Now, earlier today you missed a call, and you're kind of curious where that call might have come from. So you want to look up the calling code.
But, being a prefix code, you're not quite sure where it ends, so you decide to write a program to separate the calling code from the rest of the number.
Input

As input, you will recieve a string consisting of the digits 0-9. The first few digits will be one of the country calling codes listed below (this means the first digit will never be 0).
After the country calling code, the rest of the input will contain zero or more digits in any order - it is not guaranteed to be a valid phone number. Your program must be able to handle inputs containing at least 15 digits
Output

Your program should output the unique country calling code that is a prefix of the number. The valid outputs are as follows:

1
20
211
212
213
216
218
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
260
261
262
263
264
265
266
267
268
269
27
290
291
297
298
299
30
31
32
33
34
350
351
352
353
354
355
356
357
358
359
36
370
371
372
373
374
375
376
377
378
379
380
381
382
383
385
386
387
389
39
40
41
420
421
423
43
44
45
46
47
48
49
500
501
502
503
504
505
506
507
508
509
51
52
53
54
55
56
57
58
590
591
592
593
594
595
596
597
598
5993
5994
5997
5999
60
61
62
63
64
65
66
670
672
673
674
675
676
677
678
679
680
681
682
683
685
686
687
688
689
690
691
692
7
800
808
81
82
84
850
852
853
855
856
86
870
875
876
877
878
879
880
881
882
883
886
888
90
91
92
93
94
95
960
961
962
963
964
965
966
967
968
970
971
972
973
974
975
976
977
979
98
991
992
993
994
995
996
998

This list is based on the codes listed on Wikipedia's list of country calling codes page as of revision 915410826, with a few modifications

    All codes listed as unassigned or discontinued and some codes listed as reserved for future use were omitted
    If a code listed on Wikipedia is a prefix of another, the latter was omitted
    If a single country or territory would have more than one code, and if those codes would have a common prefix, those codes are omitted in favour of their common prefix.

This may result in independent countries being lumped together, or disputed territories being lumped in with a particular claimant. This is not intended as a political statement, and decisions about the inclusion or omission of territories and states were made based on the codes, not any beliefs I hold regarding the ownership or sovereignty of the entities using them.

If given an input that does not begin with any of these codes, your program's behaviour is undefined.

And finally:

    This is code-golf, fewer bytes of code is better
    Your submission may be either a function or a full program
    Any of the default I/O methods are fine
    The standard loopholes are forbidden

Test cases
input 	output
5292649259 	52
3264296721 	32
1550 	1
33121394 	33
7 	7
2542112543 	254
2005992972 	20
350 	350
360 	36
8505234469 	850
9795586334 	979
148985513598795 	1
222222 	222
5999995 	5999

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const char *const *p;

	p = b;
	return strncmp(a, *p, strlen(*p));
}

const char *
callprefix(const char *s)
{
	static const char *tab[] = {
	    "1",
	    "20",
	    "211",
	    "212",
	    "213",
	    "216",
	    "218",
	    "220",
	    "221",
	    "222",
	    "223",
	    "224",
	    "225",
	    "226",
	    "227",
	    "228",
	    "229",
	    "230",
	    "231",
	    "232",
	    "233",
	    "234",
	    "235",
	    "236",
	    "237",
	    "238",
	    "239",
	    "240",
	    "241",
	    "242",
	    "243",
	    "244",
	    "245",
	    "246",
	    "247",
	    "248",
	    "249",
	    "250",
	    "251",
	    "252",
	    "253",
	    "254",
	    "255",
	    "256",
	    "257",
	    "258",
	    "260",
	    "261",
	    "262",
	    "263",
	    "264",
	    "265",
	    "266",
	    "267",
	    "268",
	    "269",
	    "27",
	    "290",
	    "291",
	    "297",
	    "298",
	    "299",
	    "30",
	    "31",
	    "32",
	    "33",
	    "34",
	    "350",
	    "351",
	    "352",
	    "353",
	    "354",
	    "355",
	    "356",
	    "357",
	    "358",
	    "359",
	    "36",
	    "370",
	    "371",
	    "372",
	    "373",
	    "374",
	    "375",
	    "376",
	    "377",
	    "378",
	    "379",
	    "380",
	    "381",
	    "382",
	    "383",
	    "385",
	    "386",
	    "387",
	    "389",
	    "39",
	    "40",
	    "41",
	    "420",
	    "421",
	    "423",
	    "43",
	    "44",
	    "45",
	    "46",
	    "47",
	    "48",
	    "49",
	    "500",
	    "501",
	    "502",
	    "503",
	    "504",
	    "505",
	    "506",
	    "507",
	    "508",
	    "509",
	    "51",
	    "52",
	    "53",
	    "54",
	    "55",
	    "56",
	    "57",
	    "58",
	    "590",
	    "591",
	    "592",
	    "593",
	    "594",
	    "595",
	    "596",
	    "597",
	    "598",
	    "5993",
	    "5994",
	    "5997",
	    "5999",
	    "60",
	    "61",
	    "62",
	    "63",
	    "64",
	    "65",
	    "66",
	    "670",
	    "672",
	    "673",
	    "674",
	    "675",
	    "676",
	    "677",
	    "678",
	    "679",
	    "680",
	    "681",
	    "682",
	    "683",
	    "685",
	    "686",
	    "687",
	    "688",
	    "689",
	    "690",
	    "691",
	    "692",
	    "7",
	    "800",
	    "808",
	    "81",
	    "82",
	    "84",
	    "850",
	    "852",
	    "853",
	    "855",
	    "856",
	    "86",
	    "870",
	    "875",
	    "876",
	    "877",
	    "878",
	    "879",
	    "880",
	    "881",
	    "882",
	    "883",
	    "886",
	    "888",
	    "90",
	    "91",
	    "92",
	    "93",
	    "94",
	    "95",
	    "960",
	    "961",
	    "962",
	    "963",
	    "964",
	    "965",
	    "966",
	    "967",
	    "968",
	    "970",
	    "971",
	    "972",
	    "973",
	    "974",
	    "975",
	    "976",
	    "977",
	    "979",
	    "98",
	    "991",
	    "992",
	    "993",
	    "994",
	    "995",
	    "996",
	    "998",
	};

	const char **p;

	p = bsearch(s, tab, nelem(tab), sizeof(*tab), cmp);
	return (p) ? *p : NULL;
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = callprefix(s);
	if (p == NULL)
		assert(r == NULL);
	else
		assert(!strcmp(p, r));
}

int
main(void)
{
	test("5292649259", "52");
	test("3264296721", "32");
	test("1550", "1");
	test("33121394", "33");
	test("7", "7");
	test("2542112543", "254");
	test("2005992972", "20");
	test("350", "350");
	test("360", "36");
	test("8505234469", "850");
	test("9795586334", "979");
	test("148985513598795", "1");
	test("222222", "222");
	test("5999995", "5999");
	test("does-not-exist", NULL);

	return 0;
}
