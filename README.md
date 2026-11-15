# Kairo Engine

Kairo is an early-stage C++20 game engine project focused on learning modular
architecture, systems programming, and cross-platform development.

## Current status

Milestone 1 establishes a reusable static engine library and a separate sandbox
executable. The sandbox calls one public engine function and prints
`Hello from Kairo Engine!`.

Rendering, window management, input, scene management, and editor tooling are
planned. No game runtime is implemented yet, and there are no third-party
dependencies.

## Platform targets

- macOS on Apple Silicon: build foundation verified in Debug and Release.
- Windows: planned target; not yet validated.

Portable build configuration alone does not establish tested platform support.
The foundation was built and run with Apple Clang 21 and CMake 4.5; both
configurations printed the expected greeting and exited successfully.

## Build

Requirements: CMake 3.28 or newer, a C++20 compiler, and a native build tool
supported by CMake (for example, Make, Ninja, or MSBuild).

From the project root:

```sh
cmake --preset debug
cmake --build --preset debug

cmake --preset release
cmake --build --preset release
```

Presets use the local compiler and CMake's default generator, unless selected
through the local environment or configuration. They contain no absolute
compiler paths or operating system restrictions.

`CMAKE_BUILD_TYPE` selects the configuration for single-configuration generators
such as Make and Ninja. The build presets also select `Debug` or `Release` for
multi-configuration generators such as Visual Studio and Xcode.

Build output goes into `out/build/debug` and `out/build/release`. With a
single-configuration generator on macOS, run the Debug sandbox using:

```sh
./out/build/debug/apps/sandbox/kairo_sandbox
```

Multi-configuration generators add a configuration directory, such as `Debug`,
before the executable name; Windows executables also have the `.exe` suffix.
Choose the generator and compiler before the first configure of a build directory;
use a fresh build directory when changing either.

## Editor diagnostics with clangd

The presets request a `compile_commands.json` compilation database, which CMake
generates with Makefile and Ninja generators. This gives clangd the same include
paths, compiler options, and C++ standard as the build.

The project `.clangd` file selects `out/build/debug` for editor analysis. Run
`cmake --preset debug` before editing, even if you usually build Release. After
configuring, use **clangd: Restart language server** from VS Code's Command
Palette if old diagnostics remain. This editor selection does not change which
configuration you build.

## Structure

- `engine/include/kairo/`: public engine headers.
- `engine/src/`: engine implementation and private headers when needed.
- `apps/sandbox/src/`: application entry point and demonstration code.
- `out/`: generated build output, excluded from version control.

`kairo_engine` is a static library, also available as `Kairo::Engine` in CMake.
`kairo_sandbox` links to it and inherits its public include path and C++20
requirement. The engine has no dependency on the sandbox.

## Goals and learning objectives

- Build a reusable engine through small, verifiable milestones.
- Learn C++ ownership, RAII, compilation, and linking.
- Learn target-based CMake, testing, and platform abstraction.
- Work toward tested macOS and Windows builds.
- Explore GLFW and OpenGL initially, with Metal and Direct3D as possible future
  backends.

The build foundation uses C++20 and CMake. Graphics libraries and other engine
systems will be introduced in later milestones.
