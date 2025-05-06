cmake_minimum_required(VERSION 3.13...3.27)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
# include(pico_sdk_import.cmake)

project(pico_ssh_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

if (NOT FREERTOS_KERNEL_PATH AND NOT DEFINED ENV{FREERTOS_KERNEL_PATH})
    message("Build failed as FREERTOS_KERNEL_PATH not defined")
    return()
endif()

include(FreeRTOS_Kernel_import.cmake)

add_subdirectory(src)
