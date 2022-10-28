INCLUDEDIR = ../../src/include
SRCDIR = ../../src
LIBRARY = libswnfd.dylib
OBJS = nfd_cocoa.o nfd_common.o nfd_wizards.o

CCOPTS = -DNDEBUG -O3 -I$(INCLUDEDIR) -arch arm64 -arch x86_64 -fPIC
LDOPTS = -framework Foundation -framework AppKit -arch arm64 -arch x86_64 -fPIC -dynamiclib

all: $(LIBRARY)

.PHONY: clean
clean:
	rm -f $(LIBRARY) $(OBJS)

%.o: $(SRCDIR)/%.m
	clang $(CCOPTS) -o $@ -c $<

%.o: $(SRCDIR)/%.c
	clang $(CCOPTS) -o $@ -c $<

$(LIBRARY): $(OBJS)
	clang $(LDOPTS) -o $@ $(OBJS)


