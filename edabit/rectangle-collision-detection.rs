/*

Make a Rectangle class with four parameters, an x, a y (representing the top-left corner of the rectangle), a width and a height exclusively in that order.

Lastly, make a function intersecting that takes two Rectangle objects and returns True if those objects are intersecting (colliding), else return False.

Examples

a = Rectangle(10, 20, 100, 20)
b = Rectangle(10, 40, 15, 20)
c = Rectangle(50, 50, 20, 30)

intersecting(a, b) ➞ True

intersecting(a, c) ➞ False

intersecting(b, c) ➞ True

Notes

    No negative values will be passed.
    If it's a bit confusing, try imagining the rectangle with the given width and height and then place their top-left corner to the given x, y coordinates.

*/

#[derive(Copy, Clone)]
struct Rect {
    x: isize,
    y: isize,
    w: isize,
    h: isize,
}

fn empty(r: Rect) -> bool {
    return r.w <= 0 || r.h <= 0;
}

fn inside(mut a: isize, mut b: isize, c: isize, d: isize) -> bool {
    if c > a {
        a = c;
    }
    if d < b {
        b = d;
    }
    if b < a {
        return false;
    }
    return true;
}

fn intersect(r: Rect, s: Rect) -> bool {
    if empty(r) || empty(s) {
        return false;
    }
    if !inside(r.x, r.x+r.w, s.x, s.x+s.w) {
        return false;
    }
    if !inside(r.y, r.y+r.h, s.y, s.y+s.h) {
        return false;
    }
    return true;
}

fn main() {
    let a = Rect{x: 10, y: 20, w: 100, h: 20};
    let b = Rect{x: 10, y: 40, w: 15, h: 20};
    let c = Rect{x: 50, y: 50, w: 20, h: 30};
    let d = Rect{x: 90, y: 25, w: 100, h: 5};

    assert_eq!(intersect(a, b), true);
    assert_eq!(intersect(a, c), false);
    assert_eq!(intersect(b, c), false);
    assert_eq!(intersect(a, d), true);
    assert_eq!(intersect(c, d), false);
    assert_eq!(intersect(b, d), false);
}
