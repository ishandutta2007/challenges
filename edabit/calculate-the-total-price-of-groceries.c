/*

Create a function that takes an array of objects (groceries) which calculates the total price and returns it as a number.
A grocery object has a product, a quantity and a price, for example:

{
  "product": "Milk",
  "quantity": 1,
  "price": 1.50
}

Notes

There might be a floating point precision problem in here...

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char product[32];
	unsigned quantity;
	double price;
} Item;

double
totalprice(Item *it, size_t n)
{
	size_t i;
	double t;

	t = 0.0;
	for (i = 0; i < n; i++)
		t += it[i].price * it[i].quantity;
	return t;
}

int
main(void)
{
	Item i1[] = {
	    {"Milk", 1, 1.50},
	};
	Item i2[] = {
	    {"Milk", 1, 1.50},
	    {"Cereals", 1, 2.50},
	};
	Item i3[] = {
	    {"Milk", 3, 1.50},
	};
	Item i4[] = {
	    {"Milk", 1, 1.50},
	    {"Eggs", 12, 0.10},
	    {"Bread", 2, 1.60},
	    {"Cheese", 1, 4.50},
	};
	Item i5[] = {
	    {"Chocolate", 1, 0.10},
	    {"Lollipop", 1, 0.20},
	};

	printf("%.1f\n", totalprice(i1, nelem(i1)));
	printf("%.1f\n", totalprice(i2, nelem(i2)));
	printf("%.1f\n", totalprice(i3, nelem(i3)));
	printf("%.1f\n", totalprice(i4, nelem(i4)));
	printf("%.1f\n", totalprice(i5, nelem(i5)));
	return 0;
}
