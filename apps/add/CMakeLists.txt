add_executable(add add.cpp)
target_compile_options(add PRIVATE ${COMPILER_WARNINGS_AND_ERRORS})
target_link_libraries(add PRIVATE cmake-template)
set_target_properties(
  add
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)
