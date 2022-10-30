/*

For this problem, you just need to be able to calculate the area of convex polygons.

Input

Input starts with an integer 1≤n≤100, indicating the number of convex polygons.
The next n lines each contain one convex polygon description.
Each begins with an integer 3≤m≤100 indicating the number of points in the polygon. Following this are m pairs of integers, where each pair represents the x and y coordinates of a vertex.
The bounds on the coordinates are −5000≤x,y≤5000. The vertices are given in counter-clockwise order, and no two vertices are the same.
As is typical for a polygon, the last vertex is connected to the first one.

Output

For each polygon, output its area.

*/

fn main() {
    test(vec![[1.0, 1.0], [2.0, 1.0], [2.0, 2.0]], 0.5);
    test(vec![[0.0, 0.0], [10.0, 0.0], [13.0, 5.0], [10.0, 8.0]], 52.0);
}

fn test(v: Vec<[f64; 2]>, r: f64) {
    let p = convex_polygon_area(v);
    println!("{}", p);
    assert_eq!((p - r).abs() < 1e-3, true);
}

fn convex_polygon_area(v: Vec<[f64; 2]>) -> f64 {
    let mut r = 0.0;
    let mut i = 0;
    let mut j = 1;
    let n = v.len();
    while i < n {
        r += (v[i][0]*v[j][1]) - (v[i][1]*v[j][0]);
        i += 1;
        j = (j + 1) % n;
    }
    r*0.5
}
