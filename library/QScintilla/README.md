# QScintilla

QScintilla is a powerful code editing component for Qt, based on the Scintilla library. It provides rich features such as syntax highlighting, code folding, and auto-completion.

## Features

- Syntax highlighting for multiple programming languages
- Code folding
- Auto-completion
- Line numbering
- Compatible with Qt Designer

## Build and Install

### Building with CMake

QScintilla now supports building with CMake. Here are the steps to build:

1. Clone the QScintilla repository:

    ```bash
    git clone https://github.com/farleyrunkel/QScintilla.git
    cd QScintilla
    ```

2. Create a build directory and run CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    ```

3. Compile and install:

    ```bash
    cmake --build .
    cmake --install .
    ```

### Using as a Submodule

If you want to add QScintilla as a submodule to your project, follow these steps:

1. Add QScintilla as a submodule in your project's root directory:

    ```bash
    git submodule add https://github.com/farleyrunkel/QScintilla.git external/QScintilla
    ```

2. Include QScintilla in your project's CMakeLists.txt file:

    ```cmake
    add_subdirectory(external/QScintilla)
    ```

3. Link the QScintilla library to your target:

    ```cmake
    target_link_libraries(your_target PRIVATE QScintilla::qscintilla2_qt${Qt_VERSION_MAJOR})
    ```

## Example Project

An example project demonstrating how to use QScintilla can be found in the `example` directory.

## Changelog

### 2024-07-05  Farley Runkel  <farley.runkel@example.com>

- Added support for building QScintilla using CMake.

