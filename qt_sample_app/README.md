# Using

Requirements:
1. Win 10 (22H2) x64
2. MSVC v194 (Visual Studio 2022)

### Clone
```
git clone --recursive https://github.com/mrBelka/qt_sample_app.git
# It will work for some time, because submodule size is about 700Mb. It uses Git LFS for increase downloading.
```


### Use Qt in your app
Build
```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cmake --intall .
```

Clean
```
rm -r build
```

Launch
```
./build/Release/qt_app.exe 
```

## Some useful
### Build Qt from source in Windows 10 (MSVC)
1. Download sources for qtbase
2. Open x64 Native Command Prompt
3. mkdir /path/to/build
4. cd /path/to/build
5. /path/to/sources/configure.bat --debug-and-release
6. cmake --build build -j 6   # 6 threads because not enough RAM
7. ninja install

### Submodules
```
cd /path/to/repo/
git submodule add https://github.com/mrBelka/qt-6.12.0-win10-22H2-x64-msvc-194.git ext/
```