
#ifndef STATE_
#define STATE_  1

#include <vector>
#include <iostream>

#include "move.h"

struct state 
{

   std::vector< unsigned int > sticks; 

   state( std::initializer_list< unsigned int > init ); 
   state( unsigned int i1, unsigned int i2 );

   unsigned int sum( ) const; 
   
   unsigned int nimber ( ) const;
   
   optional_move randommove( ) const;
      // If there are sticks, then return a valid random move.
      // Note that row is the index in sticks, not the 
      // number that is shown to the user by print( ).

   optional_move makenimberzero( ) const;
      // This will come later.

   optional_move removelastmorethantwo( ) const;
      // This will come later. 

   void make( move m ); 
      // Make move m and return true if it could be made.

   optional_move usermove( std::ostream& out, std::istream& in ) const;

   void print( std::ostream& out ) const;
};


inline std::ostream& operator << ( std::ostream& out, const state& st )
{
   st. print( out );
   return out;
}

#endif

