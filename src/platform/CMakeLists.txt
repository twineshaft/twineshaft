######
## libplatform.a
######
include(CheckIncludeFiles)
include(CheckCSourceCompiles)

# On some platforms, CMake automatically adds some libraries to this by
# default (e.g. Windows) which we don't need, so unset it.
unset(CMAKE_C_STANDARD_LIBRARIES)

set(LPSRC platform)
set(LIBPLATFORM_SRCS
   ${LPSRC}/clock.h
   ${LPSRC}/events.h
   ${LPSRC}/types.h
   ${LPSRC}/gl.h
   ${LPSRC}/glwindow.h
   )
set(LIBPLATFORM_INCLUDE)
set(LIBPLATFORM_LIBS)
set(LIBPLATFORM platform)

check_include_files(stdbool.h HAVE_STDBOOL_H)
check_include_files(stdint.h HAVE_STDINT_H)

if(WIN32)
  set(LIBPLATFORM_SRCS ${LIBPLATFORM_SRCS}
      ${LPSRC}/win32/wglwindow.c
      ${LPSRC}/win32/clock.c
      )
  set(LIBPLATFORM_LIBS ${LIBPLATFORM_LIBS} gdi32 user32)
  add_definitions(-DWIN32_LEAN_AND_MEAN)
  if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:\"mainCRTStartup\"")
  endif(MSVC)
else()
  find_package(X11)
  if(X11_FOUND)
    set(LIBPLATFORM_SRCS ${LIBPLATFORM_SRCS} ${LPSRC}/glx/glxwindow.c)
    set(LIBPLATFORM_INCLUDE ${LIBPLATFORM_INCLUDE} ${X11_INCLUDE_DIR})
    set(LIBPLATFORM_LIBS ${LIBPLATFORM_LIBS} ${X11_X11_LIB})
  else()
    message(FATAL_ERROR No supported windowing system found!)
  endif()

  set(CLOCK_TEST_SRC "#define _XOPEN_SOURCE 500\n#include <time.h>\nmain(){struct timespec a;clock_gettime(CLOCK_MONOTONIC,&a);}")
  check_C_source_compiles("${CLOCK_TEST_SRC}" POSIX_clock_gettime)
  if(NOT POSIX_clock_gettime)
    set(LIBPLATFORM_LIBS ${LIBPLATFORM_LIBS} rt)
    set(CMAKE_REQUIRED_LIBRARIES rt)
    check_C_source_compiles("${CLOCK_TEST_SRC}" POSIX_clock_gettime_IN_rt)
    unset(CMAKE_REQUIRED_LIBRARIES)

    if(NOT POSIX_clock_gettime_IN_rt)
      message(FATAL_ERROR "Your OS does not support clock_gettime! Please implement a clock system.")
    endif()
  endif()
  set(LIBPLATFORM_SRCS ${LIBPLATFORM_SRCS} ${LPSRC}/posix/clock.c)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
add_library(platform STATIC ${LIBPLATFORM_SRCS})
target_link_libraries(platform ${LIBPLATFORM_LIBS})
target_include_directories(platform PRIVATE ${LIBPLATFORM_INCLUDE})
