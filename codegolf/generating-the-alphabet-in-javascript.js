/*

I'm pretty sure there's not a better way to do this but figured it couldn't hurt to ask.

I'm tired of typing out a='abcdefghijklmnopqrstuvwxyz'.

Cool languages have Range('a'..'z') or similar

What can we come up with with JS that's as short as possible??

for(i=97,a='';i<123;){a+=String.fromCharCode(i++)}

is longer than just the alphabet - but guarantees I don't screw up somewhere.

I'm hoping there's a nasty bit-shifty way to produce a-z in less than 50 characters.

I messed around with i=97;Array(26).map(x=>String.fromChar....i++

but it was always way longer by the time I joined then split the array(26) to be useable

Edit: I've gotten it down to

[...Array(26)].reduce(a=>a+String.fromCharCode(i++),'',i=97)

60 bytes

*/

function main() {
	for (i = 97; i < 123; i++)
		process.stdout.write(String.fromCharCode(i));
	console.log();
}

main();
