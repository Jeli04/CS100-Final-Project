add_library(simpleLibrary
toDoList.cpp
day.cpp
item.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})