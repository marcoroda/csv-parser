cmake_minimum_required(VERSION 3.5)
project(csv-parser)


add_subdirectory(matplotplusplus)

add_library(csv_parser_lib
        STATIC
        src/CSVParser.cpp)
target_include_directories(csv_parser_lib
        PUBLIC
        include)
target_compile_features(csv_parser_lib PUBLIC cxx_std_17)
target_compile_options(csv_parser_lib PUBLIC -g --coverage)
target_link_libraries(csv_parser_lib
        PUBLIC
        matplot)

add_executable(csv_parser main.cpp)
target_link_libraries(csv_parser
        PUBLIC
        csv_parser_lib
        gcov)