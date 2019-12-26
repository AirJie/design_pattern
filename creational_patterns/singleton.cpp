#include <iostream>

class Singleton {
 public:
  Singleton& operator=(const Singleton&) = delete;
  Singleton(const Singleton&) = delete;
  Singleton& Instance() {
    static Singleton instance;
    return instance;
  }

 private:
  Singleton() {}
};