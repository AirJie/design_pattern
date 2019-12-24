#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

typedef std::string string;

class Product {
 public:
  Product(){};
  ~Product(){};
  void ProductWheel(const string& name) {
    std::cout << "product " << name << " wheel\n";
  }
  void ProductEngine(const string& name) {
    std::cout << "product " << name << " engine\n";
  }
  void ProductDoor(const string& name) {
    std::cout << "product " << name << " door\n";
  }
};
class Builder {
 public:
  Builder() {}
  ~Builder() {}
  virtual void InstallWheel() = 0;
  virtual void InstallEngine() = 0;
  virtual void InstallDoor() = 0;

 private:
  Product* pdt_;
};

class BmwBuilder : public Builder {
 public:
  BmwBuilder() { pdt_ = std::make_shared<Product>(); }
  ~BmwBuilder() {}
  virtual void InstallWheel() {
    std::cout << name_;
    pdt_->ProductWheel(name_);
  }
  virtual void InstallEngine() {
    std::cout << name_;
    pdt_->ProductEngine(name_);
  }
  virtual void InstallDoor() {
    std::cout << name_;
    pdt_->ProductDoor(name_);
  }

 private:
  std::shared_ptr<Product> pdt_;
  const string name_ = "bmw";
};

class AudiBuilder : public Builder {
 public:
  AudiBuilder() { pdt_ = std::make_shared<Product>(); }
  ~AudiBuilder() {}
  virtual void InstallWheel() { pdt_->ProductWheel(name_); }
  virtual void InstallEngine() { pdt_->ProductEngine(name_); }
  virtual void InstallDoor() { pdt_->ProductDoor(name_); }

 private:
  std::shared_ptr<Product> pdt_;
  const string name_ = "audio";
};

class Assember {
 public:
  Assember(Builder* bdr) {
    bdr->InstallDoor();
    bdr->InstallWheel();
    bdr->InstallEngine();
  }
};

using namespace std;

int main() {
  AudiBuilder *audi = new AudiBuilder();
  Assember assember(audi);
  cout << "builder pattern" << endl;
  return 1;
}