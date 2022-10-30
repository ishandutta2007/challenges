/*

The Challenge:

Print every 2 letter word acceptable in Scrabble using as few bytes as possible.
I have created a text file list here. See also below.
There are 101 words. No word starts with C or V.
Creative, even if nonoptimal, solutions are encouraged.

AA
AB
AD
...
ZA
Rules:
The outputted words must be separated somehow.
Case does not matter, but should be consistent.
Trailing spaces and newlines are allowed. No other characters should be outputted.
The program should not take any input. External resources (dictionaries) cannot be used.
No standard loopholes.
Wordlist:

AA AB AD AE AG AH AI AL AM AN AR AS AT AW AX AY 
BA BE BI BO BY 
DE DO 
ED EF EH EL EM EN ER ES ET EX 
FA FE 
GO 
HA HE HI HM HO 
ID IF IN IS IT 
JO 
KA KI 
LA LI LO 
MA ME MI MM MO MU MY 
NA NE NO NU 
OD OE OF OH OI OM ON OP OR OS OW OX OY 
PA PE PI 
QI 
RE 
SH SI SO 
TA TI TO 
UH UM UN UP US UT 
WE WO 
XI XU 
YA YE YO 
ZA

*/

fn main() {
    let letters = vec![
        "AA", "AB", "AD", "AE", "AG", "AH", "AI", "AL", "AM", "AN", "AR", "AS", "AT", "AW", "AX",
        "AY", "BA", "BE", "BI", "BO", "BY", "DE", "DO", "ED", "EF", "EH", "EL", "EM", "EN", "ER",
        "ES", "ET", "EX", "FA", "FE", "GO", "HA", "HE", "HI", "HM", "HO", "ID", "IF", "IN", "IS",
        "IT", "JO", "KA", "KI", "LA", "LI", "LO", "MA", "ME", "MI", "MM", "MO", "MU", "MY", "NA",
        "NE", "NO", "NU", "OD", "OE", "OF", "OH", "OI", "OM", "ON", "OP", "OR", "OS", "OW", "OX",
        "OY", "PA", "PE", "PI", "QI", "RE", "SH", "SI", "SO", "TA", "TI", "TO", "UH", "UM", "UN",
        "UP", "US", "UT", "WE", "WO", "XI", "XU", "YA", "YE", "YO", "ZA",
    ];

    for str in letters {
        println!("{}", str);
    }
}
