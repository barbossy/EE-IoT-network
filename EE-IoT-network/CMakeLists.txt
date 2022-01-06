cmake_minimum_required(VERSION 3.5)
project(EE-IoT-network LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(conan.cmake)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE ./../EE-IoT-network/EE-IoT-network/
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

SET(SOURCE src)
SET(INCLUDE include)


SET(SOURCES
    ${INCLUDE}/end_user.h
    ${SOURCE}/end_user.cpp
    )

add_executable(EE-IoT-network src/main.cpp ${SOURCES})
target_link_libraries(EE-IoT-network ${CONAN_LIBS})
include_directories(include)
