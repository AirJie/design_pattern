#pragma once
#include <iostream>
#include <memory>
#include <string>

class Drink {
 public:
  Drink(int pay) : pay_(pay) {}
  virtual void MakeDrink() {}
  int GetPrice() const { return pay_; }

 protected:
  int pay_;
};

class Coffee : public Drink {
 public:
  Coffee(int pay) : Drink(pay) { std::cout << "coffee construct\n"; }
  ~Coffee() {}
  //   void Taste(std::shared_ptr<Additive> adive) { adive_sptr_ = adive; }
  void MakeDrink() {
    // adive_sptr_->ShowInfo();
    // pay_ += adive_sptr_->GetPrice();
    std::cout << "make coffee ";
  }
};

class MilkTea : public Drink {
 public:
  MilkTea(int pay) : Drink(pay) {}
  ~MilkTea() {}
  void MakeDrink() { std::cout << "make milktea "; }
};

typedef std::shared_ptr<Drink> DrinkSptr;

class Additive {
 public:
  Additive(int price) : price_(price) {}
  virtual void Taste(DrinkSptr dkptr) {}
  virtual void MakeDrink() {}

 protected:
  int price_;
};

class Sugar : public Additive {
 public:
  Sugar(int price) : Additive(price) {}
  void Taste(DrinkSptr dkptr) { dkptr_ = dkptr; }
  void MakeDrink() {
    dkptr_->MakeDrink();
    std::cout << " with sugar" << std::endl;
    int total = dkptr_->GetPrice() + price_;
    std::cout << "total price is " << total << std::endl;
  }

 private:
  DrinkSptr dkptr_;
};

class Cream : public Additive {
 public:
  Cream(int price) : Additive(price) {}
  void Taste(DrinkSptr dkptr) { dkptr_ = dkptr; }
  void MakeDrink() {
    dkptr_->MakeDrink();
    std::cout << " with cream ";
    HeatTheDrink();
    int total = dkptr_->GetPrice() + price_;
    std::cout << "total price is " << total << std::endl;
  }
  void HeatTheDrink() { std::cout << "heat the drink" << std::endl; }

 private:
  DrinkSptr dkptr_;
};