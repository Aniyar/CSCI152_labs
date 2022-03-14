
#include "phonebook.h"

#include <string>
#include <iostream>

void PhoneEntry::print( std::ostream& out ) const 
{
    out << firstname << " "<< secondname << " "<< number << "\n";
}

void PhoneEntry::read( std::istream& in )
{
    in >> firstname >> secondname >> number;
}


void PhoneBook::read( std::istream& in ) 
{
    PhoneEntry entry;
    while (in){
        entry.read(in);
        if (in){
            entries.push_back(entry);
        }
        
    }
} 


void PhoneBook::print( std::ostream& out ) const 
{
    for(PhoneEntry i : entries){
        out << i;
    }
}


void PhoneBook::checkandnormalize( std::ostream& err )
{
    for(PhoneEntry &i : entries){
        i.firstname.normalize();
        i.secondname.normalize();
        if (!i.number.iswellformed()){
            err << "WARNING: "<< "number " << i.number <<" is not well-formed" << "\n";
        }
    }

}


