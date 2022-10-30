/*

Implement a simple integer operation scriptable calculator.
Concept

The accumulator starts at 0 and has operations performed on it. At the end of the program output the value of the accumulator.

Operations:

+ adds 1 to the accumulator
- subtracts 1 from the accumulator
* multiplies the accumulator by 2
/ divides the accumulator by 2
Sample script

The input ++**--/ should give the output 3.

Example implementation

def calc(s)
    i = 0
    s.chars.each do |o|
        case o
            when '+'
                i += 1
            when '-'
                i -= 1
            when '*'
                i *= 2
            when '/'
                i /= 2
        end
    end
    return i
end

Rules
This is code-golf, so lowest answer in bytes wins, but is not selected.
Creative implementations are encouraged.
Standard loopholes are prohibited.
You get the program via stdin or arguments, and you can output the answer via return value or stdout.
Have fun.
Division truncates down because it is integer division.
The program -/ returns -1.

*/

fn main() {
    assert_eq!(calc("++**--/"), 3);
    assert_eq!(calc("-/"), -1);
    assert_eq!(calc("*///*-*+-+"), -1);
    assert_eq!(calc("/*+/*+++/*///*/+-+//*+-+-/----*-*-+++*+**+/*--///+*-/+//*//-+++--++/-**--/+--/*-/+*//*+-*-*/*+*+/+*-"), -17);
    assert_eq!(calc("+++-+--/-*/---++/-+*-//+/++-*--+*+/*/*/++--++-+//++--*/***-*+++--+-*//-*/+*/+-*++**+--*/*//-*--**-/-*+**-/*-**/*+*-*/--+/+/+//-+*/---///+**////-*//+-+-/+--/**///*+//+++/+*++**++//**+**+-*/+/*/*++-/+**+--+*++++/-*-/*+--/++*/-++/-**++++/-/+/--*/-/+---**//*///-//*+-*----+//--/-/+*/-+++-+*-*+*+-/-//*-//+/*-+//+/+/*-/-/+//+**/-****/-**-//+/+-+/*-+*++*/-/++*/-//*--+*--/-+-+/+/**/-***+/-/++-++*+*-+*+*-+-//+/-++*+/*//*-+/+*/-+/-/*/-/-+*+**/*//*+/+---+*+++*+/+-**/-+-/+*---/-*+/-++*//*/-+-*+--**/-////*/--/*--//-**/*++*+/*+/-+/--**/*-+*+/+-*+*+--*///+-++/+//+*/-+/**--//*/+++/*+*////+-*-//--*+/*/-+**/*//+*+-//+--+*-+/-**-*/+//*+---*+//*/+**/*--/--+/*-*+*++--*+//+*+-++--+-*-*-+--**+/+*-/+*+-/---+-*+-+-/++/+*///*/*-+-*//-+-++/++/*/-++/**--+-////-//+/*//+**/*+-+/+/+///*+*///*-/+/*/-//-*-**//-/-+--+/-*--+-++**++//*--/*++--*-/-///-+/+//--+*//-**-/*-*/+*/-*-*//--++*//-*/++//+/-++-+-*/*-+++**-/-*++++**+-+++-+-***-+//+-/**-+/*+****-*+++*/-*-/***/-/*+/*****++*+/-/-**-+-*-*-++**/*+-/*-+*++-/+/-++*-/*-****-*"), 18773342);
}

fn calc(s: &str) -> isize {
    let mut r = 0;
    for c in s.chars() {
        match c {
            '+' => r += 1,
            '-' => r -= 1,
            '*' => r <<= 1,
            '/' => r >>= 1,
            _ => {}
        }
    }
    r
}
