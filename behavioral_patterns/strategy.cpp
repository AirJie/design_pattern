#include <iostream>
#include <list>
#include <memory>
#include <string>

using namespace std;
class Sale {
 public:
  virtual float Calculate(double, int) = 0;
};

class RegularSale : public Sale {
 public:
  float Calculate(double price, int amount) { return price * amount; }
};

class DiscountSale : public Sale {
 public:
  DiscountSale() : count_(1.0) {}
  void SetDiscount(double count) {
    count_ = count;
    cout << "set discount:" << count_ << endl;
  }
  float Calculate(double price, int amount) { return price * amount * count_; }

 private:
  double count_;
};

class FullDiscount : public Sale {
 public:
  FullDiscount(float full, float reduce) : full_(full), reduce_(reduce) {}
  float Calculate(double price, int amount) {
    float total = price * amount;
    total = total - (total / full_) * reduce_;
  }

 private:
  float full_;
  float reduce_;
};

class SaleManager {
 public:
  struct Goods {
    string name;
    float price;
    int amount;
  };
  SaleManager(shared_ptr<Sale> sale) : sale_(sale) {}
  void BuyList(Goods& goods) { buy_.push_back(goods); }
  void SettleAccount() {
    double total = 0;
    for (auto x : buy_) total += sale_->Calculate(x.price, x.amount);
    cout << "----- total " << total << endl;
  }
  void ShowList() {
    cout << "Goods name | price | quanity" << endl;
    for (auto x : buy_) {
      cout << x.name << " |" << x.price << " |" << x.amount << endl;
    }
  }

 private:
  shared_ptr<Sale> sale_;
  list<Goods> buy_;
};

int main() { 
    SaleManager::Goods clothes{"clothes", 200, 4};
    SaleManager::Goods shoe{"shoes", 500, 3};
    SaleManager::Goods water{"water", 1.5, 10};
    SaleManager::Goods fruit{"fruit", 13.5, 29};

    SaleManager *salm = new SaleManager(make_shared<RegularSale>());
    salm->BuyList(clothes);
    salm->BuyList(shoe);
    salm->BuyList(water);
    salm->ShowList();
    salm->SettleAccount();
    delete salm;
    salm = nullptr;

    salm = new SaleManager(make_shared<FullDiscount>(800, 80));
    salm->BuyList(clothes);
    salm->BuyList(shoe);
    salm->BuyList(water);
    salm->ShowList();
    salm->SettleAccount();
    delete salm;
 }