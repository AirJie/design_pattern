#include <iostream>
#include <string>

using namespace std;

class Manager {
 public:
  Manager(Manager *mager, string name) : manager_(mager), name_(name) {}
  virtual void DealWithRequest(int num) = 0;

 protected:
  Manager *manager_;
  string name_;
};

class Common : public Manager {
 public:
  Common(Manager *mager, string title) : Manager(mager, title) {}
  void DealWithRequest(int num) {
    if (num < 1000) {
      cout << "CommonManager " << name_ << "agree the request" << endl;
    } else {
      cout << "CommonManager " << name_ << "have no right to deal" << endl;
      manager_->DealWithRequest(num);
    }
  }
};

class Majordomo : public Manager {
 public:
  Majordomo(Manager *mager, string name) : Manager(mager, name) {}
  void DealWithRequest(int num) {
    if (num < 5000) {
      cout << "Majordomo " << name_ << "agree the request" << endl;
    } else {
      cout << "Majordomo " << name_ << "have no right to deal" << endl;
      manager_->DealWithRequest(num);
    }
  }
};

class GeneralManager : public Manager {
 public:
  GeneralManager(Manager *mager, string name) : Manager(mager, name) {}
  void DealWithRequest(int num) {
    cout << "GeneralManager  " << name_ << "deal with the request" << endl;
  }
};

int main() {
    GeneralManager *genmager = new GeneralManager(NULL, "a");
    Majordomo *majmager = new Majordomo(genmager, "b");
    Common *com = new Common(majmager, "c");
    com->DealWithRequest(20000);
    com->DealWithRequest(2000);
}