#!/bin/sh

#CXX="g++"
CXX="clang++"
CXXFLAGS="-std=c++20 -Wall -O2 $(pkg-config Qt6Widgets --cflags)"
LDFLAGS="-lcurl $(pkg-config Qt6Widgets --libs)"

$CXX $CXXFLAGS cpp/*.cpp $LDFLAGS
