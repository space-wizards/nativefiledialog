#!/bin/sh

cd "$(dirname "$0")"

pushd build/gmake_macosx
make
popd

clang -Wall -fPIC -O2 -shared -o build/lib/Release/x64/libswnfd.dylib src/nfd_wizards.c -Isrc/include build/lib/Release/x64/libnfd.a -framework Foundation -framework Appkit
