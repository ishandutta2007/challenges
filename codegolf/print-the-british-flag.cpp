/*

Inspired by Print the American Flag! this is a direct copy but with the British flag as it has some symmetries but is still quite complex!

Your challenge is to produce the following ASCII-Art in as few bytes as possible! Turn your head/screen (not both!) by 90 degrees to view it properly.

 __________________________________________ 
|\  \XXXXXXXXXXXX  000000  XXXXXXXXXXXX//0/|
|0\  \XXXXXXXXXXX  000000  XXXXXXXXXXX//0/ |
|\0\  \XXXXXXXXXX  000000  XXXXXXXXXX//0/  |
|\\0\  \XXXXXXXXX  000000  XXXXXXXXX//0/  /|
|X\\0\  \XXXXXXXX  000000  XXXXXXXX//0/  /X|
|XX\\0\  \XXXXXXX  000000  XXXXXXX//0/  /XX|
|XXX\\0\  \XXXXXX  000000  XXXXXX//0/  /XXX|
|XXXX\\0\  \XXXXX  000000  XXXXX//0/  /XXXX|
|XXXXX\\0\  \XXXX  000000  XXXX//0/  /XXXXX|
|XXXXXX\\0\  \XXX  000000  XXX//0/  /XXXXXX|
|XXXXXXX\\0\  \XX  000000  XX//0/  /XXXXXXX|
|XXXXXXXX\\0\  \X  000000  X//0/  /XXXXXXXX|
|XXXXXXXXX\\0\  \  000000  //0/  /XXXXXXXXX|
|XXXXXXXXXX\\0\    000000  /0/  /XXXXXXXXXX|
|XXXXXXXXXXX\\0\   000000  0/  /XXXXXXXXXXX|
|XXXXXXXXXXXX\\0\  000000  /  /XXXXXXXXXXXX|
|XXXXXXXXXXXXX\\0  000000    /XXXXXXXXXXXXX|
|XXXXXXXXXXXXXX\\  000000   /XXXXXXXXXXXXXX|
|                  000000                  |
|000000000000000000000000000000000000000000|
|000000000000000000000000000000000000000000|
|000000000000000000000000000000000000000000|
|                  000000                  |
|XXXXXXXXXXXXXX/   000000  \\XXXXXXXXXXXXXX|
|XXXXXXXXXXXXX/    000000  0\\XXXXXXXXXXXXX|
|XXXXXXXXXXXX/  /  000000  \0\\XXXXXXXXXXXX|
|XXXXXXXXXXX/  /0  000000   \0\\XXXXXXXXXXX|
|XXXXXXXXXX/  /0/  000000    \0\\XXXXXXXXXX|
|XXXXXXXXX/  /0//  000000  \  \0\\XXXXXXXXX|
|XXXXXXXX/  /0//X  000000  X\  \0\\XXXXXXXX|
|XXXXXXX/  /0//XX  000000  XX\  \0\\XXXXXXX|
|XXXXXX/  /0//XXX  000000  XXX\  \0\\XXXXXX|
|XXXXX/  /0//XXXX  000000  XXXX\  \0\\XXXXX|
|XXXX/  /0//XXXXX  000000  XXXXX\  \0\\XXXX|
|XXX/  /0//XXXXXX  000000  XXXXXX\  \0\\XXX|
|XX/  /0//XXXXXXX  000000  XXXXXXX\  \0\\XX|
|X/  /0//XXXXXXXX  000000  XXXXXXXX\  \0\\X|
|/  /0//XXXXXXXXX  000000  XXXXXXXXX\  \0\\|
|  /0//XXXXXXXXXX  000000  XXXXXXXXXX\  \0\|
| /0//XXXXXXXXXXX  000000  XXXXXXXXXXX\  \0|
|/0//XXXXXXXXXXXX__000000__XXXXXXXXXXXX\__\|
The block is 44 x 42 characters. Note that the first line ends with a single space! No other trailing spaces are allowed but a trailing new line is allowed on the last line.

I'm not aware of any date significance for the UK at the moment!

*/

#include <cstdio>

const auto british_flag = R"(
 __________________________________________
|\  \XXXXXXXXXXXX  000000  XXXXXXXXXXXX//0/|
|0\  \XXXXXXXXXXX  000000  XXXXXXXXXXX//0/ |
|\0\  \XXXXXXXXXX  000000  XXXXXXXXXX//0/  |
|\\0\  \XXXXXXXXX  000000  XXXXXXXXX//0/  /|
|X\\0\  \XXXXXXXX  000000  XXXXXXXX//0/  /X|
|XX\\0\  \XXXXXXX  000000  XXXXXXX//0/  /XX|
|XXX\\0\  \XXXXXX  000000  XXXXXX//0/  /XXX|
|XXXX\\0\  \XXXXX  000000  XXXXX//0/  /XXXX|
|XXXXX\\0\  \XXXX  000000  XXXX//0/  /XXXXX|
|XXXXXX\\0\  \XXX  000000  XXX//0/  /XXXXXX|
|XXXXXXX\\0\  \XX  000000  XX//0/  /XXXXXXX|
|XXXXXXXX\\0\  \X  000000  X//0/  /XXXXXXXX|
|XXXXXXXXX\\0\  \  000000  //0/  /XXXXXXXXX|
|XXXXXXXXXX\\0\    000000  /0/  /XXXXXXXXXX|
|XXXXXXXXXXX\\0\   000000  0/  /XXXXXXXXXXX|
|XXXXXXXXXXXX\\0\  000000  /  /XXXXXXXXXXXX|
|XXXXXXXXXXXXX\\0  000000    /XXXXXXXXXXXXX|
|XXXXXXXXXXXXXX\\  000000   /XXXXXXXXXXXXXX|
|                  000000                  |
|000000000000000000000000000000000000000000|
|000000000000000000000000000000000000000000|
|000000000000000000000000000000000000000000|
|                  000000                  |
|XXXXXXXXXXXXXX/   000000  \\XXXXXXXXXXXXXX|
|XXXXXXXXXXXXX/    000000  0\\XXXXXXXXXXXXX|
|XXXXXXXXXXXX/  /  000000  \0\\XXXXXXXXXXXX|
|XXXXXXXXXXX/  /0  000000   \0\\XXXXXXXXXXX|
|XXXXXXXXXX/  /0/  000000    \0\\XXXXXXXXXX|
|XXXXXXXXX/  /0//  000000  \  \0\\XXXXXXXXX|
|XXXXXXXX/  /0//X  000000  X\  \0\\XXXXXXXX|
|XXXXXXX/  /0//XX  000000  XX\  \0\\XXXXXXX|
|XXXXXX/  /0//XXX  000000  XXX\  \0\\XXXXXX|
|XXXXX/  /0//XXXX  000000  XXXX\  \0\\XXXXX|
|XXXX/  /0//XXXXX  000000  XXXXX\  \0\\XXXX|
|XXX/  /0//XXXXXX  000000  XXXXXX\  \0\\XXX|
|XX/  /0//XXXXXXX  000000  XXXXXXX\  \0\\XX|
|X/  /0//XXXXXXXX  000000  XXXXXXXX\  \0\\X|
|/  /0//XXXXXXXXX  000000  XXXXXXXXX\  \0\\|
|  /0//XXXXXXXXXX  000000  XXXXXXXXXX\  \0\|
| /0//XXXXXXXXXXX  000000  XXXXXXXXXXX\  \0|
|/0//XXXXXXXXXXXX__000000__XXXXXXXXXXXX\__\|
)";

int main()
{
	printf("%s\n", british_flag);
	return 0;
}
