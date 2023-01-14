#!/bin/sh
set -xe
g++ -c -o pograph/pograph.o pograph/pograph.cpp
ar rcs pograph/libpograph.a pograph/pograph.o
cp pograph/pograph.h include/
cp pograph/libpograph.a lib/
g++ -Iinclude/ -o fentastic fentastic.cpp lib/libpograph.a
