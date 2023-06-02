project(ItemTests)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

# ADD_EXECUTABLE(testItem
#     tests/testItem.cpp
#     src/item.cpp
#     src/task.cpp
#     src/course.cpp
#     src/event.cpp
# )

# ADD_EXECUTABLE(testCourse
#     tests/testCourse.cpp
#     src/course.cpp
#     src/item.cpp
# )

# TARGET_LINK_LIBRARIES(testCourse gtest)
# TARGET_COMPILE_DEFINITIONS(testCourse PRIVATE gtest_disable_pthreads=ON)


# TARGET_LINK_LIBRARIES(testItem gtest)
# TARGET_COMPILE_DEFINITIONS(testItem PRIVATE gtest_disable_pthreads=ON)