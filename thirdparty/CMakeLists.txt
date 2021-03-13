# kaitai struct
set(KAITAI_HEADERS
  "kaitai_struct_cpp_stl_runtime/kaitai/kaitaistream.h"
  "kaitai_struct_cpp_stl_runtime/kaitai/kaitaistruct.h"
)
set(KAITAI_SOURCES
  "kaitai_struct_cpp_stl_runtime/kaitai/kaitaistream.cpp"
)
add_library(kaitai_struct STATIC ${KAITAI_HEADERS} ${KAITAI_SOURCES})
target_include_directories(kaitai_struct SYSTEM PUBLIC "kaitai_struct_cpp_stl_runtime")
set_target_properties(kaitai_struct PROPERTIES
  PUBLIC_HEADER
    "kaitai_struct_cpp_stl_runtime/kaitai/kaitaistream.h;kaitai_struct_cpp_stl_runtime/kaitai/kaitaistruct.h"
)
target_compile_definitions(kaitai_struct PRIVATE -DKS_STR_ENCODING_NONE)
set_target_properties(kaitai_struct
  PROPERTIES
    FOLDER thirdparty
)

# googletest
if(RAGLIB_BUILD_TESTS)
  if(RAGLIB_FORCE_SHARED_CRT)
    set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
  endif()
  set(INSTALL_GTEST OFF CACHE BOOL "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" FORCE)
  add_subdirectory("googletest" EXCLUDE_FROM_ALL)
  set_target_properties(gmock_main
    PROPERTIES
      FOLDER thirdparty
  )
endif()