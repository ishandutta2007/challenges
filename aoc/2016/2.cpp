/*

--- Day 2: Bathroom Security ---
You arrive at Easter Bunny Headquarters under cover of darkness. However, you left in such a rush that you forgot to use the bathroom!
Fancy office buildings like this one usually have keypad locks on their bathrooms, so you search the front desk for the code.

"In order to improve security," the document you find says, "bathroom codes will no longer be written down.
Instead, please memorize and follow the procedure below to access the bathrooms."

The document goes on to explain that each button to be pressed can be found by starting on the previous button and moving to adjacent buttons on the keypad: U moves up, D moves down, L moves left, and R moves right.
Each line of instructions corresponds to one button, starting at the previous button (or, for the first line, the "5" button); press whatever button you're on at the end of each line. If a move doesn't lead to a button, ignore it.

You can't hold it much longer, so you decide to figure out the code as you walk to the bathroom. You picture a keypad like this:

1 2 3
4 5 6
7 8 9
Suppose your instructions are:

ULL
RRDDD
LURDL
UUUUD
You start at "5" and move up (to "2"), left (to "1"), and left (you can't, and stay on "1"), so the first button is 1.
Starting from the previous button ("1"), you move right twice (to "3") and then down three times (stopping at "9" after two moves and ignoring the third), ending up with 9.
Continuing from "9", you move left, up, right, down, and left, ending with 8.
Finally, you move up four times (stopping at "2"), then down once, ending with 5.
So, in this example, the bathroom code is 1985.

Your puzzle input is the instructions from the document you found at the front desk. What is the bathroom code?

--- Part Two ---
You finally arrive at the bathroom (it's a several minute walk from the lobby so visitors can behold the many fancy conference rooms and water coolers on this floor) and go to punch in the code.
Much to your bladder's dismay, the keypad is not at all like you imagined it. Instead, you are confronted with the result of hundreds of man-hours of bathroom-keypad-design meetings:

    1
  2 3 4
5 6 7 8 9
  A B C
    D
You still start at "5" and stop when you're at an edge, but given the same instructions as above, the outcome is very different:

You start at "5" and don't move at all (up and left are both edges), ending at 5.
Continuing from "5", you move right twice and down three times (through "6", "7", "B", "D", "D"), ending at D.
Then, from "D", you move five more times (through "D", "B", "C", "C", "B"), ending at B.
Finally, after five more moves, you end at 3.
So, given the actual keypad layout, the code would be 5DB3.

Using the same instructions in your puzzle input, what is the correct bathroom code?

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> getlines(const string &name)
{
	vector<string> lines;

	fstream fin(name);
	if (!fin.is_open())
		return lines;

	string line;
	while (fin >> line)
		lines.push_back(line);

	return lines;
}

char move1(char c, int &x, int &y)
{
	static const char grid[3][3] = {
		{ '1', '2', '3' },
		{ '4', '5', '6' },
		{ '7', '8', '9' },
	};

	switch (c)
	{
	case 'U':
		y = (y > 0) ? y - 1 : y;
		break;
	case 'D':
		y = (y < 2) ? y + 1 : y;
		break;
	case 'L':
		x = (x > 0) ? x - 1 : x;
		break;
	case 'R':
		x = (x < 2) ? x + 1 : x;
		break;
	}
	return grid[y][x];
}

char move2(char c, int &x, int &y)
{
	static const char grid[5][5] = {
		{ ' ', ' ', '1', ' ', ' ' },
		{ ' ', '2', '3', '4', ' ' },
		{ '5', '6', '7', '8', '9' },
		{ ' ', 'A', 'B', 'C', ' ' },
		{ ' ', ' ', 'D', ' ', ' ' },
	};

	switch (c)
	{
	case 'U':
		if (y > 0 && grid[y - 1][x] != ' ')
			y--;
		break;
	case 'D':
		if (y < 4 && grid[y + 1][x] != ' ')
			y++;
		break;
	case 'L':
		if (x > 0 && grid[y][x - 1] != ' ')
			x--;
		break;
	case 'R':
		if (x < 4 && grid[y][x + 1] != ' ')
			x++;
		break;
	}
	return grid[y][x];
}

string follow(const vector<string> &directions, char (*move)(char, int &, int &), int x, int y)
{
	string code = "";
	for (auto direction : directions)
	{
		char key;
		for (auto c : direction)
			key = move(c, x, y);
		code += key;
	}

	return code;
}

int main()
{
	auto directions = getlines("2.txt");

	cout << follow(directions, move1, 1, 1) << endl;
	cout << follow(directions, move2, 0, 2) << endl;

	return 0;
}
