// Render digits of pi as colors to a PDF file

import processing.pdf.*;

void setup() {
  size(1000, 1000, PDF, "bookofpi-10million-text.pdf");
  String[] lines = loadStrings("pi-10million.txt");
  if (lines == null || lines.length == 0)
    println("Invalid pi file!");
  else
    gen((PGraphicsPDF) g, lines[0], 100, 100);
  exit();
}

void gen(PGraphicsPDF pdf, String pi, int rows, int cols) {  
  int pages = pi.length() / (rows*cols);
  int index = 0;

  float w = float(width) / cols;
  float h = float(height) / rows;
  
  push();
  colorMode(HSB, 1.0);
  println("Total Pages: " + pages);
  for (int i = 0; i < pages; i++) {
    for (float y = 0; y < height; y += h) {
      for (float x = 0; x < width; x += w) {
        int digit = pi.charAt(index) - '0';

        fill(digit/10.0, 1, 1);
        noStroke();
        rect(x, y, w, h);
        
        if (++index >= pi.length())
          index = pi.length() - 1;
      }
    }
    println("Page " + i + " complete!");
    pdf.nextPage();
  }
  println("Finished");
  pop();
}
