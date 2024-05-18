#ifndef FILE_CPP
#define FILE_CPP

#include "c-cpp/File.h"
#include <fstream>

File::File(const Path& name) {
    //store file name
    _file = name;
    _allHeaders[_file] = this;

    //read file into list of line strings
    std::ifstream reader(_file.to_string());
    while (reader.good()) {
        _lineList.push_back(read(reader));
    }
}

#endif //FILE_CPP