
#include "move.h"
#include "state.h"

#include <thread> 
#include <chrono>

enum player { user, computer };

int main( int arg, char* argv[] )
{
   state s( 1, 6 );
   player turn = user;
   srand( time( nullptr ));
   while( s. sum( ) > 1 )
   {
      std::cout << '\n';
      std::cout << s << '\n';

      if( turn == user )
      {
         std::cout << "hello, user, please make a move\n";
         auto mov = s. usermove( std::cout, std::cin );
         s. make( mov.m ); 
         turn = computer; 
      }
      else
      {   
         std::cout << "now I will make a move\n"; 
         std::cout << "thinking\n"; 

         for( unsigned int r = 0; r != 15; ++ r )
         {
            std::cout << '.'; std::cout. flush( ); 
            std::this_thread::sleep_for( std::chrono::milliseconds(100) ); 
         }

         std::cout << '\n';

         optional_move mov = s. randommove( ); 

         if( mov. isdefined )
            s. make( mov. m );
         else
            std::abort( );   // should not happen. 

         turn = user;
      } 
   }
      
   std::cout << '\n';
   std::cout << s << '\n';

   std::this_thread::sleep_for( std::chrono::milliseconds(500) );

   if( s. sum( ) == 0 )
   {
      if( turn == user )
         std::cout << "you won\n";
      else
         std::cout << "you lost (unnecessarily)\n";
   }
   else
   {
      if( turn == user )
         std::cout << "you lost\n";
      else 
         std::cout << "you won\n";
   }

   std::cout << "\n";

   return 0;
}


