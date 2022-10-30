/*

Check out the resources on the page's right side to learn more about queues. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

    Enqueue: add a new element to the end of the queue.
    Dequeue: remove the element from the front of the queue and return it.

In this challenge, you must first implement a queue using two stacks. Then process q queries, where each query is one of the following 3 types:

    1 x: Enqueue element x into the end of the queue.
    2: Dequeue the element at the front of the queue.
    3: Print the element at the front of the queue.

*/

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Queue
{
private:
	stack<T> head, tail;
	void fixup();

public:
	void enqueue(T x);
	void dequeue();
	T front();
};

template <typename T>
void Queue<T>::fixup()
{
	if (!head.empty())
		return;
	while (!tail.empty())
	{
		head.push(tail.top());
		tail.pop();
	}
}

template <typename T>
void Queue<T>::enqueue(T x)
{
	tail.push(x);
}

template <typename T>
void Queue<T>::dequeue()
{
	fixup();
	if (!head.empty())
		head.pop();
}

template <typename T>
T Queue<T>::front()
{
	fixup();
	assert(!head.empty());
	return head.top();
}

void run(vector<string> &lines)
{
	Queue<int> queue;
	for (auto line : lines)
	{
		auto op = atoi(line.c_str());
		switch (op)
		{
		case 1:
			queue.enqueue(atoi(&line[1]));
			break;
		case 2:
			queue.dequeue();
			break;
		case 3:
			cout << queue.front() << endl;
			break;
		}
	}
}

int main()
{
	vector<string> l1 =
	{
		"1 35",
		"1 15",
		"3",
		"2",
		"3",
	};
	run(l1);

	vector<string> l2 =
	{
		"1 42",
		"2",
		"1 14",
		"3",
		"1 28",
		"3",
		"1 60",
		"1 78",
		"2",
		"2",
	};
	run(l2);
	return 0;
}
