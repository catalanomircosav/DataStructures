cmake_minimum_required(VERSION 3.17)

project(DataStructures)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(${PROJECT_NAME}.exe src/main.cpp)

target_include_directories(${PROJECT_NAME}.exe PRIVATE ${CMAKE_SOURCE_DIR}/include)
