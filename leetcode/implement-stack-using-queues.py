#!/usr/bin/env python

"""

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.


Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.

Follow-up: Can you implement the stack using only one queue?

"""

class Queue:
    def __init__(self):
        self.values = []

    def push(self, value):
        self.values.append(value)

    def pop(self):
        value = self.peek()
        del self.values[0]
        return value

    def peek(self):
        return self.values[0]

    def size(self):
        return len(self.values)

    def empty(self):
        return self.size() == 0

class Stack:
    def __init__(self):
        self.queue = [Queue(), Queue()]

    def push(self, value):
        if self.queue[0].empty():
            self.queue[0].push(value)
            return

        size = self.queue[0].size()
        for i in range(size):
            self.queue[1].push(self.queue[0].pop())

        self.queue[0].push(value)
        
        for i in range(size):
            self.queue[0].push(self.queue[1].pop())

    def pop(self):
        return self.queue[0].pop()

    def top(self):
        return self.queue[0].peek()

    def empty(self):
        return self.queue[0].empty()

def test1():
    stack = Stack()
    for i in range(1, 11):
        stack.push(10*i)
    
    i = 10
    while not stack.empty():
        assert(stack.top() == 10*i)
        assert(stack.pop() == 10*i)
        i -= 1

def test2():
    stack = Stack()
    stack.push(1)
    stack.push(2)
    assert(stack.top() == 2)
    assert(stack.pop() == 2)
    assert(stack.empty() == False)

def main():
    test1()
    test2()

main()
