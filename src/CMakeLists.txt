file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

if (SOURCES)
    add_library(DataStructures ${SOURCES})
endif()
