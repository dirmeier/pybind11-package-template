# pybind11-package-template

[![Project
Status](http://www.repostatus.org/badges/latest/concept.svg)](http://www.repostatus.org/#concept)

> A template for pybind11 python packages

## About

This repository hosts an example template for the folder structure of a Python package
that uses [`pybind11`](https://github.com/pybind/pybind11) to interface to C++.

## Installation

The Python package can be installed using:

```bash
make install
```

I recommended to install everything within a virtual environment, e.g., using conda. 

## Dependencies

To automatically build the C++ sources and interface to Python `pybind11` we will use 
CMake as described [here](https://pybind11.readthedocs.io/en/stable/compiling.html#building-with-cmake)

To build the entire project you will need to install the following dependencies:

- `cmake >= 3.16`,
- `pkg-config`

For development you also need to install:

- [`googletest`](https://github.com/google/googletest) and `pytest` for running unit tests, 
- `clang-format` and `black` for code formatting,
- `cpplint`, `pydocstyle` and `pylint` to lint the code,
- `cppcheck` for static code analysis.

To create documentation files you also need to install 

- `sphinx`
- the requirements in `docs/requirements.txt`

You can install the dependencies using Conda, PyPI or most Linux package managers.

## Development

Clone/download the project and run

```bash
make debug
```

to build the C++ sources in debug mode. This builds an test executables in
 `build/` and a static library.

To run unit tests, lints, etc. call:

```bash
make test
make format
make lint
make check
```

To document everything call:

```bash
make docs
```

This builds html documentation in `docs`.

## Author

 Simon Dirmeier <a href="mailto:simon.dirmeier @ web.de">simon.dirmeier @ web.de</a>