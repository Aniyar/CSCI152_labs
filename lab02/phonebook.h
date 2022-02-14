
#ifndef PHONEBOOK_
#define PHONEBOOK_ 

#include <string>
#include <vector>
#include <iostream>

#include "phonenumber.h"
#include "name.h"

struct PhoneEntry 
{
   Name firstname;   
   Name secondname; 
   PhoneNumber number; 

   PhoneEntry( ) = default;

   PhoneEntry( const Name& firstname,
               const Name& secondname,
               const PhoneNumber& number )
      : firstname( firstname ),
        secondname( secondname ),
        number( number )
   { }

   void print( std::ostream& out ) const;
   void read( std::istream& in ); 
};

inline std::ostream& operator << ( std::ostream& out, const PhoneEntry& e )
{
   e. print( out );
   return out;
}

inline std::istream& operator >> ( std::istream& in, PhoneEntry& e )
{
   e. read( in );  
   return in;
}


struct PhoneBook
{
   std::vector< PhoneEntry > entries; 

   PhoneBook( ) = default;

   void insert( const PhoneEntry& e ) 
   {
      entries. push_back(e);
   }

   void print( std::ostream& out ) const;
   void read( std::istream& in ); 

   void checkandnormalize( std::ostream& err );
      // Errors are reported into err.
};

inline std::ostream& operator << ( std::ostream& out, const PhoneBook& book )
{
   book. print( out );
   return out;
}

inline std::istream& operator >> ( std::istream& in, PhoneBook& book )
{
   book. read( in );
   return in;
}

#endif


