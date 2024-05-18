#ifndef LINKER_CPP
#define LINKER_CPP

#include "cpp/Linker.h"

Linker::Linker(const std::string& main, const ArgVec& includes) {
    _main = makeFilePtr(main);
    _includeFolders = includes;
}

Linker::Linker(const FilePtr mainPtr, const ArgVec& includes) {
    _main = mainPtr;
    _includeFolders = includes;
}

bool Linker::link() {

}

#endif //LINKER_CPP