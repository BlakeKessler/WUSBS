#ifndef WUSBS_READER_H
#define WUSBS_READER_H

#include "defines.h"
#include "utils.h"

#include "CommandMap.h"

#include <string>
#include <strstream>
#include <fstream>

class WUSBS_Reader {
   private:
      CommandMap _commandMap;
      ArgVec _WUSBS_args;

      bool preProcess(const std::string& rawLine, std::string&code, std::string& comments) const;
   public:
      WUSBS_Reader(const std::string& path);
};

#endif //WUSBS_READER_H