/*

United States senators are sorted into three classes, based on what year their six-year term starts. Since each state has two senators, each state has a senator in two of the three classes.

Given a full state name and a class number (1, 2, or 3), output truthy if that state has a senator of that class, and falsey if that state does not have a senator of that class.

States with Class 1 senators:

    Arizona, California, Connecticut, Delaware, Florida, Hawaii, Indiana, Maine, Maryland, Massachusetts, Michigan, Minnesota, Mississippi, Missouri, Montana, Nebraska, Nevada, New Jersey, New Mexico, New York, North Dakota, Ohio, Pennsylvania, Rhode Island, Tennessee, Texas, Utah, Vermont, Virginia, Washington, West Virginia, Wisconsin, Wyoming

States with Class 2 senators:

    Alabama, Alaska, Arkansas, Colorado, Delaware, Georgia, Idaho, Illinois, Iowa, Kansas, Kentucky, Louisiana, Maine, Massachusetts, Michigan, Minnesota, Mississippi, Montana, Nebraska, New Hampshire, New Jersey, New Mexico, North Carolina, Oklahoma, Oregon, Rhode Island, South Carolina, South Dakota, Tennessee, Texas, Virginia, West Virginia, Wyoming

States with Class 3 senators:

    Alabama, Alaska, Arizona, Arkansas, California, Colorado, Connecticut, Florida, Georgia, Hawaii, Idaho, Illinois, Indiana, Iowa, Kansas, Kentucky, Louisiana, Maryland, Missouri, Nevada, New Hampshire, New York, North Carolina, North Dakota, Ohio, Oklahoma, Oregon, Pennsylvania, South Carolina, South Dakota, Utah, Vermont, Washington, Wisconsin

Test Cases

"Rhode Island", 1 -> true
"Rhode Island", 2 -> true
"Rhode Island", 3 -> false
"California", 1 -> true
"California", 2 -> false
"California", 3 -> true
"South Dakota", 1 -> false
"South Dakota", 2 -> true
"South Dakota", 3 -> true

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	int kind;
} Class;

int
cmp(const void *a, const void *b)
{
	const Class *x, *y;

	x = a;
	y = b;
	return strcmp(x->name, y->name);
}

bool
classify(const char *s, int k)
{
	static const Class ctab[] = {
	    {"Alabama", 0x6},
	    {"Alaska", 0x6},
	    {"Arizona", 0x5},
	    {"Arkansas", 0x6},
	    {"California", 0x5},
	    {"Colorado", 0x6},
	    {"Connecticut", 0x5},
	    {"Delaware", 0x3},
	    {"Florida", 0x5},
	    {"Georgia", 0x6},
	    {"Hawaii", 0x5},
	    {"Idaho", 0x6},
	    {"Illinois", 0x6},
	    {"Indiana", 0x5},
	    {"Iowa", 0x6},
	    {"Kansas", 0x6},
	    {"Kentucky", 0x6},
	    {"Louisiana", 0x6},
	    {"Maine", 0x3},
	    {"Maryland", 0x5},
	    {"Massachusetts", 0x3},
	    {"Michigan", 0x3},
	    {"Minnesota", 0x3},
	    {"Mississippi", 0x3},
	    {"Missouri", 0x5},
	    {"Montana", 0x3},
	    {"Nebraska", 0x3},
	    {"Nevada", 0x5},
	    {"New Hampshire", 0x6},
	    {"New Jersey", 0x3},
	    {"New Mexico", 0x3},
	    {"New York", 0x5},
	    {"North Carolina", 0x6},
	    {"North Dakota", 0x5},
	    {"Ohio", 0x5},
	    {"Oklahoma", 0x6},
	    {"Oregon", 0x6},
	    {"Pennsylvania", 0x5},
	    {"Rhode Island", 0x3},
	    {"South Carolina", 0x6},
	    {"South Dakota", 0x6},
	    {"Tennessee", 0x3},
	    {"Texas", 0x3},
	    {"Utah", 0x5},
	    {"Vermont", 0x5},
	    {"Virginia", 0x3},
	    {"Washington", 0x5},
	    {"West Virginia", 0x3},
	    {"Wisconsin", 0x5},
	    {"Wyoming", 0x3},
	};
	Class c, *p;

	memset(&c, 0, sizeof(c));
	snprintf(c.name, sizeof(c.name), "%s", s);
	p = bsearch(&c, ctab, nelem(ctab), sizeof(c), cmp);
	if (!p || (k < 1 || k > 3))
		return false;
	return (p->kind & (1 << (k - 1))) != 0;
}

int
main(void)
{
	assert(classify("Rhode Island", 1) == true);
	assert(classify("Rhode Island", 2) == true);
	assert(classify("Rhode Island", 3) == false);
	assert(classify("California", 1) == true);
	assert(classify("California", 2) == false);
	assert(classify("California", 3) == true);
	assert(classify("South Dakota", 1) == false);
	assert(classify("South Dakota", 2) == true);
	assert(classify("South Dakota", 3) == true);

	return 0;
}
