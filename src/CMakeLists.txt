add_library(simpleLibrary
calendar.cpp
course.cpp
courseList.cpp
day.cpp
event.cpp
item.cpp
mainMenu.cpp
task.cpp
toDoList.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})