#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Subject {
 public:
  virtual void Request() {}
};

class RealSubject : public Subject {
 public:
  void Request() { cout << "realize the request" << endl; }
};

class Proxy : public Subject {
 public:
  Proxy(shared_ptr<RealSubject> realptr) : realptr_(realptr) {}

  void Request() {
    cout << "proxy ";
    realptr_->Request();
  }

 private:
  std::shared_ptr<RealSubject> realptr_;
};

int main() {
  Proxy proxy(make_shared<RealSubject>());
  proxy.Request();
}