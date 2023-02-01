# CORE2 firmware template for development with mbed-os

## Web resources
- https://os.mbed.com/docs/mbed-os/v6.15/build-tools/mbed-cli-2.html
- https://github.com/ARMmbed/mbed-tools
- https://github.com/ARMmbed/mbed-os-5-docs/blob/development/docs/porting/custom-target-porting.md
- https://forums.mbed.com/t/mbed-cli-2-not-configuring-project/12588
- https://os.mbed.com/docs/mbed-os/v6.15/build-tools/use.html
- https://docs.docker.com/get-docker/
- https://code.visualstudio.com/docs/devcontainers/containers

## Prerequisites
- `Visual Studio Code` IDE + required extensions
- `Docker` installed on the host

## Setup environment
1. Download `mbed-os` library.

2. Start the dev container using the `Dev Containers: Open Workspace in Container...` command.

3. Fetch and init dependencies

    ```bash
    git submodule update --init --recursive
    ```

## Generate cmake configuration
```bash
mbed-tools configure -m CORE2 -t GCC_ARM -b release --mbed-os-path $MBED_OS_LIB_PATH --custom-targets-json lib/stm32customtargets/custom_targets.json
```

## Build

### Build using cmake
```bash
cmake -S . -B cmake_build/CORE2/release/GCC_ARM -GNinja
cmake --build cmake_build/CORE2/release/GCC_ARM
```

### Build using mbed-tools
```bash
mbed-tools compile -m CORE2 -t GCC_ARM -b release --mbed-os-path $MBED_OS_LIB_PATH --custom-targets-json lib/stm32customtargets/custom_targets.json
```

## Uploading firmware using the core2-flasher tool
Connect CORE2 to your computer via micro-usb port and use the `core2-flasher` tool (from this repo) to upload a generated `firmware.hex` file.

To flash firmware using `core2-flasher` run:
```bash
./core2-flasher ./cmake_build/CORE2/release/GCC_ARM/firmware.hex
```

## Serial
```bash
mbed-tools sterm -b 9600 -p <port>
```

## CORE2
https://husarion.com/manuals/core2/

###  Pinout
This board pinout is described in `src/TARGET_CORE2/PinNames.h` file. Pin names defined in that file are similar to ones used by `hFramework` and should be easily identifiable. Peripheral functions available for each pin are described in the `PeripheralPinMaps.h` file.