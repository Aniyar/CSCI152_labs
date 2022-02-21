


Flags = -Wpedantic -pedantic-errors -std=c++17
CPP = g++


nim : Makefile   nim.o state.o 
	$(CPP) $(Flags) -o nim   nim.o state.o 

nim.o : Makefile   nim.cpp   state.h move.h 
	$(CPP) -c $(Flags) nim.cpp -o  nim.o


state.o : Makefile   state.cpp   state.h move.h 
	$(CPP) -c $(Flags) state.cpp -o  state.o


