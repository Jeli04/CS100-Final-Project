add_library(simpleLibrary
    item.cpp
    course.cpp
    event.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})