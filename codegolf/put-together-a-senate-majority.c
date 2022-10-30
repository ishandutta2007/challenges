/*

There are one hundred members of the United States Senate. Assuming that nobody filibusters and that the Vice President isn't cooperating, at least fifty-one members are necessary to pass a bill. But some members work together better than others, entropy-wise.

Your task: Output the last names of at least 51 of the US senators at the time this question was posted in 2017. Any 51 are acceptable; put together a Cruz-Sanders coalition if you'd like. The names may be output in any order.

The full list is as follows (note that Van Hollen is one person):

    Alexander, Baldwin, Barrasso, Bennet, Blumenthal, Blunt, Booker, Boozman, Brown, Burr, Cantwell, Capito, Cardin, Carper, Casey, Cassidy, Cochran, Collins, Coons, Corker, Cornyn, Cortez Masto, Cotton, Crapo, Cruz, Daines, Donnelly, Duckworth, Durbin, Enzi, Ernst, Feinstein, Fischer, Flake, Franken, Gardner, Gillibrand, Graham, Grassley, Harris, Hassan, Hatch, Heinrich, Heitkamp, Heller, Hirono, Hoeven, Inhofe, Isakson, Johnson, Kaine, Kennedy, King, Klobuchar, Lankford, Leahy, Lee, Manchin, Markey, McCain, McCaskill, McConnell, Menendez, Merkley, Moran, Murkowski, Murphy, Murray, Nelson, Paul, Perdue, Peters, Portman, Reed, Risch, Roberts, Rounds, Rubio, Sanders, Sasse, Schatz, Schumer, Scott, Shaheen, Shelby, Stabenow, Strange, Sullivan, Tester, Thune, Tillis, Toomey, Udall, Van Hollen, Warner, Warren, Whitehouse, Wicker, Wyden, Young

Querying Wolfram Alpha (or any other database of senators) is specifically disallowed. Anything else is fair game; use gzip as a language if you'd like.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
senators(void)
{
	static const char *tab[] = {
	    "Alexander",
	    "Baldwin",
	    "Barrasso",
	    "Bennet",
	    "Blumenthal",
	    "Blunt",
	    "Booker",
	    "Boozman",
	    "Brown",
	    "Burr",
	    "Cantwell",
	    "Capito",
	    "Cardin",
	    "Carper",
	    "Casey",
	    "Cassidy",
	    "Cochran",
	    "Collins",
	    "Coons",
	    "Corker",
	    "Cornyn",
	    "Cortez Masto",
	    "Cotton",
	    "Crapo",
	    "Cruz",
	    "Daines",
	    "Donnelly",
	    "Duckworth",
	    "Durbin",
	    "Enzi",
	    "Ernst",
	    "Feinstein",
	    "Fischer",
	    "Flake",
	    "Franken",
	    "Gardner",
	    "Gillibrand",
	    "Graham",
	    "Grassley",
	    "Harris",
	    "Hassan",
	    "Hatch",
	    "Heinrich",
	    "Heitkamp",
	    "Heller",
	    "Hirono",
	    "Hoeven",
	    "Inhofe",
	    "Isakson",
	    "Johnson",
	    "Kaine",
	    "Kennedy",
	    "King",
	    "Klobuchar",
	    "Lankford",
	    "Leahy",
	    "Lee",
	    "Manchin",
	    "Markey",
	    "McCain",
	    "McCaskill",
	    "McConnell",
	    "Menendez",
	    "Merkley",
	    "Moran",
	    "Murkowski",
	    "Murphy",
	    "Murray",
	    "Nelson",
	    "Paul",
	    "Perdue",
	    "Peters",
	    "Portman",
	    "Reed",
	    "Risch",
	    "Roberts",
	    "Rounds",
	    "Rubio",
	    "Sanders",
	    "Sasse",
	    "Schatz",
	    "Schumer",
	    "Scott",
	    "Shaheen",
	    "Shelby",
	    "Stabenow",
	    "Strange",
	    "Sullivan",
	    "Tester",
	    "Thune",
	    "Tillis",
	    "Toomey",
	    "Udall",
	    "Van Hollen",
	    "Warner",
	    "Warren",
	    "Whitehouse",
	    "Wicker",
	    "Wyden",
	    "Young",
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("%s\n", tab[i]);
}

int
main(void)
{
	senators();
	return 0;
}
