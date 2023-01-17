#!/bin/sh

set -xe

g++ -c -o pograph/pograph.o pograph/pograph.cpp
ar rcs pograph/libpograph.a pograph/pograph.o
mkdir -p include
cp pograph/pograph.h include/
mkdir -p lib
cp pograph/libpograph.a lib/
g++ -Wall -Wextra -Iinclude/ -o fentastic fentastic.cpp lib/libpograph.a
