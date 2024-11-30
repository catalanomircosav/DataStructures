cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(DataStructures VERSION 0.0.1)

add_subdirectory(src)

target_include_directories(DataStructures PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Aggiungi l'eseguibile
add_executable(${PROJECT_NAME}.exe src/main.cpp)

# Linka la libreria all'eseguibile
target_link_libraries(${PROJECT_NAME}.exe PRIVATE DataStructures)

# Imposta il percorso dell'eseguibile
set_target_properties(${PROJECT_NAME}.exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)