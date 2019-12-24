#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Iterator {
 public:
  virtual string First() = 0;
  virtual string Next() = 0;
  virtual bool IsDone() = 0;
  virtual int GetCurrent() = 0;
  virtual ~Iterator() {}
};

class Aggregate {
 public:
  virtual shared_ptr<Iterator> CreateIterator() = 0;
  virtual string PopBack(int) = 0;
  virtual bool IsEnd(int) = 0;
  virtual ~Aggregate() {}
};

class ConcreteIterator : public Iterator {
 public:
  ConcreteIterator(Aggregate* agte) : agte_(agte), index_(0) {
    cout << "ctor Concreteiterator" << endl;
  }
  string First() { return agte_->PopBack(0); }
  string Next() { return agte_->PopBack(index_++); }
  bool IsDone() { return agte_->IsEnd(index_); }
  int GetCurrent() { return index_; }

 private:
  Aggregate* agte_;
  int index_;
};

class ConcreteAggreaget : public Aggregate {
 public:
  ConcreteAggreaget() {
    mapstr_[0] = "Monday";
    mapstr_[1] = "Tuesday";
    mapstr_[2] = "Wednesday";
    mapstr_[3] = "Thursday";
    mapstr_[4] = "Friday";
    mapstr_[5] = "Saturday";
    mapstr_[6] = "Sunday";
    iter_ = nullptr;
  }
  virtual ~ConcreteAggreaget() {}
  shared_ptr<Iterator> CreateIterator() {
    if (iter_ == nullptr) {
      iter_ = make_shared<ConcreteIterator>(this);
    }
    return iter_;
  }
  string PopBack(int num) {
    string str = mapstr_[num % mapstr_.size()];
    return str;
  }
  bool IsEnd(int num) { return num >= mapstr_.size(); }

 private:
  map<int, string> mapstr_;
  vector<string> vecname_;
  shared_ptr<Iterator> iter_;
};

int main() {
  cout << "iterator pattern cpp" << endl;
  shared_ptr<ConcreteAggreaget> agte = make_shared<ConcreteAggreaget>();
  shared_ptr<Iterator> itor = agte->CreateIterator();
  cout << "first:" << itor->First();
  while (!itor->IsDone()) {
    cout << itor->Next() << endl;
  }
  cout << endl;
}