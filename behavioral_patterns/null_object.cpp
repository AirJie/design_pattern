#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
class Book {
 public:
  virtual bool IsNull() = 0;
  virtual int GetBookID() = 0;
  virtual void ShowBookInfo() = 0;
  virtual ~Book() {}
};

class NullBook : public Book {
 public:
  bool IsNull() { return true; }
  int GetBookID() { return -1; }
  void ShowBookInfo() {}
};

class ConcreteBook : public Book {
 public:
  ConcreteBook(int id, string name, string author)
      : id_(id), name_(name), author_(author) {}
  bool IsNull() { return false; }
  int GetBookID() { return id_; }
  void ShowBookInfo() {
    cout << "book name:" << name_ << " author:" << author_ << endl;
  }

 private:
  int id_;
  string name_;
  string author_;
};
class Library {
 public:
  void InsertLib(shared_ptr<ConcreteBook> book) { vecbook_.push_back(book); }
  shared_ptr<Book> Search(int id) {
    for (auto x : vecbook_)
      if (id == x->GetBookID()) return x;
    shared_ptr<Book> bk = make_shared<NullBook>();
    return bk;
  }

 private:
  vector<shared_ptr<ConcreteBook>> vecbook_;
};

int main() {
  Library libbook;
  shared_ptr<ConcreteBook> cbook =
      make_shared<ConcreteBook>(1, "c++ primer", "Lippman");
  shared_ptr<ConcreteBook> cbook2 =
      make_shared<ConcreteBook>(2, "Design Pattern", "Erich Gamma");
  shared_ptr<ConcreteBook> cbook3 =
      make_shared<ConcreteBook>(3, "Effective c++", "Scott Meyers");
  libbook.InsertLib(cbook);
  libbook.InsertLib(cbook2);
  libbook.InsertLib(cbook3);

  shared_ptr<Book> findbook = libbook.Search(2);
  findbook->ShowBookInfo();

  findbook = libbook.Search(5);
}