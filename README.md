# How to build using pico-sdk

```bash
sudo apt install cmake python3 build-essential gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib

git clone -b master https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
export PICO_SDK_PATH=$(pwd)
cd ..
git clone https://github.com/tony-mikhailov/zxtester
cd zxtester
mkdir build
cd ./build
cmake ..
make
```
