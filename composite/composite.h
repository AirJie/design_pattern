#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Company {
 public:
  typedef std::shared_ptr<Company> ShareCpmyPtr;

  Company() {}
  Company(const std::string name) : name_(name) {}
  ~Company() {}
  virtual void AddOffice(ShareCpmyPtr cp) {}
  virtual void ShowOffice() {
    std::cout << "office name:" << name_ << std::endl;
  };

 protected:
  std::string name_;
};

class ConcreteCompany : public Company {
 public:
  ConcreteCompany(std::string name) : Company(name) {}
  ~ConcreteCompany() { std::cout << "destruct ConcreteCompany" << std::endl; }
  void AddOffice(ShareCpmyPtr cp) {
    std::cout << "add office" << std::endl;
    vecomp_.push_back(cp);
  }
  void ShowOffice() {
    for (auto x : vecomp_) x->ShowOffice();
    std::cout << "top 1 company:" << name_ << std::endl;
  }

 private:
  std::vector<ShareCpmyPtr> vecomp_;
};

class FinanceDepartment : public Company {
 public:
  FinanceDepartment(const std::string name) : Company(name) {
    std::cout << "create finance department" << std::endl;
  }
  ~FinanceDepartment() { std::cout << "destruct finance" << std::endl; }
};

class PersonnelDepartment : public Company {
 public:
  PersonnelDepartment(const std::string name) : Company(name) {
    std::cout << "create finance department" << std::endl;
  }
  ~PersonnelDepartment() { std::cout << "destruct personnel" << std::endl; }
};