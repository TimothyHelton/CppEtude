#include <string>


//! Class for counting digits.
class CountDigits {

public:
  std::string digits{};
  int digit{}, num{};

  //! Default constructor
  CountDigits() = default;
  //! Convenience constructor
  //! \param _digit: digit of interest to be counted
  //! \param _num: maximum number in range beginning at zero to define digits
  CountDigits(int _num, int _digit) : num(_num), digit(_digit) {}
  virtual ~CountDigits() = default;

  long count_digits() {
    for (int i = 0; i <= num; ++i) {
      digits += std::to_string(i * i);
    }
    return std::count(digits.begin(), digits.end(), std::to_string(digit)[0]);
  }
};
