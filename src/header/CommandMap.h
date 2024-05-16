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
      std::string _lang;

      bool initFromLang();
         bool initCPP();
      
      bool preProcessFile(const std::string& rawLine, std::string&code, std::string& comments) const;
   public:
      // CommandMap() { ThrowErrWUSBS("A language must be selected"); }
      CommandMap(const CommandMap& other);
      CommandMap& operator=(const CommandMap& other) = default;
      CommandMap(const std::string& path = "", const std::string& lang = "");
      ArgVec& operator[](const std::string& command);
      bool contains(const std::string& command) { return _commandMapPtr->contains(command); }
      const std::string lang() { return _lang; }
};

#endif //COMMAND_MAP_H