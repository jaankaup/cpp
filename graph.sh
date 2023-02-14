#!/bin/bash -x

cd test_dot
dot -Tsvg test.dot > test.svg
inkscape "test.svg"
cd ..
