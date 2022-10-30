/*

Create a Pizza class with the attributes order_number and ingredients (which is given as a list).
Only the ingredients will be given as input.

You should also make it so that its possible to choose a ready made pizza flavour rather than typing out the ingredients manually!
As well as creating this Pizza class, hard-code the following pizza flavours.

Name	Ingredients
hawaiian	ham, pineapple
meat_festival	beef, meatball, bacon
garden_feast	spinach, olives, mushroom
Examples

p1 = Pizza(["bacon", "parmesan", "ham"])    # order 1
p2 = Pizza.garden_feast()                  # order 2

p1.ingredients ➞ ["bacon", "parmesan", "ham"]

p2.ingredients ➞ ["spinach", "olives", "mushroom"]

p1.order_number ➞ 1

p2.order_number ➞ 2

Notes

    All words are given in lowercase.
    See the Resources tab for some helpful tutorials on classes!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char ingredients[8][32];
	size_t num_ingredients;
} Pizza;

unsigned
get_order(Pizza *p)
{
	static unsigned order = 0;
	return ++order;

	(void)p;
}

void
new_pizza(Pizza *p, const char **s, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		strcpy(p->ingredients[i], s[i]);
	p->num_ingredients = n;
}

void
hawaiian(Pizza *p)
{
	strcpy(p->ingredients[0], "ham");
	strcpy(p->ingredients[1], "pineapple");
	p->num_ingredients = 2;
}

void
meat_festival(Pizza *p)
{
	strcpy(p->ingredients[0], "beef");
	strcpy(p->ingredients[1], "meatball");
	strcpy(p->ingredients[2], "bacon");
	p->num_ingredients = 3;
}

void
garden_feast(Pizza *p)
{
	strcpy(p->ingredients[0], "spinach");
	strcpy(p->ingredients[1], "olives");
	strcpy(p->ingredients[2], "mushroom");
	p->num_ingredients = 3;
}

void
assert_ingredients(Pizza *p, const char **s)
{
	size_t i;

	for (i = 0; i < p->num_ingredients; i++)
		assert(!strcmp(p->ingredients[i], s[i]));
}

int
main(void)
{
	static const char *i1[] = {
	    "bacon",
	    "parmesan",
	    "ham",
	};
	static const char *i2[] = {
	    "spinach",
	    "olives",
	    "mushroom",
	};
	static const char *i3[] = {
	    "ham",
	    "pineapple",
	};
	static const char *i4[] = {
	    "beef",
	    "meatball",
	    "bacon",
	};
	static const char *i5[] = {
	    "pepperoni",
	    "bacon",
	};
	static const char *i6[] = {
	    "cheese",
	    "caviar",
	    "oyster",
	    "uranium",
	};

	Pizza p1, p2, p3, p4, p5, my_pizza;

	new_pizza(&p1, i1, nelem(i1));
	garden_feast(&p2);
	hawaiian(&p3);
	meat_festival(&p4);
	new_pizza(&p5, i5, nelem(i5));
	new_pizza(&my_pizza, i6, nelem(i6));

	assert_ingredients(&p1, i1);
	assert_ingredients(&p2, i2);
	assert_ingredients(&p3, i3);
	assert_ingredients(&p4, i4);
	assert_ingredients(&p5, i5);
	assert_ingredients(&my_pizza, i6);

	assert(get_order(&p1) == 1);
	assert(get_order(&p2) == 2);
	assert(get_order(&p3) == 3);
	assert(get_order(&p4) == 4);
	assert(get_order(&p5) == 5);
	assert(get_order(&my_pizza) == 6);

	return 0;
}
