/*

Antiferromagnetic ordering

Antiferromagnetism is what IBM researchers used to jump from a 1 terabyte disk to a 100 terabyte disk in the same amount of atoms.

In materials that exhibit antiferromagnetism, the magnetic moments of atoms or molecules, usually related to the spins of electrons, align in a regular pattern with neighboring spins (on different sublattices) pointing in opposite directions.

Your job is to write a program that draws the ordering of antiferromagnetic atoms like the picture shown above. You must be able to have at least four sets of pairs, though you may have more.

Each pair must be shown as follows, though they must be actual arrows:

 up  down
down  up
 up  down

Your output can be in ascii art or graphical output.

You can make only a function or a whole program, but it must take an input and draw that many pairs. Examples with only words:

Input: 1

 up  down
down  up
 up  down

Input: 2

 up  down  up  down 
down  up  down  up  
 up  down  up  down

Acceptable arrows:

    ↑ and ↓
    ⇅ and ⇵
    /|\ and \|/

Please put your answers in Language, X bytes format, as it's easy to read. The least amount of bytes wins!

*/

fn main() {
    magnets(3, 2);
    magnets(3, 4);
}

fn magnets(n: isize, m: isize) {
    for i in 0..n {
        for j in 0..m {
            if (i^j)&1 == 0 {
                print!("↑");
            } else {
                print!("↓");
            }
        }
        println!();
    }
}
