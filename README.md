# Cross Platform Graphical User Interfaces in C++

Tutorial from _javidx9_  
1. https://www.youtube.com/watch?v=FOIbK4bJKS8
2. https://www.youtube.com/watch?v=FwUGeV2fnfM

__*The `wxStatusBar` on Linux only works if on `wxMDIParentFrame` class, not in `wxMDIChildFrame`*__

### wxWidgets
https://www.wxwidgets.org/  
https://github.com/wxWidgets/wxWidgets/  

```
sudo apt install libcurl4-openssl-dev libxtst-dev libgspell-1-dev libsecret-1-dev libnotify-dev
```
Install SDL2  


Download wxWidgets source code, extract and enter folder
```
./configure
mkdir build_dir
cd build_dir
cmake .. -DCMAKE_BUILD_TYPE=Release
# cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$HOME/.local
cmake --build . -j10
cmake --build . --target install
```