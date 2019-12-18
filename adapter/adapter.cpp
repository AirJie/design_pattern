#include "adapter.h"

int main() {
  Rectangle *rectangle = new PositionRectangle(1, 1, 4, 5);
  rectangle->Draw();
}
