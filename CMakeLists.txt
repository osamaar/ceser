cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/ceser/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/ceser/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/ceser/bin)

project(ceser C CXX)

set(
    sources
    src/ceser.c
    src/float_ieee754.c
)

add_library(ceser SHARED ${sources})
target_link_libraries(ceser m)

add_library(ceser_static STATIC ${sources})
target_link_libraries(ceser_static m)

target_include_directories(ceser PUBLIC include)
target_include_directories(ceser_static PUBLIC include)

add_executable(
    readwrite
    examples/rw.c
)

target_link_libraries(readwrite PUBLIC ceser_static)

# Tests
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(third_party/googletest)

enable_testing()
add_executable(
    ceser_test
    tests/ceserTest.cpp
)
target_link_libraries(ceser_test PUBLIC gtest_main)
add_test(
    NAME ceser_test
    COMMAND ceser_test
)


# Apply to a Single Target
# if ( CMAKE_COMPILER_IS_GNUCC )
    # target_compile_options(main PRIVATE "-Wall -Wextra")
# endif()
# if ( MSVC )
    # target_compile_options(main PRIVATE "/W4")
# endif()

# # Apply to All Targets
# if (CMAKE_COMPILER_IS_GNUCC)
#     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# endif()
# if (0)
#     set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
# endif()

# message(${CMAKE_CXX_FLAGS})
