
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

#include "stack.h"


int main( int argc, char* argv [ ] )
{
   stack s();
   stack s1 = { 4, 2, 1 };
   s1.print(std::cout);
   stack s2 = { 8, 7, 4, 3, 0 };
   s2.print(std::cout);
   for( size_t i = 0; i < 1000; ++ i )
   {
      s1. push( i*i ); 
      s2 = s1;
   }

   double sum = 0;
   while( s2. size( ))
   {
      stack s3 = s2;
      sum += s3. peek( );
      s2. pop( );
   }
   std::cout << "the sum is " << sum << "\n";
   std::cout << " should be 3.32834e+08\n"; 
   return 0;
}

