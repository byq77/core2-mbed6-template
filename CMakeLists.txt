# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.19.0)

# GLOBAL MBED-OS PATH
if(DEFINED ENV{MBED_OS_LIB_PATH})
    set(MBED_PATH $ENV{MBED_OS_LIB_PATH} CACHE INTERNAL "")
else()
    set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")
endif()

set(MBED_CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "")
set(APP_TARGET firmware)

include(${MBED_PATH}/tools/cmake/app.cmake)

project(${APP_TARGET})

add_executable(${APP_TARGET})

# USER OPTIONS

# SUBDIRECTORIES
add_subdirectory(lib/stm32customtargets) # custom targets that include CORE2
add_subdirectory(lib/Foo EXCLUDE_FROM_ALL) # Foo library
add_subdirectory(${MBED_PATH} ${CMAKE_CURRENT_BINARY_DIR}/mbed-os)

set(FIRMWARE_TARGET_SOURCE_FILES src/main.cpp CACHE INTERNAL "")

get_target_property(FOO_LIB_EXCLUDED foo EXCLUDE_FROM_ALL)
if(NOT ${FOO_LIB_EXCLUDED})
    list(APPEND CUSTOM_LIBS foo)
endif()

target_sources(${APP_TARGET}
    PRIVATE
    ${FIRMWARE_TARGET_SOURCE_FILES}
)

target_link_libraries(${APP_TARGET}
    PRIVATE 
    mbed-os
    ${CUSTOM_LIBS}
)

mbed_set_post_build(${APP_TARGET})

option(VERBOSE_BUILD "Have a verbose build process")
if(VERBOSE_BUILD)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()