cmake_minimum_required(VERSION 3.16...3.18)

project(
  cmake-template
  VERSION 0.1.0
  DESCRIPTION "A CMake template project"
  LANGUAGES CXX)

option(BUILD_DOCS "Build documentation for the public api's")
option(BUILD_TESTS "Build unit tests and test runner")

# List warnings and errors to be used by internal targets.
#
# NOTE: Some of these are quite new and might require newer versions of
# compilers then those usually distributed.
set(COMPILER_WARNINGS_AND_ERRORS
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:MSVC>:/w44061>
    $<$<CXX_COMPILER_ID:MSVC>:/w44062>
    $<$<CXX_COMPILER_ID:MSVC>:/w44265>
    $<$<CXX_COMPILER_ID:MSVC>:/w44267>
    $<$<CXX_COMPILER_ID:MSVC>:/permissive->
    $<$<CXX_COMPILER_ID:GNU>:-Wmisleading-indentation>
    $<$<CXX_COMPILER_ID:GNU>:-Wduplicated-cond>
    $<$<CXX_COMPILER_ID:GNU>:-Wduplicated-branches>
    $<$<CXX_COMPILER_ID:GNU>:-Wlogical-op>
    $<$<CXX_COMPILER_ID:GNU>:-Wnull-dereference>
    $<$<CXX_COMPILER_ID:GNU>:-Wuseless-cast>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wdocumentation>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wweak-vtables>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wexit-time-destructors>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wglobal-constructors>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wall>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wextra>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wpedantic>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wshadow>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wnon-virtual-dtor>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Woverloaded-virtual>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wunreachable-code>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wmissing-noreturn>)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Setup compile_commands for clangd
  if(CMAKE_EXPORT_COMPILE_COMMANDS)
    execute_process(
      COMMAND
        ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json)
  endif()

  # Build tests only if configured to
  if(BUILD_TESTS OR BUILD_TESTING)
    add_subdirectory(tests)
  endif()

  # Build docs only if configured to
  if(BUILD_DOCS)
    add_subdirectory(docs)
  endif()
endif()

add_subdirectory(src)
add_subdirectory(apps)
