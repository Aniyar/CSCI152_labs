
#ifndef NAME_H
#define NAME_H

#include <string>
#include <iostream>

class Name
{
   std::string n;     
      // It is hard to give meaningful names to such fields. 
      // This is a consequence of the fact that we are trying
      // to restrict a type without using inheritance.

public: 
   Name( ) = default;
   // Construct from C++-string:

   Name( const std::string& n ) 
      : n(n)
   {
      normalize( );  
   }
   // Construct from C-string:
 
   Name( const char* c )
      : Name( std::string(c)) 
   { } 

   void print( std::ostream& out ) const
      { out << n; } 

   void read( std::istream& in ) 
      { in >> n; }

   void normalize( );

   bool operator > ( const Name& other ) const
   { 
      return n > other.n;
   }
};

inline std::ostream& operator << ( std::ostream& out, const Name& n )
{
   n. print( out );
   return out;
}

inline std::istream& operator >> ( std::istream& in, Name& n )
{
   n. read( in );
   return in;
}





#endif

