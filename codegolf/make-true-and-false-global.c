/*

We all know true and false, but what do speakers around the globe say?

+----------------------+------------+------------+
| Language             | True       | False      |
+----------------------+------------+------------+
| Arabic               | sahih      | zaif       |
| Armenian             | irakan     | kelc       |
| Assamese             | asol       | misa       |
| Breton               | gwir       | gaou       |
| Bulgarian            | veren      | neveren    |
| Catalan              | veritable  | fals       |
| Cornish              | gwir       | gaw        |
| Czech                | pravdivy   | nepravdivy |
| Danish               | sand       | falsk      |
| Dutch                | waar       | onwaar     |
| English              | true       | false      |
| Esperanto            | vera       | malvera    |
| Finnish              | tosi       | epatosi    |
| French               | vrai       | faux       |
| Galician, Portuguese | verdadeiro | falso      |
| Georgian             | namdvili   | cru        |
| German               | wahr       | falsch     |
| Greek                | alithis    | psevdis    |
| Hebrew               | hiyuvi     | shikri     |
| Hindi, Urdu          | thik       | jhutha     |
| Hungarian            | igaz       | hamis      |
| Icelandic            | sannur     | rangur     |
| Indonesian, Malay    | benar      | salah      |
| Irish                | fior       | breagach   |
| Italian              | vero       | falso      |
| Japanese             | shin       | nise       |
| Korean               | cham       | geojit     |
| Latin                | verus      | falsus     |
| Latvian              | patiess    | nepareizs  |
| Mandarin Chinese     | zhen       | jia        |
| Maori                | pono       | pate       |
| Persian              | dorost     | galat      |
| Polish               | prawdziwy  | falszywy   |
| Romanian             | adevarat   | fals       |
| Russian              | vernyj     | falsivyj   |
| Sardinian            | beru       | falsu      |
| Scottish Gaelic      | fior       | breugach   |
| Spanish              | verdadero  | falso      |
| Swedish              | sann       | falskt     |
| Sylheti              | hasa       | misa       |
| Turkish              | dogru      | yanlis     |
| Volapuk              | veratik    | dobik      |
| Welsh                | gwir       | anwir      |
+----------------------+------------+------------+
All words ASCIIfied from Wiktionary: true, false. Preference given to first entry under 'A state in Boolean logic that indicates an affirmative or positive result'/'state in Boolean logic that indicates a negative result',
then first entry under 'concurring with a given set of facts'/'untrue, not factual, wrong'. I apologise if your favourite language is not included or the word choice for your language is not optimal - go edit Wiktionary!

Write a program or function that takes one word from the table above as input and outputs a consistent truthy value if the word means 'true' and a consistent falsy value otherwise.
Your code must produce the correct output for all 79 possible inputs. Shortest code (in bytes) in each language wins.

Sorted list of unique words meaning 'true':

adevarat,alithis,asol,benar,beru,cham,dogru,dorost,fior,gwir,hasa,hiyuvi,igaz,irakan,namdvili,patiess,pono,pravdivy,prawdziwy,sahih,sand,sann,sannur,shin,thik,tosi,true,vera,veratik,verdadeiro,verdadero,veren,veritable,vernyj,vero,verus,vrai,waar,wahr,zhen
Sorted list of unique words meaning 'false':

anwir,breagach,breugach,cru,dobik,epatosi,fals,falsch,false,falsivyj,falsk,falskt,falso,falsu,falsus,falszywy,faux,galat,gaou,gaw,geojit,hamis,jhutha,jia,kelc,malvera,misa,nepareizs,nepravdivy,neveren,nise,onwaar,pate,psevdis,rangur,salah,shikri,yanlis,zaif

*/

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *truetab[] = {
    "adevarat",
    "alithis",
    "asol",
    "benar",
    "beru",
    "cham",
    "dogru",
    "dorost",
    "fior",
    "gwir",
    "hasa",
    "hiyuvi",
    "igaz",
    "irakan",
    "namdvili",
    "patiess",
    "pono",
    "pravdivy",
    "prawdziwy",
    "sahih",
    "sand",
    "sann",
    "sannur",
    "shin",
    "thik",
    "tosi",
    "true",
    "vera",
    "veratik",
    "verdadeiro",
    "verdadero",
    "veren",
    "veritable",
    "vernyj",
    "vero",
    "verus",
    "vrai",
    "waar",
    "wahr",
    "zhen",
};

const char *falsetab[] = {
    "anwir",
    "breagach",
    "breugach",
    "cru",
    "dobik",
    "epatosi",
    "fals",
    "falsch",
    "false",
    "falsivyj",
    "falsk",
    "falskt",
    "falso",
    "falsu",
    "falsus",
    "falszywy",
    "faux",
    "galat",
    "gaou",
    "gaw",
    "geojit",
    "hamis",
    "jhutha",
    "jia",
    "kelc",
    "malvera",
    "misa",
    "nepareizs",
    "nepravdivy",
    "neveren",
    "nise",
    "onwaar",
    "pate",
    "psevdis",
    "rangur",
    "salah",
    "shikri",
    "yanlis",
    "zaif",
};

int
cmp(const void *a, const void *b)
{
	const char *const *p;

	p = b;
	return strcmp(a, *p);
}

int
truth(const char *s)
{

	const char **p;

	p = bsearch(s, truetab, nelem(truetab), sizeof(*truetab), cmp);
	if (p)
		return 1;

	p = bsearch(s, falsetab, nelem(falsetab), sizeof(*falsetab), cmp);
	if (p)
		return 0;

	return -1;
}

int
main(void)
{
	size_t i;

	for (i = 0; i < nelem(truetab); i++)
		assert(truth(truetab[i]) == 1);

	for (i = 0; i < nelem(falsetab); i++)
		assert(truth(falsetab[i]) == 0);

	assert(truth("nyet") == -1);
	assert(truth("") == -1);

	return 0;
}
