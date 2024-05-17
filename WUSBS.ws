PROJECT_NAME = WUSBS
PROJECT_VERSION = 1-0.0.0-1

BUILD_DIR = bin
MAKEFILE = WUSBS.mk
TARGET = WUSBS.o

HEADERS = src/header/* src/defines.h
SOURCES = src/src/*
MAIN = src/main.cpp

COMPILER = g++
STD = c++23