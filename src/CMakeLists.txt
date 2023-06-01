add_library(simpleLibrary
    mainMenu.cpp
)

add_executable(PriorityFlow
    mainMenu.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})