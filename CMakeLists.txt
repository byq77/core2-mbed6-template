# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.19.0 FATAL_ERROR)

# GLOBAL MBED-OS PATH
if(DEFINED ENV{MBED_OS_LIB_PATH})
    set(MBED_PATH $ENV{MBED_OS_LIB_PATH} CACHE INTERNAL "")
else()
    set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")
endif()

set(MBED_CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "")

include(${MBED_PATH}/tools/cmake/app.cmake)

project(core2-mbed6-template VERSION 1.0.0)

# USER OPTIONS
option(VERBOSE_BUILD "Have a verbose build process")

# SUBDIRECTORIES
add_subdirectory(${MBED_PATH} ${CMAKE_CURRENT_BINARY_DIR}/mbed-os)
add_subdirectory(lib/stm32customtargets) # custom targets that include CORE2
add_subdirectory(lib/Foo EXCLUDE_FROM_ALL) # Foo library

# region main target
set(APP_TARGET main)

add_executable(${APP_TARGET})

target_sources(${APP_TARGET} PRIVATE src/main.cpp)

target_link_libraries(${APP_TARGET} PRIVATE 
    mbed-os
    foo)

set_target_properties(${APP_TARGET} PROPERTIES ARTIFACT_NAME firmware)

mbed_set_post_build(${APP_TARGET})
# endregion

if(VERBOSE_BUILD)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()