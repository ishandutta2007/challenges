/*

Write a program rotates some Cartesian coordinates through an angle about the origin (0.0,0.0). The angle and coordinates will be read from a single line of stdin in the following format:

angle x1,y1 x2,y2 x3,y3 ...

eg.

3.14159265358979 1.0,0.0 0.0,1.0 1.0,1.0 0.0,0.0  

The results should be printed to stdout in the following format:

x1',y1' x2',y2' x3',y3' ...

eg.

-1.0,-3.23108510433268e-15 -3.23108510433268e-15,-1.0 -1.0,-1.0 -0.0,-0.0

*/

use std::f64::consts::PI;

struct Vec2 {
    x: f64,
    y: f64,
}

fn main() {
    let vectors: [Vec2; 4] = [
        Vec2{x: 1.0, y: 0.0},
        Vec2{x: 0.0, y: 1.0},
        Vec2{x: 1.0, y: 1.0},
        Vec2{x: 0.0, y: 0.0},
    ];
    rotate(PI, &vectors);
}

fn rotate(angle: f64, vectors: &[Vec2]) {
    let s = angle.sin();
    let c = angle.cos();
    for v in vectors {
        let x = v.x*c - v.y*s;
        let y = v.x*s + v.y*c;
        println!("{:.6} {:.6}", x, y);
    }
}
