
// Modern coding: We are going to center our code around types.
// Put different types in different files, and move the code to the type that
// they belong to (most)

// What is a type?
// simple view (old fashioned) : Type is defined by implementation.
// two things that have the same implementation, have the same type.
// In C if you define a type, you only define its implementation.

#include "phonebook.h"
#include <fstream>

int main( )
{
   Name n( "CATO" );
   std::cout << n << std::endl;

   n = Name( "van-beethoven" );
   std::cout << n << "\n";

   std::ifstream f( "phonebook.txt" );
   if( !f )
   {
      std::cout << "could not open the phonebook\n";
      return -1;
   }
   PhoneBook book;
   f >> book;
   book.checkandnormalize(std::cout);

   
   for( size_t i1 = 0; i1 != book. entries. size( ); i1++ ){
      for( size_t i2 = i1 + 1; i2 != book. entries. size( ); i2++ )
      {
         if( book. entries[i1]. secondname > book.entries[i2]. secondname )
         {
            std::swap( book. entries[i1], book. entries[i2] );
         }
      }
   }
   
   std::cout << book << "\n";

   std::ofstream sorted( "sorted.txt" );
   if( !sorted )
   {
   std::cout << "could not open outputfile\n";
   return -1;
   }
   sorted << book;

   return 0;



}

