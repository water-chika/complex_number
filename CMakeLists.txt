cmake_minimum_required(VERSION 3.20)

project(cpp_project)

add_library(complex_number INTERFACE
    complex_number.hpp
)

target_include_directories(complex_number INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(complex_number INTERFACE cxx_std_23)

add_executable(test_complex_number
    test_complex_number.cpp
)

target_link_libraries(test_complex_number PUBLIC complex_number)
