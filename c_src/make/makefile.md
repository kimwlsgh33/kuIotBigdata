<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->

**Table of Contents** _generated with [DocToc](https://github.com/thlorenz/doctoc)_

- [Getting Started](#getting-started)
  - [Why do Makefiles exist?](#why-do-makefiles-exist)
  - [What alternatives are there to Make?](#what-alternatives-are-there-to-make)
    - [C/C++](#cc)
    - [Java](#java)
    - [Go, Rust, Typescript, etc...](#go-rust-typescript-etc)
  - [Makefile Syntax](#makefile-syntax)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Getting Started

> Makefile

## Why do Makefiles exist?

- Makefiles are used to help decide which parts of a large program need to **be recompiled**.
- In the vast majority of cases, `C` or `C++` files are compiled.

If any file's dependencies changes, then only that files will get recompiled.

## What alternatives are there to Make?

### C/C++

- [CMake](https://cmake.org/)
- [Ninja](https://ninja-build.org/)

### Java

- [Maven](https://maven.apache.org/)
- [Gradle](https://gradle.org/)

### Go, Rust, Typescript, etc...

They all have their own build systems.

## Makefile Syntax

A Makefile consists of a set of rules. A rule generally looks like this:

```make
target: dependencies
    command
    command
    command
```

- target : The name of the target and the name of the file.
- dependencies : The dependencies of the target. This must exist before the target's command can be executed.
- command : The command to be executed.
