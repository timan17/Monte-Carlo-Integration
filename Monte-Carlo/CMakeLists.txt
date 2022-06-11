cmake_minimum_required(VERSION 3.10.0)
add_executable(Monte-Carlo-test Monte-Carlo.hpp test.cpp)
target_link_libraries(Monte-Carlo-test PUBLIC doctest default)
add_test(NAME Monte-Carlo-test COMMAND Monte-Carlo-test --force-colors -d)
add_custom_target(cloud-test COMMAND Monte-Carlo-test --force-colors -d)

add_executable(Monte-Carlo Monte-Carlo.hpp main.cpp)
target_link_libraries(Monte-Carlo PUBLIC default)