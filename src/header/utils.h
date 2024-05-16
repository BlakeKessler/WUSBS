#ifndef WUSBS_UTILS_H
#define WUSBS_UTILS_H

#include <iostream>
#include <vector>

   using ArgVec = std::vector<std::string>;
   std::ostream& operator<<(std::ostream& out, ArgVec& argVec);
   const std::string toString(const ArgVec& args, const char delim = ' ');

   void ThrowErrWUSBS(const std::string& errorCode);

   std::string read(std::istream& in, const char delim = '\n');

#endif //WUSBS_UTILS_H