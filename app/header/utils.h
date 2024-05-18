#ifndef WUSBS_UTILS_H
#define WUSBS_UTILS_H

#include <string>
// #include <iostream>
#include <iosfwd>
#include <vector>
#include <filesystem>
#include <memory>

   using ArgVec = std::vector<std::string>;
   std::ostream& operator<<(std::ostream& out, ArgVec& argVec);
   const std::string toString(const ArgVec& args, const char delim = ' ');

   using Path = std::filesystem::path;
   using PathVec = std::vector<Path>;

   using StringPtr = std::shared_ptr<std::string>;
   auto makeStringPtr = std::make_shared<std::string>;

   void ThrowErrWUSBS(const std::string& errorCode);

   std::string read(std::istream& in, const char delim = '\n');

#endif //WUSBS_UTILS_H