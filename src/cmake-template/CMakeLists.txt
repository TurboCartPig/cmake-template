file(GLOB HEADER_FILES CONFIGURE_DEPENDS
     "${PROJECT_SOURCE_DIR}/include/cmake-template/*.h")
file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(cmake-template ${SOURCE_FILES} ${HEADER_FILES})
target_compile_options(cmake-template PRIVATE ${COMPILER_WARNINGS_AND_ERRORS})
target_include_directories(
  cmake-template
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
          "${PROJECT_SOURCE_DIR}/include/cmake-template"
  PUBLIC "${PROJECT_SOURCE_DIR}/include")

set_target_properties(
  cmake-template
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)
