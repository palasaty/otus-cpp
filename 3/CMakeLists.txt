cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(allocator VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

#add_library(alloclib allocator.cc)
add_executable(allocator main.cc)

set_target_properties(allocator PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(allocator PRIVATE
    -Wall -Wextra -pedantic -Werror -ggdb
)

#target_link_libraries(allocator alloclib)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)
FetchContent_MakeAvailable(googletest)

install(TARGETS allocator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT aakiba@ya.ru)
include(CPack)

enable_testing()

add_executable(
  alloctest
  test.cc
)
target_link_libraries(
  alloctest
  #alloclib
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(alloctest)
