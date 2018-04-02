#include <set>
#include <string>


class CondenseStrings {
  std::string str_1, str_2;

public:
  CondenseStrings() = default;
  CondenseStrings(std::string str_1, std::string str_2) :
      str_1(std::move(str_1)), str_2(std::move(str_2)) {}
  virtual ~CondenseStrings() = default;

  std::string combine () {
    std::string comb = str_1 + str_2;
    std::set<char> s(comb.begin(), comb.end());
    return std::string(s.begin(), s.end());
  }

};
