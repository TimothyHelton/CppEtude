include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Unit_Tests_run
    test_combine_strings.cpp
    test_count_digits.cpp
    test_dna.cpp
    test_example.cpp
)

target_link_libraries(Unit_Tests_run gtest gtest_main)
target_link_libraries(Unit_Tests_run ${CMAKE_PROJECT_NAME}_lib)