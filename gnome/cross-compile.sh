#!/bin/sh

sudo apt-get install mingw-w64 python3-pip python3-venv wine bison flex

if [ ! -d meson ]; then
	python3 -m venv meson
	meson/bin/pip3 install meson
fi

meson/bin/meson setup --cross-file cross.meson build-mingw
meson/bin/meson compile -C build-mingw

rm -fr ./bin
mkdir -p ./bin
DESTDIR=./../bin meson/bin/meson install -C build-mingw
