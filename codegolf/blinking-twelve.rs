/*

Many electronic devices, specially old ones, will show a blinking 12:00 when the time has not been set. The purpose of this challenge is to recreate this.

Specifically, the task is to display 12:00 and --:-- alternatively in an infinite loop.

The period should be 1 second, divided evenly in two periods of 0.5 seconds. Here "1 second" and "evenly" can be interpreted loosely.
For example, it is acceptable if the code pauses for 0.5 seconds between displaying the strings, even if the resulting period will then be a little higher than 1 second.
An initial pause before displaying the first string is acceptable.

Each new string can be displayed either by replacing the former string or in a new line.
Trailing whitespace is allowed, except that if each new string is on a different line there should be no empty lines between consecutive strings.

Shortest code in bytes wins.

*/

use std::{thread, time};

fn main() {
    let mut i = 0;
    loop {
        print!("\x1bc");
        if i == 0 {
            println!("12:00");
        } else {
            println!("--:--");
        }
        i = 1 - i;

        let delay = time::Duration::from_secs(1);
        thread::sleep(delay);
    }
}
