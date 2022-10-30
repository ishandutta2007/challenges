#!/usr/bin/env lua

--[[

English, Spanish, German, French, Italian and Russian are the 6 most prominent languages in the countries of European Union.
Figure on the left shows intensity of English speaking people in different European countries.
All of these languages have different words to represent the English word “HELLO”.
For example in Spanish the word equivalent to “HELLO” is “HOLA”.
In German, French, Italian and Russian language the word that means (or similar to) “HELLO” is “HALLO”, “BONJOUR”, “CIAO” and “ZDRAVSTVUJTE” respectively.
In this problem your task is pretty simple.
You will be given one of the six words mentioned above or any other word and you will have to try and detect the language it is from.

Input
Input file contains around 2000 lines of inputs.
Each line contains a string S. You can assume that all the letters of the string are uppercase English letters and the maximum length of the string is 14.
Input is terminated by a line containing a single ‘#’ character (without the quote).
This line should not be processed.

Output
For each line of input except the last one produce one line of output. This line contains the serial of output followed by a language name.
If the input string is ‘HELLO’ or ‘HOLA’ or ‘HALLO’ or ‘BONJOUR’ or ‘CIAO’ or ‘ZDRAVSTVUJTE’ then you should report the language it belongs to.
If the input string is something other than these 6 strings print the string ‘UNKNOWN’ (without the quotes) instead.
All characters in the output strings are uppercase as well.
Look at the output for sample input for formatting details.

Sample Input
HELLO
HOLA
HALLO
BONJOUR
CIAO
ZDRAVSTVUJTE
#

Sample Output
Case 1: ENGLISH
Case 2: SPANISH
Case 3: GERMAN

--]]

function detect(s)
	tab = {
		["HELLO"] = "ENGLISH",
		["HOLA"] = "SPANISH",
		["HALLO"] = "GERMAN",
		["BONJOUR"] = "FRENCH",
		["CIAO"] = "ITALIAN",
		["ZDRAVSTVUJTE"] = "RUSSIAN",
	}
	
	l = tab[s]
	if l == nil then
		l = "UNKNOWN"
	end
	
	return l
end

assert(detect("HELLO") == "ENGLISH")
assert(detect("HOLA") == "SPANISH")
assert(detect("HALLO") == "GERMAN")
assert(detect("BONJOUR") == "FRENCH")
assert(detect("CIAO") == "ITALIAN")
assert(detect("ZDRAVSTVUJTE") == "RUSSIAN")
assert(detect("???") == "UNKNOWN")
