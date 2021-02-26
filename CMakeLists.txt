cmake_minimum_required(VERSION 3.15)
project(csv-parser)

find_package(GTest REQUIRED)

add_library(csv_parser_lib
        STATIC
        src/CSVParser.cpp )
target_include_directories(csv_parser_lib
        PUBLIC
        include)
target_compile_features(csv_parser_lib PUBLIC cxx_std_17)
target_compile_options(csv_parser_lib PUBLIC -g --coverage)

add_executable(csv_parser main.cpp)
target_link_libraries(csv_parser
        PUBLIC
        csv_parser_lib
        gcov)

# Unit Testing
enable_testing()
add_executable(unit_tests tests/unit_tests.cpp)
target_include_directories(unit_tests PUBLIC tests)
target_compile_options(unit_tests PRIVATE -g)
target_link_libraries(
        unit_tests
        PUBLIC
        csv_parser_lib
        GTest::gtest
        gcov)
add_test(test_all unit_tests --gtest_output=xml:gtest_report.xml)
