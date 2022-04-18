
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++2a
CPP = g++ -O3 -flto


main : Makefile   main.o timetable.o sorting.o stack.o 
	$(CPP) $(Flags) -o main   main.o timetable.o sorting.o stack.o 

main.o : Makefile   main.cpp   timer.h stack.h sorting.h timetable.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


timetable.o : Makefile   timetable.cpp   timetable.h 
	$(CPP) -c $(Flags) timetable.cpp -o  timetable.o


sorting.o : Makefile   sorting.cpp   sorting.h 
	$(CPP) -c $(Flags) sorting.cpp -o  sorting.o


stack.o : Makefile   stack.cpp   stack.h 
	$(CPP) -c $(Flags) stack.cpp -o  stack.o


