cmake_minimum_required(VERSION 3.26)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
SET(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
SET(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

# Link runTests with what we want to test and the GTest and pthread library
add_library(NextDate NextDate.cpp)
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread NextDate)

#add_library(NextDate NextDate.cpp)
add_executable(NextDateTool shownext.cpp)
target_link_libraries(NextDateTool pthread NextDate)
