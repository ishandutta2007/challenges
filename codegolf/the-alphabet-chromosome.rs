/*

Introduction
Alphabet challenges are in our DNA, so let's show it.

Challenge
Print the following the text exactly:

AaBbCc        cCbBaA
BbCcDd        dDcCbB
EeFfGg        gGfFeE
HhIiJj        jJiIhH
KkLlMm        mMlLkK
NnOoPp        pPoOnN
QqRrSs        sSrRqQ
TtUuVv        vVuUtT
   WwXx      xXwW
       Yy  yY
         ZZ
         zz
         ZZ
       Yy  yY
   WwXx      xXwW
TtUuVv        vVuUtT
QqRrSs        sSrRqQ
NnOoPp        pPoOnN
KkLlMm        mMlLkK
HhIiJj        jJiIhH
EeFfGg        gGfFeE
BbCcDd        dDcCbB
AaBbCc        cCbBaA

Rules
You must match the case of each letter
Trailing and/or leading newlines and/or spaces are allowed

Winning
Shortest code in bytes wins.

*/

fn main() {
    println!("{}", TEXT);
}

const TEXT: &str = "
AaBbCc        cCbBaA
BbCcDd        dDcCbB
EeFfGg        gGfFeE
HhIiJj        jJiIhH
KkLlMm        mMlLkK
NnOoPp        pPoOnN
QqRrSs        sSrRqQ
TtUuVv        vVuUtT
   WwXx      xXwW
       Yy  yY
         ZZ
         zz
         ZZ
       Yy  yY
   WwXx      xXwW
TtUuVv        vVuUtT
QqRrSs        sSrRqQ
NnOoPp        pPoOnN
KkLlMm        mMlLkK
HhIiJj        jJiIhH
EeFfGg        gGfFeE
BbCcDd        dDcCbB
AaBbCc        cCbBaA
";
