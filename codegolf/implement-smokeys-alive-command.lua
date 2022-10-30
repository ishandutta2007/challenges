#!/usr/bin/env lua

--[[

Note: SmokeDetector is a bot that detects spam and offensive posts on the network and posts alerts to chat.

What to implement
Smokey's !!/alive command uniformly at random picks one of these messages:

Yup
You doubt me?
Of course
... did I miss something?
plz send teh coffee
Watching this endless list of new questions never gets boring
Kinda sorta
You should totally drop that and use jQuery
¯\_(ツ)_/¯
... good question
and prints it to the screen.

Your task is to implement that command.

Rules
Regular code-golf — the shortest answer in bytes wins ;)

Good luck!

--]]

function alive()
	tab = {
		"Yup",
		"You doubt me?",
		"Of course",
		"... did I miss something?",
		"plz send teh coffee",
		"Watching this endless list of new questions never gets boring",
		"Kinda sorta",
		"You should totally drop that and use jQuery",
		"¯\\_(ツ)_/¯",
		"... good question",
	}
	return tab[math.random(1, #tab)]
end

for i=1,20 do
	print(alive())
end
