# CORE2 firmware template for mbed-os>=6.13 and CLI2

> Tested on Ubuntu 20.04.2 LTS

## Web resources
- https://os.mbed.com/docs/mbed-os/v6.12/build-tools/install-or-upgrade.html
- https://github.com/ARMmbed/mbed-tools
- https://github.com/ARMmbed/mbed-os-5-docs/blob/development/docs/porting/custom-target-porting.md
- https://forums.mbed.com/t/mbed-cli-2-not-configuring-project/12588
- https://os.mbed.com/docs/mbed-os/v6.12/build-tools/use.html

## Prerequisites
- `Visual Studio Code` IDE + required extensions
- `python3.6` or newer with `pip` and `venv` packages
- `CMake 3.19.0` or newer
- `Ninja 1.0` or newer
- `GNU Arm Embedded version 9 (9-2019-q4-major)` compiler (in `PATH`)

### Setup environment
1. Download `mbed-os` library.

```bash
$ cd ~
$ wget https://github.com/ARMmbed/mbed-os/archive/refs/tags/mbed-os-6.13.0.zip
$ unzip mbed-os-6.13.0.zip && ln -s mbed-os-mbed-os-6.13.0 mbed-os
```

2. Create `python3` virtual environment.

```bash
$ cd ~
$ python3 -m venv .venv
```

3. Install all required python packages in `.venv` environment

```bash
$ source ~/.venv/bin/activate
(.venv) $ pip install mbed-tools
(.venv) $ pip install -r ~/mbed-os/requirements.txt 
```

### Setup template in VSC

All required extension are listed in `.vscode/extensions.json`. 
For this template and all extensions to work correctly edit configurations in `.vscode/settings.json`:

* Path to your `mbed-os` library (env passed to integrated terminal)
```json
"terminal.integrated.env.linux": {
    "MBED_OS_LIB_PATH": "/home/byq77/mbed-os"
}
```

* Path to your `mbed-os` library (env passed to cmake extension)
```json
"cmake.environment": {
    "MBED_OS_LIB_PATH": "/home/byq77/mbed-os"
}
```

* Path to interpreter from `.venv` directory (passed to python extension)
```json
"python.defaultInterpreterPath": "/home/byq77/.venv/bin/python"
```

### Generate cmake configuration (release)
```bash
(.venv) $ mbed-tools configure -m CORE2 -t GCC_ARM -b release --mbed-os-path $MBED_OS_LIB_PATH
```

## Build

### Build using cmake
```bash
$ cmake -S . -B cmake_build/CORE2/release/GCC_ARM -GNinja
$ cmake --build cmake_build/CORE2/release/GCC_ARM
```

### Build using mbed-tools 
```bash
(.venv) $ mbed-tools compile -m CORE2 -t GCC_ARM -b release --mbed-os-path $MBED_OS_LIB_PATH
```

## Uploading firmware using the core2-flasher tool
Connect CORE2 to your computer via micro-usb port and use the `core2-flasher` tool (from this repo) to upload a generated `firmware.hex` file.

To flash firmware using `core2-flasher` run:
```bash
$ ./core2-flasher ./cmake_build/CORE2/release/GCC_ARM/firmware.hex
```

## Serial

```bash
(.venv) $ mbed-tools sterm -b 9600 -p /dev/ttyUSB0
```

## CORE2
https://husarion.com/manuals/core2/

###  Pinout
This board pinout is described in `src/TARGET_CORE2/PinNames.h` file. Pin names defined in that file are similar to ones used by `hFramework` and should be easily identifiable. Peripheral functions available for each pin are described in the `PeripheralPinMaps.h` file.

![CORE2 PINOUT](https://husarion.com/docs/assets/img/core2-hardware/cheatsheet_small.jpg)