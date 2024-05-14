#ifndef MAIN
#define MAIN

#include <iostream>
#include <strstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <functional>

#include "defines.h"

using ArgVec = std::vector<std::string>;

struct StrippedHash {
   std::size_t operator()(const std::string& key) const {
      std::string strippedKey = "";
      for (const char c : key) {
         if (c != ' ') {
            strippedKey.push_back(c);
         }
      }
      return std::hash<std::string>()(strippedKey);
   }
};
std::string read(std::istream& in, const char delim = '\n');
std::ostream& operator<<(std::ostream& out, ArgVec& argVec);
std::string nameExecutable(std::string main);

int main(int argc, char** argv) {
   //check arguments
   if (argc < 2) {
      std::cerr << "Please provide a WUSBS file" << std::endl;
      return -1;
   }

   const std::string wusbsPath(argv[1]);
   std::ifstream wusbsRead(wusbsPath);
   if (!wusbsRead.good()) {
      std::cerr << "Unable to open file '" << wusbsPath << "' as WUSBS file." << std::endl;
      return -1;
   }

   //instantiate command map
   std::unordered_map<std::string, ArgVec> commands{
      //compiler commands
      {"COMPILER", DEFAULT_COMPILER},
      {"STD", {}},
      {"FLAGS", DEFAULT_FLAGS},
      {"DEBUG_FLAGS", DEFAULT_DEBUG_FLAGS},
      {"RELEASE_FLAGS", DEFAULT_RELEASE_FLAGS},

      //makefile/executable commands
      {"TARGET", {}},
      {"MAKEFILE", DEFAULT_MAKEFILE},
      {"BUILD_DIR", DEFAULT_BUILD_DIR},

      //include commands
      {"ROOT", DEFAULT_ROOT},
      {"HEADERS", {}},
      {"SOURCES", {}},
      {"MAIN", DEFAULT_MAIN},
      {"L", {}},
      {"l", {}},
      {"I", {}},

      //dummy commands
      {"PROJECT_NAME", {}},
      {"PROJECT_VERSION", {}}
   };

   //process WUSBS file into command map
   while (wusbsRead.good()) {
      //read line
      std::string rawLine = read(wusbsRead);

      //preprocess line
      if (rawLine.size() == 0) { continue; } //skip to next line if the current line is empty
      std::istrstream preStream(rawLine.c_str());
      std::string line = "";
      std::string comments = "";
      while (preStream.good()) {
         line += read(preStream, COMMENT_DELIM);
         comments += read(preStream, COMMENT_DELIM);
         if (comments.size() > 0) { comments.push_back('\n'); } //add newline character between comments
      }
      
      //process line
      if (line.size() == 0) { continue; } //skip to next line if the current line contains no uncommented commands
      std::istrstream lineStream(line.c_str());
      const std::string command = read(lineStream, COMMAND_DELIM);

      if (!commands.contains(command)) {
         std::cerr << "'" << command << "' is not a valid command" << std::endl;
         return -2;
      }
      ArgVec& arguments = commands[command];
      arguments = {};
      while (lineStream.good()) { //get parameters
         arguments.push_back(read(lineStream, ARG_DELIM));
      }
   }

   //generate makefile
   const std::string mkFilePath = commands["BUILD_DIR"][0] + '/' + commands["MAKEFILE"][0];
   std::ofstream makeMaker(mkFilePath);
   if (!makeMaker.good()) {
      std::cerr << "Unable to create makefile '" << mkFilePath << "'." << std::endl;
      return -2;
   }
   
   makeMaker << commands["BUILD_DIR"][0] << "/" << commands["TARGET"] << ": " << commands["HEADERS"] << commands["SOURCES"] << commands["MAIN"] << std::endl; //write target and prereqs
   makeMaker << "\t" << commands["COMPILER"] << "-std=" << commands["STD"] << "$^ -o $@" << std::endl; //write compile command

   makeMaker.close();
   return 0;
}


std::string read(std::istream& in, const char delim) {
   //remove leading spaces
   while (in.peek() == ' ') {
      in.get();
   }

   //read line
   std::string str = "";
   std::getline(in, str, delim);
   
   //remove trailing spaces
   while (str.back() == ' ') {
      str.pop_back();
   }
   return str;
}

std::ostream& operator<<(std::ostream& out, ArgVec& argVec) {
   for (const std::string& arg : argVec) {
      out << arg << ' ';
   }
   return out;
}

#endif //MAIN