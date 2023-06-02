project(ItemTests)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(testTask
    tests/testTask.cpp
    src/task.cpp
    src/item.cpp
)

TARGET_LINK_LIBRARIES(testTask gtest)
TARGET_COMPILE_DEFINITIONS(testTask PRIVATE gtest_disable_pthreads=ON)