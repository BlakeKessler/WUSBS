bin/WUSBS.o: src/header/utils.h src/header/CommandMap.h src/header/MakeBuilder.h src/defines.h src/src/utils.cpp src/src/CommandMap.cpp src/src/CommandMapInit.cpp src/src/MakeBuilder.cpp src/main.cpp 
	g++ -std=c++23 -g $^ -Isrc -Isrc/header
