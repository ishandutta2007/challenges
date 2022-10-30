/*

Your challenge is to create a clock that displays the time as a hex number, and the background color as the hex color code of the time.

Requirements: No input. In the center of your output you should display the number sign and the current time in 24 hour format as "#hhmmss".
The program should update to the current time at least once every second.
The text must be centered and white (or a light color that stands out).
The background should be entirely the color of the hex code. Shortest code wins, but creative answers are encouraged.

Live example. Idea from r/InternetIsBeautiful.
http://www.jacopocolo.com/hexclock/

*/

void setup() {
  size(640, 480);
  textSize(32);
}

void draw() {
  int r = hour();
  int g = minute();
  int b = second();
  background(r, g, b);
  
  fill(230, 230, 230);
  textAlign(CENTER);
  text(String.format("#%02X%02X%02X", r, g, b), width/2, height/2);
}
