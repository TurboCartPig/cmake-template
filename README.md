[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

# CMake Template

A relativly simple template for a cmake project setup with a separation between binaries and libraries, in addition to testing via [Catch2](https://github.com/catchorg/Catch2) and documentation via [Doxygen](https://doxygen.nl).

### How to build

Configure cmake:
```bash
make configure
```

Build entire project:
```bash
make build
```

Build and run tests:
```bash
make test
```

Generate doxygen documentation and open it in browser:
```bash
make doc
```

### Structure

#### Mandatory directories

- src/<project_name> - Contains the source code for the main library exported by this project.
- include/<project_name> - Contains the public headers exposed by the main library.
- tests - Contains the main testing framework and defines the cmake target for running tests.
- docs - Contatins documentation that relates to the project and defines a cmake target for generating documentation.

#### Optional directories

- apps - Applications and binaries generated from the project, can be renamed `examples` if that make more sense.
- apps/<app_name> - All source code related to one binary.
- src/<other_library> - Some other optionally buildt library that implements modulerized functionality that can be optinally consumed by other libraries or binaries within this project.
- include/<other_librariy> - The public header files for the library defined above.
- res - Contains non-code resources used by the project at runtime.

#### Ephemeral directories

- build - Contains build artifacts, could have subdirectories like `debug` or `msvc-x86_64-release`.

> These directories are ignored by git and should not be checked in.

### Further Reading

- [Modern CMake Tutorial](https://cliutils.gitlab.io/modern-cmake)
- [Catch2 Tutorial](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top)

