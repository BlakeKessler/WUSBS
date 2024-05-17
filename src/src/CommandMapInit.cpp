#ifndef COMMAND_MAP_INIT_CPP
#define COMMAND_MAP_INIT_CPP

#include "CommandMap.h"

//initialize a WUSBS command map for C++
bool CommandMap::init() {
   _commandMapPtr = std::make_shared<std::unordered_map<std::string, ArgVec>>();
   (*_commandMapPtr)["LANGUAGE"] = DEFAULT_LANG;
   (*_commandMapPtr)["COMPILER"] = DEFAULT_COMPILER;
   (*_commandMapPtr)["STD"] = {};
   (*_commandMapPtr)["FLAGS"] = DEFAULT_FLAGS;
   (*_commandMapPtr)["DEBUG_FLAGS"] = DEFAULT_DEBUG_FLAGS;
   (*_commandMapPtr)["RELEASE_FLAGS"] = DEFAULT_RELEASE_FLAGS;
   
   (*_commandMapPtr)["TARGET"] = {};
   (*_commandMapPtr)["MAKEFILE"] = DEFAULT_MAKEFILE;
   (*_commandMapPtr)["BUILD_DIR"] = DEFAULT_BUILD_DIR;
   
   (*_commandMapPtr)["ROOT"] = DEFAULT_ROOT;
   (*_commandMapPtr)["HEADERS"] = {};
   (*_commandMapPtr)["SOURCES"] = {};
   (*_commandMapPtr)["MAIN"] = DEFAULT_MAIN;
   (*_commandMapPtr)["L"] = {};
   (*_commandMapPtr)["l"] = {};
   (*_commandMapPtr)["I"] = {};
   
   (*_commandMapPtr)["PROJECT_NAME"] = {};
   (*_commandMapPtr)["PROJECT_VERSION"] = {};

   return true;
}

#endif //COMMAND_MAP_INIT_CPP