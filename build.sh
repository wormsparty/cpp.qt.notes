#!/bin/sh

CC=clang++
CXXFLAGS=$(curl-config --cflags)
LDFLAGS=$(curl-config --libs)

$CC output main.cpp $CXXFLAGS $LDFLAGS