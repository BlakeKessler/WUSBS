#ifndef FILE_H
#define FILE_H

#include "utils.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <list>
#include <iosfwd>

class File;
using FilePtr = std::shared_ptr<File>;
using makeFilePtr = std::make_shared<File>;

class File {
    private:
        friend class Linker;
        Path _file;
        std::list<std::string> _lineList;
        Path _compiledFile;
        std::vector<FilePtr> _includes;
        std::vector<FilePtr> _definitions;
    public:
        static std::unordered_map<Path, FilePtr> _allHeaders;

        File(const Path& name);
        File(const File& other) = default;

        bool runPreProcessor();
        
        bool operator==(const File& other) = default;
        bool operator==(const std::string& otherName);
        bool operator<(const File& other);
        bool operator<(const std::string& otherName);
};

#endif //FILE_H