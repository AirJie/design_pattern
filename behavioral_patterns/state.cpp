#include <iostream>
#include <string>
using namespace std;

class State {
 public:
  virtual void Answer() = 0;
  virtual void Reject() = 0;
  virtual void Hangup() = 0;
  virtual ~State() {}
};

class PhoneCall {
 public:
  void Answer() { state_->Answer(); }
  void Reject() { state_->Reject(); }
  void Hangup() { state_->Hangup(); }
  void SetState(State* st) { state_ = st; }

 private:
  State* state_;
};

class Standby : public State {
 public:
  void Answer() { cout << "ready to answer the call" << endl; }
  void Reject() { cout << "refuse to call" << endl; }
  void Hangup() { cout << "phone is on standby cann't hangup" << endl; }
};

class Calling : public State {
 public:
  void Answer() { cout << "sorry the number you dialed is busy now" << endl; }
  void Reject() { cout << "phone is on calling can not reject" << endl; }
  void Hangup() { cout << "phone ready to hangup to end the call"; }
};

class AirPlane : public State {
 public:
  void Answer() { cout << "The number you dialed has no signal" << endl; }
  void Reject() { cout << "The number you dialed has no signal" << endl; }
  void Hangup() { cout << "The number you dialed has no signal" << endl; }
};

int main() {
  State* stby = new Standby();
  State* calling = new Calling();
  State* air = new AirPlane();

  PhoneCall pca;
  pca.SetState(stby);
  pca.Answer();
  pca.Hangup();

  pca.SetState(calling);
  pca.Answer();
  pca.Hangup();

  pca.SetState(air);
  pca.Answer();
  pca.Hangup();
  delete stby, calling, air;
  return 1;
}