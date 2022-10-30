/*

This is the logo for LAPACK, a widely used software library for numerical linear algebra.

enter image description here

Your task is to print the logo (color and matrix brackets not required) as this exact string. Trailing newline is allowed.

L  A  P  A  C  K
L -A  P -A  C -K
L  A  P  A -C -K
L -A  P -A -C  K
L  A -P -A  C  K
L -A -P  A  C -K

*/

fn main() {
    logo();
}

fn logo() {
    let text =
"L  A  P  A  C  K
L -A  P -A  C -K
L  A  P  A -C -K
L -A  P -A -C  K
L  A -P -A  C  K
L -A -P  A  C -K";

    println!("{}", text);
}
