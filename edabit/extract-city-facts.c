/*

Create a function that takes an object as an argument and returns a string with facts about the city. The city facts will need to be extracted from the object's three properties:

    name
    population
    continent

The string should have the following format: X has a population of Y and is situated in Z (where X is the city name, Y is the population and Z is the continent the city is situated in).
Examples

cityFacts({
  name: "Paris",
  population: "2,140,526",
  continent: "Europe"
}) ➞ "Paris has a population of 2,140,526 and is situated in Europe"

cityFacts({
  name: "Tokyo",
  population: "13,929,286",
  continent: "Asia"
}) ➞ "Tokyo has a population of 13,929,286 and is situated in Asia"


*/

#include <stdio.h>

typedef struct {
	char name[32];
	char population[32];
	char continent[32];
} City;

void
cityfacts(City *c)
{
	printf("%s has a population of %s and is situated in %s\n", c->name, c->population, c->continent);
}

int
main(void)
{
	City c1 = { "Manila", "1,780,148", "Asia" };
	City c2 = { "Melbourne", "4,936,349", "Australia" };
	City c3 = { "Kampala", "1,507,080", "Africa" };
	City c4 = { "Buenos Aires", "2,891,082", "South America" };
	City c5 = { "Vancouver", "631,486", "North America" };
	City c6 = { "Berlin", "3,748,148", "Europe" };
	City c7 = { "Paris", "2,140,526", "Europe" };
	City c8 = { "Tokyo", "13,929,286", "Asia" };

	cityfacts(&c1);
	cityfacts(&c2);
	cityfacts(&c3);
	cityfacts(&c4);
	cityfacts(&c5);
	cityfacts(&c6);
	cityfacts(&c7);
	cityfacts(&c8);

	return 0;
}
