#! /bin/bash

export FREERTOS_KERNEL_PATH=$(pwd)/FreeRTOS-Kernel
export PICO_SDK_PATH=$(pwd)/pico-sdk
export PICO_BOARD=pico2_w
export PICO_PLATFORM=rp2350

cmake -S . -B build \
    -DFREERTOS_KERNEL_PATH=$FREERTOS_KERNEL_PATH \
    -DPICO_SDK_PATH=$PICO_SDK_PATH \
    -DPICO_BOARD=$PICO_BOARD \
    -DPICO_PLATFORM=$PICO_PLATFORM \