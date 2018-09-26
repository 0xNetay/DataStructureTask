cmake_minimum_required(VERSION 3.12)
project(PQ)

set(CMAKE_CXX_STANDARD 14)

include_directories(../include)
file(GLOB_RECURSE SRC_FILES ./* ../include/*)

add_executable(PQ ${SRC_FILES} ../include/internal/BTreeNode.h ../include/PriorityList.h ../include/PriorityTree.h)