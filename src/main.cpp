#ifndef MAIN
#define MAIN

#include "utils.h"
#include "CommandMap.h"
#include "MakeBuilder.h"

#include <iostream>

int main(int argc, char** argv) {
   //check arguments
   if (argc < 2) {
      ThrowErrWUSBS("Please provide a WUSBS file.");
      return -2;
   }
   
   //process arguments
   const std::string wusbsFilePath(argv[1]);
   const std::string lang(argv[2]);

   //read WUSBS file
   CommandMap commandMap(wusbsFilePath);

   //build makefile
   MakeBuilder WUSBS_builder(commandMap);
   return 1 - WUSBS_builder.build();
}

#endif //MAIN