
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++11
CPP = g++ -O3 -flto


main : Makefile   set.o main.o
	$(CPP) $(Flags) -o main   set.o main.o

set.o : Makefile   set.cpp   set.h
	$(CPP) -c $(Flags) set.cpp -o  set.o

main.o : Makefile   main.cpp   set.h
	$(CPP) -c $(Flags) main.cpp -o  main.o
