#include <iostream>
#include <string>

using namespace std;

class Mediator;

class Person {
 public:
  void SetMediator(Mediator *mediator) { mediator_ = mediator; }
  virtual void PublishMessage(string msg) = 0;
  virtual void RecvMessage(string msg) = 0;
  virtual ~Person() {}

 protected:
  Mediator *mediator_;
};

class Renter : public Person {
 public:
  void RecvMessage(string msg) {
    cout << "renter receive message from mediator:" << msg << endl;
  }
  void PublishMessage(string msg);
};

class Landlord : public Person {
 public:
  void RecvMessage(string msg) {
    cout << "landlord receive message from mediator:" << msg << endl;
  }
  void PublishMessage(string msg);
};

class Mediator {
 public:
  virtual void RelayedMessage(string msg, Person *person) = 0;
};

class HourseMedia : public Mediator {
 public:
  HourseMedia(Renter *rter, Landlord *lord) : rter_(rter), lord_(lord) {}
  void RelayedMessage(string msg, Person *person) {
    if (person == rter_) {
      lord_->RecvMessage(msg);
    } else if (person == lord_) {
      rter_->RecvMessage(msg);
    } else {
      cout << "get invalid message" << endl;
    }
  }

 private:
  Renter *rter_;
  Landlord *lord_;
};

void Renter::PublishMessage(string msg) {
  if (mediator_ != nullptr) mediator_->RelayedMessage(msg, this);
}
void Landlord::PublishMessage(string msg) {
  if (mediator_ != nullptr) mediator_->RelayedMessage(msg, this);
}

int main() {
  Landlord *lord = new Landlord();
  Renter *rter = new Renter();
  Mediator *mediator = new HourseMedia(rter, lord);
  lord->SetMediator(mediator);
  rter->SetMediator(mediator);
  lord->PublishMessage("two bedrooms and one living room is for renting");
  rter->PublishMessage("i want to rent");
  delete lord;
  delete rter;
  delete mediator;
}