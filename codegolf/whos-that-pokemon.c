/*

Input: an integer N between 1 and 151

Output: the Nth Pokemon.
Rules

    You may use one data file.

    You may not use any already made data decompression algorithms. This includes libraries and other programs.

    Your program may not access files other than itself and your data file.

Scoring

Your score is the sum of the length of your code and data file.
Helpful Stuff

Here's a list of the first 151 pokemon separated by semicolons to help you generate your data file. Your output should exactly match the Nth entry of this line:

Bulbasaur;Ivysaur;Venusaur;Charmander;Charmeleon;Charizard;Squirtle;Wartortle;Blastoise;Caterpie;Metapod;Butterfree;Weedle;Kakuna;Beedrill;Pidgey;Pidgeotto;Pidgeot;Rattata;Raticate;Spearow;Fearow;Ekans;Arbok;Pikachu;Raichu;Sandshrew;Sandslash;Nidoran (f);Nidorina;Nidoqueen;Nidoran (m);Nidorino;Nidoking;Clefairy;Clefable;Vulpix;Ninetales;Jigglypuff;Wigglytuff;Zubat;Golbat;Oddish;Gloom;Vileplume;Paras;Parasect;Venonat;Venomoth;Diglett;Dugtrio;Meowth;Persian;Psyduck;Golduck;Mankey;Primeape;Growlith;Arcanine;Poliwag;Poliwhirl;Poliwrath;Abra;Kadabra;Alakazam;Machop;Machoke;Machamp;Bellsprout;Weepinbell;Victreebell;Tentacool;Tentacruel;Geodude;Graveler;Golem;Ponyta;Rapidash;Slowpoke;Slowbro;Magnemite;Magneton;Farfetch'd;Doduo;Dodrio;Seel;Dewgong;Grimer;Muk;Shellder;Cloyster;Gastly;Haunter;Gengar;Onix;Drowsee;Hypno;Krabby;Kingler;Voltorb;Electrode;Exeggute;Exeggutor;Cubone;Marowak;Hitmonlee;Hitmonchan;Lickitung;Koffing;Weezing;Rhyhorn;Rhydon;Chansey;Tangela;Kangaskhan;Horsea;Seadra;Goldeen;Seaking;Staryu;Starmie;Mr. Mime;Scyther;Jynx;Electabuzz;Magmar;Pinsir;Tauros;Magikarp;Gyarados;Lapras;Ditto;Eevee;Vaporeon;Jolteon;Flareon;Porygon;Omanyte;Omastar;Kabuto;Kabutops;Aerodactyl;Snorlax;Articuno;Zapdos;Moltres;Dratini;Dragonair;Dragonite;Mewtwo;Mew

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
pokemon(unsigned n)
{
	static const char *tab[] = {
	    "Bulbasaur",
	    "Ivysaur",
	    "Venusaur",
	    "Charmander",
	    "Charmeleon",
	    "Charizard",
	    "Squirtle",
	    "Wartortle",
	    "Blastoise",
	    "Caterpie",
	    "Metapod",
	    "Butterfree",
	    "Weedle",
	    "Kakuna",
	    "Beedrill",
	    "Pidgey",
	    "Pidgeotto",
	    "Pidgeot",
	    "Rattata",
	    "Raticate",
	    "Spearow",
	    "Fearow",
	    "Ekans",
	    "Arbok",
	    "Pikachu",
	    "Raichu",
	    "Sandshrew",
	    "Sandslash",
	    "Nidoran (f)",
	    "Nidorina",
	    "Nidoqueen",
	    "Nidoran (m)",
	    "Nidorino",
	    "Nidoking",
	    "Clefairy",
	    "Clefable",
	    "Vulpix",
	    "Ninetales",
	    "Jigglypuff",
	    "Wigglytuff",
	    "Zubat",
	    "Golbat",
	    "Oddish",
	    "Gloom",
	    "Vileplume",
	    "Paras",
	    "Parasect",
	    "Venonat",
	    "Venomoth",
	    "Diglett",
	    "Dugtrio",
	    "Meowth",
	    "Persian",
	    "Psyduck",
	    "Golduck",
	    "Mankey",
	    "Primeape",
	    "Growlith",
	    "Arcanine",
	    "Poliwag",
	    "Poliwhirl",
	    "Poliwrath",
	    "Abra",
	    "Kadabra",
	    "Alakazam",
	    "Machop",
	    "Machoke",
	    "Machamp",
	    "Bellsprout",
	    "Weepinbell",
	    "Victreebell",
	    "Tentacool",
	    "Tentacruel",
	    "Geodude",
	    "Graveler",
	    "Golem",
	    "Ponyta",
	    "Rapidash",
	    "Slowpoke",
	    "Slowbro",
	    "Magnemite",
	    "Magneton",
	    "Farfetch'd",
	    "Doduo",
	    "Dodrio",
	    "Seel",
	    "Dewgong",
	    "Grimer",
	    "Muk",
	    "Shellder",
	    "Cloyster",
	    "Gastly",
	    "Haunter",
	    "Gengar",
	    "Onix",
	    "Drowsee",
	    "Hypno",
	    "Krabby",
	    "Kingler",
	    "Voltorb",
	    "Electrode",
	    "Exeggute",
	    "Exeggutor",
	    "Cubone",
	    "Marowak",
	    "Hitmonlee",
	    "Hitmonchan",
	    "Lickitung",
	    "Koffing",
	    "Weezing",
	    "Rhyhorn",
	    "Rhydon",
	    "Chansey",
	    "Tangela",
	    "Kangaskhan",
	    "Horsea",
	    "Seadra",
	    "Goldeen",
	    "Seaking",
	    "Staryu",
	    "Starmie",
	    "Mr. Mime",
	    "Scyther",
	    "Jynx",
	    "Electabuzz",
	    "Magmar",
	    "Pinsir",
	    "Tauros",
	    "Magikarp",
	    "Gyarados",
	    "Lapras",
	    "Ditto",
	    "Eevee",
	    "Vaporeon",
	    "Jolteon",
	    "Flareon",
	    "Porygon",
	    "Omanyte",
	    "Omastar",
	    "Kabuto",
	    "Kabutops",
	    "Aerodactyl",
	    "Snorlax",
	    "Articuno",
	    "Zapdos",
	    "Moltres",
	    "Dratini",
	    "Dragonair",
	    "Dragonite",
	    "Mewtwo",
	    "Mew",
	};

	if (n == 0 || n - 1 >= nelem(tab))
		return NULL;
	return tab[n - 1];
}

int
main(void)
{
	unsigned i;

	for (i = 1; i <= 151; i++)
		printf("%s\n", pokemon(i));
	return 0;
}
