#include "builder.h"

using namespace std;

int main() {
  AudiBuilder *audi = new AudiBuilder();
  Assember assember(audi);
  cout << "builder pattern" << endl;
  return 1;
}