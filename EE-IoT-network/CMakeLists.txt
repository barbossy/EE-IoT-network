cmake_minimum_required(VERSION 3.5)
project(EE-IoT-network LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(conan.cmake)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE ./../EE-IoT-network/EE-IoT-network/
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

SET(SRC_DIR src)
SET(INCLUDE_DIR include)


SET(SOURCES
    ${INCLUDE_DIR}/cell.h
#    ${INCLUDE_DIR}/interference.h
    ${INCLUDE_DIR}/defines.h
    ${INCLUDE_DIR}/end_user.h
    ${INCLUDE_DIR}/link.h
    ${INCLUDE_DIR}/network.h
    ${INCLUDE_DIR}/rayleigh_channel.h
    ${SRC_DIR}/cell.cpp
#    ${SRC_DIR}/interference.cpp
    ${SRC_DIR}/end_user.cpp
    ${SRC_DIR}/link.cpp
    ${SRC_DIR}/network.cpp
    ${SRC_DIR}/rayleigh_channel.cpp
    )

add_executable(EE-IoT-network src/main.cpp ${SOURCES})
target_link_libraries(EE-IoT-network ${CONAN_LIBS})
include_directories(include)
