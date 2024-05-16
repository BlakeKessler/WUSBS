#ifndef COMMAND_MAP_CPP
#define COMMAND_MAP_CPP

#include "CommandMap.h"
   #include <iostream>

//returns if the processing of the line should continue
bool CommandMap::preProcessFile(const std::string& rawLine, std::string&code, std::string& comments) const {
   //skip to next line if the current line is empty
   if (rawLine.size() == 0) {
      return false;
   }

   //put commented and un-commented sections of the line in the appropriate output strings
   std::istrstream preStream(rawLine.c_str());
   while (preStream.good()) {
      //read from raw line
      code += read(preStream, COMMENT_DELIM);
      comments += read(preStream, COMMENT_DELIM);
      //add newline character between comments
      if (comments.size() > 0) {
         comments.push_back('\n');
      }
   }

   //continue to processing if any code is not commented out
   return code.size() > 0;
}

CommandMap::CommandMap(const CommandMap& other) {
   _commandMapPtr = other._commandMapPtr;
   _lang = other._lang;
}

//construct command map from WUSBS file
CommandMap::CommandMap(const std::string& path, const std::string& lang) {
   //initialize map
   _lang = lang;
   initFromLang();
   
   //load WUSBS file
   std::ifstream reader(path);

   //create command map from WUSBS file
   while (reader.good()) {
      //read line
      std::string rawLine = read(reader);
      //invoke WUSBS preprocessor
      std::string code = "";
      std::string comments = "";
      if (!preProcessFile(rawLine, code, comments)) {
         continue;
      }
      
      //extract command
      std::istrstream commandStream(code.c_str());
      const std::string command = read(commandStream, COMMAND_DELIM);

      //find and clear appropriate list of arguments
      ArgVec& arguments = (*_commandMapPtr)[command];
      arguments = {};

      //extract parameters
      while (commandStream.good()) {
         arguments.push_back(read(commandStream, ARG_DELIM));
      }
   }
}

//access arguments for a command
//throws an error if an invalid command for the language is used
ArgVec& CommandMap::operator[](const std::string& command) {
   if (!_commandMapPtr->contains(command)) {
      ThrowErrWUSBS("'" + command + "' is not a valid WUSBS command");
   }
   return (*_commandMapPtr)[command];
}

#endif //COMMAND_MAP_CPP