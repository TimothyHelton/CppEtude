#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "combine_strings.cpp"

using ::testing::TestParamInfo;
using ::testing::TestWithParam;
using ::testing::tuple;
using TestParams = tuple<std::string, std::string, std::string>;


class TestCondenseStrings : public TestWithParam<TestParams> {

protected:
  std::string expected, test_str_1, test_str_2;
  CondenseStrings *test_inst{};

  virtual void SetUp() {
    std::tie(test_str_1, test_str_2, expected) = GetParam();
    test_inst = new CondenseStrings(test_str_1, test_str_2);
  }

  virtual void TearDown() {
    delete test_inst;
    test_inst = nullptr;
  }
};

TEST_P(TestCondenseStrings, combine) {
  ASSERT_EQ(expected, test_inst->combine());
}

INSTANTIATE_TEST_CASE_P(Parameters, TestCondenseStrings,
                        testing::Values(
                            TestParams ("abc", "abc", "abc"),
                            TestParams ("xzy", "abc", "abcxyz"),
                            TestParams ("hhiijj", "ddeeff", "defhij")
                        ),
);