/*

Task
Given an m×n binary ascii "photo", return the negative of the photo

Example:

  #  
 # # 
#   #
 # # 
  # 
->
## ##
# # #
 ### 
# # #
## ##

General rules:
This is code-golf, so the shortest answer in bytes wins
Standard rules and default I/O rules apply
Your output characters must be the same as your input characters (e.g. ["#"," "] -> [" ","#"]), which you are free to choose (but must be printable characters)
Your output photo must have the same m×n dimensions as the input
Trailing whitespace is allowed

Test cases
Input 1:

  #  
 # # 
#   #
 # # 
  # 
Output 1:

## ##
# # #
 ### 
# # #
## ##
Input 2:

    # #
  #####
  # #  
#####  
# #    
Output 2:

#### # 
##     
## # ##
     ##
 # ####
Input 3:

##############################################################################################
#  ###  ##       ##  #######  #######       ######  ###  ##       ##       ##  #######      ##
#  ###  ##  #######  #######  #######  ###  ######  ###  ##  ###  ##  ###  ##  #######  ###  #
#       ##     ####  #######  #######  ###  ######  # #  ##  ###  ##       ##  #######  ###  #
#  ###  ##  #######  #######  #######  ###  ######   #   ##  ###  ##  #  ####  #######  ###  #
#  ###  ##       ##       ##       ##       ######  ###  ##       ##  ###  ##       ##      ##
##############################################################################################
Output 3:

 ##   ##  #######  ##       ##       #######      ##   ##  #######  #######  ##       ######  
 ##   ##  ##       ##       ##       ##   ##      ##   ##  ##   ##  ##   ##  ##       ##   ## 
 #######  #####    ##       ##       ##   ##      ## # ##  ##   ##  #######  ##       ##   ## 
 ##   ##  ##       ##       ##       ##   ##      ### ###  ##   ##  ## ##    ##       ##   ## 
 ##   ##  #######  #######  #######  #######      ##   ##  #######  ##   ##  #######  ######  

*/

#include <iostream>
#include <string>

using namespace std;

const string input1 = R"(
  #
 # #
#   #
 # #
  # )";

const string input2 = R"(
    # #
  #####
  # #
#####
# #    )";

const string input3 = R"(

##############################################################################################
#  ###  ##       ##  #######  #######       ######  ###  ##       ##       ##  #######      ##
#  ###  ##  #######  #######  #######  ###  ######  ###  ##  ###  ##  ###  ##  #######  ###  #
#       ##     ####  #######  #######  ###  ######  # #  ##  ###  ##       ##  #######  ###  #
#  ###  ##  #######  #######  #######  ###  ######   #   ##  ###  ##  #  ####  #######  ###  #
#  ###  ##       ##       ##       ##       ######  ###  ##       ##  ###  ##       ##      ##
##############################################################################################)";

string negate_photo(const string &str, char a = '#', char b = ' ')
{
	string out;
	for (auto c : str) {
		if (c == a)
			c = b;
		else if (c == b)
			c = a;

		out += c;
	}
	return out;
}

int main()
{
	cout << negate_photo(input1) << endl;
	cout << negate_photo(input2) << endl;
	cout << negate_photo(input3) << endl;

	return 0;
}
