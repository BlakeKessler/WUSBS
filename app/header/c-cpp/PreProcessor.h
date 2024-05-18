#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include "utils.h"
#include "File.h"

#include <list>
#include <string>
#include <iosfwd>

//https://en.cppreference.com/w/cpp/filesystem/directory_iterator
class PreProcessor {
    private:
        FilePtr _file;
        ArgVec _directives;
    public:
        // PreProcessor(const std::string& path);
        // PreProcessor(const Path& path);
        // PreProcessor(std::istream& input);
        PreProcessor(File& inputFile); //modifies the file passed to it

        // static ArgVec& PreProcess(std::list<std::string>& lineList);
};

#endif //PRE_PROCESSOR_H