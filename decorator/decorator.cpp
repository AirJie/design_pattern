#include "decorator.h"

using namespace std;

int main() {
  DrinkSptr coff_ptr = make_shared<Coffee>(20);
  shared_ptr<Additive> coff_taste = make_shared<Sugar>(3);
  shared_ptr<Additive> coff_cream = make_shared<Cream>(5);
  coff_taste->Taste(coff_ptr);
  coff_taste->MakeDrink();

  std::cout << "make other oder" << std::endl;
  coff_cream->Taste(coff_ptr);
  coff_cream->MakeDrink();
}