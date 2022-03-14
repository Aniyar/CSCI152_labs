
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++2a
CPP = g++


book : Makefile   book.o phonebook.o name.o phonenumber.o 
	$(CPP) $(Flags) -o book   book.o phonebook.o name.o phonenumber.o 

book.o : Makefile   book.cpp   phonebook.h phonenumber.h name.h 
	$(CPP) -c $(Flags) book.cpp -o  book.o


phonebook.o : Makefile   phonebook.cpp   phonebook.h phonenumber.h name.h 
	$(CPP) -c $(Flags) phonebook.cpp -o  phonebook.o


name.o : Makefile   name.cpp   name.h 
	$(CPP) -c $(Flags) name.cpp -o  name.o


phonenumber.o : Makefile   phonenumber.cpp   phonenumber.h 
	$(CPP) -c $(Flags) phonenumber.cpp -o  phonenumber.o


