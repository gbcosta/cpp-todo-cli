#!/bin/bash

BUILD_DIR="build"

rm -rf ./$BUILD_DIR
echo "build folder deleted"

cmake -B $BUILD_DIR
