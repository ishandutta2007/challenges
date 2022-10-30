/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

*/

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MinStack
{
private:
	stack<T> vals, mins;
public:
	MinStack()
	{
	}

	void push(T x)
	{
		vals.push(x);
		if (mins.empty())
			mins.push(x);
		else
			mins.push(min(mins.top(), x));
	}

	void pop()
	{
		vals.pop();
		mins.pop();
	}

	T top()
	{
		return vals.top();
	}

	T getMin()
	{
		return mins.top();
	}
};

int main()
{
	MinStack<int> s;
	s.push(-2);
	s.push(0);
	s.push(-3);
	cout << s.getMin() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.getMin() << endl;
	return 0;
}
