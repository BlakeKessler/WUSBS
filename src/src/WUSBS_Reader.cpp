#ifndef WUSBS_READER_CPP
#define WUSBS_READER_CPP

#include "WUSBS_Reader.h"

//returns if the processing of the line should continue
bool WUSBS_Reader::preProcess(const std::string& rawLine, std::string&code, std::string& comments) const {
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

//read a WUSBS file
WUSBS_Reader::WUSBS_Reader(const std::string& path) {
   //load WUSBS file
   std::ifstream reader(path);
   //extract language
   std::string lang = read(reader);
   lang = lang.substr(0, lang.find(' '));

   //initialize command map
   _commandMap = CommandMap(lang);

   //create command map from WUSBS file
   while (reader.good()) {
      //read line
      std::string rawLine = read(reader);

      //invoke WUSBS preprocessor
      std::string code = "";
      std::string comments = "";
      if (!preProcess(rawLine, code, comments)) {
         continue;
      }
      
      //extract command
      std::istrstream commandStream(code.c_str());
      const std::string command = read(commandStream, COMMAND_DELIM);
      
      //find and clear appropriate list of arguments
      ArgVec& arguments = _commandMap[command];
      arguments = {};

      //extract parameters
      while (commandStream.good()) {
         arguments.push_back(read(commandStream, ARG_DELIM));
      }
   }
}

#endif //WUSBS_READER_CPP