/*

You have a 3x3 grid. Each cell can be colored black or white. Display all 512 of these colorings. Fewest bytes wins.

You can display the grids in any formation as long as they are visually separated and the spacing looks regular. You may use ASCII art or images.
Any two distinct visible symbols or colors can be used for black and white. Any whitespace is fine as long as the result is visually correct.

*/

fn main() {
    display();
}

fn display() {
    for i in 0..512 {
        grid(i);
    }
}

fn grid(v: isize) {
    let mut i = 2;
    while i >= 0 {
        let mut j = 2;
        while j >= 0 {
            let b = (3 * i) + j;
            if v & (1 << b) != 0 {
                print!("X");
            } else {
                print!(".");
            }
            j -= 1;
        }
        println!();
        i -= 1;
    }
    println!();
}
