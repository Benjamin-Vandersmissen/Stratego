cmake_minimum_required(VERSION 3.12)
project(Stratego)

set(CMAKE_CXX_STANDARD 14)

add_executable(Stratego main.cpp Piece.cpp Piece.h Board.cpp Board.h)