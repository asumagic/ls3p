# ls3p

This is extremely WIP and is currently unusable for real projects. Don't trust the tenses used in this document ;)

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) 3.16 server implementation for C++17, aiming to be reasonably lightweight and embeddable.  
It hopes to provide a useful, clean and complete interface for the LSP, and to eliminate boilerplate in user code as much as possible.

This may be adapted to serve as a LSP client, however, it is currently a non-goal and serialization of client messages may not be as thorough.

It is built upon a basic JSON-RPC implementation and makes extensive use of [nlohmann/json](https://github.com/nlohmann/json).  
It also provides an optional but convenient TCP transport implementation that makes implementing clients easy.

## Usecase

There are [many SDKs](https://microsoft.github.io/language-server-protocol/implementors/sdks/) for the LSP, but few written in C or C++. Yet, C++ could be the language of choice in various usecases where interfacing to existing code is a requirement, and the few existing options may be unsuitable when embedding to an existing project, due to heavy reliance on external libraries like Boost.  
It however still makes extensive use of some C++17 classes and functionality and of the standard library containers.

The main reason for developing this is as part of an AngelScript Language Server, that is more specifically meant to be embedded as part of [King Arthur's Gold](https://kag2d.com/en/)'s engine, in order to improve development and modding workflow.

## Overview

- [`ls3p::messages::`](include/ls3p/messages/) provides C++ class representations of LSP messages that can be parsed from `nlohmann::json` objects, and provides additional helper functions. It is split up in namespaces that generally match the LSP specification categories. Each file groups up related structures. Convenience headers inside of the root directory allow including all headers of a particular `ls3p::messages::` namespace.