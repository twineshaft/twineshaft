############
### Project Setup
############
cmake_minimum_required(VERSION 2.8)
project(twineshaft C)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

include(../build/cmake/FindC99.cmake)
set(CMAKE_C_FLAGS ${C99_CFLAGS})

find_package(OpenGL REQUIRED)
include(platform/CMakeLists.txt)
include_directories(${OPENGL_INCLUDE_DIR})

######
## tests
######
add_subdirectory(../tests ${CMAKE_CURRENT_BINARY_DIR}/tests/)

######
## twineshaft
######
set(SRCS
   main.c
   twineshaft.c
   twineshaft.h
   render/render.h
   render/gl/glrender.c
   util/ascii.h
   util/geometry.h
   )
add_executable(twineshaft ${SRCS})
target_link_libraries(twineshaft platform ${OPENGL_gl_LIBRARY})
