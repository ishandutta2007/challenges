import processing.pdf.*;

void render(PGraphicsPDF pdf, PFont font, String text, float w, float h) {
  background(255);
  textFont(font);

  int margin = 100;
  int index = 0;
  int page = 0;

loop:
  while (true) {
    for (float y = margin; y < height-margin; y += h) {
      float x = margin;
      while (x < width-margin-w/2) {
        String s = "" + text.charAt(index);
        fill(0);
        textAlign(CENTER, CENTER);
        text(s, x + w/2, y + h/2);
        x += w;

        if (++index >= text.length())
          break loop;
      }
    }
    page++;
    println("Page " + page + " complete!");
    pdf.nextPage();
  }
  println("Finished");
}

void setup() {
  size(850, 1150, PDF, "book_of_pi_10_million.pdf");
  
  PGraphicsPDF pdf = (PGraphicsPDF) g;
  PFont font = createFont("Courier", 12);
  String text = "3." + loadStrings("pi-10million.txt")[0];
  float textwidth = textWidth("0");
  float textheight = 14.4;
  render(pdf, font, text, textwidth, textheight);

  exit();
}
