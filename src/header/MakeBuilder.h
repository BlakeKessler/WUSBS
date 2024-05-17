#ifndef MAKE_MAKER_H
#define MAKE_MAKER_H

#include "defines.h"
#include "utils.h"

#include "CommandMap.h"

#include <string>
#include <fstream>

class MakeBuilder {
   private:
      CommandMap _commandMap;
      bool generateCommandMap();
      const std::string writeMakeRule(const std::vector<ArgVec>& lines);
   public:
      MakeBuilder();
      MakeBuilder(CommandMap& commands);
      ArgVec& operator[](const std::string& command);
      bool build();
};

#endif //MAKE_MAKER_H