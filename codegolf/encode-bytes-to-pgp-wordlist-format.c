/*

The PGP Word List is a set of 512 English words for verbally communicating strings of bytes, such as authentication codes or hashes.
It is used in secure VoIP software as well as in some other important applications, such as the DNSSEC Root KSK Ceremonies held four times a year.

It consists of 256 two-syllable words and 256 three-syllable words. Bytes at even offsets become two-syllable words, while bytes at odd offsets become three-syllable words.
This protects against transposition of adjacent words, repetition of a word, or omission of a word.

The two subsets are kept as alphabetical lists and numbered accordingly, so a null byte (hex 00) becomes "aardvark" at an even offset and "adroitness" at an odd offset. Likewise, the words for hex FF are "Zulu" and "Yucatan" respectively.

Write a complete program to encode a sequence of bytes (represented as pairs of hex digits) as a sequence of words from the PGP Word List.

Because the program is to be run on a secure, air-gapped computer, and USB drives are a security risk, the program should be as short as possible to facilitate manual entry.
(The length of each program is measured in bytes, because if I were to use the complicated keystroke formula I came up with, this specification would be twice as long as it is now.)

Input format
The program must accept a string of hex digits as either a single line of input or a command-line argument. You may assume the following:

There are no spaces or other separators between hex digits.
The number of hex digits is between 2 and 128 inclusive.
The number of hex digits is even.
Digits A-F are either all lowercase or all uppercase (if the required letter case is documented).
Example input: 9030e74b

Output format
The program must print a corresponding line of words from the PGP Word List. Adjacent words must be separated by a single space. However, case of the letters within the words may differ from that shown in the PGP Word List.

Example output: peachy commando transit disable

Restrictions
The program must not rely on any external copy of the PGP Word List, including any data known to be largely derived from the list that may be present in a system file or library.

Test cases
A TSV file is provided. In each line, column 1 contains the input (as lowercase hex digits), and column 2 contains the corresponding output. More test cases may be added if necessary.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
encode(uint8_t *b, size_t n, char *s)
{
	static const char *words[256][2] = {
	    {"aardvark", "adroitness"},
	    {"absurd", "adviser"},
	    {"accrue", "aftermath"},
	    {"acme", "aggregate"},
	    {"adrift", "alkali"},
	    {"adult", "almighty"},
	    {"afflict", "amulet"},
	    {"ahead", "amusement"},
	    {"aimless", "antenna"},
	    {"Algol", "applicant"},
	    {"allow", "Apollo"},
	    {"alone", "armistice"},
	    {"ammo", "article"},
	    {"ancient", "asteroid"},
	    {"apple", "Atlantic"},
	    {"artist", "atmosphere"},
	    {"assume", "autopsy"},
	    {"Athens", "Babylon"},
	    {"atlas", "backwater"},
	    {"Aztec", "barbecue"},
	    {"baboon", "belowground"},
	    {"backfield", "bifocals"},
	    {"backward", "bodyguard"},
	    {"banjo", "bookseller"},
	    {"beaming", "borderline"},
	    {"bedlamp", "bottomless"},
	    {"beehive", "Bradbury"},
	    {"beeswax", "bravado"},
	    {"befriend", "Brazilian"},
	    {"Belfast", "breakaway"},
	    {"berserk", "Burlington"},
	    {"billiard", "businessman"},
	    {"bison", "butterfat"},
	    {"blackjack", "Camelot"},
	    {"blockade", "candidate"},
	    {"blowtorch", "cannonball"},
	    {"bluebird", "Capricorn"},
	    {"bombast", "caravan"},
	    {"bookshelf", "caretaker"},
	    {"brackish", "celebrate"},
	    {"breadline", "cellulose"},
	    {"breakup", "certify"},
	    {"brickyard", "chambermaid"},
	    {"briefcase", "Cherokee"},
	    {"Burbank", "Chicago"},
	    {"button", "clergyman"},
	    {"buzzard", "coherence"},
	    {"cement", "combustion"},
	    {"chairlift", "commando"},
	    {"chatter", "company"},
	    {"checkup", "component"},
	    {"chisel", "concurrent"},
	    {"choking", "confidence"},
	    {"chopper", "conformist"},
	    {"Christmas", "congregate"},
	    {"clamshell", "consensus"},
	    {"classic", "consulting"},
	    {"classroom", "corporate"},
	    {"cleanup", "corrosion"},
	    {"clockwork", "councilman"},
	    {"cobra", "crossover"},
	    {"commence", "crucifix"},
	    {"concert", "cumbersome"},
	    {"cowbell", "customer"},
	    {"crackdown", "Dakota"},
	    {"cranky", "decadence"},
	    {"crowfoot", "December"},
	    {"crucial", "decimal"},
	    {"crumpled", "designing"},
	    {"crusade", "detector"},
	    {"cubic", "detergent"},
	    {"dashboard", "determine"},
	    {"deadbolt", "dictator"},
	    {"deckhand", "dinosaur"},
	    {"dogsled", "direction"},
	    {"dragnet", "disable"},
	    {"drainage", "disbelief"},
	    {"dreadful", "disruptive"},
	    {"drifter", "distortion"},
	    {"dropper", "document"},
	    {"drumbeat", "embezzle"},
	    {"drunken", "enchanting"},
	    {"Dupont", "enrollment"},
	    {"dwelling", "enterprise"},
	    {"eating", "equation"},
	    {"edict", "equipment"},
	    {"egghead", "escapade"},
	    {"eightball", "Eskimo"},
	    {"endorse", "everyday"},
	    {"endow", "examine"},
	    {"enlist", "existence"},
	    {"erase", "exodus"},
	    {"escape", "fascinate"},
	    {"exceed", "filament"},
	    {"eyeglass", "finicky"},
	    {"eyetooth", "forever"},
	    {"facial", "fortitude"},
	    {"fallout", "frequency"},
	    {"flagpole", "gadgetry"},
	    {"flatfoot", "Galveston"},
	    {"flytrap", "getaway"},
	    {"fracture", "glossary"},
	    {"framework", "gossamer"},
	    {"freedom", "graduate"},
	    {"frighten", "gravity"},
	    {"gazelle", "guitarist"},
	    {"Geiger", "hamburger"},
	    {"glitter", "Hamilton"},
	    {"glucose", "handiwork"},
	    {"goggles", "hazardous"},
	    {"goldfish", "headwaters"},
	    {"gremlin", "hemisphere"},
	    {"guidance", "hesitate"},
	    {"hamlet", "hideaway"},
	    {"highchair", "holiness"},
	    {"hockey", "hurricane"},
	    {"indoors", "hydraulic"},
	    {"indulge", "impartial"},
	    {"inverse", "impetus"},
	    {"involve", "inception"},
	    {"island", "indigo"},
	    {"jawbone", "inertia"},
	    {"keyboard", "infancy"},
	    {"kickoff", "inferno"},
	    {"kiwi", "informant"},
	    {"klaxon", "insincere"},
	    {"locale", "insurgent"},
	    {"lockup", "integrate"},
	    {"merit", "intention"},
	    {"minnow", "inventive"},
	    {"miser", "Istanbul"},
	    {"Mohawk", "Jamaica"},
	    {"mural", "Jupiter"},
	    {"music", "leprosy"},
	    {"necklace", "letterhead"},
	    {"Neptune", "liberty"},
	    {"newborn", "maritime"},
	    {"nightbird", "matchmaker"},
	    {"Oakland", "maverick"},
	    {"obtuse", "Medusa"},
	    {"offload", "megaton"},
	    {"optic", "microscope"},
	    {"orca", "microwave"},
	    {"payday", "midsummer"},
	    {"peachy", "millionaire"},
	    {"pheasant", "miracle"},
	    {"physique", "misnomer"},
	    {"playhouse", "molasses"},
	    {"Pluto", "molecule"},
	    {"preclude", "Montana"},
	    {"prefer", "monument"},
	    {"preshrunk", "mosquito"},
	    {"printer", "narrative"},
	    {"prowler", "nebula"},
	    {"pupil", "newsletter"},
	    {"puppy", "Norwegian"},
	    {"python", "October"},
	    {"quadrant", "Ohio"},
	    {"quiver", "onlooker"},
	    {"quota", "opulent"},
	    {"ragtime", "Orlando"},
	    {"ratchet", "outfielder"},
	    {"rebirth", "Pacific"},
	    {"reform", "pandemic"},
	    {"regain", "Pandora"},
	    {"reindeer", "paperweight"},
	    {"rematch", "paragon"},
	    {"repay", "paragraph"},
	    {"retouch", "paramount"},
	    {"revenge", "passenger"},
	    {"reward", "pedigree"},
	    {"rhythm", "Pegasus"},
	    {"ribcage", "penetrate"},
	    {"ringbolt", "perceptive"},
	    {"robust", "performance"},
	    {"rocker", "pharmacy"},
	    {"ruffled", "phonetic"},
	    {"sailboat", "photograph"},
	    {"sawdust", "pioneer"},
	    {"scallion", "pocketful"},
	    {"scenic", "politeness"},
	    {"scorecard", "positive"},
	    {"Scotland", "potato"},
	    {"seabird", "processor"},
	    {"select", "provincial"},
	    {"sentence", "proximate"},
	    {"shadow", "puberty"},
	    {"shamrock", "publisher"},
	    {"showgirl", "pyramid"},
	    {"skullcap", "quantity"},
	    {"skydive", "racketeer"},
	    {"slingshot", "rebellion"},
	    {"slowdown", "recipe"},
	    {"snapline", "recover"},
	    {"snapshot", "repellent"},
	    {"snowcap", "replica"},
	    {"snowslide", "reproduce"},
	    {"solo", "resistor"},
	    {"southward", "responsive"},
	    {"soybean", "retraction"},
	    {"spaniel", "retrieval"},
	    {"spearhead", "retrospect"},
	    {"spellbind", "revenue"},
	    {"spheroid", "revival"},
	    {"spigot", "revolver"},
	    {"spindle", "sandalwood"},
	    {"spyglass", "sardonic"},
	    {"stagehand", "Saturday"},
	    {"stagnate", "savagery"},
	    {"stairway", "scavenger"},
	    {"standard", "sensation"},
	    {"stapler", "sociable"},
	    {"steamship", "souvenir"},
	    {"sterling", "specialist"},
	    {"stockman", "speculate"},
	    {"stopwatch", "stethoscope"},
	    {"stormy", "stupendous"},
	    {"sugar", "supportive"},
	    {"surmount", "surrender"},
	    {"suspense", "suspicious"},
	    {"sweatband", "sympathy"},
	    {"swelter", "tambourine"},
	    {"tactics", "telephone"},
	    {"talon", "therapist"},
	    {"tapeworm", "tobacco"},
	    {"tempest", "tolerance"},
	    {"tiger", "tomorrow"},
	    {"tissue", "torpedo"},
	    {"tonic", "tradition"},
	    {"topmost", "travesty"},
	    {"tracker", "trombonist"},
	    {"transit", "truncated"},
	    {"trauma", "typewriter"},
	    {"treadmill", "ultimate"},
	    {"Trojan", "undaunted"},
	    {"trouble", "underfoot"},
	    {"tumor", "unicorn"},
	    {"tunnel", "unify"},
	    {"tycoon", "universe"},
	    {"uncut", "unravel"},
	    {"unearth", "upcoming"},
	    {"unwind", "vacancy"},
	    {"uproot", "vagabond"},
	    {"upset", "vertigo"},
	    {"upshot", "Virginia"},
	    {"vapor", "visitor"},
	    {"village", "vocalist"},
	    {"virus", "voyager"},
	    {"Vulcan", "warranty"},
	    {"waffle", "Waterloo"},
	    {"wallet", "whimsical"},
	    {"watchword", "Wichita"},
	    {"wayside", "Wilmington"},
	    {"willow", "Wyoming"},
	    {"woodlark", "yesteryear"},
	    {"Zulu", "Yucatan"},
	};

	size_t i, l;

	l = 0;
	for (i = 0; i < n; i++)
		l += sprintf(s + l, "%s ", words[b[i]][i & 1]);

	if (l)
		s[l - 1] = '\0';

	return s;
}

void
test(uint8_t *b, size_t n, char *r)
{
	char p[1024];

	encode(b, n, p);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	uint8_t b1[] = {0xE5, 0x82, 0x94, 0xF2, 0xE9, 0xA2, 0x27, 0x48, 0x6E, 0x8B, 0x06, 0x1B, 0x31, 0xCC, 0x52, 0x8F, 0xD7, 0xFA, 0x3F, 0x19};
	uint8_t b2[] = {0x90, 0x30, 0xe7, 0x4b};

	test(b1, nelem(b1), "topmost Istanbul Pluto vagabond treadmill Pacific brackish dictator goldfish Medusa afflict bravado chatter revolver Dupont midsummer stopwatch whimsical cowbell bottomless");
	test(b2, nelem(b2), "peachy commando transit disable");

	return 0;
}
