/*

The challenge: output this exact ASCII art of a spiderweb in a window:

 _______________________________
|\_____________________________/|
||    \         |         /    ||
||     \       /|\       /     ||
||     /\'.__.' : '.__.'/\     ||
|| __.'  \      |      /  '.__ ||
||'.     /\'---':'---'/\     .'||
||\ '. /'  \__ _|_ __/  '\ .' /||
|| |  /.   /\ ' : ' /\   .\  | ||
|| |  | './  \ _|_ /  \.' |  | ||
||/ '/.  /'. // : \\ .'\  .\' \||
||__/___/___/_\(+)/_\___\___\__||
||  \   \   \ /(O)\ /   /   /  ||
||\ .\'  \.' \\_:_// './  '/. /||
|| |  | .'\  /  |  \  /'. |  | ||
|| |  \'   \/_._:_._\/   '/  | ||
||/ .' \   /    |    \   / '. \||
||.'_   '\/.---.:.---.\/'   _'.||
||   '.  / __   |   __ \  .'   ||
||     \/.'  '. : .'  '.\/     ||
||     /       \|/       \     ||
||____/_________|_________\____||
|/_____________________________\|
Source: Joan Stark (slightly modified spider and frame, and remove the initials for the sake of the challenge).

Required characters: _|\/'.:-(+)O (12) + space & new-line (2)

Challenge rules:
One or multiple trailing spaces and/or new-lines are allowed.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

*/

package main

import "fmt"

func main() {
	fmt.Println(spiderweb)
}

const spiderweb = `
 _______________________________
|\_____________________________/|
||    \         |         /    ||
||     \       /|\       /     ||
||     /\'.__.' : '.__.'/\     ||
|| __.'  \      |      /  '.__ ||
||'.     /\'---':'---'/\     .'||
||\ '. /'  \__ _|_ __/  '\ .' /||
|| |  /.   /\ ' : ' /\   .\  | ||
|| |  | './  \ _|_ /  \.' |  | ||
||/ '/.  /'. // : \\ .'\  .\' \||
||__/___/___/_\(+)/_\___\___\__||
||  \   \   \ /(O)\ /   /   /  ||
||\ .\'  \.' \\_:_// './  '/. /||
|| |  | .'\  /  |  \  /'. |  | ||
|| |  \'   \/_._:_._\/   '/  | ||
||/ .' \   /    |    \   / '. \||
||.'_   '\/.---.:.---.\/'   _'.||
||   '.  / __   |   __ \  .'   ||
||     \/.'  '. : .'  '.\/     ||
||     /       \|/       \     ||
||____/_________|_________\____||
|/_____________________________\|

`
