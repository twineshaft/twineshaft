######
## libtest.a
######
add_library(testutils STATIC EXCLUDE_FROM_ALL testutils.c testutils.h)
target_link_libraries(testutils platform)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

######
## libplatform tests
######
add_executable(platform_test EXCLUDE_FROM_ALL
  platform_test/test_clock.c
  platform_test/test_types.c
  platform_test/main.c
  )
target_link_libraries(platform_test testutils)

add_custom_target(check COMMAND platform_test)
add_dependencies(check platform_test)
