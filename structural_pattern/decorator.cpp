#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Drink {
 public:
  virtual void MakeDrink() {}
};

typedef std::shared_ptr<Drink> DrinkSptr;

class Coffee : public Drink {
 public:
  Coffee() { std::cout << "coffee construct\n"; }
  ~Coffee() {}
  void MakeDrink() { std::cout << "make coffee " << std::endl; }
};

class MilkTea : public Drink {
 public:
  MilkTea() {}
  ~MilkTea() {}
  void MakeDrink() { std::cout << "make milktea "; }
};

class Additive : public Drink {
 public:
  Additive(DrinkSptr dkptr) : dkptr_(dkptr) {}
  // virtual void Taste(DrinkSptr dkptr) {}
  void MakeDrink() {
    if (dkptr_ != nullptr) {
      dkptr_->MakeDrink();
      cout << "additive:";
    }
  }

 private:
  DrinkSptr dkptr_;

 protected:
  int price_;
};

class Sugar : public Additive {
 public:
  Sugar(DrinkSptr dkptr) : Additive(dkptr) {}
  // void Taste(DrinkSptr dkptr) { dkptr_ = dkptr; }
  void MakeDrink() {
    Additive::MakeDrink();
    std::cout << "add sugar" << std::endl;
  }
};

class Cream : public Additive {
 public:
  Cream(DrinkSptr dkptr) : Additive(dkptr) {}
  void MakeDrink() {
    Additive::MakeDrink();
    std::cout << "add cream ";
    HeatTheDrink();
  }
  void HeatTheDrink() { std::cout << "and heat the drink" << std::endl; }
};

using namespace std;

int main() {
  DrinkSptr coff = make_shared<Sugar>(make_shared<Coffee>());
  coff->MakeDrink();
  std::cout << "make other oder" << std::endl;
  DrinkSptr latte = make_shared<Cream>(make_shared<Coffee>());
  latte->MakeDrink();
  std::cout << "done" << std::endl;
}