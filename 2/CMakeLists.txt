cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ipfilter VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

add_library(ip ip.cc)
add_executable(ipfilter main.cc)

set_target_properties(ipfilter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(ipfilter PRIVATE
    -Wall -Wextra -pedantic -Werror
)

target_link_libraries(ipfilter ip)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)
FetchContent_MakeAvailable(googletest)

install(TARGETS ipfilter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT aakiba@ya.ru)
include(CPack)

enable_testing()

add_executable(
  iptest
  test.cc
)
target_link_libraries(
  iptest
  ip
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(iptest)
