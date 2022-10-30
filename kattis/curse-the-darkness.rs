/*

You are trying to read in a dark room. The room contains many candles, but none are lit.
You are considering that it might be worthwhile to light one, but before you do you want to be certain that it will actually light your book.
You only get to light one and each is bright enough to cast light in a radius of 8 meters.
You are a stubborn reader and you are not willing to move your book or one of the candles.

Input

Input begins with an integer 0≤m≤50, giving the number of test cases that follow.
A test case begins with the real-valued X,Y location of your book.
This is followed by an integer 0≤n≤1000, giving the number of candles in the room and the real-valued X,Y locations of each candle.
All locations are measured in meters. All real values in the input are in the range −1000 to 1000 and have at most 7 digits past the decimal point.

Output

For each test case, output “light a candle” if there is a candle close enough to cast light on the position of your book. Otherwise, output “curse the darkness”.

*/

struct Point {
    x: f64,
    y: f64,
}

fn main() {
    assert_eq!(castable(&Point{x: 10.0, y: 10.0}, &vec![Point{x: 15.0, y: 15.0}]), "light a candle");
    assert_eq!(castable(&Point{x: 10.0, y: 10.0}, &vec![Point{x: 20.5, y: 15.0}, Point{x: 10.0, y: 20.5}]), "curse the darkness");
}

fn castable(p: &Point, a: &Vec<Point>) -> &'static str {
    for q in a {
        if distance(p, q) <= 8.0 {
            return "light a candle";
        }
    }
    return "curse the darkness";
}

fn distance(p: &Point, q: &Point) -> f64 {
    let dx = p.x - q.x;
    let dy = p.y - q.y;
    return f64::sqrt(dx*dx + dy*dy);
}
