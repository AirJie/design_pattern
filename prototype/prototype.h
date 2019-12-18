#pragma once
#include <iostream>
#include <map>
#include <string>

typedef std::string string;

class WorkExperience {
 public:
  WorkExperience(const char* comp, const char* date) {
    exper[string(date)] = string(comp);
  }
  WorkExperience(const WorkExperience& wexp) { exper = wexp.exper; }
  void AddWorkExperience(const char* comp, const char* date) {
    exper[string(date)] = string(comp);
  }
  void ShowWorkExper() {
    for (auto x : exper) {
      std::cout << x.first << " company:" << x.second << std::endl;
    }
  }

 public:
  std::map<string, string> exper;
};
class Resume {
 public:
  Resume() {}
  virtual ~Resume() {}
  virtual void ShowResume() = 0;
  virtual Resume* Clone() = 0;
  virtual Resume* Clone(const char*, const char*) = 0;
};

class ResumeA : public Resume {
 public:
  ResumeA(const char* comp, const char* date) : wexp_(comp, date) {}
  ResumeA(const ResumeA& resume) : wexp_(resume.wexp_) {}
  ResumeA* Clone() { return new ResumeA(*this); }
  ResumeA* Clone(const char* comp, const char* date) {
    ResumeA* resu = new ResumeA(*this);
    resu->wexp_.AddWorkExperience(comp, date);
    return resu;
  }
  void ShowResume() { wexp_.ShowWorkExper(); }

 private:
  WorkExperience wexp_;
};
