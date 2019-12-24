#include <iostream>
#include <string>

class Rectangle {
 public:
  Rectangle() {}
  virtual ~Rectangle() {}
  virtual void Draw() = 0;
};

class WidthRectangle {
 public:
  WidthRectangle(int x, int y, int width, int high) {
    xa_ = x, ya_ = y;
    xb_ = x + width, yb_ = y;
    xc_ = x + width, yc_ = y + high;
    xd_ = x, yd_ = y + high;
    std::cout << "rectangle with width & high" << std::endl;
  }
  void WidthDraw() { std::cout << "draw rectangle" << std::endl; }

 private:
  int xa_, ya_;
  int xb_, yb_;
  int xc_, yc_;
  int xd_, yd_;
};

class PositionRectangle : public Rectangle, private WidthRectangle {
 public:
  PositionRectangle(int x1, int y1, int x2, int y2)
      : WidthRectangle(x1, y1, x2 - x1, y2 - y1) {
    std::cout << "rectangle with position" << std::endl;
  }
  virtual void Draw() { WidthDraw(); }
};

int main() {
  Rectangle *rectangle = new PositionRectangle(1, 1, 4, 5);
  rectangle->Draw();
}
