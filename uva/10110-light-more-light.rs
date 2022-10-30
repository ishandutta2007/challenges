/*

There is man named ”mabu” for switching on-off light in our University. He switches on-off the lights in a corridor.
Every bulb has its own toggle switch. That is, if it is pressed then the bulb turns on. Another press will turn it off.
To save power consumption (or may be he is mad or something else) he does a peculiar thing.
If in a corridor there is n bulbs, he walks along the corridor back and forth n times and in i-th walk he toggles only the switches whose serial is divisible by i.
He does not press any switch when coming back to his initial position.
A i-th walk is defined as going down the corridor (while doing the peculiar thing) and coming back again. Now you have to determine what is the final condition of the last bulb. Is it on or off?

Input
The input will be an integer indicating the n’th bulb in a corridor. Which is less then or equals 2^32 −1.
A zero indicates the end of input. You should not process this input.

Output
Output ‘yes’ if the light is on otherwise ‘no’, in a single line.

Sample Input
3
6241
8191
0

Sample Output
no
yes
no

*/

fn main() {
    assert_eq!(light(3), false);
    assert_eq!(light(6241), true);
    assert_eq!(light(8191), false);
}

fn light(n: usize) -> bool {
    let x = (n as f64).sqrt() as usize;
    x * x == n
}
