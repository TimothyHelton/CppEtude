#include "year.h"


Year::Year() = default;

Year::Year(int _year) : year(_year) {}

Year::~Year() = default;

int Year::getCentury() {
  return (year + 99) / 100;
}
