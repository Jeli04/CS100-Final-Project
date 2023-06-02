cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")

add_subdirectory(googletest)

add_executable(TaskTests
    ../tests/testTask.cpp
    ../src/item.cpp
    ../src/task.cpp
)

target_link_libraries(TaskTests gmock gtest gtest_main)
target_link_libraries(TaskTests simpleLibrary)
