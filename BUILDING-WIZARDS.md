I can't just leave this repo being used without at all documenting how it's being built.

Anyways, `nativefiledialog` only compiles to a static lib which is pretty damn dumb if you ask me.
So `src/nfd_wizards.c` is compiled against that to provide a dynamic lib API.

Build script is `link_linux.sh`. I'll add Windows/macOS later I guess.
If that doesn't work then start praying because I don't know why either.
