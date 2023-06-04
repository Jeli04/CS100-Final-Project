cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")

add_subdirectory(googletest)

add_executable(Tests
    ../src/item.cpp
    ../src/course.cpp
    ../src/task.cpp
    ../tests/testDisplayEvents.cpp
    ../tests/testCourse.cpp
    ../tests/testEvent.cpp
    ../tests/testDisplayCourse.cpp
    ../tests/testDisplayTasks.cpp
)

target_link_libraries(Tests gmock gtest gtest_main)
target_link_libraries(Tests simpleLibrary)