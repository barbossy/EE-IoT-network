cmake_minimum_required(VERSION 3.5)
project(EE-IoT-network-tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET (UNIT_TESTS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (UNIT_TESTS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set (TOP_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")

include(${TOP_SRC_DIR}/conan.cmake)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE ./../EE-IoT-network/EE-IoT-network/unit_test/
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


set(UNIT_TESTS_SOURCES
    ${UNIT_TESTS_SRC_DIR}/ut_main.cpp
    ${UNIT_TESTS_SRC_DIR}/end_user_tests.cpp
    ${UNIT_TESTS_INCLUDE_DIR}/end_user_mock.h)

set (SOURCES_TO_TEST
    ${TOP_SRC_DIR}/include/end_user.h
    ${TOP_SRC_DIR}/src/end_user.cpp
    )

add_executable(EE-IoT-network-tests ${UNIT_TESTS_SOURCES} ${SOURCES_TO_TEST})
target_link_libraries(EE-IoT-network-tests ${CONAN_LIBS})

include_directories(${TOP_SRC_DIR}/include)
include_directories(include)
