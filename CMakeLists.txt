cmake_minimum_required(VERSION 3.25)
project(EasyJson)

set(CMAKE_CXX_STANDARD 20)

add_executable(EasyJson test.cpp JSONValue.cpp JSONValue.h JSONParser.cpp)