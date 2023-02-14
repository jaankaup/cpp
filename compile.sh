#!/bin/bash -x

mkdir -p build/$1
# cmake -S$1 -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -H. -Bbuild/$1
cmake --graphviz=test_dot/test.dot -S$1 -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -Bbuild/$1
cd build/$1
make -j4 all
cd ../..
