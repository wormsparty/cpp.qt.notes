#!/bin/sh

cd "`dirname $0`"

if [ ! -d ./tmp ]; then
	echo "Run ./configure first"
fi

cmake --build tmp --config Release
