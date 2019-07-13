#!/bin/sh

cd "$(dirname "$0")"

pushd build/gmake_linux
make
popd

GTK_FLAGS="$(pkg-config --cflags --libs gtk+-3.0)"

gcc -Wall -fPIC -O2 -shared -o build/lib/Release/x64/libswnfd.so src/nfd_wizards.c -Isrc/include build/lib/Release/x64/libnfd.a $GTK_FLAGS
