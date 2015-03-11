######
## Platform-specific global scope stuff.
######

# On some platforms, CMake automatically adds some libraries to this by
# default (e.g. Windows) which we don't need, so unset it.
unset(CMAKE_C_STANDARD_LIBRARIES)

if(WIN32)
  add_definitions(-DWIN32_LEAN_AND_MEAN)
  if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:\"mainCRTStartup\"")
  endif(MSVC)
endif()
