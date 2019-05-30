cmake_minimum_required(VERSION 2.8.12)
 
project(PPolygon)
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++14" CACHE STRING "compile flags" FORCE)
 
file(GLOB EXEMPLO_SRC_FILES "*.cpp")
file(GLOB EXEMPLO_HDR_FILES "*.hpp")
 
add_executable(sizedStack ${EXEMPLO_SRC_FILES} ${EXEMPLO_HDR_FILES})
