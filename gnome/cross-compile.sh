#!/bin/sh

if ! which "x86_64-w64-mingw32-g++"; then
	sudo apt-get install mingw-w64 python3-pip python3-venv wine bison flex
fi

cd "`dirname $0`"

if [ ! -d meson ]; then
	python3 -m venv meson
	meson/bin/pip3 install meson
fi

meson/bin/meson setup --cross-file cross.meson build-mingw
meson/bin/meson compile -C build-mingw

rm -fr ./bin
mkdir -p ./bin
DESTDIR=./../bin meson/bin/meson install -C build-mingw

cp /usr/lib/gcc/x86_64-w64-mingw32/12-win32/libssp-0.dll ./bin/usr/local/bin/
cp /usr/lib/gcc/x86_64-w64-mingw32/12-win32/libstdc++-6.dll ./bin/usr/local/bin/
cp /usr/lib/gcc/x86_64-w64-mingw32/12-win32/libgcc_s_seh-1.dll ./bin/usr/local/bin/
