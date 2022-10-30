/*

Here I found a cool math problem. I thought you could write some golfed code to compute all answers between x and x.(there is an infinite amount).

Problem: Once upon a time, and old lady went to sell her vast quantity of eggs at the local market. When asked how many she had, she replied:

Son, I can't count past 100 but I know that:

    If you divide the number of eggs by 2 OR 3 OR 4 OR 5 OR 6 OR 7 OR 8 OR 9 OR 10, there will be one egg left.
    If you divide the number of eggs by 11 there will be NO EGGS left!

How many eggs did the old lady have?

i answered the question on that thread with:

    public static void main(String... args)
    {
        for (int i = 0; i < 1000000000; i++)
        {
            boolean a = true;
            for (int x = 2; x < 11; x++)
            {
                if (i % x != 1) a = false;
            }
            if (i % 11 != 0) a = false;
            if (a) System.out.println(i);
        }
    }

Catch:
If some sharp eyed person noticed, you could start at 25201 and keep adding 27720 to get to the next one. You can NOT use this machanic to answer the question. So dont post something like this:

public class test {
public static void main(String... args) {   
    long l=25201;
    while(true){
        System.out.println(l);
        l+=27720;
    }
}
}

*/

#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;

void
eggs(void)
{
	uvlong i, n;

	n = 27720ull;
	for (i = 25201ull; ULLONG_MAX - i > n; i += n)
		printf("%llu\n", i);
}

int
main(void)
{
	eggs();
	return 0;
}
