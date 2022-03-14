
#ifndef PHONENUMBER_
#define PHONENUMBER_

// It is common to use capitals for types.

#include <string>
#include <iostream>


class PhoneNumber
{
   std::string nr;

public: 
   PhoneNumber( ) = default;

   PhoneNumber( const std::string& s )
       : nr(s)
   { } 

   PhoneNumber( const char* c ) 
      : PhoneNumber( std::string(c))
   { }

   bool iswellformed( ) const; 
      // True if number seems well-formed.

   void print( std::ostream& out ) const
   {
      out << nr; 
   }

   void read( std::istream& in ) 
   {
      in >> nr;
   }

};

inline std::ostream& operator << ( std::ostream& out, const PhoneNumber& num )
{
   num. print( out ); 
   return out;
}

inline std::istream& operator >> ( std::istream& in, PhoneNumber& num )
{
   num. read( in );
   return in;
}

#endif

