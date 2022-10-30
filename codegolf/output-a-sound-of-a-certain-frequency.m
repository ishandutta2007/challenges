%{

This is a rather simple challenge, but I couldn't find any question that was really similar to it. The challenge is to take a frequency in using STDIN or an equivalent, and then output a tone that matches that frequency, in Hz, for 5 seconds. For example

Input: 400
Output: (a tone of 400 Hz with a duration of 5 seconds)
Rules
Input must be taken in through STDIN, or your language's equivalent
The answer must be a full program
Builtins may be used
The frequency will be anywhere from 50 - 5000 Hz
The output must be played for 5 seconds
The output must be in the form of a sine wave

Test cases
Input: 440

Output:

Input: 200

Output:

Input: 4000

Output:


This is not about finding the language with the shortest solution for this (there are some where the empty program does the trick) - this is about finding the shortest solution in every language. Therefore, no answer will be marked as accepted.

Unlike our usual rules, feel free to use a language (or language version) even if it's newer than this challenge. Languages specifically written to submit a 0-byte answer to this challenge are fair game but not particularly interesting.

Note that there must be an interpreter so the submission can be tested. It is allowed (and even encouraged) to write this interpreter yourself for a previously unimplemented language.

Also note that languages do have to fullfil our usual criteria for programming languages.

%}

args = argv();
if (nargin < 1)
	printf("usage: <frequency> ...\n");
	return;
end

for i = 1:nargin
	frequency = str2double(args{i});
	sample_rate = 44100;
	duration = 5;
	t = 0 : (1/sample_rate) : duration;
	x = sin(2*pi*frequency*t);

	printf("Playing tone %f\n", frequency);
	soundsc(x, sample_rate, 24);
end

