cmake_minimum_required(VERSION 3.2)

project(homework1 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version ${CMAKE_BINARY_DIR}/test/test_version)
