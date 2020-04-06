cmake_minimum_required(VERSION 3.2)

project(homework1 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

add_executable(homework1_cli main.cpp)

set_target_properties(
    homework1_cli PROPERTIES  
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    homework1_cli
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(
    homework1_cli
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

target_link_libraries(
    homework1_cli PRIVATE
    homework1_lib
)

if (MSVC)
    target_compile_options(homework1_cli PRIVATE
        /W4
    )
else ()
    target_compile_options(homework1_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS homework1_cli RUNTIME DESTINATION bin)




