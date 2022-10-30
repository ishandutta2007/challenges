#!/usr/bin/perl -w

=pod

Output or display the following three lines of text, exactly as they are shown below. A trailing newline is accepted.

 bC#eF&hI)kL,nO/qR2tU5wX8z
A!cD$fG'iJ*lM-oP0rS3uV6xY9
aB"dE%gH(jK+mN.pQ1sT4vW7yZ

That block of text is the same as the one below, but where the n'th column is rotated n times downward:

 !"#$%&'()*+,-./0123456789
ABCDEFGHIJKLMNOPQRSTUVWXYZ
abcdefghijklmnopqrstuvwxyz

Keep in mind that this is a kolmogorov-complexity challenge, so the output format is not flexible.

=cut

use strict;

print "bC#eF&hI)kL,nO/qR2tU5wX8z\n";
print "A!cD\$fG'iJ*lM-oP0rS3uV6xY9\n";
print "aB\"dE%gH(jK+mN.pQ1sT4vW7yZ\n";
