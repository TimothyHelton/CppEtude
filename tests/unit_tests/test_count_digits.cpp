#include <iostream>
#include "gtest/gtest.h"
#include "count_digits.cpp"

using ::testing::TestParamInfo;
using ::testing::TestWithParam;
using ::testing::tuple;
using CountParams = tuple<int, int, int>;


class TestCountDigits : public TestWithParam<CountParams> {

public:
  static std::string suffix(const TestParamInfo<CountParams> &info) {
    std::stringstream name;
    name << "num_" << std::to_string(std::get<0>(info.param))
         << "___digit_" << std::to_string(std::get<1>(info.param));
    return name.str();
  }

protected:
  int expected{}, test_digits{}, test_num{};
  CountDigits *test_num_digits{};

  virtual void SetUp() {
    std::tie(test_num, test_digits, expected) = GetParam();
    test_num_digits = new CountDigits(test_num, test_digits);
  }

  virtual void TearDown() {
    delete test_num_digits;
    test_num_digits = nullptr;
  }
};

TEST_P(TestCountDigits, ) {
  EXPECT_EQ(expected, test_num_digits->count_digits());
}

INSTANTIATE_TEST_CASE_P(Parameters, TestCountDigits,
                        testing::Values(
                            CountParams(10, 1, 4),
                            CountParams(5750, 0, 4700),
                            CountParams(11011, 2, 9481),
                            CountParams(12224, 8, 7733),
                            CountParams(0, 0, 1)
                        ),
                        TestCountDigits::suffix
);