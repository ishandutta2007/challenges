#!/usr/bin/env python

"""

Your task is to write a full program that will continue to count down from 10 every time it is run.

The first time you run the program, it should print 10.
The next time, it should output 9.
The next time, it should output 8, and so on.
Instead of printing 0, the program should crash. You do not have to handle the program running any more times after that.
Any facilities used for storage may be assumed to be empty before the first execution of the program.
Here's an example implementation in Python 3:

try:f=open("a","r+");v=int(f.read())
except:f=open("a","w");v=10
1/v
print(v)
f.seek(0)
f.write(str(v-1))
This is code-golf, so the shortest answer (measured in bytes) wins.

"""

def get():
    try:
        f = open("counter.txt", "r+")
        v = int(f.read())
        f.close()
    except:
        v = 10
    return v

def put(v):
    try:
        f = open("counter.txt", "w")
        f.write(str(v))
        f.close()
    except:
        pass

def crashoff():
    v = get()
    if v == 0:
        raise Exception('CRASH AND BURN')
    print(v)
    put(v - 1)

def main():
    crashoff()

main()
