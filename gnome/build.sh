#!/bin/sh

cd "`dirname $0`"

if [ ! -d ./build ]; then
	meson setup build
fi

cd build/
meson compile
