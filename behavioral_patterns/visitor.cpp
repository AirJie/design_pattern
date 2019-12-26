#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Visitor;

class Teller {
 public:
  virtual void Accept(Visitor *vtor) = 0;
};

class CardTeller : public Teller {
 public:
  void Accept(Visitor *vtor);
  void OperateCard(string name, string pswd) {
    cout << "create a card, account:" << name << endl;
    cout << "set the password:" << pswd << endl;
  }
};

class LoanTeller : public Teller {
 public:
  void Accept(Visitor *vtor);
  void FinancialLoan(int memory, int date) {
    cout << "financial loan:" << memory << endl;
    cout << "financial date:" << date << endl;
  }
  void MortgageFinance(int memory) {
    cout << "mortgage finance " << memory << endl;
  }
};

class Visitor {
 public:
  virtual void Visit(CardTeller *cter) = 0;
  virtual void Visit(LoanTeller *lter) = 0;
  virtual ~Visitor() {}
};

class PersonVisitor : public Visitor {
 public:
  void Visit(CardTeller *cter) { cter->OperateCard("Jim", "123456"); }
  void Visit(LoanTeller *lter) { lter->FinancialLoan(20000, 4); }
};

class BusinessVisitor : public Visitor {
 public:
  void Visit(CardTeller *cter) {
    cter->OperateCard("Normal card", "##123456");
    cter->OperateCard("platinum card", "##456");
    cter->OperateCard("bussness card", "##456");
  }
  void Visit(LoanTeller *lter) {
    lter->FinancialLoan(8000000, 5);
    lter->MortgageFinance(100000000);
  }
};

class Bank {
 public:
  Bank() {
    vecter_.push_back(make_shared<CardTeller>());
    vecter_.push_back(make_shared<LoanTeller>());
  }
  void VisitTeller(Visitor *vtor) {
    vecter_[0]->Accept(vtor);
    vecter_[1]->Accept(vtor);
  }
  ~Bank() {}

 private:
  vector<shared_ptr<Teller>> vecter_;
};

void CardTeller::Accept(Visitor *vtor) { vtor->Visit(this); }
void LoanTeller::Accept(Visitor *vtor) { vtor->Visit(this); }

int main() {
  Visitor *pervtor = new PersonVisitor();
  Visitor *busnvtor = new BusinessVisitor();
  Bank bank;
  bank.VisitTeller(pervtor);
  bank.VisitTeller(busnvtor);

  delete pervtor, busnvtor;
  return 1;
}