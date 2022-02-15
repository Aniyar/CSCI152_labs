
#ifndef MOVE_
#define MOVE_ 1

#include <iostream>

struct move
{
   unsigned int row;
   unsigned int remaining;

   move( unsigned int row, unsigned int remaining )
      : row( row ), remaining( remaining )
   { }
};

inline std::ostream& operator << ( std::ostream& out, move m )
{
   out << "move( " << m. row << ", " << m. remaining << " )";
   return out; 
}


struct optional_move
{
   bool isdefined; 
   move m;
  
   optional_move( )   
      : isdefined( false ),
        m(0,0)                  // Nonsense values. 
   { }

   optional_move( move m )
      : isdefined( true ),
        m(m)
   { }

};


inline 
std::ostream& operator << ( std::ostream& out, const optional_move& opt )
{
   if( opt. isdefined )  
      out << opt. m;
   else
      out << "(undefined move)";
   return out;
}

 
#endif

