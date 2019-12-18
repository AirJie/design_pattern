#include "factory.h"

int main(int args, char** argv) {
  ShoesFactory sfac;
  std::shared_ptr<Product> prt = sfac.CreateProduct();
}