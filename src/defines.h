#ifndef DEFINES
#define DEFINES

   #define DEFAULT_COMPILER {"g++"}
   #define DEFAULT_HEADER_EXTENSIONS {"hpp", "h"}
   #define DEFAULT_SOURCE_EXTENSIONS {"cpp", "cxx", "c", "cc"}
   // #define DEFAULT_STD {"c++23"}
   #define DEFAULT_FLAGS {"-Wall", "-Wextra"} //maybe add -xc++-header
   #define DEFAULT_DEBUG_FLAGS {"-g", "-Og"}
   #define DEFAULT_RELEASE_FLAGS {"-O3"}
   #define DEFAULT_MAIN {"main.cpp"}
   #define DEFAULT_ROOT {"."}
   #define DEFAULT_BUILD_DIR {"bin"}
   #define DEFAULT_MAKEFILE {"make.mk"}

   #define DEFAULT_MAX_DEPTH 0xFF //max recursion depth
   #define COMMAND_DELIM '='
   #define ARG_DELIM ' '
   #define COMMENT_DELIM '#'

#endif //DEFINES