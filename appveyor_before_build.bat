@echo off
CD /D %~dp0
IF NOT EXIST build64 md build64
cd build64
cmake -G "Visual Studio 15 2017 Win64" -DUSE_SDL=OFF .. 
rem NOTE: REMOVE -DUSE_SDL=OFF
cd ..
