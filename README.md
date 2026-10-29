# MiniKV

MiniKV is a lightweight, Redis-inspired in-memory key-value store
implemented in C++17.

It provides a command-line interface for storing, retrieving,
updating, and deleting key-value pairs. The project uses
`std::unordered_map` for storage, CMake as its build system,
and GoogleTest for automated testing.

## Features

- SET: Insert or update a key-value pair.
- GET: Retrieve the value associated with a key.
- DEL: Delete a key.
- HELP: Display available commands.
- EXIT: Exit the application.
- Automated unit tests using GoogleTest.
- Separate storage library and command-line interface.

## Tech Stack

- C++17
- STL (`std::unordered_map`)
- CMake
- Ninja
- GoogleTest
- Git

## Project Structure

```text
MiniKV/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   └── minikv/
│       └── store.h
├── src/
│   ├── store.cpp
│   └── main.cpp
└── tests/
    └── store_test.cpp