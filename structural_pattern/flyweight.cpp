#include <cstdlib>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#define AWESOME_MAKE_ENUM(name, ...)                              \
  enum class name { __VA_ARGS__, __COUNT };                       \
  inline std::ostream& operator<<(std::ostream& os, name value) { \
    std::string enumName = #name;                                 \
    std::string str = #__VA_ARGS__;                               \
    int len = str.length();                                       \
    std::vector<std::string> strings;                             \
    std::ostringstream temp;                                      \
    for (int i = 0; i < len; i++) {                               \
      if (isspace(str[i]))                                        \
        continue;                                                 \
      else if (str[i] == ',') {                                   \
        strings.push_back(temp.str());                            \
        temp.str(std::string());                                  \
      } else                                                      \
        temp << str[i];                                           \
    }                                                             \
    strings.push_back(temp.str());                                \
    os << enumName << "::" << strings[static_cast<int>(value)];   \
    return os;                                                    \
  }

AWESOME_MAKE_ENUM(Bark, kSmooth, kRough, kWither);
AWESOME_MAKE_ENUM(Leaves, kStraight, kBend);
AWESOME_MAKE_ENUM(Colors, kBlack, kGray, kGreen);

class Forest {};

class TreeModle {
 protected:
  Bark bark_;
  Leaves leaves_;
  Colors color_;

 public:
  static TreeModle& GetInstance(Bark bk, Leaves ls, Colors cs) {
    static TreeModle treemodle(bk, ls, cs);
    return treemodle;
  }

  void RenderTree() {
    std::cout << "Render a tree with" << bark_ << " " << leaves_ << std::endl;
  }

 private:
  TreeModle(Bark bk, Leaves ls, Colors cs)
      : bark_(bk), leaves_(ls), color_(cs) {
    std::cout << "render tree with "
              << " " << bark_ << " " << leaves_ << std::endl;
  };
  std::mutex mutex_;
};

class Tree {
 public:
  Tree(double posx, double posy, int high, Bark bk, Leaves ls, Colors cs)
      : high_(high),
        posx_(posx),
        posy_(posy),
        trem_(TreeModle::GetInstance(bk, ls, cs)) {
    std::cout << "high" << high_ << " in " << posx_ << "," << posy_
              << std::endl;
    trem_.RenderTree();
  }

 private:
  TreeModle& trem_;
  int high_;
  double posx_, posy_;
};

int main() {
  const int TreeNumbers = 100;
  int high = 0;
  Tree* forest[TreeNumbers];

  std::cout << "run ";
  for (int x = 0; x < TreeNumbers; ++x) {
    high = rand() % 1000;
    forest[x] =
        new Tree(x, x, high, Bark::kSmooth, Leaves::kBend, Colors::kGreen);
  }
}
