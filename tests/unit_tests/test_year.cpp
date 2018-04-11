#include <iostream>
#include "gtest/gtest.h"
#include "year.cpp"

using ::testing::TestParamInfo;
using ::testing::TestWithParam;
using ::testing::tuple;
using CenturyParams = tuple<int, int>;


class TestYearGetCentury : public TestWithParam<CenturyParams> {

public:
  static std::string suffix(const TestParamInfo<CenturyParams> &info) {
    std::stringstream name;
    name << "year_" << std::to_string(std::get<0>(info.param))
         << "___century_" << std::to_string(std::get<1>(info.param));
    return name.str();
  }

protected:
  int expected{}, year{};
  Year* test_year{};

  virtual void SetUp() {
    std::tie(year, expected) = GetParam();
    test_year = new Year(year);
  }

  virtual void TearDown() {
    delete test_year;
    test_year = nullptr;
  }
};

TEST_P(TestYearGetCentury, ) {
  EXPECT_EQ(expected, test_year->getCentury());
}

INSTANTIATE_TEST_CASE_P(Parameters, TestYearGetCentury,
                        testing::Values(
                            CenturyParams(1705, 18),
                            CenturyParams(1900, 19),
                            CenturyParams(1601, 17),
                            CenturyParams(2000, 20)
                        ),
                        TestYearGetCentury::suffix
);