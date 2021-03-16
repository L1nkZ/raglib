add_library(sanitizers_flags INTERFACE)

# Windows (MSVC)
if(MSVC)
  if(RAGLIB_LSAN OR RAGLIB_TSAN OR RAGLIB_USAN)
    message(FATAL_ERROR "These sanitizers are not supported on this platform")
  endif()
  if(RAGLIB_ASAN)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "Win32")
      target_link_libraries(sanitizers_flags
        INTERFACE
          clang_rt.asan$<$<CONFIG:Debug>:_dbg>-i386
          clang_rt.asan_cxx$<$<CONFIG:Debug>:_dbg>-i386
      )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
      target_link_libraries(sanitizers_flags
        INTERFACE
          clang_rt.asan$<$<CONFIG:Debug>:_dbg>-x86_64
          clang_rt.asan_cxx$<$<CONFIG:Debug>:_dbg>-x86_64
      )
    else()
      message(FATAL_ERROR "These sanitizers are not supported on this platform")
    endif()
    message(STATUS "Address sanitizer enabled")
    target_compile_options(sanitizers_flags INTERFACE -fsanitize=address /Zi)
    target_link_options(sanitizers_flags INTERFACE /debug -incremental:no /FORCE:MULTIPLE)
  endif(RAGLIB_ASAN)
  return()
endif()

# Linux, macOS (GCC, Clang)
if(RAGLIB_ASAN OR RAGLIB_LSAN OR RAGLIB_TSAN OR RAGLIB_USAN)
  target_compile_options(sanitizers_flags INTERFACE -fno-omit-frame-pointer -g -O1)
endif()

if(RAGLIB_ASAN)
  message(STATUS "Address sanitizer enabled")
  target_compile_options(sanitizers_flags INTERFACE -fsanitize=address)
  target_link_options(sanitizers_flags INTERFACE -fsanitize=address)
endif()

if(RAGLIB_LSAN)
  message(STATUS "Leak sanitizer enabled")
  target_compile_options(sanitizers_flags INTERFACE -fsanitize=leak)
  target_link_options(sanitizers_flags INTERFACE -fsanitize=leak)
endif()

if(RAGLIB_TSAN)
  message(STATUS "Thread sanitizer enabled")
  target_compile_options(sanitizers_flags INTERFACE -fsanitize=thread)
  target_link_options(sanitizers_flags INTERFACE -fsanitize=thread)
endif()

if(RAGLIB_USAN)
  message(STATUS "Undefined behavior sanitizer enabled")
  target_compile_options(sanitizers_flags INTERFACE -fsanitize=undefined)
  target_link_options(sanitizers_flags INTERFACE -fsanitize=undefined)
endif()
