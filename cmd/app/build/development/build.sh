#!/bin/bash

ROOT_INCLUDE=`readlink -e ../../../../`;
ROOT_LOCAL=`readlink -e ./`;

mkdir -p $ROOT_LOCAL/inc
mkdir -p $ROOT_LOCAL/src

cp -rf $ROOT_INCLUDE/inc/* $ROOT_LOCAL/inc
cp -rf $ROOT_INCLUDE/src/* $ROOT_LOCAL/src

make debug -j
pendev