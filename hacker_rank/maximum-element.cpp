/*
You have an empty sequence, and you will be given  queries. Each query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.

Execute each query
*/

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void run(vector<string> &lines)
{
	vector<int> stack;

	for (size_t i = 0; i < lines.size(); i++)
	{
		auto str = lines[i].c_str();
		switch (str[0])
		{
		case '1':
			stack.push_back(atoi(str + 1));
			break;

		case '2':
			if (stack.size() > 0)
				stack.pop_back();
			break;

		case '3':
			int v = 0;
			if (stack.size() > 0)
			{
				v = stack[0];
				for (size_t n = 1; n < stack.size(); n++)
				{
					if (v < stack[n])
						v = stack[n];
				}
			}
			printf("%d\n", v);
			break;
		}
	}
}

int main()
{
	vector<string> lines =
	{
		{"1 97"},
		{"2"},
		{"1 20"},
		{"2"},
		{"1 26"},
		{"1 20"},
		{"2"},
		{"3"},
		{"1 91"},
		{"3"},
	};
	run(lines);
	return 0;
}
