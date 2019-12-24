#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cook {
 public:
  void Chicken() { cout << "cook a spicy chicken" << endl; }
  void Beef() { cout << "cook a beef" << endl; }
  void Fish() { cout << "cook a fish"; }
};

class OrderCommand {
 public:
  OrderCommand() {}
  OrderCommand(Cook* cook) : cook_(cook) {}
  virtual void CookFood() = 0;
  virtual string OrderInfo() = 0;

 protected:
  Cook* cook_;
};

class OrderChicken : public OrderCommand {
 public:
  OrderChicken(Cook* cook) : OrderCommand(cook) {}
  void CookFood() { cook_->Chicken(); }
  string OrderInfo() { return "food: chicken price:30￥"; }
};

class OrderBeef : public OrderCommand {
 public:
  OrderBeef(Cook* cook) : OrderCommand(cook) {}
  void CookFood() { cook_->Beef(); }
  string OrderInfo() { return "food:beef price:50￥"; }
};


class OrderFish : public OrderCommand {
 public:
  OrderFish(Cook* cook) : OrderCommand(cook) {}
  void CookFood() { cook_->Fish(); }
  string OrderInfo() { return "food:fish price:20￥"; }
};

class Waiter {
 public:
  void Book(OrderCommand* orcmd) { vecmd_.push_back(orcmd); }
  void Notify() {
    for (auto x : vecmd_) {
      cout << x->OrderInfo();
      x->CookFood();
    }
  }

 private:
  vector<OrderCommand*> vecmd_;
};

int main() {
  Waiter waiter;
  Cook* cookptr = new Cook();
  OrderChicken* chicken = new OrderChicken(cookptr);
  OrderBeef* beef = new OrderBeef(cookptr);
  waiter.Book(chicken);
  waiter.Book(beef);
  waiter.Notify();
}
