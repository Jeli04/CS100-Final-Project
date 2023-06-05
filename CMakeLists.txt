cmake_minimum_required(VERSION 3.2)
project(PrioirtyFlow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/header)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(

  ${CMAKE_SOURCE_DIR}/tests/googletest/include/
)

# add_executable (test
#   tests/toDoListTest.cpp
#   src/item.cpp
# )

add_subdirectory(src)
add_subdirectory(tests)

# TARGET_LINK_LIBRARIES(test gtest)
# TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
