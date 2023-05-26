cmake_minimum_required(VERSION 3.20)
project(PriorityFlow)

add_library(simpleLibrary
    item.cpp
)


find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})