# Greeter

An app which greets the user.

# About

This app was made to learn how to make a Flux-like architecture using C++ and QML. This app includes a few of my own customisations and changes to the system made for [MuseScore](https://github.com/musescore/MuseScore).

# Building

## Linux

1. Make sure `Qt 5` and `CMake` (at least 3.20) are installed.
2. Clone this repository.
```bash
# Choose the parent directory of the cloned repository
cd to/a/directory

# Clone either the GitLab or GitHub repository
# GitLab
git clone https://gitlab.com/iwoithe/Greeter.git
# GitHub
git clone https://github.com/iwoithe/Greeter.git
```
2. Open a terminal in the root directory of the source code.
3. Make a build directory.
```bash
mkdir builds && cd builds
```
4. Run CMake.
```bash
cmake ..
```
5. Run the compiler (Ninja in this example, you can use any compiler which you want to use).
```bash
ninja -j2
```
6. Run Greeter.
```bash
./src/main/Greeter
```

## macOS

<!-- As I don't have experience with macOS -->
Contributions welcome!

## Windows
1. Download and install [MSYS2](https://msys2.org).
2. Open the ``MSYS2 MSYS2`` terminal.
3. Run the following command to install the required packages.
```bash
TODO
```
<!-- TODO: Find the correct link for the Qt Online Installer -->
4. Download and install the latest Qt 5 version from the [Qt Online Installer](https://qt.io/download).
2. Clone this repository.
```bash
# Choose the parent directory of the cloned repository
cd to/a/directory

# Clone either the GitLab or GitHub repository
# GitLab
git clone https://gitlab.com/iwoithe/Greeter.git
# GitHub
git clone https://github.com/iwoithe/Greeter.git
```
2. Open a terminal in the root directory of the source code.
3. Make a build directory.
```bash
mkdir builds && cd builds
```
4. Run CMake.
```bash
cmake ..
```
5. Run the compiler (Ninja in this example, you can use any compiler which you want to use).
```bash
ninja -j2
```
6. Run Greeter.
```bash
./src/main/Greeter.exe
```

# Documentation

Documentation on the whole system will be written at somepoint, however no date is set.

# Acknowledgements

A lot of the code is based/taken from [MuseScore](https://github.com/musescore/MuseScore). Without MuseScore this project would have taken a lot longer.

# License

Greeter is released under the GNU General Public version 3 license.
