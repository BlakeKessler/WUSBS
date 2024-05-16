#ifndef WUSBS_UTILS_CPP
#define WUSBS_UTILS_CPP

#include "utils.h"

//print an ArgVec to and output stream
std::ostream& operator<<(std::ostream& out, ArgVec& argVec) {
   for (const std::string& arg : argVec) {
      out << arg << ' ';
   }
   return out;
}

//convert an ArgVec to a string with the delimeter character after each string
const std::string toString(const ArgVec& args, const char delim) {
   std::string outStr = "";
   for (const std::string& arg : args) {
      outStr += arg;
      outStr.push_back(delim);
   }
   return outStr;
}

//throw a WUSBS error
//not mechanically different from normal error-throwing, but formatted
void ThrowErrWUSBS(const std::string& errorCode) {
   std::cerr << "WUSBS ERROR: " << errorCode << std::endl;
   throw("WUSBS ERROR: " + errorCode);
}

//read until a specific delimeter from an input stream
//ignores leading and trailing spaces
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

#endif //WUSBS_UTILS_CPP