#ifndef COMMAND_MAP_H
#define COMMAND_MAP_H

#include "defines.h"
#include "utils.h"

#include <unordered_map>
#include <memory>
#include <string>
#include <strstream>
#include <fstream>

class CommandMap {
   private:
      std::shared_ptr<std::unordered_map<std::string, ArgVec>> _commandMapPtr;

      bool init();
      
      bool preProcessFile(const std::string& rawLine, std::string&code, std::string& comments) const;
   public:
      CommandMap(const std::string& path = "");
      CommandMap(const CommandMap& other) = default;
      CommandMap& operator=(const CommandMap& other) = default;
      ArgVec& operator[](const std::string& command);
      bool contains(const std::string& command) { return _commandMapPtr->contains(command); }
};

#endif //COMMAND_MAP_H