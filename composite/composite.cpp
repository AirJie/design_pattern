#include "composite.h"

using namespace std;

int main() {
  Company::ShareCpmyPtr cp_root = make_shared<ConcreteCompany>("Alibaba");
  Company::ShareCpmyPtr finance = make_shared<FinanceDepartment>("Alibaba finance depatrment");
  Company::ShareCpmyPtr personnel = make_shared<PersonnelDepartment>("Alibaba personnel department");
  cp_root->AddOffice(finance);
  cp_root->AddOffice(personnel);
  Company::ShareCpmyPtr branch = make_shared<ConcreteCompany>("Ant");
  Company::ShareCpmyPtr branch_finc = make_shared<FinanceDepartment>("Ant finance depatrment");
  Company::ShareCpmyPtr branch_personnel = make_shared<PersonnelDepartment>("Ant personnel department");
  cp_root->AddOffice(branch);
  cp_root->AddOffice(branch_finc);
  cp_root->AddOffice(branch_personnel);
  std::cout << "show company struct" << std::endl;
  cp_root->ShowOffice();
}