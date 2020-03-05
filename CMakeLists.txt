cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(ceser)

set(
    sources
    src/ceser.c
)
add_library(ceser SHARED ${sources})
add_library(ceser_static STATIC ${sources})

target_include_directories(ceser PUBLIC include)
target_include_directories(ceser_static PUBLIC include)

add_executable(
    readwrite
    examples/rw.c
)

target_link_libraries(readwrite PUBLIC ceser) 

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
