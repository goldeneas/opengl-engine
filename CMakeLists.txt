cmake_minimum_required(VERSION 3.0.0)
project(Yellow-Engine VERSION 0.1.0)

include(CTest)
enable_testing()

# Custom Paths
set(RELATIVE_SRC_PATH src)
set(RELATIVE_HEADER_PATH src/header)
set(RELATIVE_INCLUDE_PATH src/include)

set(OPENGL_INCLUDE_PATH C:/OpenGL/include)
set(OPENGL_LIB_PATH C:/OpenGL/lib)

# Add include paths from relative folders (inside the project)
file(GLOB SOURCES
    ${RELATIVE_HEADER_PATH}/*.h
    ${RELATIVE_SRC_PATH}/*.cpp
    ${RELATIVE_INCLUDE_PATH}/*.c
    ${RELATIVE_INCLUDE_PATH}/*.cpp

    ${RELATIVE_SRC_PATH}/rendering/*.cpp
)

# Include libraries from OpenGL directory
file(GLOB LIBRARIES
    ${OPENGL_LIB_PATH}/*.a
)

# Bind relative include sources to the executable
add_executable(Yellow-Engine ${SOURCES})

# Include files from global OpenGL directory
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_PATH})

# Link libraries from global OpenGL directory
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
