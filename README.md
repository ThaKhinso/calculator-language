# Calculator_lang

A simple C project for a calculator language.

## Prerequisites

- [CMake](https://cmake.org/) >= 3.10
- [Visual Studio 2022](https://visualstudio.microsoft.com/) (or any C compiler supporting C11)

## Building

1. Clone or download this repository.
2. Open a terminal and navigate to the project root directory.

Note that Making a build directory is recommended so that the build files don't mix with the project

## Cloning the repo

1. First, get the link from project box top right and you will see the green button.
2. Press it and it will show a drop down box with the link you can copy. Press that copy button from the right side of the link.
3. Use git command to clone the repo on your machine.
For example:
```sh
git clone "replace this text with the link you copied".
```
You are good to go.

### Using CMake to build the project in any operating system

```sh
mkdir build
cd build
cmake ..
cmake --build . --config Debug
```

This will generate the executable in the `build/Debug` directory.

### Running

After building, run the program:

```sh
cd Debug
./Calculator_lang.exe
```

## Project Structure

- `src/` - Source files (`main.c`, etc.)
- `include/` - Header files
- `CMakeLists.txt` - Build configuration

## Notes

- The project uses the C11 standard.
- To clean the build, simply delete the `build/` directory.

## ⚠️ Important

**If you target the visual studio as build system, you need to use the visual studio to get correct code autocomplete, suggestions, etc.**
**If you had targeted visual studio and do the development on other editors, you would get funky include errors but those are fine**
