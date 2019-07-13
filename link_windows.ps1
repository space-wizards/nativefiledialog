# You need to run this after running vcvars.
# You know like run powershell from Visual Studio Native Tools Command Prompt.
# Make sure to get x64.

cl /MD /LD /O2 src/nfd_wizards.c build/lib/Release/x64/nfd.lib /I src/include comctl32.lib ole32.lib shell32.lib /link /OUT:swnfd.dll