# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.19.0)

# GLOBAL MBED-OS PATH
if(DEFINED ENV{MBED_OS_LIB_PATH})
    set(MBED_PATH $ENV{MBED_OS_LIB_PATH} CACHE INTERNAL "")
else()
    set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")
endif()

set(MBED_CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "")
set(APP_TARGET firmware)

include(${MBED_PATH}/tools/cmake/app.cmake)

add_subdirectory(lib/Foo) # Foo library
list(APPEND CUSTOM_LIBS foo)

add_subdirectory(TARGET_CORE2) # custom target CORE2 board

add_subdirectory(${MBED_PATH} ${CMAKE_CURRENT_BINARY_DIR}/mbed-os)

add_executable(${APP_TARGET}
    src/main.cpp
)

project(${APP_TARGET})

target_link_libraries(${APP_TARGET} 
    mbed-os
    ${CUSTOM_LIBS}
)

mbed_set_post_build(${APP_TARGET})

option(VERBOSE_BUILD "Have a verbose build process")
if(VERBOSE_BUILD)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()