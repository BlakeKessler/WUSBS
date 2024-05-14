bin/WUSBS.o : src/defines.h src/main.cpp 
	g++ -std=c++23 $^ -o $@
