@echo off
rem install sdl from http://www.libsdl.org/release/SDL2-2.0.5-win32-x64.zip
CD /D %~dp0

git submodule init
git submodule update

IF NOT EXIST install md install
IF NOT EXIST build64 md build64
cd build64
cmake -G "Visual Studio 15 2017 Win64" -DUSE_SDL=OFF -Dgtest_force_shared_crt=ON -DCOMPILE_TESTS=OFF -DCMAKE_INSTALL_PREFIX="..\install" ..
rem NOTE: REMOVE -DUSE_SDL=OFF when I work out how to get SDL
cd ..
