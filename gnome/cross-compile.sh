#!/bin/sh

sudo apt-get install mingw-w64 python3-pip python3-venv wine bison flex

python3 -m venv meson
meson/bin/pip3 install meson

if [ ! -f spec.txt ]; then
	cat << EOT > spec.txt
[binaries]
c = 'x86_64-w64-mingw32-gcc'
cpp = 'x86_64-w64-mingw32-g++'
ar = 'x86_64-w64-mingw32-ar'
strip = 'x86_64-w64-mingw32-strip'
windres = 'x86_64-w64-mingw32-windres'
exe_wrapper = 'wine'

[host_machine]
system = 'windows'
cpu_family = 'x86_64'
cpu = 'x86_64'
endian = 'little'
EOT
fi

meson/bin/meson setup --cross-file spec.txt build-mingw
meson/bin/meson compile -C build-mingw
meson/bin/meson dist -C build-mingw
