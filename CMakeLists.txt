cmake_minimum_required(VERSION 3.13)
project(InterpolationChebyshev)

set(CMAKE_CXX_STANDARD 14)

add_executable(InterpolationChebyshev main.cpp plot.cpp interpolation.cpp cmake-build-debug/input.txt)