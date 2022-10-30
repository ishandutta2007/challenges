/*

For this challenge, you must accept input as a comma-separated list (columns) of a run (rows) of the first letters of any of the colors red, orange, yellow, green, blue, or purple, and output (to stdout) the HTML for a table of those colors.

This is fairly hard to understand, so I'll just give a simple example.

Input:

rgb,gbr,grb
Output (with example screenshot):

<html>
  <head>
  </head>
  <body>
    <table>
      <tbody>
        <tr>
          <td style="background-color: red" width="50" height="50"></td>
          <td style="background-color: green" width="50" height="50"></td>
          <td style="background-color: blue" width="50" height="50"></td>
        </tr>
        <tr>
          <td style="background-color: green" width="50" height="50"></td>
          <td style="background-color: blue" width="50" height="50"></td>
          <td style="background-color: red" width="50" height="50"></td>
        </tr>
        <tr>
          <td style="background-color: green" width="50" height="50"></td>
          <td style="background-color: red" width="50" height="50"></td>
          <td style="background-color: blue" width="50" height="50"></td>
        </tr>
      </tbody>
    </table>
  </body>
</html>
image

Note that the HTML you output need not be valid; it just has to work. By "work", I mean that your output will be pasted into a .html file and viewed in the latest (currently, 9/28/13) Chrome (v 29.0.1547.76).
The squares must be 50 pixels width and height. You may have whatever padding between them as you want (Chrome automatically uses 1 pixel of padding, even when you specify padding: 0px, so I can't control that).

Input will always be valid (letters will be one of roygbp), but the rows are not guaranteed to have equal amounts of squares in them. For example, roygbp,ooo is valid and should output

image 2

This is code-golf, shortest code wins.

*/

fn main() {
    table("rgb,gbr,grb");
    table("roygbp,ooo");
}

fn table(s: &str) {
    let mut p = Printer::new();
    p.enter("html");
    p.enter("head");
    p.leave("head");
    p.enter("body");
    p.enter("table");
    p.enter("tbody");
    p.enter("tr");
    for c in s.chars() {
        if c == ',' {
            p.leave("tr");
            p.enter("tr");
        } else {
            p.td(c);
        }
    }
    p.leave("tr");
    p.leave("tbody");
    p.leave("table");
    p.leave("body");
    p.leave("html");
    println!("");
}

struct Printer {
    level: isize,
}

impl Printer {
    fn new() -> Printer {
        Printer { level: 0 }
    }

    fn indent(&self) {
        for _ in 0..self.level * 2 {
            print!(" ");
        }
    }

    fn enter(&mut self, tag: &str) {
        self.indent();
        println!("<{}>", tag);
        self.level += 1;
    }

    fn leave(&mut self, tag: &str) {
        self.level -= 1;
        self.indent();
        println!("</{}>", tag);
    }

    fn td(&self, code: char) {
        let background = match code {
            'r' => "red",
            'g' => "green",
            'b' => "blue",
            'o' => "orange",
            'y' => "yellow",
            'p' => "purple",
            _ => "white",
        };

        self.indent();
        println!(
            "<td style=\"background-color: {}\" width=\"50\", height=\"50\"></td>",
            background
        );
    }
}
