cmake_minimum_required(VERSION 3.6)
project(Embedded_Systems_1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp includes/OptParser.h src/OptParser.cpp)
add_executable(Embedded_Systems_1 ${SOURCE_FILES} includes/OptParser.h)