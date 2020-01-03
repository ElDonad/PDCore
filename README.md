# PDCore
A generic library that implements the logic of Pixel Dungeon.

The ultimate goal is to port [Pixel Dungeon](https://github.com/watabou/pixel-dungeon) from Watabou to the Nintendo DS via the devkitpro's devkitARM toolchain (the purpose of the makefile).

Speaking of makefiles, I am absolutely unable to write nor customize myself one of those. Currently the test build is made using the python script (directly called by COMPILE.bat), and the makefile has been stolen from the devkitARM templates, and is responsible for building the DS compatible lib.

The "client" meant to run on the nintendo DS, as well as the test client, will be published once they get enough work. Currently I'm more focusing on the logic engine.

One of my **long term** objective is to implement modding through a LUA api, then exploit the networking capabilities of the NDS to serve the mods to users through the internet.

That being said, I work on this project during my (very sparse) free time and I'm a self-taught C++ programmer, so don't expect high quality coding nor rapid extension.
