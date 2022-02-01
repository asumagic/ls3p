# ls3p

This is extremely WIP and is currently unusable for real projects.

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/) server implementation for C++17, aiming to be lightweight and embeddable.

## Usecase

There are a fair number of [existing SDKs](https://microsoft.github.io/language-server-protocol/implementors/sdks/) for the LSP, but few written in C or C++.  
Yet, C++ could be the language of choice in various usecases, where interfacing to existing C or C++ code or even embedding as part of a C++ codebase is a requirement.

The main reason for developing this is as part of an AngelScript Language Server, that is more specifically meant to be embedded as part of [King Arthur's Gold](https://kag2d.com/en/)'s engine, in order to improve development and modding workflow.