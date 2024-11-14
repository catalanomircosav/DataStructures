cmake_minimum_required(VERSION 3.17)

file(GLOB_RECURSE SOURCES "*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES})