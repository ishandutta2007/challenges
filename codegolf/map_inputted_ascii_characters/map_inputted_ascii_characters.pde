/*

Be sure to see the other challenge, Reverse ASCII character map!

The ASCII charset (American Standard Code for Information Interchange) is the most widely-used character encoding standard. ASCII codes represent text in computers, telecommunications equipment, and other devices.

Challenge
Your challenge is to print a mapping of the ASCII character set as the user inputs them. GIF:

After the user enters every ASCII character, the output should look like this:

table

Mapping
Each character has an assigned position on a 16x6 logical grid, starting with the space character in the top left position, and wrapping such that the digit 0 appears below it.

When printable ASCII input is received, print that ASCII character at its assigned screen location without deleting any of the characters currently onscreen.

Rules

Your program only needs to map out the printable ASCII characters, 0x20 to 0x7E.
Your program must not terminate and continue to map characters to the screen until all printable ASCII characters have been inputted. From here, your program can either terminate or run off into Neverland.
Your program can map characters any way you like, e.g. to a spreadsheet, table, console window, or a graphical window.
No matter how you display the mapping, it must be updated in realtime (as soon as it receives user input).
If your program does not read input silently, it must put the cursor out of the way, so the text won't get in the way of the map.

Help
Here is the pseudocode algorithm I used to generate the GIF:

loop forever
    c = input
    y_coord = c / 16
    x_coord = c - y * 16
    if c is printable
        print c at (x_coord * 2 + 1, y_coord + 1)
    end if
end loop
There may be another way to achieve the required output. You can choose to use my algorithm or your own, but the output must be the same regardless.

Here's a useful ASCII table reference.

Scoring

The answer with the least bytes in each language wins. Have fun!

*/

boolean[] chars;
int fontsize;

void setup() {
  fontsize = 16;
  chars = new boolean[128];

  size(256, 128);
  textSize(fontsize);
}

void draw() {
  background(0);

  stroke(255);
  int x = 0;
  int y = 0;
  int c = 0;
  for (int i = 32; i < 128; i++) {
    if (chars[i]) {
      String txt = String.format("%c", i);
      float dx = (fontsize - textWidth(txt)) / 2;
      text(txt, x + dx, y + fontsize);
    }
    
    if ((c&15) == 15) {
      x = 0;
      y += fontsize;
      c = 0;
    } else {
      x += fontsize;
      c += 1;
    }
  }
}

void keyPressed() {
  if (keyCode == BACKSPACE || keyCode == ENTER) {
    for (int i = 0; i < chars.length; i++)
      chars[i] = (keyCode == BACKSPACE) ? false : true;
  } else if (key <= chars.length)
    chars[key] = true;
  else if (keyCode == ' ')
    chars[' '] = true;
}
