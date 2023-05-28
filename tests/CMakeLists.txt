cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")

add_subdirectory(googletest)

add_executable(Tests
  toDoListTest.cpp 
  dayTest.cpp
  calendarTest.cpp
)

target_link_libraries(Tests gmock gtest gtest_main)
target_link_libraries(Tests simpleLibrary)

# Add the following lines to your CMakeLists.txt file

# # Find and include Google Mock
# find_package(GMock REQUIRED)
# include_directories(${GMOCK_INCLUDE_DIRS})

# Link against Google Mock
# target_link_libraries(Tests ${GMOCK_BOTH_LIBRARIES})
