%{

I'm work on a problem which I set myself for fun, which is to create a python script which prints the even numbers from 0 to 100. The challenge is to make the script as small as possible. This is what I have so far:

for x in range(0, 101):
    if (x % 2 == 0):
        print x

Currently it is 60 bytes. Can anyone think of a way to make it smaller?

Edit: print(*range(2,101,2),sep='\n') which is 30 bytes. Any smaller?

%}

for i = 0:2:100
	disp(i)
end
