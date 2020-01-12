#!/bin/bash

target="build"

if [ ! -d $target ]; then
    mkdir -p $target
fi

cd $target

echo "*******************************************************************************"
echo "start to build demo ..."


cmake ..
cmake --build .

if [ $? -ne 0 ]; then
    echo "FAILED!"
    cd ..
    exit 1
fi

echo "*******************************************************************************"
echo "start to run tests..."
make test

if [ $? -ne 0 ]; then
    echo "FAILED!"
    cd ..
    exit 1
fi

cd ..

echo "*******************************************************************************"
echo "SUCCESS!"
exit 0
