# nanoTekSpice

## Overview
nankoTekSpice is a project developed as part of the Epitech curriculum. It is an Object-Oriented Programming (OOP) project that simulates a simple electronic circuit.

## Directory Structure
The project directory is organized as follows:

```
/home/kaiwinta/Epitech/Tek2/OOP/nankoTekSpice/
├── src/
│   ├── NanotekSpice/
│   ├── Parser/
│   ├── Console/
│   ├── main.cpp
│   └── ...
├── include/
│   ├── NanotekSpice/
│   ├── Parser/
│   ├── Console/
│   └── ...
├── tests/
│   ├── base.nanotest
│   ├── files/
│   │   ├── testfiles
│   ├── res/
│   │   ├── testresults.ntsres
│   ├── start_test.sh
│   └── test.sh
└── Makefile
```

### src/
Contains the source code for the project, including the main application, `NanotekSpice` core logic, `Parser` for file parsing, and `Console` for handling user input.

### include/
Contains the header files for the project, organized similarly to the `src` directory.

### tests/
Contains the test files for the project, ensuring the components and circuits work as expected. It includes test scripts and test result files.

### Makefile
The build configuration file used to compile the project.

## Getting Started
To build and run the project, follow these steps:

1. Build the project using the provided Makefile:
    ```sh
    make
    ```
2. Run the application:
    ```sh
    ./nanotekspice <filename>
    ```

## Running Tests
To run the tests, use the following command:
```sh
    make tests_all
```

You can also use this script if the project is already compiled:
```sh
./tests/start_test.sh
```

## TODO

- Update test script and result
- Test with `|` in a terminal (cf `isatty`)
- Implement basic component and crash test the archi