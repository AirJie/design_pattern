#include <iostream>
#include <string>
#include <sys/time.h>
#include <thread>
#include <chrono>

class Order {
 public:
  void SubmitOrderRequest() { state_ = 0; }
  bool OrderTracking() {
    std::cout << str_state[state_ % 4] << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    return (kComplete == state_++) ? true : false;
  }

 private:
  enum OrderState { kReceived, kBook, kPaid, kComplete };
  const std::string str_state[4] = {"order receiverd", "order book",
                                    "order paid", "order complete"};

  int state_;
};

class Vendor {
 public:
  void SubmitOrderRequest() { state_ = 0; }
  bool OrderTracking() {
    std::cout << "Vendor state " << str_state_[state_ % 5] << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    return (kComplete == state_++) ? true : false;
  }

 private:
  enum VendorState { kReceived, kVerify, kPrepare, kPackage, kComplete };
  const std::string str_state_[5] = {"Received", "Verify", "Prepare", "Package",
                                     "Complete"};
  int state_;
};

class Courier {
 public:
  void SubmitOrderRequest() { state_ = 0; }
  bool OrderTracking() {
    std::cout << "courier state " << str_state_[state_ % 5] << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    return (kComplete == state_++) ? true : false;
  }

 private:
  enum CourierState {
    kReceived,
    kSorting,
    kVerifyAddress,
    kDeliver,
    kComplete
  };
  const std::string str_state_[5] = {"Received", "Sorting", "VerifyAddress",
                                     "Deliver", "Complete"};
  int state_;
};

class Shopping {
 public:
  void SubmitOrderRequest() { state_ = kUnStarted; 
    order_.SubmitOrderRequest();
    vendor_.SubmitOrderRequest();
    courier_.SubmitOrderRequest();
  }
  bool OrderTracking() {
    if (kUnStarted == state_) {
      std::cout << "step---1" << std::endl;
      state_++;
    } else if (kOrder == state_) {
      std::cout << "next step---2" << std::endl;
      if (order_.OrderTracking()) state_++;
    } else if (kVendor == state_) {
      std::cout << "next step---3" << std::endl;
      if (vendor_.OrderTracking()) state_++;
    } else if (kCourier == state_) {
      std::cout << "next step---4" << std::endl;
      if (courier_.OrderTracking()) state_++;
    } else {
      std::cout << "shopping order complete" << std::endl;
      return true;
    }
    return false;
  }

 private:
  enum ShoppingState { kUnStarted, kOrder, kVendor, kCourier, kComplete };
  int state_;
  Order order_;
  Vendor vendor_;
  Courier courier_;
};

int main() {
  Shopping shp;
  std::cout << "shopping online";
  shp.SubmitOrderRequest();
  while (!shp.OrderTracking())
    ;
}