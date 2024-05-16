C++
PROJECT_NAME = WUSBS
PROJECT_VERSION = 0-0.0.0-1

BUILD_DIR = bin
MAKEFILE = WUSBS.mk

HEADERS = src/header/utils.h src/header/CommandMap.h src/header/MakeBuilder.h src/defines.h
SOURCES = src/src/utils.cpp src/src/CommandMap.cpp src/src/CommandMapInit.cpp src/src/MakeBuilder.cpp
MAIN = src/main.cpp

COMPILER = g++
STD = c++23