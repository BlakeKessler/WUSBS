#ifndef MAKE_MAKER_CPP
#define MAKE_MAKER_CPP

#include "MakeBuilder.h"

//write makefile rule to create a single executable
const std::string MakeBuilder::writeMakeRule(const std::vector<ArgVec>& lines) {
   std::string command = toString(lines[0]) + '\n';
   for (uint i = 1; i < lines.size(); ++i) {
      command += '\t' + toString(lines[i]) + '\n';
   }
   return command;
}

//public constructor from language
//throws an error if an unsupported language is used
MakeBuilder::MakeBuilder(CommandMap& commands) {
   _commandMap = commands;
}

//access arguments for a command
//throws an error if an invalid command for the language is used
ArgVec& MakeBuilder::operator[](const std::string& command) {
   if (!_commandMap.contains(command)) {
      ThrowErrWUSBS("'" + command + "' is not a valid WUSBS command");
   }
   return _commandMap[command];
}

//create makefile
bool MakeBuilder::build() {
   //open makefile output-stream
   const std::string makeFilePath = _commandMap["BUILD_DIR"][0] + '/' + _commandMap["MAKEFILE"][0];
   std::ofstream makeMaker(makeFilePath);
   if (!makeMaker.good()) {
      ThrowErrWUSBS("Unable to create makefile '" + makeFilePath + "'.");
      return false;
   }

   //create makefile contents
   const std::string targetPath = _commandMap["BUILD_DIR"][0] + "/" + _commandMap["TARGET"][0];
   const std::string includes = toString(_commandMap["HEADERS"]) + toString(_commandMap["SOURCES"]) + toString(_commandMap["MAIN"]);
   const std::string compiler = _commandMap["COMPILER"][0] + (_commandMap["STD"].size() > 0 ? (" -std=" + _commandMap["STD"][0]) : "") + ' ';
   const std::string sourceFiles = "$^";
   // const std::string executableName = "-o $@";

   //write command to makefile
   const std::vector<ArgVec> command{
      {targetPath, " : ", includes},
      {compiler, sourceFiles}
   };
   makeMaker << writeMakeRule(command);

   //close makefile stream
   makeMaker.close();
   return true;
}

#endif //MAKE_MAKER_CPP