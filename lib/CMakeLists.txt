cmake_minimum_required(VERSION 3.2)

project(Library)

#configure_file(version.h.in version.h)

add_library(homework1_lib lib.cpp lib.h)

set_target_properties(
    homework1_lib PROPERTIES  
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    homework1_lib
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/../src
)

if (MSVC)
    target_compile_options(homework1_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(homework1_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


