#include <sstream>


#ifndef CPPETUDE_YEAR_H
#define CPPETUDE_YEAR_H


class Year {
  int year{};

  public:

  Year();
  explicit Year(int _year);

  virtual ~Year();

  std::string print () const {
    std::ostringstream s;
    s << "Year(year=" << std::to_string(year) << ")" << std::endl;
    return s.str();
  }

  int getCentury ();
};


#endif //CPPETUDE_YEAR_H
