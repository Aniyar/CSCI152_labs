
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++14
CPP = g++


main : Makefile   input.o filereader.o main.o 
	$(CPP) $(Flags) -o main   input.o filereader.o main.o 

input.o : Makefile   input.cpp   dfa.h input.h filereader.h 
	$(CPP) -c $(Flags) input.cpp -o  input.o


filereader.o : Makefile   filereader.cpp   filereader.h 
	$(CPP) -c $(Flags) filereader.cpp -o  filereader.o


main.o : Makefile   main.cpp   input.h filereader.h stack.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


