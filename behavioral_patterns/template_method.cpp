#include <iostream>
#include <string>

using namespace std;

class Worker {
 public:
  void WorlerDaily() {
    cout << "worker daily router:";
    Getup();
    Breakfast();
    GotoWork();
    Working();
    GetoffWork();
    cout << endl;
  }

  void Getup() { cout << "1.getup" << endl; }
  void Breakfast() { cout << "2.have breakfast" << endl; }
  virtual void GotoWork() = 0;
  virtual void Working() = 0;
  void GetoffWork() { cout << "5.get off work" << endl; }
};

class Doctor : public Worker {
 public:
  void GotoWork() { cout << "doctor go to work by car" << endl; }
  virtual void Working() { cout << "doctor operate on patient" << endl; }
};

class Teacher : public Worker {
 public:
  void GotoWork() { cout << "teacher to got by bike" << endl; }
  void Working() { cout << "teacher is lecturing" << endl; }
};

int main() {
  Worker *wk = new Doctor();
  wk->WorlerDaily();
  Worker *wk2 = new Teacher();
  wk2->WorlerDaily();
}