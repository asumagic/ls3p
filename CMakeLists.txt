cmake_minimum_required(VERSION 3.16)

run_vcpkg()

project(ls3p LANGUAGES CXX)


target_compile_features(ls3p INTERFACE cxx_std_17)