# Helper function taken from abseil-cpp's AbseilHelpers.cmake
function(add_cc_test)
  if(NOT RAGLIB_BUILD_TESTS)
    return()
  endif()

  cmake_parse_arguments(ADD_CC_TEST
    ""
    "NAME"
    "SRCS;COPTS;DEFINES;LINKOPTS;DEPS"
    ${ARGN}
  )

  set(_NAME "raglib_${ADD_CC_TEST_NAME}")

  add_executable(${_NAME} "")
  target_sources(${_NAME} PRIVATE ${ADD_CC_TEST_SRCS})
  target_include_directories(${_NAME}
    PRIVATE ${GMOCK_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS}
  )

  target_compile_definitions(${_NAME}
    PUBLIC
    RAGLIB_TEST_DATA_PATH="${CMAKE_SOURCE_DIR}/tests/rag_test_data"
    ${ADD_CC_TEST_DEFINES}
  )
  target_compile_options(${_NAME}
    PRIVATE ${ADD_CC_TEST_COPTS}
  )

  target_link_libraries(${_NAME}
    PUBLIC ${ADD_CC_TEST_DEPS}
    PRIVATE
      ${ADD_CC_TEST_LINKOPTS}
  )
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 17)

  # Add all targets to a folder in the IDE for organization.
  set_property(TARGET ${_NAME} PROPERTY FOLDER tests)

  add_test(NAME ${_NAME} COMMAND ${_NAME})
endfunction()