/*

After an amazing performance, the crowd goes wild! People clap enthusiastically and most claps overlap with each other to create one homogeneous sound.

An overlapped clap is a clap which starts but doesn't finish, as in "ClaClap" (the first clap is cut short and there are overall 2 claps).

Given a string of what the overlapping claps sounded like, return how many claps were made in total.

Notes

Claps will start with a capital letter (to signify how loud they are).

*/

#include <stdio.h>
#include <assert.h>

size_t
claps(const char *s)
{
	size_t i, c;

	for (i = c = 0; s[i]; i++) {
		if (s[i] == 'C')
			c++;
	}
	return c;
}

int
main(void)
{
	assert(claps("ClaClaClaClap!") == 4);
	assert(claps("ClClClaClaClaClap!") == 6);
	assert(claps("CCClaClClap!Clap!ClClClap!") == 9);
	assert(claps("ClCCClaClaClaClCClap!CClaClap!Clap!ClClClClaClaClap!Clap!ClClCClap!Clap!ClClap!ClaCClClap!ClClap!Clap!CClClaClaClaCClaCClaClClaCCCClaClap!Clap!ClaClaClap!ClaClap!CClap!Clap!ClClap!") == 61);
	assert(claps("Clap!ClClaClap!ClaClap!CClap!ClClClap!CClaClap!CClap!ClClap!ClaClaClClap!ClaClap!ClClCClaClaCClaCCCCClClCClap!ClaCClaClCClap!Clap!ClaClaClaCClaClap!") == 52);
	assert(claps("Clap!CClaClClap!ClCClCCClaCClap!ClCCClCClClap!ClClClap!CClap!CClCClap!ClCClap!Clap!Clap!Clap!ClClap!Clap!CClaClClap!ClaClaClaClCClClaClClap!ClaClClaClap!ClaClap!CClClClap!ClClaClClap!Clap!ClaClaClaClaClClap!CClaClClaCClap!ClClClClClap!Clap!CClClap!ClClap!ClaClap!CClClaClaClap!Clap!") == 97);
	assert(claps("CClCClaCClap!Clap!ClaClap!ClCCClap!ClClClClap!ClaClCClClaClap!") == 23);
	assert(claps("Clap!Clap!ClClCClCClClaClaClaCClaClClaClClClClap!CClap!ClClap!ClClClaClaClClaClaClaClaCClClaClap!") == 36);
	assert(claps("ClaCCClClCClClaCClCClap!ClaClClaClap!Clap!ClClClClap!Clap!CClap!CClaClClaClCClaClap!ClaClaClaClap!Clap!ClClap!CCClap!ClClaClap!CClClClap!CClaClaClClaClap!ClClap!ClaCClaClap!Clap!Clap!Clap!CClaCCCClap!ClaClap!ClClap!Clap!CClaClaClaClap!CClaCClap!Clap!CClaCClaClaCClaCClap!") == 94);
	assert(claps("CClClap!Clap!CClCClClaCClaClaClap!ClaClaClaCCCClap!CCClClap!Clap!ClaClaClap!ClClClap!ClCCClap!ClaClaClap!CClap!ClaClap!CClClClap!CClap!CClClaCClClap!ClaClap!ClaClClClCClap!ClaClClap!ClaClaCClap!CClClaClClap!ClaClaClClaClClaClaClap!") == 82);
	assert(claps("ClaCCClCClaClClaClCClaClaClap!Clap!CClaClap!ClaClap!Clap!ClaClap!Clap!") == 23);
	assert(claps("CClClaClClaClClap!Clap!Clap!ClClaClap!ClClClClaClap!CClap!ClaClaCCClap!ClClap!CClap!Clap!Clap!ClaClaClap!ClaClClClaClaClap!ClaClaClap!ClClCClaClaCClClaClap!Clap!Clap!CClClaClaClaClaClCClClaClaCClaClap!ClCClClClap!Clap!Clap!Clap!Clap!CClaClap!Clap!CCClaClCClClaClClClaClaClaClaCClap!Clap!") == 96);
	assert(claps("Clap!ClaClCClaClap!ClCClap!ClClClaClap!ClaClaCClap!ClaClaClap!ClaCClap!Clap!CClClClap!ClClCClaCClCClaCClClClClaClap!ClClaCClap!CCCClap!Clap!ClClap!ClaCClaCClClap!ClClaClap!ClClaClaClaClaCCClClap!CClaClaClap!Clap!ClClap!") == 78);
	assert(claps("Clap!ClaClCClaClaClap!CClaClap!CCClCClap!Clap!Clap!Clap!ClClap!Clap!ClaClaClClap!Clap!ClaClaClap!CClaClap!CCClClap!ClaClaClap!ClClaClaClaClaClap!CClap!ClaClCClaClap!CClClCClaClap!Clap!CClaCClap!") == 63);
	assert(claps("Clap!CClaClap!ClClap!ClClClap!ClaCClap!ClaCClClap!CClap!CClClaClap!ClaClaClCCClap!Clap!CClClaClCClaClaClClap!Clap!CClaCClaCClap!ClaCClClCClap!CClap!CClap!ClaClaClaClaClap!ClClap!CClaClaClaClClaClClCClClCClClaClaCClClap!") == 80);
	assert(claps("CClaCClClap!Clap!Clap!Clap!Clap!Clap!Clap!ClClClap!CClap!CClap!CCClaClClClClClaCClaClap!ClClap!CClaClap!Clap!CCClaClap!Clap!CClClClaClaClaClap!ClaCClap!ClClaClaCClClap!CClap!ClaClap!") == 60);
	assert(claps("ClaCCClap!") == 4);
	assert(claps("ClaClap!ClaClaClap!Clap!") == 6);
	assert(claps("CClap!ClaClaClClap!Clap!ClaCCClap!ClClaClap!CClap!CClap!ClaClClaCClaClap!ClaClap!ClaClClaClaCCClClaClaClap!Clap!") == 37);
	assert(claps("ClClaCClap!ClaCClaClap!Clap!Clap!ClaClClap!ClClaClaClClaClaClaCCClClClClClap!") == 27);
	assert(claps("ClClClCClClap!Clap!CCCClap!ClCCClClap!CCClap!Clap!Clap!CClap!ClaClaCClaCClaClaClaClClap!ClaClCCClClaClap!ClClaClaCClCCClClClap!Clap!ClaClap!ClaClaCClap!ClCCClaClap!ClaClap!CClap!CClaClClaClCClaClap!CClClap!ClClap!Clap!CClap!CClaClaClClaClap!") == 88);
	assert(claps("ClClCClClClaClClCClap!ClCClap!ClaClaClClap!ClaCClClap!ClClaClap!ClaClaClaClap!Clap!Clap!CCCClaClaClaClaClaCClCClaClaClap!Clap!CCCClap!ClaClap!CCClaClaClaClap!ClClClap!CClCCCClap!Clap!CClClClaClap!ClClaCClClap!ClaClClap!ClaClap!ClCClaClaCClap!") == 88);
	assert(claps("ClClap!Clap!CCClClClaClClClClap!Clap!CClap!ClClap!ClClaCCClap!") == 22);
	assert(claps("ClaClaClClClaCClap!ClaClaCCClaClaClClap!CClCClCClClClClap!ClaClap!Clap!ClaCCClap!ClCCClaClClClaCCClaClCClClaClap!ClClaClClaClap!ClClap!Clap!ClaClaClClap!") == 58);
	assert(claps("ClaCClClClClaClClap!ClClap!CCClaCCClClCCClaClap!Clap!CClClClap!ClaCClClaCClaCClClap!ClClClClaCClaClap!Clap!") == 43);
	assert(claps("ClaClCClClCClCClaCCClap!ClaClaCClap!ClaClap!CClaClaClClaCClClaClaClCCClaClap!ClClap!Clap!Clap!ClaCCClap!ClClaClaClap!ClaClap!CCClap!CClap!CClClap!") == 54);
	assert(claps("Clap!ClaCCCCCClClaCCCClaClaClClap!CClaCClaCClap!CClap!CClCClClap!CCCCClaClap!") == 35);
	assert(claps("ClClaClap!Clap!ClCClaClaCClaCClaClap!CCClaCClaClClap!Clap!ClCCCClaClaClap!Clap!ClaClap!ClaClClap!ClCClCClaClClap!CClaClap!ClClClaCClaCClap!Clap!ClCClCClap!ClaCCClClap!Clap!Clap!CClaClaClap!ClaCClaCClap!") == 73);
	assert(claps("CClaClClaClap!ClClClaCClaClaCClCClCClaClaCClaClap!CCCCClap!ClaCClClaClClap!ClClClap!ClCClaClCClClClap!CClap!ClaClClap!ClCClap!") == 51);
	assert(claps("ClaClaClaCClClap!ClaClap!Clap!ClCCCClaClap!Clap!CCClClClaClaCClClap!CClClaClClap!ClCCClaClClap!Clap!CClaCCCClClap!") == 44);
	assert(claps("CClClap!ClClCClaClClaClaClap!ClaCClClaClaClaClaClap!ClClaClap!Clap!CClap!CClaClClap!ClClap!CClaClClap!ClaCCClap!CCClaClaClClClaClaClClap!CCClClaClClClClap!ClClap!ClaClClClap!Clap!CClaClaClaCClap!Clap!Clap!ClaClClClap!CClaClaClaClaClaCClClClaClap!ClClap!ClClaCClaClaCClClap!Clap!") == 98);
	assert(claps("ClaCClaClap!CClap!ClClaClClaClaClaClCClaCClap!") == 17);
	assert(claps("ClaClClap!") == 3);
	assert(claps("ClClaClap!CClaCClClap!") == 8);
	assert(claps("ClCClaClaClap!Clap!ClaCCClap!CClCClaClClap!CClClap!ClClCCCCClaCClClClaClClCClaClap!Clap!") == 36);
	assert(claps("Clap!CClaCCCClClaClaClaClap!ClClaClClap!") == 15);
	assert(claps("CClap!ClCCCCClClaClap!ClClClap!CClap!ClaClaClaClCCClCCClaClClap!Clap!CClaClClCClap!ClaClClap!ClCClaClaClap!") == 42);
	assert(claps("Clap!ClaCClap!CCCCClaClap!ClClaCClClap!ClaClClap!ClaClClaClaClaClCCCClaClaCClap!Clap!ClaCCClap!ClClap!ClClap!ClClap!CClClClClap!Clap!CClaCClClClap!ClaCClClaCCClClap!CCClap!") == 65);
	assert(claps("Clap!ClCClClap!CCClap!ClClap!ClClaClaClap!ClCClClClaClClap!ClCClap!Clap!Clap!ClCClap!ClCCClCClap!Clap!ClClCClCClap!ClCClaClaClCClap!") == 49);
	assert(claps("ClCClap!ClaClap!CCClClCCClaClClCClaClClap!CClap!CClaClCClClap!ClClap!") == 28);
	assert(claps("Clap!ClaClaCClap!") == 5);
	assert(claps("ClClap!ClClap!ClaCCClap!ClClCClaClaClCClap!Clap!Clap!ClClaCClClaClap!Clap!ClClClClap!ClCCCClaClClap!Clap!ClClClap!ClaCClap!CClaClap!Clap!ClClClaClClClClaClaClClaClaClClClaCCClap!ClaClap!Clap!ClClClap!Clap!Clap!") == 72);
	assert(claps("CClaCClCCClClClap!ClClaCCClap!Clap!Clap!ClClCClClClClaClaCClap!ClClClap!CClap!ClaClClaCCClClaClClap!CClCCCClaClaClCCClap!CClap!Clap!ClaClaClClaClClClaClaCClClap!Clap!CCClaClap!CClClaCClap!ClClClap!Clap!ClaClaClClClClap!Clap!ClaClap!") == 88);
	assert(claps("CClClaCClaClClClaClaClap!Clap!ClaClaCClClaClaCClCClap!") == 21);
	assert(claps("CClap!ClaClap!ClClap!CClaClClaClClap!CCClap!CClCCClap!CClap!Clap!ClClap!ClClap!Clap!ClClap!ClClClaClaCClaClaClCClap!ClaClap!CClap!ClaCClClap!Clap!Clap!Clap!ClClap!ClClClaCCClClap!ClaCCClaClCCClaClap!") == 69);
	assert(claps("CClClap!Clap!ClCCClaClClCClClap!ClClClaCCClClaClaCClap!ClClap!Clap!ClClaClClClaCClaClClClaClClClaCClaClCClap!ClCCClClCClap!CCClClap!CClaClClap!ClCClClaClaClaClap!Clap!CClClap!ClaCClaClClClCClap!ClaClClClaClaCClaClap!") == 86);
	assert(claps("Clap!Clap!ClClap!Clap!CClClaClaCClCClClap!ClClaCClClClCClaClClClaClClCClaCClClClap!ClaClap!ClClaClCCClaClaClaCCClaClap!") == 47);
	assert(claps("ClaClaClClClap!Clap!ClClClClap!") == 10);
	assert(claps("ClaClap!CClap!ClClClClap!CClaClClClap!CCClaClaClap!ClaClap!CClaCClClClaClap!ClClClClCClaCClap!ClClap!Clap!") == 38);
	assert(claps("CCClaClClClClap!Clap!ClCCClClClaClCClCCClClap!") == 21);
	assert(claps("ClClap!") == 2);
	assert(claps("Clap!CCClClClaClap!ClaCClClap!CClClaClClaClap!Clap!ClaClap!") == 20);
	assert(claps("ClaClap!CClaClaClap!CClClClap!ClCClap!Clap!Clap!") == 15);
	assert(claps("ClaCClap!ClClap!ClaCClClaClap!Clap!Clap!") == 12);
	assert(claps("ClClap!ClaClaCCClaClCClap!CClap!ClaClClaClap!CClClap!ClClap!ClaCClaCClaClaClCClaClaClaClClap!ClClap!CClaClap!Clap!CClap!ClCClap!ClaClaClap!ClaClap!ClClClCCClClaCCClaClClaClClClClaClClaClClap!ClaClap!CCClCClaCClClap!ClaClaClap!") == 83);
	assert(claps("ClCClCClap!Clap!ClaClaClap!ClaCClClClap!ClaClaClaClap!ClClaClap!ClCCCClaCCClaClap!CClap!ClClap!ClaClap!CCCCClaClap!Clap!") == 43);
	assert(claps("Clap!ClClClCClap!ClClap!ClClap!ClaClaClap!CClap!") == 15);
	assert(claps("ClaClClap!ClCClaCClap!ClClap!CClaClap!CClClaCClaClap!CClaClaClaCCCCClap!CClaClaClClaClClap!ClClap!ClCClap!Clap!ClClap!CClClaClClap!CClaCClap!CClClap!ClaCClap!Clap!ClaClap!Clap!Clap!ClaClClap!Clap!Clap!ClClaClaClap!CClaClCClap!ClClClClaClaCClaClClClClap!") == 88);
	assert(claps("ClClCClap!ClaClClaCCClaClaCClaClap!CClaClap!ClaCClClaClaClClap!ClaClaClClap!ClClCClaCClClap!") == 35);
	assert(claps("ClaClClClap!Clap!ClClaClClaClaCClClaClap!ClaClClClaClClaClClaClClClaClCClaClap!CCCClap!Clap!CClap!Clap!ClaClap!CClap!ClClap!CClClClaClap!ClClCClaClClap!ClaClClaClaClCClClClap!ClClaClap!Clap!ClaCClClClaCClap!Clap!ClClaClClClClaClClap!ClClap!") == 85);
	assert(claps("CClaClaClaClap!Clap!Clap!") == 7);
	assert(claps("Clap!ClClClaClaClCClap!") == 8);
	assert(claps("ClClap!Clap!Clap!CClCClap!Clap!Clap!CClClaCClap!ClaClap!Clap!ClClaClClCClap!") == 24);
	assert(claps("ClCClap!ClaClaClap!CClap!Clap!ClaClap!ClaClClap!Clap!ClClaClap!ClClClaClaClaClaClaClaClap!") == 27);
	assert(claps("CClap!ClaClClap!ClCClap!CClaCClClaClClap!CClap!CCCClClaClClap!CCClaClaClap!CCClap!Clap!Clap!Clap!ClClaCCCClaClClap!ClaClap!ClaClClaClap!Clap!ClaCClap!Clap!ClClClap!Clap!ClClaCClClaClap!Clap!Clap!ClCCClClap!Clap!ClCClCCClaClap!ClaCCClClClCCClClClaClaClap!Clap!ClaClaCClaClap!") == 98);
	assert(claps("Clap!ClClClaCClap!CClap!ClaCClaClCClap!Clap!CClaCClCCClClClap!ClaClaCCCClClaCClaClClap!CClCClClap!Clap!CCClaClaClClaClaClap!Clap!ClCClaClaClClClap!Clap!ClaClClap!ClClClap!ClaClap!CCClap!ClaClap!ClClap!Clap!ClaClap!ClClClap!Clap!Clap!ClaCCClap!CClap!ClClaCClaClaClap!ClaCClap!ClaClCCClap!") == 101);
	assert(claps("CCCCClClClap!ClaCClClClClaClClClaClClaClaClCCClap!ClClaCClap!CClap!Clap!ClaClap!Clap!Clap!") == 34);
	assert(claps("ClClap!ClCClap!CClaClap!ClCClaCCClap!ClClap!CClap!CCClaClap!Clap!CClaClap!Clap!ClaClaClap!ClaClClClClaClCCCClap!CClap!CClap!CClaClClClClaClaClClClCClCClap!ClaCCClClClCCClClap!CClClap!Clap!ClaCClap!ClaClaCClaClap!ClaClaClap!") == 83);
	assert(claps("Clap!Clap!Clap!ClClClCClClClap!Clap!Clap!ClClClClaClap!ClClClaClap!ClaClap!ClCClap!Clap!ClCClaCClClaClCCClClaCClCClCClaClap!Clap!CClaClap!ClClap!Clap!CCClap!CClaCClClClClap!ClClap!Clap!ClaClaClaCClap!ClClClap!Clap!Clap!") == 75);
	assert(claps("Clap!ClaCClaClClap!ClCClaClClClap!ClClap!Clap!Clap!CClap!ClaClCClaClCClap!Clap!ClaClaClaClaClaClClap!CClCCClaCClap!ClaCClClaCCClClap!CClClCClaClap!ClaClCClCClap!ClaClCClClClap!ClClaClap!ClClap!ClCClaClClaCClaClaClClCClap!Clap!CClap!") == 86);
	assert(claps("ClaCClap!ClClaCCClap!Clap!ClaClap!") == 11);
	assert(claps("Clap!ClaClap!ClaClap!ClCClaClap!Clap!CCClaClaClap!ClaClaClap!ClClaCClClaCClaClClap!ClClClap!ClCClClCClap!Clap!") == 37);
	assert(claps("ClClaClClaClaCClClap!ClaClaClaCClap!CCClClap!ClClaCClClaClaClaClap!ClaCCClaClaClap!ClaCClaClap!") == 35);
	assert(claps("ClClaClClap!ClClaClap!Clap!ClaClClClap!ClaClap!ClaCCClap!Clap!ClClap!ClClaCClClCClClClaClap!ClClClCClaClap!CClap!ClClClap!ClCCClap!Clap!CClClCClaCClCClaClClap!CClaCCClap!CCClaClClap!ClaClClap!Clap!ClaClClap!ClaClaClap!Clap!ClaClap!ClClCClaCClaClClap!") == 89);
	assert(claps("ClaClaClClap!ClaClCCClaClaCClap!CClCClap!Clap!") == 17);
	assert(claps("CCClaCClap!ClClaClaClaClaClaClaCClaClap!Clap!CClClap!CClClaClap!Clap!ClClClaClaCClaCClaClClap!ClClClap!CClaClaClaClap!Clap!ClClap!Clap!ClaCClClClap!ClaClaClap!CCClClap!Clap!ClCCClClaClClCClap!ClaClap!") == 70);
	assert(claps("ClCClaClap!ClClClClap!ClaClaCClaClClClap!CClCClCClClap!CClCClClClClaClCClap!CClaCCCCCClClap!ClaClaClaClClaClaClClaCClClap!Clap!CCClaClClaClap!ClCClap!CClClap!Clap!ClaClClap!CClaClaClap!CClClaClap!Clap!") == 78);
	assert(claps("Clap!ClaClClCClaClCClaClClaClap!Clap!") == 13);
	assert(claps("CClClap!Clap!CClaClap!ClaClap!ClCCClaClClap!ClaCClClaCClap!ClaClClClap!CClap!Clap!") == 28);
	assert(claps("ClClaClap!CCClClClaCCClCClClap!ClaClCClaClClap!ClaClap!ClClaCClClaClaClaCClClaClap!ClClaClap!Clap!CCClClaClap!Clap!CClClClClClaClClCClClaCClap!Clap!ClaClaClCClap!Clap!ClaClaClClap!CClaCClaCClaClClaClap!CClap!ClCClap!CClCClaClaClClaClaClap!Clap!Clap!ClClaClap!Clap!") == 96);
	assert(claps("ClaClap!ClaClCClClClClap!Clap!CClaClap!Clap!CCClaClaCClaCCCCClaClaClaCClClClaClap!ClClap!CClaCClClClap!ClaClCCCClap!ClClClaClClaClClap!") == 53);
	assert(claps("ClClap!CClap!Clap!CClaCClClaCClClCClap!") == 15);
	assert(claps("CClCClap!ClClap!ClCClaClap!Clap!CClaClaClaClClClap!") == 18);
	assert(claps("ClaClCClaCClaClaClClaClClaClap!ClaCCClClaClap!Clap!CClap!ClCClap!CClClClap!ClClap!CClClap!") == 33);
	assert(claps("ClaClap!ClClClap!ClClaClaCCCClaClClap!Clap!ClaClaClap!ClClap!Clap!CClap!Clap!CClClClap!ClaClCClap!Clap!ClClap!ClaCClap!Clap!") == 39);
	assert(claps("ClClap!CCClap!ClClaClaCClCCClap!ClCCCClaClClaClap!ClClClaClClClaCCClaClap!Clap!Clap!ClCClaClaClap!ClaClCCClClClaClClClap!Clap!Clap!ClaCClap!ClClCClaClap!Clap!CClaClap!Clap!") == 63);
	assert(claps("ClaClClCClClClap!ClaClaClap!Clap!ClClap!ClCClap!ClClap!ClaClap!ClaCClaClap!CClaClap!ClaClClaClaClap!ClClaClap!ClaCClap!CClClaCClap!Clap!CCClClCCCClClClClaCClClap!") == 58);
	assert(claps("ClaClap!ClaClClap!ClCClClClaCClap!ClCClaClaClaClaClaCClap!ClClap!Clap!ClClaClCClap!ClaCClaClap!Clap!Clap!CClaCClClap!Clap!CClaClap!ClClClClaClap!ClaClap!") == 51);
	assert(claps("ClCClCClCClClap!ClaClap!ClClaCCClCClaClaClap!CCClaClClap!ClClap!ClaClap!CClap!Clap!ClaClClaClap!Clap!ClClCClaClClClaClaClaClap!") == 46);
	assert(claps("CClClClap!CCClap!CClap!Clap!CClClap!CCClaClClaCClap!ClaCClClCClap!Clap!CClap!ClaCClaClaClaClap!") == 35);
	assert(claps("ClaCClaClap!CClCCClap!ClClap!CClap!Clap!ClCClCCCClCClap!ClaClClCCClaClap!") == 30);
	assert(claps("CClaClClap!CClClClap!ClaClap!CClClClClaClaCCClaClaClap!Clap!Clap!ClaCClap!ClClCClap!ClaClClCCCClap!ClaClap!Clap!CCCCClaClap!CClap!Clap!ClaClClap!ClaClClaClClClap!Clap!") == 59);
	assert(claps("ClClap!ClClaCClaCClap!CCCClap!Clap!ClClClap!Clap!Clap!ClCCClaClClCCClap!ClClap!CCClClap!ClaClap!ClaClap!ClCClap!Clap!ClaClCClClCClap!ClaCClCClap!Clap!Clap!ClClClClap!ClaCClaClaClCClClaClap!CClap!CCCCClaClap!ClaClap!") == 78);
	assert(claps("ClClaClap!ClaClaClap!Clap!Clap!Clap!ClaClaClap!ClaCClaClap!ClClClap!Clap!CClaClap!CClClaClClCClap!ClaClap!ClClaClap!ClCCClaClCClap!ClCClClaClap!ClClaClap!Clap!Clap!Clap!ClCClap!ClClClaClap!Clap!Clap!ClaCClaClClaClCClClap!ClClCCClCClaClCClCCClClaClaClaClap!CClClClap!") == 92);
	assert(claps("CClClap!ClClap!ClaClap!ClaCCCClaClaCClap!CClap!CClClaClap!CClap!ClClClaClClaClap!CClClaCClap!ClClaCClClaClap!CClap!CClClap!CClap!Clap!Clap!ClClClap!ClClaClap!CCClap!CCClCClCClCClaClaClClaClaClap!") == 72);
	assert(claps("CCClaClap!CClaClClaClaCClaClClap!ClaCClCClaCClClClaClaCClaCCCClClap!ClaClaClaCClap!ClaClClaClClap!Clap!CClaCClap!CClClap!Clap!ClaCCClCClClap!ClaClaClaCCClaClaClaClCCClaClCClClap!") == 72);
	assert(claps("ClCClap!ClaClaClCClap!CClap!Clap!ClClCCClClap!CCCClClClaClap!Clap!Clap!ClClaClClaClap!ClCCClaClap!CClClaCCClap!Clap!Clap!CClClaClap!Clap!ClaClCClap!ClCCClap!ClaClap!CCClaClap!CCClaClap!CClaClClaClaClaClap!Clap!CClap!Clap!Clap!Clap!ClClap!") == 82);
	assert(claps("CClCCCCClap!CClap!Clap!CClap!ClaClaCCCClaClap!Clap!Clap!ClClap!CClaClaClaClaCClap!CClap!ClaCCClClaClClCCClaClaClCClaCCClap!") == 49);
	assert(claps("ClClaClap!ClaCClaClaClap!Clap!CClClaClap!ClaClap!ClaClClaClaClap!ClaCClCCClaClaCClCClClap!ClCClap!ClClaClaClCClaClap!ClaClClaCCClap!ClaClap!ClClaClap!CClCClap!ClaClap!ClaClCClaClaCClap!ClClClap!Clap!CClClap!Clap!ClClaCClaCClaClap!Clap!CCClaClaClClap!Clap!ClCClClaClaClaClClClCClap!") == 100);
	assert(claps("ClClap!ClCClClClap!CCClaCCCClaClCClClaClClClaClap!ClaClap!ClCClClap!ClaClap!ClaClClClap!ClCClaCClClap!ClClClClap!ClaClClaClap!ClClClaCClaClClaCClap!CClClap!ClaClap!Clap!ClaCClap!ClaClClap!CClClClaClCClaClaClaCClap!ClaClap!CClap!") == 84);
	assert(claps("ClaClCClap!Clap!ClaClaClaClap!ClaClap!CClClap!ClaClCClaClClCCClClClClaClap!Clap!CClap!Clap!ClaCClaClClaCClap!ClClCCClaClClaClaCCClClap!Clap!CClaClap!CClap!ClClClap!ClaClaCClaCClClaClaClClaCClClap!ClCCClClap!ClCClap!CClaClaClap!Clap!ClaClap!ClCClaClap!Clap!") == 92);
	assert(claps("ClCClap!Clap!Clap!ClaCClap!Clap!ClaClaClaClap!Clap!ClaClClap!") == 17);
	assert(claps("ClClap!CClap!ClClaClaClClClClaClaClap!CCClaClaClaClap!ClClaClap!Clap!ClCClaCClap!ClClaCClaClap!Clap!ClaClaClap!ClaClap!CClap!ClCClap!ClClap!ClaClaClaClaClaClap!CClClClaCClap!CClaCCClaCClap!Clap!CCCClap!ClClClaCClap!Clap!ClaClClap!ClaClCClClap!") == 84);
	return 0;
}
