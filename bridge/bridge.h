#pragma once
#include <iostream>
#include <string>

class Scheduler {
 public:
  Scheduler() {}
  ~Scheduler() {}
  virtual void Execute() {}
};

class TimerScheduler : public Scheduler {
 public:
  TimerScheduler() {}
  virtual void Execute() {
    std::cout << "execute timer scheduler" << std::endl;
  }
};

class DisplayScheduler : public Scheduler {
 public:
  DisplayScheduler() {}
  virtual void Execute() {
    std::cout << "execute display scheduler" << std::endl;
  }
};

class System {
 public:
  System() {}
  System(Scheduler* imp) {}
  virtual void Execute() { }
};

class LinuxSystem : public System {
 public:
  LinuxSystem(Scheduler* imp) : imp_(imp) {
    std::cout << "linux system" << std::endl;
  }
  virtual void Execute() { imp_->Execute(); }

 private:
  Scheduler* imp_;
};

class WindowsSystem : public System {
 public:
  WindowsSystem(Scheduler* imp) : imp_(imp) {
    std::cout << "windows system" << std::endl;
  }
  virtual void Execute() { imp_->Execute(); }

 private:
  Scheduler* imp_;
};
