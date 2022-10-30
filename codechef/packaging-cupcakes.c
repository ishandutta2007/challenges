/*

Now that Chef has finished baking and frosting his cupcakes, it's time to package them.
Chef has N cupcakes, and needs to decide how many cupcakes to place in each package.
Each package must contain the same number of cupcakes.
Chef will choose an integer A between 1 and N, inclusive, and place exactly A cupcakes into each package.
Chef makes as many packages as possible. Chef then gets to eat the remaining cupcakes.
Chef enjoys eating cupcakes very much. Help Chef choose the package size A that will let him eat as many cupcakes as possible. 

*/
#include <stdio.h>

int
cupcakes(int n)
{
	if (n <= 0)
		return 0;
	return n / 2 + 1;
}

int
main(void)
{
	printf("%d\n", cupcakes(2));
	printf("%d\n", cupcakes(5));
	printf("%d\n", cupcakes(100000));
	return 0;
}
