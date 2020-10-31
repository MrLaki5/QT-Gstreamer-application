#!/bin/bash

# Absolute path for root dir where bash is located
ROOT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# If build folder does not exist, create it
if [ ! -d "${ROOT_DIR}/build" ] 
then
    mkdir "${ROOT_DIR}/build"
fi
# Out build folder
if [ ! -d "${ROOT_DIR}/build/out" ] 
then
    mkdir "${ROOT_DIR}/build/out"
fi
# Install build folder
if [ ! -d "${ROOT_DIR}/build/install" ] 
then
    mkdir "${ROOT_DIR}/build/install"
fi

# Switch to build folder
cd "${ROOT_DIR}/build/out"

# Build
cmake -DCMAKE_INSTALL_PREFIX=${ROOT_DIR}/build/install ../..
make install
