<?php

/*
 
Challenge: Produce the following output using as few chars as possible:

 _   _      _ _                             _     _ _
| | | | ___| | | ___    __      _____  _ __| | __| | |
| |_| |/ _ \ | |/ _ \   \ \ /\ / / _ \| '__| |/ _` | |
|  _  |  __/ | | (_) |   \ V  V / (_) | |  | | (_| |_|
|_| |_|\___|_|_|\___( )   \_/\_/ \___/|_|  |_|\__,_(_)
                    |/
Rules and restrictions:

You may not use FIGLet or any similar tools. (Otherwise, figlet Hello, world! would be a trivial and pretty much unbeatable solution.)

Your program must consist entirely of printable ASCII characters — specifically, code points 9 (TAB), 10 (LF) and 32 – 126.
(If your language / OS requires CRLF line breaks, you may use those instead of plain LFs.)
Yes, this regrettably disqualifies any language that requires non-ASCII characters (or non-textual data) as part of its syntax.

The output must look exactly like the example above. You may, however, include extra whitespace around the output if you want. You may assume 8-character tab spacing (or your chosen platform's native default setting, if it has a consistent one).

Ps. To set the par, I came up with a 199-char Perl solution. I won't post it yet, though, in case someone comes up with it independently. (Also, it's kind of cheesy.) Of course, this shouldn't discourage you from posting your own solution, even if it's longer.

Update: Now that han has beaten it by one char, here's my cheesy 199-char Perl solution:

use Compress'Zlib;say uncompress unpack u,'M>-I]BT$*`S$,`^]YQ=R:0,&_Z<DP?8@?WVQJ]E2J"%E$$@)R(/(/MCJ*\U!OM`Z#=5`4Y>6M=L\L%DMP&DB0V.4GQL&OOGB$4:%`4TT4!R8O-Z(^BTZWNV?>F86K:9+""-35*-LNC:T^D:_$#%^`";"DD0'
It's very similar to D C's solution (and all the other zlib/gzip-based solutions in various languages), except that I used uuencoding instead of base64 for the compressed text and a few other minor golfing tricks.

Update 2: I think it's time to officially accept a winner. The first place goes to konsolenfreddy's PHP code, since, however you count the chars, it is the shortest submitted so far.
In fact, combining it with the optimized DEFLATE stream from my 199-char Perl code yields an even shorter 176-char solution:

<?=gzinflate(base64_decode("fYtBCgMxDAPvecXcmkDBv+nJMH2IH99savZUqghZRBICciDyD7Y6ivNQbwOg3VQFOXlrXbPLBZLcBpIkNjlJ8bBr754hFGhQFNNFAcmLzeiPotOt7tn3plq2mSwgjU1SjbLo2tPpGvxAxfgA"));
However, I do think that han deserves a special honorary mention for getting so close without using any pre-written decompression tools. Congratulations to both of you, and a happy new year to everyone! 
 
*/


$ART = <<<EOF
 _   _      _ _                             _     _ _
| | | | ___| | | ___    __      _____  _ __| | __| | |
| |_| |/ _ \ | |/ _ \   \ \ /\ / / _ \| '__| |/ _` | |
|  _  |  __/ | | (_) |   \ V  V / (_) | |  | | (_| |_|
|_| |_|\___|_|_|\___( )   \_/\_/ \___/|_|  |_|\__,_(_)
					|/

EOF;

print $ART;

?>
