#include "facade.h"
int main() {
  Shopping shp;
  std::cout << "shopping online";
  shp.SubmitOrderRequest();
  while (!shp.OrderTracking())
    ;
}