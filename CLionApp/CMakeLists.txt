cmake_minimum_required(VERSION 3.19)
project(CLionApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLionApp main.cpp HotDrink.h IHotDrinkFactory.h ISaveAble.h)