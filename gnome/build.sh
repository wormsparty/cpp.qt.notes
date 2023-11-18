#!/bin/sh

cd "`dirname $0`"

meson setup ./build --wipe
meson compile -C ./build
