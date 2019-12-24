#include <iostream>
#include <memory>

typedef std::string string;

class Product {
 public:
  Product(){};
  virtual ~Product(){};
};

class ProductNike : public Product {
 public:
  ProductNike() { std::cout << "Nike" << std::endl; }
  ~ProductNike() { std::cout << "destruct Nike" << std::endl; }
};

class ProductAnta : public Product {
 public:
  ProductAnta() { std::cout << "Anta" << std::endl; }
  ~ProductAnta() { std::cout << "Anta destruct" << std::endl; }
};

class Factory {
 public:
  virtual ~Factory() { std::cout << "destruct factory" << std::endl; }
  virtual std::shared_ptr<Product> CreateProduct() = 0;

 protected:
  Factory() { std::cout << "instruct Factory" << std::endl; }
};

class ShoesFactory : public Factory {
 public:
  ShoesFactory() { std::cout << "build shoes Factory" << std::endl; }
  std::shared_ptr<Product> CreateProduct() {
    std::cout << "this factory create product:";
    std::shared_ptr<Product> prod = std::make_shared<ProductNike>();
    return prod;
  }
  ~ShoesFactory() { std::cout << "shoes factory desctruct" << std::endl; }
};

class ClothesFactory : public Factory {
 public:
  ClothesFactory() { std::cout << "build clothes Factory" << std::endl; };
  std::shared_ptr<Product> CreateProduct() {
    std::cout << " this factory create product:";
    std::shared_ptr<Product> prod = std::make_shared<ProductAnta>();
    return prod;
  }
  ~ClothesFactory() { std::cout << "clothes desctruct" << std::endl; };
};

int main(int args, char** argv) {
  ShoesFactory sfac;
  std::shared_ptr<Product> prt = sfac.CreateProduct();
}