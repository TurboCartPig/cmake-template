find_package(Catch2 REQUIRED)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/*/*.test.cpp")

add_executable(tests tests.cpp ${SOURCE_FILES})
target_compile_options(tests PRIVATE ${COMPILER_WARNINGS_AND_ERRORS})
target_link_libraries(tests PRIVATE cmake-template Catch2::Catch2)
