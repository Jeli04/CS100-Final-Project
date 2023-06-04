cmake_minimum_required(VERSION 3.2)
project(PrioirtyFlow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

<<<<<<< HEAD
ADD_EXECUTABLE(testTask
    tests/testTask.cpp
    src/task.cpp
    src/item.cpp
)

TARGET_LINK_LIBRARIES(testTask gtest)
TARGET_COMPILE_DEFINITIONS(testTask PRIVATE gtest_disable_pthreads=ON)
=======
include_directories(${CMAKE_SOURCE_DIR}/header)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(
  ${CMAKE_SOURCE_DIR}/tests/lib/googletest/include/
)

add_subdirectory(src)
add_subdirectory(tests)


>>>>>>> john/riri
