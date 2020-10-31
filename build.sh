#!/bin/bash

# Absolute path for root dir where bash is located
ROOT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# If build folder does not exist, create it
if [ ! -d "${ROOT_DIR}/build" ] 
then
    mkdir "${ROOT_DIR}/build"
fi

# Switch to build folder
cd "${ROOT_DIR}/build"

# Build
cmake ..
make