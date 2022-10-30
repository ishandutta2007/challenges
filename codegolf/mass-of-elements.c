/*

There are more than 100 elements in the modern periodic table. You challenge is to output the rounded mass of an element with respect to the input given.

Input
Input will contain an abbreviation of an element.
Input can be taken from any one of the following:

stdin
command-line arguments

function arguments

Input will contain a one or two letter abbreviation of an element. The first character is always an uppercase letter and the second character, if any, will be a lowercase letter.

Output
Output the mass of the element entered
Output must be in the stdout or closest equivalent.
Output may contain a trailing newline character
Elements and their masses
Here is the list of abbreviation of elements and their masses:

Sl.No     Elements     Abbreviation     Mass

1         Hydrogen     H                1
2         Helium       He               4
3         Lithium      Li               7
4         Beryllium    Be               9
5         Boron        B                11
6         Carbon       C                12
7         Nitrogen     N                14
8         Oxygen       O                16
9         Fluorine     F                19
10        Neon         Ne               20
11        Sodium       Na               23
12        Magnesium    Mg               24
13        Aluminium    Al               27
14        Silicon      Si               28
15        Phosphorus   P                31
16        Sulfur       S                32
17        Chlorine     Cl               35
18        Argon        Ar               40
19        Potassium    K                39
20        Calcium      Ca               40
21        Scandium     Sc               45
22        Titanium     Ti               48
23        Vanadium     V                51
24        Chromium     Cr               52
25        Manganese    Mn               55
26        Iron         Fe               56
27        Cobalt       Co               59
28        Nickel       Ni               59
29        Copper       Cu               64
30        Zinc         Zn               65
31        Gallium      Ga               70
32        Germanium    Ge               73
33        Arsenic      As               75
34        Selenium     Se               79
35        Bromine      Br               80
36        Krypton      Kr               84
37        Rubidium     Rb               85
38        Strontium    Sr               88
39        Yttrium      Y                89
40        Zirconium    Zr               91
41        Niobium      Nb               93
42        Molybdenum   Mo               96
43        Technetium   Tc               98
44        Ruthenium    Ru               101
45        Rhodium      Rh               103
46        Palladium    Pd               106
47        Silver       Ag               108
48        Cadmium      Cd               112
49        Indium       In               115
50        Tin          Sn               119
51        Antimony     Sb               122
52        Tellurium    Te               128
53        Iodine       I                127
54        Xenon        Xe               131
55        Cesium       Cs               133
56        Barium       Ba               137
57        Lanthanum    La               139
58        Cerium       Ce               140
59        Praseodymium Pr               141
60        Neodymium    Nd               144
61        Promethium   Pm               145
62        Samarium     Sm               150
63        Europium     Eu               152
64        Gadolinium   Gd               157
65        Terbium      Tb               159
66        Dysprosium   Dy               163
67        Holmium      Ho               165
68        Erbium       Er               167
69        Thulium      Tm               169
70        Ytterbium    Yb               173
71        Lutetium     Lu               175
72        Hafnium      Hf               178
73        Tantalum     Ta               181
74        Tungsten     W                184
75        Rhenium      Re               186
76        Osmium       Os               190
77        Iridium      Ir               192
78        Platinum     Pt               195
79        Gold         Au               197
80        Mercury      Hg               201
81        Thallium     Tl               204
82        Lead         Pb               207
83        Bismuth      Bi               209
84        Polonium     Po               209
85        Astatine     At               210
86        Radon        Rn               222
87        Francium     Fr               223
88        Radium       Ra               226
89        Actinium     Ac               227
90        Thorium      Th               232
91        Protactinium Pa               231
92        Uranium      U                238
93        Neptunium    Np               237
94        Plutonium    Pu               244
95        Americium    Am               243
96        Curium       Cm               247
97        Berkelium    Bk               247
98        Californium  Cf               251
99        Einsteinium  Es               252
100       Fermium      Fm               257
Yes. Your code only needs to deal with elements having atomic number 0-100 as seen in the table above.

Rules
Standard loopholes are disallowed, as is fetching the data from built-ins
You may write a full program, or a function.
Test Cases
O    --> 16
Sn   --> 119
H    --> 1
Fm   --> 257
Scoring
This is code-golf, so the shortest submission (in bytes) wins.

*/

#include <assert.h>
#include <stdio.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[16];
	char abbrev[4];
	int mass;
} Element;

static const Element elements[] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 4},
    {"Lithium", "Li", 7},
    {"Beryllium", "Be", 9},
    {"Boron", "B", 11},
    {"Carbon", "C", 12},
    {"Nitrogen", "N", 14},
    {"Oxygen", "O", 16},
    {"Fluorine", "F", 19},
    {"Neon", "Ne", 20},
    {"Sodium", "Na", 23},
    {"Magnesium", "Mg", 24},
    {"Aluminium", "Al", 27},
    {"Silicon", "Si", 28},
    {"Phosphorus", "P", 31},
    {"Sulfur", "S", 32},
    {"Chlorine", "Cl", 35},
    {"Argon", "Ar", 40},
    {"Potassium", "K", 39},
    {"Calcium", "Ca", 40},
    {"Scandium", "Sc", 45},
    {"Titanium", "Ti", 48},
    {"Vanadium", "V", 51},
    {"Chromium", "Cr", 52},
    {"Manganese", "Mn", 55},
    {"Iron", "Fe", 56},
    {"Cobalt", "Co", 59},
    {"Nickel", "Ni", 59},
    {"Copper", "Cu", 64},
    {"Zinc", "Zn", 65},
    {"Gallium", "Ga", 70},
    {"Germanium", "Ge", 73},
    {"Arsenic", "As", 75},
    {"Selenium", "Se", 79},
    {"Bromine", "Br", 80},
    {"Krypton", "Kr", 84},
    {"Rubidium", "Rb", 85},
    {"Strontium", "Sr", 88},
    {"Yttrium", "Y", 89},
    {"Zirconium", "Zr", 91},
    {"Niobium", "Nb", 93},
    {"Molybdenum", "Mo", 96},
    {"Technetium", "Tc", 98},
    {"Ruthenium", "Ru", 101},
    {"Rhodium", "Rh", 103},
    {"Palladium", "Pd", 106},
    {"Silver", "Ag", 108},
    {"Cadmium", "Cd", 112},
    {"Indium", "In", 115},
    {"Tin", "Sn", 119},
    {"Antimony", "Sb", 122},
    {"Tellurium", "Te", 128},
    {"Iodine", "I", 127},
    {"Xenon", "Xe", 131},
    {"Cesium", "Cs", 133},
    {"Barium", "Ba", 137},
    {"Lanthanum", "La", 139},
    {"Cerium", "Ce", 140},
    {"Praseodymium", "Pr", 141},
    {"Neodymium", "Nd", 144},
    {"Promethium", "Pm", 145},
    {"Samarium", "Sm", 150},
    {"Europium", "Eu", 152},
    {"Gadolinium", "Gd", 157},
    {"Terbium", "Tb", 159},
    {"Dysprosium", "Dy", 163},
    {"Holmium", "Ho", 165},
    {"Erbium", "Er", 167},
    {"Thulium", "Tm", 169},
    {"Ytterbium", "Yb", 173},
    {"Lutetium", "Lu", 175},
    {"Hafnium", "Hf", 178},
    {"Tantalum", "Ta", 181},
    {"Tungsten", "W", 184},
    {"Rhenium", "Re", 186},
    {"Osmium", "Os", 190},
    {"Iridium", "Ir", 192},
    {"Platinum", "Pt", 195},
    {"Gold", "Au", 197},
    {"Mercury", "Hg", 201},
    {"Thallium", "Tl", 204},
    {"Lead", "Pb", 207},
    {"Bismuth", "Bi", 209},
    {"Polonium", "Po", 209},
    {"Astatine", "At", 210},
    {"Radon", "Rn", 222},
    {"Francium", "Fr", 223},
    {"Radium", "Ra", 226},
    {"Actinium", "Ac", 227},
    {"Thorium", "Th", 232},
    {"Protactinium", "Pa", 231},
    {"Uranium", "U", 238},
    {"Neptunium", "Np", 237},
    {"Plutonium", "Pu", 244},
    {"Americium", "Am", 243},
    {"Curium", "Cm", 247},
    {"Berkelium", "Bk", 247},
    {"Californium", "Cf", 251},
    {"Einsteinium", "Es", 252},
    {"Fermium", "Fm", 257},
};

int lut[256][256];

void
init(void)
{
	const Element *e;
	int a, b;
	size_t i;

	for (i = 0; i < nelem(elements); i++) {
		e = elements + i;
		a = e->abbrev[0] & 0xff;
		b = e->abbrev[1] & 0xff;
		lut[a][b] = e->mass;
	}
}

int
mass(const char *s)
{
	int a, b;

	if (!s[0])
		return 0;
	a = s[0] & 0xff;
	b = s[1] & 0xff;
	return lut[a][b];
}

int
main(void)
{
	init();

	assert(mass("O") == 16);
	assert(mass("Sn") == 119);
	assert(mass("H") == 1);
	assert(mass("Fm") == 257);

	return 0;
}
