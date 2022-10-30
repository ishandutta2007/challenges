/*

Input:
Integer n which is >=0 or >=1 (f(0) is optional)

Output:
The n'th number in the sequence below, OR the sequence up to and including the n'th number.

Sequence:
(0),1,-1,-3,0,5,-1,-7,0,9,-1,-11,0,13,-1,-15,0,17,-1,-19,0,21,-1,-23,0,25,-1,-27,0,29,-1,-31,0,33,-1,-35,0,37,-1,-39,0,41,-1,-43,0,45,-1,-47,0,49,-1,-51,0,53,-1,-55,0,57,-1,-59,0,61,-1,-63,0,65,-1,-67,0,69,-1,-71,0,73,-1,-75,0,77,-1,-79,0,81,-1,-83,0,85,-1,-87,0,89,-1,-91,0,93,-1,-95,0,97,-1,-99
How is this sequence build?

f(n=0) = 0 (optional)
f(n=1) = f(0) + n or f(n=1) = 1
f(n=2) = f(1) - n
f(n=3) = f(2) * n
f(n=4) = f(3) / n
f(n=5) = f(4) + n
etc.

Or in pseudo-code:

function f(integer n){
  Integer result = 0
  Integer i = 1
  Loop as long as i is smaller than or equal to n
  {
    if i modulo-4 is 1:
      result = result plus i
    if i modulo-4 is 2 instead:
      result = result minus i
    if i modulo-4 is 3 instead:
      result = result multiplied with i
    if i modulo-4 is 0 instead:
      result = result integer/floor-divided with i
    i = i plus 1
  }
  return result
}
But as you may have noted there are two patterns in the sequence:

0, ,-1,  ,0, ,-1,  ,0, ,-1,   ,0,  ,-1,   ,0,  ,-1,   ,...
 ,1,  ,-3, ,5,  ,-7, ,9,  ,-11, ,13,  ,-15, ,17,  ,-19,...
so any other approaches resulting in the same sequence are of course completely fine as well.

Challenge rules:
0-indexed and 1-indexed inputs will result in the same result (which is why the f(0) is optional for 0-indexed inputs if you want to include it).
You are allowed to output the n'th number of this sequence. Or the entire sequence up and including the n'th number. (So f(5) can result in either 5 or 0,1,-1,-3,0,5.)
If you choose to output the sequence up to and including the n'th number, output format is flexible. Can be a list/array, comma/space/new-line delimited string or printed to STDOUT, etc.
The divide (/) is integer/floor division, which rounds towards 0 (not towards negative infinity as is the case in some languages).
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Additional test cases above n=100:
Input     Output

1000      0
100000    0
123       -123
1234      -1
12345     12345
123456    0

*/

fn main() {
    let res = vec![
        0, 1, -1, -3, 0, 5, -1, -7, 0, 9, -1, -11, 0, 13, -1, -15, 0, 17, -1, -19, 0, 21, -1, -23,
        0, 25, -1, -27, 0, 29, -1, -31, 0, 33, -1, -35, 0, 37, -1, -39, 0, 41, -1, -43, 0, 45, -1,
        -47, 0, 49, -1, -51, 0, 53, -1, -55, 0, 57, -1, -59, 0, 61, -1, -63, 0, 65, -1, -67, 0, 69,
        -1, -71, 0, 73, -1, -75, 0, 77, -1, -79, 0, 81, -1, -83, 0, 85, -1, -87, 0, 89, -1, -91, 0,
        93, -1, -95, 0, 97, -1, -99,
    ];

    for (i, v) in res.iter().enumerate() {
        assert_eq!(f(i as isize), *v);
    }

    assert_eq!(f(1000), 0);
    assert_eq!(f(100000), 0);
    assert_eq!(f(123), -123);
    assert_eq!(f(1234), -1);
    assert_eq!(f(12345), 12345);
    assert_eq!(f(123456), 0);
}

fn f(n: isize) -> isize {
    let mut r = 0;
    for i in 1..n + 1 {
        r = match i & 3 {
            1 => r + i,
            2 => r - i,
            3 => r * i,
            _ => r / i,
        };
    }
    r
}
