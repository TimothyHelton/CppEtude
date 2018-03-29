#include <string>
#include "gtest/gtest.h"
#include "dna.cpp"

using ::testing::TestParamInfo;
using ::testing::TestWithParam;
using ::testing::tuple;
using ComplementParams = tuple<std::string, std::string>;


class TestComplement : public TestWithParam<ComplementParams> {

public:
  static std::string suffix(const TestParamInfo<ComplementParams> &info) {
    return std::get<0>(info.param);
  }

protected:
  std::string expected;
  DNA *test_dna{};

  virtual void SetUp() {
    std::string test_string;
    std::tie(test_string, expected) = GetParam();
    test_dna = new DNA(test_string);
  }

  virtual void TearDown() {
    delete test_dna;
    test_dna = nullptr;
  }
};

TEST_P(TestComplement, complement_if) {
  test_dna->complement_if();
  EXPECT_EQ(expected, test_dna->get_dna());
}

TEST_P(TestComplement, complement_map) {
  test_dna->complement_map();
  EXPECT_EQ(expected, test_dna->get_dna());
}

TEST_P(TestComplement, complement_switch) {
  test_dna->complement_switch();
  EXPECT_EQ(expected, test_dna->get_dna());
}

TEST_P(TestComplement, complement_array) {
  test_dna->complement_array();
  EXPECT_EQ(expected, test_dna->get_dna());
}

INSTANTIATE_TEST_CASE_P(Parameters, TestComplement,
                        testing::Values(
                            ComplementParams("AAAA", "TTTT"),
                            ComplementParams("ATTGC", "TAACG"),
                            ComplementParams("GTAT", "CATA")
                        ),
                        // The next line will add the suffix to each test name
//                        TestComplement::suffix
);