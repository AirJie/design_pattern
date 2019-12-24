#include <string.h>
#include <iostream>
#include <string>

class Thousands;
class Hundreds;
class Tens;
class Ones;

class RNumInterpretern {
 public:
  RNumInterpretern();
  RNumInterpretern(int) {}
  int Interpret(char* input) {
    int total = 0;
    thousands->Interpret(input, total);
    hundreds->Interpret(input, total);
    tens->Interpret(input, total);
    ones->Interpret(input, total);
    if (strcmp(input, "")) return 0;
    return total;
  }
  virtual int Interpret(char* input, int& total) {
    int index = 0;
    if (!strncmp(input, nine(), 2)) {
      total += 9 * multipler();
      index += 2;
    } else if (!strncmp(input, four(), 2)) {
      total += 4 * multipler();
      index += 2;
    } else {
      if (five() == input[0]) {
        total += 5 * multipler();
        index += 1;
      } else {
        index = 0;
      }
      for (int end = index + 3; index < end; index++) {
        if (one() == input[index])
          total += 1 * multipler();
        else
          break;
      }
    }
    strcpy(input, &(input[index]));
  }

 protected:
  virtual const char one() {}
  virtual const char* four() {}
  virtual const char five() {}
  virtual const char* nine() {}
  virtual const int multipler() {}

 private:
  RNumInterpretern* thousands;
  RNumInterpretern* hundreds;
  RNumInterpretern* tens;
  RNumInterpretern* ones;
};

class Thousands : public RNumInterpretern {
 public:
  Thousands(int) : RNumInterpretern(1) {}

 protected:
  const char one() { return 'M'; }
  const char* four() { return (char*)""; }
  const char five() { return '\0'; }
  const char* nine() { return (char*)""; }
  const int multipler() { return 1000; }
};

class Hundreds : public RNumInterpretern {
 public:
  Hundreds(int) : RNumInterpretern(1) {}

 protected:
  const char one() { return 'C'; }
  const char* four() { return "CD"; }
  const char five() { return 'D'; }
  const char* nine() { return (char*)"CM"; }
  const int multipler() { return 100; }
};
class Tens : public RNumInterpretern {
 public:
  Tens(int) : RNumInterpretern(1) {}

 protected:
  const char one() { return 'X'; }
  const char* four() { return (char*)"XL"; }
  const char five() { return 'L'; }
  const char* nine() { return (char*)"XC"; }
  const int multipler() { return 10; }
};

class Ones : public RNumInterpretern {
 public:
  Ones(int) : RNumInterpretern(1) {}

 protected:
  const char one() { return 'I'; }
  const char* four() { return "IV"; }
  const char five() { return 'V'; }
  const char* nine() { return "IX"; }
  const int multipler() { return 1; }
};

RNumInterpretern::RNumInterpretern() {
  thousands = new Thousands(1);
  hundreds = new Hundreds(1);
  tens = new Tens(1);
  ones = new Ones(1);
}

int main() {
  char input[20];
  RNumInterpretern rninter;
  std::cout << "Enter a roman numeral:";
  while (std::cin >> input) {
    std::cout << "interpretation is " << rninter.Interpret(input) << std::endl;
    std::cout << "Enter a roman numeral:";
  }
}