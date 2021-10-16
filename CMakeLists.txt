cmake_minimum_required(VERSION 3.0.0)
project(countingsort VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(countingsort countingsort.cpp)

add_executable(
  countingsort_test
  countingsort_test.cpp
)
target_link_libraries(
  countingsort_test
  countingsort
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(countingsort_test)
