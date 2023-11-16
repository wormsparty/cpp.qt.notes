#!/bin/sh

cd "`dirname $0`"

rm -fr ./tmp
mkdir -p ./tmp
cd ./tmp

VCPKG_PATH="C:/Users/mob/vcpkg"
cmake .. "-DCMAKE_TOOLCHAIN_FILE=${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake"
