#!/bin/sh

set -xe

# CFLAGS="-Wall -Wextra -Werror -Wpedantic -std=c99"
CFLAGS="-Wall -Wextra -std=c99 -o3 -mfma"
LIBS="-lm"

INC_DIR="-I util"

INC_BASIC_LINEAR_REGRESSION_DIR="-I linear_regression/inc"
SCR_BASIC_LINEAR_REGRESSION_DIR="linear_regression/src"
 
mkdir -p build/
clang $CFLAGS $INC_BASIC_LINEAR_REGRESSION_DIR $INC_DIR -o build/basic_linear_regression $SCR_BASIC_LINEAR_REGRESSION_DIR/basic_linear_regression.c $LIBS

