# ls3p

This is extremely WIP and is currently unusable for real projects. Don't trust the tenses used in this document ;)

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) server implementation for C++17, aiming to be reasonably lightweight and embeddable.  
It hopes to provide a useful, clean and complete interface for the LSP, and to eliminate boilerplate in user code as much as possible.

It is built upon a basic JSON-RPC implementation using [nlohmann/json](https://github.com/nlohmann/json).  
It also provides an optional but convenient TCP transport implementation that makes implementing clients easy.

## Usecase

There are [many SDKs](https://microsoft.github.io/language-server-protocol/implementors/sdks/) for the LSP, but few written in C or C++. Yet, C++ could be the language of choice in various usecases where interfacing to existing code is a requirement, and the few existing options may be unsuitable when embedding to an existing project, due to heavy reliance on external libraries like Boost.

The main reason for developing this is as part of an AngelScript Language Server, that is more specifically meant to be embedded as part of [King Arthur's Gold](https://kag2d.com/en/)'s engine, in order to improve development and modding workflow.

## Overview

- [`ls3p::messages::`](include/ls3p/messages/) provides C++ class representations of LSP messages that can be parsed from `nlohmann::json` objects, and provides additional helper functions.
    - [`ls3p::messages::base::`](include/ls3p/messages/base/) implements ["base" messages](https://microsoft.github.io/language-server-protocol/specifications/specification-current/#requestMessage) as defined in the LSP and/or JSON-RPC specifications.
    - [`ls3p::messages::caps::`](include/ls3p/messages/caps/) implements messages defined in the LSP that refer to client or server capabilities.
    - The rest of the main namespace contains all other definitions.