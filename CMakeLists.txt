cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DataStructures VERSION 0.0.1)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

add_executable(${PROJECT_NAME}.exe src/main.cpp)

target_link_libraries(${PROJECT_NAME}.exe PRIVATE DataStructures)

set_target_properties(${PROJECT_NAME}.exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)