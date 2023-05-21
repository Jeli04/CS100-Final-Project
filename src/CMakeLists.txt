add_library(simpleLibrary
    display.cc
)

add_executable(runDisplay
    display.cc
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})