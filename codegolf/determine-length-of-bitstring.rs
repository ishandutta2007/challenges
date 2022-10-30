/*

Optimize the following function for number of tokens:

int length(int x)
{
    switch (x)
    {
    case 1: return 1;
    case 3: return 2;
    case 7: return 3;
    case 15: return 4;
    case 31: return 5;
    case 63: return 6;
    case 127: return 7;
    case 255: return 8;
    case 511: return 9;
    case 1023: return 10;
    case 2047: return 11;
    default: return 0;
    }
}

No additional cases besides the 11 shown above need to be handled. The default case will never occur (but Java needs one, or else it does not compile). Any programming language is allowed. Whole programs are also allowed.

If you embed another language inside strings, the tokens in the embedded language count as well.

The baseline is 53 tokens, since separators don't seem to count in atomic-code-golf. Have fun!

*/

fn main() {
    assert_eq!(length(1), 1);
    assert_eq!(length(3), 2);
    assert_eq!(length(7), 3);
    assert_eq!(length(15), 4);
    assert_eq!(length(31), 5);
    assert_eq!(length(63), 6);
    assert_eq!(length(127), 7);
    assert_eq!(length(255), 8);
    assert_eq!(length(511), 9);
    assert_eq!(length(1023), 10);
    assert_eq!(length(2047), 11);
}

fn length(x: usize) -> usize {
    format!("{:b}", x).len()
}
