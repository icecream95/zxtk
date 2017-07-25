# zxtk
[![Travis CI build status](https://api.travis-ci.org/icecream95/zxtk.svg?branch=master)](https://travis-ci.org/icecream95/zxtk) [![Appveyor build status](https://ci.appveyor.com/api/projects/status/github/icecream95/zxtk?branch=master&svg=true)](https://ci.appveyor.com/project/icecream95/zxtk) [![Coverity scan build status](https://scan.coverity.com/projects/12869/badge.svg)](https://scan.coverity.com/projects/icecream95-zxtk) [![Codecov](https://img.shields.io/codecov/c/github/icecream95/zxtk.svg)](https://codecov.io/gh/icecream95/zxtk) [![license](https://img.shields.io/github/license/icecream95/zxtk.svg)](https://github.com/icecream95/zxtk/blob/master/LICENSE)

ZX spectrum Tool Kit: a fast, efficient, capable, modular ZX Spectrum emulator

**NOTE:** This is WIP so don't expect it to do much more than compile

Finished:
 - [x] Register set implementation
 - [ ] Memory interface (not finalised, will be changed)

Working on:
 - [x] Z80 instructions
 - [ ] I/O interface
 - [ ] Spectrum ULA
 - [ ] File interface
 - [ ] Mod interface
 - [ ] Graphics interface
 

Points of discussion - feel free to open an issue on your thoughts about these:
 - The use of lowercase namespace names - sorry Bjarne, but I think it looks neater

Possible features - these might not be added until after 1.0
 - ZX81 compatibility?
 - Issue 1 speccy?
 - Should memory have a buffer, allowing the z80 to run ahead of the ULA?
 - In-emulator [worldofspectrum.org](https://worldofspectrum.org) program downloader?
 - Assembler
 - Utilities (similar to [fuse-emulator-utils](https://sourceforge.net/p/fuse-emulator/fuse-utils/ci/master/tree/))
 - BASIC parser
 - Operating System
