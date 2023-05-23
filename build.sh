#!/bin/sh

set -xe

# CFLAGS="-Wall -Wextra -Werror -Wpedantic -std=c99"
CFLAGS="-Wall -Wextra -std=c99"
LIBS="-lm"
INC_BASIC_LINEAR_REGRESSION_DIR="linear_regression/inc"
SCR_BASIC_LINEAR_REGRESSION_DIR="linear_regression/src"
 
mkdir -p build/
clang $CFLAGS -I $INC_BASIC_LINEAR_REGRESSION_DIR -o build/basic_linear_regression $SCR_BASIC_LINEAR_REGRESSION_DIR/basic_linear_regression.c $LIBS

