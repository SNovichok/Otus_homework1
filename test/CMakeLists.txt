cmake_minimum_required(VERSION 3.2)

project(Tests)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test_version test_version.cpp)

set_target_properties(
    test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    test_version
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(
    test_version
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

set_target_properties(
    test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(
    test_version
    ${Boost_LIBRARIES}
    homework1_lib
)

if (MSVC)
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS test_version RUNTIME DESTINATION bin)



