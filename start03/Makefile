
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17
CPP = g++ -flto -O3


main : Makefile   main.o set.o timetable.o 
	$(CPP) $(Flags) -o main   main.o set.o timetable.o 

main.o : Makefile   main.cpp   timer.h timetable.h set.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


set.o : Makefile   set.cpp   set.h 
	$(CPP) -c $(Flags) set.cpp -o  set.o


timetable.o : Makefile   timetable.cpp   timetable.h 
	$(CPP) -c $(Flags) timetable.cpp -o  timetable.o


