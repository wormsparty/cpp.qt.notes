#!/bin/sh

#CXX="g++"
CXX="clang++"
CXXFLAGS="-std=c++20 -Wall -O2"
LDFLAGS="-lcurl"

$CXX $CXXFLAGS CppTest/*.cpp $LDFLAGS
