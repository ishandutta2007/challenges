/*

Lajuk is a little girl who loves playing with array. In her 10th birthday, she got two arrays as presents.
Let’s call them A and B. Both arrays have the same size n and contains integers between 0 to 30000.

Lajuk’s hard-drive is almost full of presents and she barely has any space to keep the arrays. She discovered a brilliant function to merge the array into one:


int encodeInteger(int x, int n){
	n = n<<(1<<(1<<(1<<1)));
	x = x | n;
	return x;
}
void encodeArray(int *A, int *B, int n){
	for(int i=0;i<n;i++) {
    	    A[i] = encodeInteger(A[i], B[i]);
	}
}

Lajuk passed A and B into the encodeArray function. After that she discarded array B and saved the modified version of array A in the hard-drive.

Now in her 15th birthday Lajuk wants to play with those arrays again. She found the modified version of array A in the hard-drive
but she forgot how to recover the original arrays from it. Being upset, she asked for your help. Can you help her to recover the original arrays?

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
recover(int c, int *a, size_t n)
{
	size_t i;
	int x;

	printf("Case %d\n", c);
	for (i = 0; i < n; i++) {
		x = a[i] & 0xffff;
		printf("%d ", x);
	}
	printf("\n");

	for (i = 0; i < n; i++) {
		x = (a[i] >> 16) & 0xffff;
		printf("%d ", x);
	}
	printf("\n");
}

int
main(void)
{
	int a[] = {196613, 655370, 196620, 131079};
	recover(1, a, nelem(a));
	return 0;
}
