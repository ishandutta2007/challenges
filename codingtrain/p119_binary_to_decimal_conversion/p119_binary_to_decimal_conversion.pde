// Interactive binary to decimal number converter.

Bits bits;

void setup() {
  size(1024, 768);
  reset();
}

void reset() {
  bits = new Bits((long)random(255), 8);
}

void draw() {
  background(90, 100, 110);
  bits.draw();
}

void keyPressed() {
  bits.keyPressed();
}

void mousePressed() {
  bits.mousePressed();
}

long clamp(long x, long a, long b) {
  if (x < a)
    x = a;
  else if (x > b)
    x = b;
  return x;
}

boolean inCircle(PVector c, PVector p) {
  float dx = p.x - c.x;
  float dy = p.y - c.y;
  float r = c.z;
  return dx*dx + dy*dy < r*r;
}

class Bits {
  long value;
  long size;
  
  boolean mousepress;
  PVector mousepos;
  
  Bits(long value, long size) {
    this.value = value;
    this.size = size;

    mousepress = false;
    mousepos = new PVector();
  }
  
  void keyPressed() {
    if (keyCode == RIGHT)
      size++;
    else if (keyCode == LEFT)
      size--;
    size = clamp(size, 1, 63);
    
    long limit = (1L<<size) - 1;
    if (keyCode == UP)
      value = (value < limit) ? value+1 : value;
    else if (keyCode == DOWN)
      value = (value > 0) ? value-1 : 0;
    
    if (key == ' ')
      value = 0;
    else if (key == ENTER)
      value |= ~0L;

    value &= limit;
  }
  
  void mousePressed() {
    mousepress = mousePressed && mouseButton == LEFT;
    mousepos.set(mouseX, mouseY);
  }
  
  void draw() {
    drawDots();
    drawText();
  }
  
  void drawDots() {
    push();
    strokeWeight(2);
    
    long d = 32;
    long p = d + d/2;
    long s = d + p;
    long w = width / (s/2);

    long y = 0;
    long b = size;
    long m = 1;

    long t = value;
    while (b > 0) {
      long xo = (long) min(b, w);
      for (long x = 0; x < w; x++) {
        long px = (width - s*(xo/2 -x)) / 2;
        long py = height/2 + y*s;
        
        if ((value & m) != 0)
          fill(60, 70, 80);
        else
          fill(255);
        
        PVector c = new PVector(px, py, d/2);
        if (mousepress && inCircle(c, mousepos)) {
          t ^= m;
          mousepress = false;
        }
        
        circle(px, py, d);

        m <<= 1;
        if (--b < 1)
          break;
      }
      y++;
    }
    value = t;
    
    pop();
  }
  
  void drawText() {
    push();
    
    textAlign(CENTER);
    textSize(32);

    long s = 50;
    long x = width/2;
    long y = height/2 - s;
    text(String.format("Value: %d | %X", value, value), x, y);
    text(String.format("Size:  %d", size), x, y-s);
    
    pop();
  }
}
