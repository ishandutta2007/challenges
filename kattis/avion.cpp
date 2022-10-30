/*

Mirko and Slavko are USKOK agents tracking the movements of an unnamed corrupt government official. Anonymous sources have tipped them about his upcoming escape attempt.
They now know he plans to use his diplomatic liaisons to try and hitch a ride on a CIA blimp leaving from Severin na Kupi blimp port.

It is common knowledge that all CIA blimps have the string “FBI” somewhere in their registration codes. They obtained a list of all blimps scheduled for the designated day.
There are exactly 5 blimps on the list. Write a program that will point out all CIA blimps.

Input

There are exactly 5 rows of input, each row representing one blimp registration code from the list. A registration code is a sequence of at most 11 uppercase letters of the English alphabet, digits ‘0’ to ‘9’, or dashes ‘-’.

Output

The first and only line of output must contain a space separated list of integers, sorted in increasing order, indicating the corresponding input rows containing registrations of CIA blimps.

If there are no CIA blimps, output the string “HE GOT AWAY!”.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void avion(const vector<string> &list)
{
	size_t i = 1, n = 0;
	for (auto &l : list)
	{
		if (l.find("FBI") != string::npos)
		{
			if (n++ >= 1)
				cout << " ";
			cout << i;
		}
		i++;
	}
	if (n == 0)
		cout << "HE GOT AWAY!";
	cout << endl;
}

int main()
{
	avion({"N-FBI1", "9A-USKOK", "I-NTERPOL", "G-MI6", "RF-KGB1"});
	avion({"N321-CIA", "F3-B12I", "F-BI-12", "OVO-JE-CIA", "KRIJUMCAR1"});
	avion({"47-FBI", "BOND-007", "RF-FBI18", "MARICA-13", "13A-FBILL"});
	return 0;
}
