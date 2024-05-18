#ifndef LINKER_H
#define LINKER_H

#include "c-cpp/Header.h"

#include <string>
#include <vector>

class Linker {
    private:
        const File _main;
        ArgVec _includeFolders;
        std::vector<FilePtr> _headers;
        std::vector<FilePtr> _sources;
    public:
        Linker(const std::string& main, const ArgVec& includes);
        Linker(const FilePtr mainPtr, const ArgVec& includes);

        bool link();

};

//NOTE: _includeFolders should probably be associative 

#endif //LINKER_H