/*

A heap, also known as a priority-queue, is an abstract data type.
Conceptually, it's a binary tree where the children of every node are smaller than or equal to the node itself.
(Assuming it's a max-heap.) When an element is pushed or popped, the heap rearranges itself so the the biggest element is the next to be popped.
It can easily be implemented as a tree or as an array.

Your challenge, should you choose to accept it, is to determine if an array is a valid heap.
An array is in heap form if every element's children are smaller than or equal to the element itself.
Take the following array as an example:

[90, 15, 10, 7, 12, 2]

Really, this is a binary tree arranged in the form of an array. This is because every element has children. 90 has two children, 15 and 10.

       15, 10,
[(90),         7, 12, 2]

15 also has children, 7 and 12:

               7, 12,
[90, (15), 10,        2]

10 has children:

                      2
[90, 15, (10), 7, 12,  ]

and the next element would also be a child of 10, except that there isn't room. 7, 12 and 2 would all also have children if the array was long enough. Here is another example of a heap:

[16, 14, 10, 8, 7, 9, 3, 2, 4, 1]

And here is a visualization of the tree the previous array makes:

enter image description here

Just in case this isn't clear enough, here is the explicit formula to get the children of the i'th element

//0-indexing:
child1 = (i * 2) + 1
child2 = (i * 2) + 2

//1-indexing:
child1 = (i * 2)
child2 = (i * 2) + 1

You must take an non-empty array as input and output a truthy value if the array is in heap order, and a falsy value otherwise.
This can be a 0-indexed heap, or a 1-indexed heap as long as you specify which format your program/function expects.
You may assume that all arrays will only contain positive integers. You may not use any heap-builtins. This includes, but is not limited to

    Functions that determine if an array is in heap-form
    Functions that convert an array into a heap or into heap-form
    Functions that take an array as input and return a heap data-structure

You can use this python script to verify if an array is in heap-form or not (0 indexed):

def is_heap(l):
    for head in range(0, len(l)):
        c1, c2 = head * 2 + 1, head * 2 + 2
        if c1 < len(l) and l[head] < l[c1]:
            return False
        if c2 < len(l) and l[head] < l[c2]:
            return False

    return True

Test IO:

All of these inputs should return True:

[90, 15, 10, 7, 12, 2]
[93, 15, 87, 7, 15, 5]
[16, 14, 10, 8, 7, 9, 3, 2, 4, 1]
[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
[100, 19, 36, 17, 3, 25, 1, 2, 7]
[5, 5, 5, 5, 5, 5, 5, 5]

And all of these inputs should return False:

[4, 5, 5, 5, 5, 5, 5, 5]
[90, 15, 10, 7, 12, 11]
[1, 2, 3, 4, 5]
[4, 8, 15, 16, 23, 42]
[2, 1, 3]

As usual, this is code-golf, so standard loopholes apply and the shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
ismaxheap(int *a, size_t n)
{
	size_t i, l, r;

	for (i = 0; i < n; i++) {
		l = i * 2 + 1;
		r = i * 2 + 2;
		if (l < n && a[i] < a[l])
			return false;
		if (r < n && a[i] < a[r])
			return false;
	}
	return true;
}

int
main(void)
{
	int t1[] = {90, 15, 10, 7, 12, 2};
	int t2[] = {93, 15, 87, 7, 15, 5};
	int t3[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
	int t4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int t5[] = {100, 19, 36, 17, 3, 25, 1, 2, 7};
	int t6[] = {5, 5, 5, 5, 5, 5, 5, 5};

	int f1[] = {4, 5, 5, 5, 5, 5, 5, 5};
	int f2[] = {90, 15, 10, 7, 12, 11};
	int f3[] = {1, 2, 3, 4, 5};
	int f4[] = {4, 8, 15, 16, 23, 42};
	int f5[] = {2, 1, 3};

	assert(ismaxheap(t1, nelem(t1)) == true);
	assert(ismaxheap(t2, nelem(t2)) == true);
	assert(ismaxheap(t3, nelem(t3)) == true);
	assert(ismaxheap(t4, nelem(t4)) == true);
	assert(ismaxheap(t5, nelem(t5)) == true);
	assert(ismaxheap(t6, nelem(t6)) == true);

	assert(ismaxheap(f1, nelem(f1)) == false);
	assert(ismaxheap(f2, nelem(f2)) == false);
	assert(ismaxheap(f3, nelem(f3)) == false);
	assert(ismaxheap(f4, nelem(f4)) == false);
	assert(ismaxheap(f5, nelem(f5)) == false);

	return 0;
}
