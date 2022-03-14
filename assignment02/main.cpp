
#include "queue.h"

int main( int argc, char* argv [ ] )
{
   queue q = { "we", "are", "waiting", "in", "the", "queue" };

   std::cout << q << "\n";
  
   while( q. size( ) > 3 ) 
   {
      auto s = q. peek( );
      std::cout << s << "\n";
      q. pop( );
   }
 
   queue andtheygo =
      { "et", "eunt", "homines", "mirari", "alta", "montium",
        "et", "ingentes", "fluctus", "maris", "et", "latissimos", "lapsus", 
        "fluminum", "et", "Oceani", "ambitum", "et", "gyros", "siderum", 
        "et", "relinquunt", "se", "ipsos", "nec", "mirantur" };

   q = andtheygo;

   while( q. size( ))
   {
      std::cout << q. peek( ) << "\n";
      q. pop( );
   }

   return 0;
}

