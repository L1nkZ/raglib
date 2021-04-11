cmake_minimum_required(VERSION 3.13)

project(raglib LANGUAGES CXX VERSION 0.1.0)

option(RAGLIB_BUILD_TESTS "Build unit tests" OFF)
option(RAGLIB_FORCE_SHARED_CRT "Force linking the CRT as shared" OFF)
# Sanitizers
option(RAGLIB_ASAN "Enable address sanitizer" OFF)
option(RAGLIB_LSAN "Enable leak sanitizer" OFF)
option(RAGLIB_TSAN "Enable thread sanitizer" OFF)
option(RAGLIB_USAN "Enable undefined behavior sanitizer" OFF)
option(RAGLIB_FUZZING "Build fuzzers" OFF)

list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_CURRENT_LIST_DIR}/cmake"
)
include(RaglibHelpers)
include(Sanitizers)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC AND NOT RAGLIB_FORCE_SHARED_CRT)
  add_compile_options(/MT$<$<CONFIG:Debug>:d>)
endif()

link_libraries(sanitizers_flags)

set(RAGLIB_BUILD_INCLUDE_DIRS
  "${CMAKE_CURRENT_LIST_DIR}/include"
)

if(RAGLIB_BUILD_TESTS)
  message(STATUS "Building unit tests")
  enable_testing()
endif()

add_library(raglib
  STATIC
    "src/rsm.cc"
    "src/gnd.cc"
)
target_include_directories(raglib SYSTEM INTERFACE
  "$<BUILD_INTERFACE:${RAGLIB_BUILD_INCLUDE_DIRS}>"
)
target_link_libraries(raglib PUBLIC kaitai_struct)
target_include_directories(raglib PRIVATE ${RAGLIB_BUILD_INCLUDE_DIRS})
add_library(raglib::raglib ALIAS raglib)

add_subdirectory("thirdparty")

# Unit tests
add_cc_test(
  NAME
    rsm_test
  SRCS
   "src/rsm_test.cc"
  DEPS
    raglib::raglib
    gmock_main
)

# Fuzzers
add_cc_fuzzer(
  NAME
    rsm_fuzzer
  SRCS
   "src/rsm_fuzzer.cc"
  DEPS
    raglib::raglib
)

add_cc_fuzzer(
  NAME
    gnd_fuzzer
  SRCS
   "src/gnd_fuzzer.cc"
  DEPS
    raglib::raglib
)
