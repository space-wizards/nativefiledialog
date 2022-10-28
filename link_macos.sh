#!/bin/sh

cd "$(dirname "$0")"

pushd build/darwin_multiarch
make
popd

# the result is in build/darwin_multiarch/libswnfd.dylib

# maintain backwards compatiblity with stuff that expects the file in the old location 
mkdir -p build/lib/Release/x64
cp build/darwin_multiarch/libswnfd.dylib build/lib/Release/x64/libswnfd.dylib

