#include <iostream>
#include <map>
#include <string>
#include <memory>

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


using namespace std;

int main() {
    Resume* resume = new ResumeA("google", "2015-2017");
    resume->ShowResume();

    cout << "copy :" << endl;
    Resume* resume_copy = resume->Clone("baidu", "2017-2019");
    resume->ShowResume();
    resume_copy->ShowResume();
    delete resume_copy;
    delete resume;
    resume = nullptr;
    resume_copy = nullptr;
}