#!/bin/sh

if ! which pacman; then
	echo "Please install MSYS first"
	open "https://www.msys2.org/"
	exit 1
fi

pacman -S git mingw-w64-x86_64-meson mingw-w64-x86_64-python3 mingw-w64-x86_64-gtk4
