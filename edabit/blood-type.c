/*

When a person receives a blood transfusion, it is essential to make sure that the donor's blood type is compatible with the receiver's blood type.
Receiving a blood type that is not compatible with your own can be life-threating, so blood banks always make sure to note the type of blood they receive from donors so that they can ensure a safe transfusion.

Blood types are named according to three factors: presence of antigen A, presence of antigen B, and presence of Rh factor. If antigen A is found, the blood type includes the letter "A". If antigen B is found, the blood type includes the letter "B". And if the Rh factor is present, the blood type ends with "+"; otherwise, it ends with "-". If neither antigen A nor antigen B are found, the blood type includes the letter "O".

For example, a person with only antigen A would have the blood type "A-". A person with both antigens A and B and the Rh factor would have blood type "AB+", and a person wih only the Rh factor would have blood type "O+".

The rules for giving and receiving blood are as follows:

    A person with antigen A may only give blood to another person with antigen A.
    A person with antigen B may only give blood to another person with antigen B.
    A person with the Rh factor may only give blood to another person with the Rh factor.
    A person with none of the above factors (O-) can give blood to anyone.

Write a function that takes in a donor's and receiver's blood types as strings and returns whether or not the donor can safely give blood to the receiver, according to the rules above.
Examples

canGiveBlood("O+", "A+") ➞ true

canGiveBlood("A-", "B-") ➞ false

canGiveBlood("A-", "AB+") ➞ true

Notes

    All letters are capital.
    Each blood type will be one of the following strings: "O+", "O-", "A+", "A-", "B+", "B-", "AB+", "AB-".

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
giveblood(const char *s, const char *t)
{
	static const struct {
		const char *name;
		int value;
	} tab[] = {
	    {"O-", 0xff},
	    {"O+", 0xaa},
	    {"A-", 0xcc},
	    {"A+", 0x88},
	    {"B-", 0xf0},
	    {"B+", 0xa0},
	    {"AB-", 0x80},
	    {"AB+", 0xc0},
	};

	size_t i;
	int d, r;

	d = r = 0;
	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i].name))
			d = tab[i].value;
		if (!strcmp(t, tab[i].name))
			r = 1 << i;
	}
	return (d & r) != 0;
}

int
main(void)
{
	assert(giveblood("O+", "A+") == true);
	assert(giveblood("A-", "B-") == false);
	assert(giveblood("A-", "AB+") == true);
	assert(giveblood("AB-", "B-") == false);
	assert(giveblood("AB+", "A+") == false);
	assert(giveblood("O-", "A-") == true);
	assert(giveblood("A-", "O-") == false);
	assert(giveblood("O+", "AB-") == false);
	assert(giveblood("O-", "AB+") == true);
	assert(giveblood("AB+", "AB+") == true);
	assert(giveblood("O+", "O-") == false);

	return 0;
}
